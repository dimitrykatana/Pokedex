// https://lazyfoo.net/tutorials/SDL/index.php
// https://wiki.libsdl.org/

#include <SDL.h>
#include <iostream>



const int WIDTH = 800, HEIGHT = 600;
// This allows us to use cout without 
// having to write std::cout or std::endl
// std stands for standard
using namespace std;

int main(int argc, char* argv[]) {

    // cout stands for Character OUTput.
    // the endl passes a condition to the application that the 
    //curser should move to the next line and so it prints what is behind
    // I let the std here to see how it works
                // cout << "Welcome to kano" << endl;
                // std::cin.get();

            //The window we'll be rendering to
    SDL_Window* fenetre = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }  else
    { //select all word with ctrl shift L
        //Create window              titre video
        fenetre = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );
        if( fenetre == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        } else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( fenetre );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0x00, 0x00 ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( fenetre );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }  //Destroy window
    SDL_DestroyWindow( fenetre );

    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}  