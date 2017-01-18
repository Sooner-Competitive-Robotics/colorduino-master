var i2c = require('i2c')

module.exports = class {

	constructor(address = 0x18, device = '/dev/i2c-1') { // /dev/i2c-0 is rev 1; /dev/i2c-1 is rev 2
		this.wire = new i2c(address, { device: device })
	}

	setPixel(x, y, r, g, b, callback = err => { throw err }) {
		if(x < 0 || x > 7) {
			return callback(new Error(`The supplied x coordinate ${x} lies outside of the legal range [0, 7].`))
		}
		if(y < 0 || y > 7) {
			return callback(new Error(`The supplied y coordinate ${y} lies outside of the legal range [0, 7].`))
		}
		if(r < 0 || r > 63) {
			return callback(new Error(`The supplied red component ${r} lies outside of the legal range [0, 63].`))
		}
		if(g < 0 || g > 63) {
			return callback(new Error(`The supplied green component ${g} lies outside of the legal range [0, 63].`))
		}
		if(b < 0 || b > 63) {
			return callback(new Error(`The supplied blue component ${b} lies outside of the legal range [0, 63].`))
		}
		this.wire.write([x, y, r, g, b], callback)
	}

	setPixelWhite(x, y, callback) {
		this.setPixel(x, y, 63, 63, 63, callback)
	}

	scanForAddresses(callback) {
		if(!callback) { throw new Error('Master class\'s scanForAddresses function requires a callback (of format (err, addresses)) to be useful.') }
		this.wire.scan(callback)
	}

	addDataHandler(handler) {
		this.wire.on('data', handler) // data buffer, address, length, timestamp
	}

}