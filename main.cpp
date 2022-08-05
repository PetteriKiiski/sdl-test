#include "item.h"
#include <SDL2/SDL.h>
int main(int argc, char** arg)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* win = SDL_CreateWindow("SDL Window", 30, 30, 600, 500, SDL_WINDOW_SHOWN);
	SDL_Renderer* screen = SDL_CreateRenderer(win, -1, 0);
	item bob;
	bob.setRenderer(screen);
	bob.loadImage("grass.png");
	bob.setPos(30, 30);
	bool run = true;
	int speedx = 0;
	int speedy = 0;
	int fps = 60;
	int desiredDelta = 1000/fps;
	while (run)
	{
		int startLoop = SDL_GetTicks();
		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
				case SDL_QUIT:
					run = false;
					break;
				case SDL_KEYDOWN:
					switch(ev.key.keysym.sym)
					{
						case SDLK_UP:
							speedy = -3;
							break;
						case SDLK_DOWN:
							speedy = 3;
							break;
						case SDLK_RIGHT:
							speedx = 3;
							break;
						case SDLK_LEFT:
							speedx = -3;
							break;
					}
					break;
				case SDL_KEYUP:
					switch(ev.key.keysym.sym)
					{
						case SDLK_UP:
							speedy = 0;
							break;
						case SDLK_DOWN:
							speedy = 0;
							break;
						case SDLK_RIGHT:
							speedx = 0;
							break;
						case SDLK_LEFT:
							speedx = 0;
							break;
					}
					break;
			}
		bob.move(speedx, speedy);
		bob.draw();
		SDL_RenderPresent(screen);
		int delta = SDL_GetTicks() - startLoop;
		if (delta < desiredDelta) {
			SDL_Delay(desiredDelta - delta);
		}
		}
	}
	SDL_DestroyWindow(win);
	SDL_Quit();
}
