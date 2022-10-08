// // This allows us to use cout without having to write std::cout or std::endl
// using namespace std;

   // std::cin.get();
     // stream is a sequence of character
     // << these 2 notations are operators for inserting something to our output stream

//select all occurrences with ctrl shift L in vs code
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
 
 
const int SCREEN_WIDTH = 1240;
const int SCREEN_HEIGHT = 960;

int main(int argc, char ** argv)
{

    bool quit = false;
    SDL_Event event;

    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    SDL_Surface * image = NULL;
    SDL_Texture * texture = NULL;

    // Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) != 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }  else
    { 
    // initialize image
    IMG_Init(IMG_INIT_PNG);  

    window = SDL_CreateWindow("POKEMON", 10,
    10, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, 0);
    image = IMG_Load("./src/res/spritesheet.png");
    texture = SDL_CreateTextureFromSurface(renderer, image);
 
    SDL_SetRenderDrawColor(renderer, 99, 177, 146, 1);

    while (!quit)
    {
        Uint32 ticks = SDL_GetTicks();
        int sprite = (ticks/1000) % 154;
        
        // la portion de l'image à prendre 
        // x=lig, y=col, taillex, tailley
        SDL_Rect crop_image = { sprite * 64 , 0, 64, 64 };

        // first: where to draw and then the size
        // be carefull to not pass the x and y position or the pokemon will move
        SDL_Rect place_size_image = { (SCREEN_WIDTH/2) - crop_image.w, (SCREEN_HEIGHT/2) - crop_image.h, 128, 128 };
        
        // dans le poll event faites attention à mettre que ce que vous voulez gérer
        // avec un comportement du clavier
        while (SDL_PollEvent(&event)){
        
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
            }
            
        }
            // delete the old pokemon to display the new one

            SDL_RenderClear(renderer);  
            SDL_RenderCopy(renderer, texture, &crop_image, &place_size_image);
            SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    }
    SDL_DestroyWindow(window);
    IMG_Quit();
    //Quit SDL subsystems
    SDL_Quit();

// The main function needs to return a 0 at the end to know that everything went smoothly
    return 0;
}