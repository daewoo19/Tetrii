#ifndef Timer_H
#define Timer_H

#include "SDL/SDL.h"

// == Drop Timer ==
Uint32 dropTimerCallback(Uint32 interval, void *param);

// == [other timer] ==

#endif

///*This source code copyrighted by Lazy Foo' Productions (2004-2007) and may not be redestributed without written permission.*/
//
////The headers
//#include "SDL/SDL.h"
//
//
//
////The timer
//class Timer
//{
//    private:
//    //The clock time when the timer started
//    int startTicks;
//    
//    //The ticks stored when the timer was paused
//    int pausedTicks;
//    
//    //The timer status
//    bool paused;
//    bool started;
//    
//    public:
//    //Initializes variables
//    Timer();
//    
//    //The various clock actions
//    void start();
//    void stop();
//    void pause();
//    void unpause();
//    
//    //Gets the timer's time
//    int get_ticks();
//    
//    //Checks the status of the timer
//    bool is_started();
//    bool is_paused();    
//};

