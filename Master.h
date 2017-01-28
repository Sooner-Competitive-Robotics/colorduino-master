#ifndef FLUFFY_KITTENS
#define FLUFFY_KITTENS

class Master {
	
    Master(int address);
    Master(void); // Default address is 8.
    
    int setPixelBlue(int x, int y); // Returns 0 on success, -1 on failure.
    int setPixelRed(int x, int y); // Returns 0 on success, -1 on failure.
    int setPixelYellow(int x, int y); // Returns 0 on success, -1 on failure.

    int setPixel(int x, int y, int r, int g, int b); // Returns 0 on success, -1 on failure.
    
};

#endif // FLUFFY_KITTENS