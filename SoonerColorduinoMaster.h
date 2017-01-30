#ifndef SOONERCOLORDUINOMASTER_H
#define SOONERCOLORDUINOMASTER_H

class SoonerColorduinoMaster {
	
	public:
		SoonerColorduinoMaster(int address);
		SoonerColorduinoMaster(); // Default address is 8.
		virtual ~SoonerColorduinoMaster();
		
		int setPixelBlue(int x, int y); // Returns 0 on success, -1 on failure.
		int setPixelRed(int x, int y); // Returns 0 on success, -1 on failure.
		int setPixelYellow(int x, int y); // Returns 0 on success, -1 on failure.
	
		int setPixel(int x, int y, int r, int g, int b); // Returns 0 on success, -1 on failure.
		
    private:
		int address;
};

#endif // FLUFFY_KITTENS