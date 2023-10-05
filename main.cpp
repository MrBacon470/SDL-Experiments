#include <stdio.h>
#include <SDL2/SDL.h>
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 100
using namespace std;

int main(int argc, char* argv[]) {
	//The Window Displayed Using SDL
	SDL_Window* window = NULL;
	//The window's surface
	SDL_Surface* screenSurface = NULL;

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) { //Checks if all SDL Systems Initialized Properly
		printf("Error Initializing SDL: %s\n",SDL_GetError());
		return EXIT_FAILURE;
	}
	
	printf("SDL Initialized Successfully!\n");

	window = SDL_CreateWindow("SDL Tutorial :)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	/*
	 * SDL_CreateWindow(Window Name, Window Starting X Pos, Window Starting Y Pos, Window Width, Window Height, show window when created)
	 */
	if(window == NULL) {
		printf("Error Initializing SDL Window: %s",SDL_GetError());
		return EXIT_FAILURE;
	}
	else {
		screenSurface = SDL_GetWindowSurface(window); 						//Assign the Window's Surface
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));	//Set the screen to white
		SDL_UpdateWindowSurface(window);							//Do Actually Have to Update the window :(
		
		//Hacky Way to Keep the Window From Closing
		SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

	}
	SDL_DestroyWindow(window); //Deallocates all the window's and its surface's memory

	SDL_Quit(); //Shuts all SDL Systems Down
	return EXIT_SUCCESS;
}

