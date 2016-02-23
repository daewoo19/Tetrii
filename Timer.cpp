#include "Timer.h"
#include "DropTimerParams.h"
#include "SDL/SDL.h"

Uint32 dropTimerCallback(Uint32 interval, void *dropTimerParams)
{
        SDL_Event event;
        SDL_UserEvent userevent;

        /* In this example, our callback pushes an SDL_USEREVENT event
           into the queue, and causes ourself to be called again at the
           same interval: */

		DropTimerParams *params = (DropTimerParams*)dropTimerParams;

        userevent.type = SDL_USEREVENT;
        userevent.code = 0;
        //userevent.data1 = NULL;
        //userevent.data2 = NULL;

        event.type = SDL_USEREVENT;
        event.user = userevent;

        SDL_PushEvent(&event);
        return(interval);
}

//#include "Timer.h"
//
//
//Timer::Timer()
//{
//    //Initialize the variables
//    startTicks = 0;
//    pausedTicks = 0;
//    paused = false;
//    started = false;    
//}
//
//void Timer::start()
//{
//    //Start the timer
//    started = true;
//    
//    //Unpause the timer
//    paused = false;
//    
//    //Get the current clock time
//    startTicks = SDL_GetTicks();    
//}
//
//
//void Timer::stop()
//{
//    //Stop the timer
//    started = false;
//    
//    //Unpause the timer
//    paused = false;    
//}
//
//void Timer::pause()
//{
//    //If the timer is running and isn't already paused
//    if( ( started == true ) && ( paused == false ) )
//    {
//        //Pause the timer
//        paused = true;
//    
//        //Calculate the paused ticks
//        pausedTicks = SDL_GetTicks() - startTicks;
//    }
//}
//
//void Timer::unpause()
//{
//    //If the timer is paused
//    if( paused == true )
//    {
//        //Unpause the timer
//        paused = false;
//    
//        //Reset the starting ticks
//        startTicks = SDL_GetTicks() - pausedTicks;
//        
//        //Reset the paused ticks
//        pausedTicks = 0;
//    }
//}
//
//int Timer::get_ticks()
//{
//    //If the timer is running
//    if( started == true )
//    {
//        //If the timer is paused
//        if( paused == true )
//        {
//            //Return the number of ticks when the the timer was paused
//            return pausedTicks;
//        }
//        else
//        {
//            //Return the current time minus the start time
//            return SDL_GetTicks() - startTicks;
//        }    
//    }
//    
//    //If the timer isn't running
//    return 0;    
//}
//
//bool Timer::is_started()
//{
//    return started;    
//}
//
//bool Timer::is_paused()
//{
//    return paused;    
//}
//
////int main( int argc, char* args[] )
////{
////    //Quit flag
////    bool quit = false;
////    
////    //Initialize
////    if( init() == false )
////    {
////        return 1;
////    }
////    
////    //Load the files
////    if( load_files() == false )
////    {
////        return 1;
////    }
////    
////    //Make the timer
////    Timer myTimer;
////    
////    //Generate the message surfaces
////    startStop = TTF_RenderText_Solid( font, "Press S to start or stop the timer", textColor );
////    pauseMessage = TTF_RenderText_Solid( font, "Press P to pause or unpause the timer", textColor );
////    
////    //Start the timer
////    myTimer.start();
////    
////    //While the user hasn't quit
////    while( quit == false )
////    {
////        //While there's an event to handle
////        while( SDL_PollEvent( &event ) )
////        {
////            //If a key was pressed
////            if( event.type == SDL_KEYDOWN )
////            {
////                //If s was pressed
////                if( event.key.keysym.sym == SDLK_s )
////                {
////                    //If the timer is running
////                    if( myTimer.is_started() == true )
////                    {
////                        //Stop the timer
////                        myTimer.stop();    
////                    }
////                    else
////                    {
////                        //Start the timer
////                        myTimer.start();    
////                    }
////                }
////                //If p was pressed
////                if( event.key.keysym.sym == SDLK_p )
////                {
////                    //If the timer is paused
////                    if( myTimer.is_paused() == true )
////                    {
////                        //Unpause the timer
////                        myTimer.unpause();
////                    }
////                    else
////                    {
////                        //Pause the timer
////                        myTimer.pause();
////                    }
////                }
////            }
////            
////            //If the user has Xed out the window
////            else if( event.type == SDL_QUIT )
////            {
////                //Quit the program
////                quit = true;
////            }
////        }
////        
////        //Apply the background
////        apply_surface( 0, 0, background, screen );
////        
////        //Apply the messages
////        apply_surface( ( SCREEN_WIDTH - startStop->w ) / 2, 200, startStop, screen );
////        apply_surface( ( SCREEN_WIDTH - pauseMessage->w ) / 2, 250, pauseMessage, screen );
////        
////        //The timer's time as a string
////        std::stringstream time;
////            
////        //Convert the timer's time to a string
////        time << "Timer: " << myTimer.get_ticks() / 1000.f;
////        
////        //Render the time surface
////        seconds = TTF_RenderText_Solid( font, time.str().c_str(), textColor );
////        
////        //Apply the time surface
////        apply_surface( ( SCREEN_WIDTH - seconds->w ) / 2, 0, seconds, screen );
//// 
////        //Free the time surface
////        SDL_FreeSurface( seconds );
////               
////        //Update the screen
////        if( SDL_Flip( screen ) == -1 )
////        {
////            return 1;    
////        }
////    }
////        
////    //Clean up
////    clean_up();
////    
////    return 0;    
////}

