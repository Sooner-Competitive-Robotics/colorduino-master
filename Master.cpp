#include <Colorduino.h>
#include <Wire.h>

class Master {
  public:
    Master(void) {
      Wire.begin(); // Join the bus as a master (of the Jedi Council).
    }
    ~Master(void) {
      // There's apparently no way to un-join the bus, so that's cool. You should use this class as a singleton.
    }
    int setPixel(int x, int y, int r, int g, int b) {
      Wire.beginTransmission(8);
      int success = Wire.write(x) && Wire.write(y) && Wire.write(r) && Wire.write(g) && Wire.write(b); // This is a little bit ugly, but it'll work.
      Wire.endTransmission(8);
      return success ? 0 : -1;
    }
};

