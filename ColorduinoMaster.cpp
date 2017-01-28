#include <Colorduino.h>
#include <Wire.h>

class SoonerColorduinoMaster {
  
  int address;

  public:

    Master(int deviceAddress) {
      address = deviceAddress;
      Wire.begin(); // Join the bus as a master (of the Jedi Council).
    }

    Master(void) {
      address = 8;
      Wire.begin(); // Join the bus as a master (of the Jedi Council).
    }

    ~Master(void) {
      // There's apparently no way to un-join the bus, so that's cool. You should use this class as a singleton.
    }

    int setPixel(int x, int y, int r, int g, int b) { // The cash cow. The money-maker. Et cetera.
      Wire.beginTransmission(address);
      int success = Wire.write(x) && Wire.write(y) && Wire.write(r) && Wire.write(g) && Wire.write(b); // This is a little bit ugly, but it'll work.
      Wire.endTransmission(address);
      return success ? 0 : -1;
    }

    /// Convenience functions; these just call setPixel with a predefined color.

    int setPixelBlue(int x, int y) {
      return setPixel(x, y, 0, 0, 63);
    }

    int setPixelRed(int x, int y) {
      return setPixel(x, y, 63, 0, 0);
    }

    int setPixelYellow(int x, int y) {
      return setPixel(x, y, 63, 63, 0);
    }

};

