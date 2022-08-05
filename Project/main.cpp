#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main (int argc, char** args)
{

	//Setup
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* IsItYellow = IMG_Load("IsItYellow.png");
	if (IsItYellow == NULL) {
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("Window", 30, 30, 600, 500, SDL_WINDOW_SHOWN);
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	bool run = true;
	SDL_Rect rect;
	rect.y = 0;
	rect.w = 1;
	rect.h = 500;
	for (int x = 0; x < 250; x++) 
	{
		rect.x = x * 2;
		SDL_BlitSurface(IsItYellow, NULL, surface, &rect);
	}
	//Mainloop
	while (run)
	{
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
			}
		}
	}

	//Closing out of everything
	SDL_DestroyWindow(window);
	SDL_Quit();
}
