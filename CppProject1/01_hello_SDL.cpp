/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			
			// Draw paddle
			SDL_Rect rect;
			rect.h = 100;
			rect.w = 100;
			rect.x = 100;
			rect.y = 100;

			Uint32 red = SDL_MapRGB(screenSurface->format, 0x80, 0x15, 0x15);
			SDL_FillRect(screenSurface, &rect, red);
			// Draw Ball
			//Circle circle;
			//circle.x = 100;
			//circle.y = 100;
			//circle.r = 10;

			//Uint32 blue = SDL_MapRGB(screenSurface->format, 0x80, 0x15, 0x15);
			//SDL_FillCircule(screenSurface, &circle, blue);
			
			//Update the surface
			SDL_UpdateWindowSurface( window );

			//Wait two seconds
			SDL_Delay( 2000 );
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}

/**
*  \brief  The structure that defines a point
*
*  \sa SDL_EnclosePoints
*  \sa SDL_PointInRect
*/
//typedef struct Circle
//{
//	int x;
//	int y;
//	int r;
//} SDL_Point;
//
//int SDL_FillCircule(SDL_Surface * dst, Circle * Circle, Uint32 color) {
//	
//}