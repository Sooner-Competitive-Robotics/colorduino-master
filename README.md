# colorduino-master

This (branch of this) repository contains C++ code to communicate with a Colorduino device via I^2^C (intended to be used with [colorduino-slave](https://github.com/Sooner-IEEE-Robotics/colorduino-slave)) to set a given light to a certain color value. Since it runs on an Arduino itself, it doesn't do exception handling or anything very flexible/complicated, but it ought to work for what we need it to do.

This library exposes a single class, `Master`. This class, intended to be used as a singleton, exposes simple functions to do things to the Colorduino display (which you would expect), documented below.

--------

## Documentation

### `Master`


#### `Master(void)`

Returns an instance of the Master class which communicates using I^2^C address 8.


#### `Master(int address)`

Returns an instance of the Master class which will communicate with the given target address. Use this if you don't want to use the default (which is 8 as of version 1.0).

#### `int setPixel(int x, int y, int r, int g, int b)`
Returns either 0 (on success) or -1 (on failure). Sends a message to the slave to set the pixel located at (x, y) (indexed from the bottom-left in the intended-for-use [colorduino-slave](https://github.com/Sooner-IEEE-Robotics/colorduino-slave) library) to a color with RGB components (r, g, b). This the the bread-winner. The moneymaker. Et cetera.