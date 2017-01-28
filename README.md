# colorduino-master

This (branch of this) repository contains C++ code to communicate with a Colorduino device via I<sup>2</sup>C (intended to be used with [colorduino-slave](https://github.com/Sooner-IEEE-Robotics/colorduino-slave)) to set a given light to a certain color value. Since it runs on an Arduino itself, it doesn't do exception handling or anything very flexible/complicated, but it ought to work for what we need it to do.

This library exposes a single class, `SoonerColorduinoMaster`. This class, intended to be used as a singleton, exposes simple functions to do things to the Colorduino display (which you would expect), documented below.

--------

## Documentation

### `SoonerColorduinoMaster`


#### `SoonerColorduinoMaster(void)`

Returns an instance of the `SoonerColorduinoMaster` class which communicates using I<sup>2</sup>C address `8`.


#### `SoonerColorduinoMaster(int address)`

Returns an instance of the `SoonerColorduinoMaster` class which will communicate with the given target address. Use this if you don't want to use the default (which is `8` (`0b1000`) as of version 1.0).

#### `int setPixel(int x, int y, int r, int g, int b)`
Returns either `0` (on success) or `-1` (on failure). Sends a message to the slave to set the pixel located at `(x, y)` (indexed from the bottom-left in the intended-for-use [colorduino-slave](https://github.com/Sooner-IEEE-Robotics/colorduino-slave) library) to a color with RGB components `(r, g, b)`. This the the bread-winner. The moneymaker. Et cetera.

#### `int setPixelBlue(int x, int y)`
Returns either `0` (on success) or `-1` (on failure). This is a convenience method which simply invokes `setPixel` with the RGB values `(0, 0, 63)`.

#### `int setPixelRed(int x, int y)`
Returns either `0` (on success) or `-1` (on failure). This is a convenience method which simply invokes `setPixel` with the RGB values `(63, 0, 0)`.

#### `int setPixelYellow(int x, int y)`
Returns either `0` (on success) or `-1` (on failure). This is a convenience method which simply invokes `setPixel` with the RGB values `(63, 63, 0)`.