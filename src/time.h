#ifndef TIME_H
#define TIME_H

class Time {
	public:
		static void init();
		static long deltaTime();
		static float deltaTimeSecs();
		static void update();		
};

#endif

