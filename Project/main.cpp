#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

int main (int argc, char** args)
{

	//Setup
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	//Loading images
	SDL_Surface* IsItYellow = IMG_Load("IsItYellow.png");
	SDL_Surface* ItsNotYellow = IMG_Load("ItsNotYellow.png");
	if (IsItYellow == NULL || ItsNotYellow == NULL) {
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("This is not yellow, people. Press left key to show zoom in", 30, 30, 500, 500, SDL_WINDOW_SHOWN);
	SDL_Surface* surface = SDL_GetWindowSurface(window);

	bool run = true;
	//rects to place certain items
	SDL_Rect rect;
	rect.y = 0;
	rect.w = 1;
	rect.h = 500;
	SDL_Rect rect2;
	rect2.y = 0;
	rect2.w = 500;
	rect2.h = 500;
	//change value to "change" the "value" of the x position of rects
	int chval = 0;
	//white surface to empty screen
	SDL_Surface* white = SDL_CreateRGBSurface(0, 500, 500, 32, 0, 0, 0, 0);
	Uint32 color = SDL_MapRGB(white->format, 255, 255, 255);
	SDL_FillRect(white, 0, color);
	SDL_Rect whiterect;
	whiterect.x = 0;
	whiterect.y = 0;
	whiterect.w = 0;
	whiterect.h = 0;
	//Mainloop
	while (run)
	{
		//Clear screen
		SDL_BlitSurface(white, NULL, surface, &whiterect);
		//This is where the magic happens
		for (int x = 0; x < 250; x++) 
		{
			//Setting image to go 2 pixels in x appart
			rect.x = x * 2 + chval;
			//Each image is one green and one red really close to eachother, creating an illusion. Though, to be honest, any time you see yellow on a screen, it is just red and green
			SDL_BlitSurface(IsItYellow, NULL, surface, &rect);
		}
		//Placing zoomed in image
		rect2.x = 500 + chval;
		SDL_BlitSurface(ItsNotYellow, NULL, surface, &rect2);
		//Events
		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
				case SDL_QUIT:
					SDL_DestroyWindow(window);
					SDL_Quit();
					run = false;
					break;
				case SDL_KEYDOWN:
					switch (ev.key.keysym.sym)
					{
						case SDLK_RIGHT:
							if (chval < 0)
							{
								chval += 500;
							}
							break;
						case SDLK_LEFT:
							if (chval > -500)
							{
								chval -= 500;
							}
							break;
					}
					break;	
			}
		}
		//Update window
		SDL_UpdateWindowSurface(window);
	}
	//Closing out of everything
	SDL_DestroyWindow(window);
	SDL_Quit();
}
