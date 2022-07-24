#include "item.h"
#include <SDL2/SDL.h>

item::item()
{
	pos.x = 30;
	pos.y = 60;
	image = SDL_CreateRGBSurface(0, 100, 200, 32, 0, 0, 0, 0);
	pos.w = image->clip_rect.w;
	pos.h = image->clip_rect.h;
	SDL_FillRect(image, NULL, 0xffff00);
}

item::~item()
{
	if (image != NULL)
	{
		SDL_FreeSurface(image);
	}
}

void item::draw(SDL_Surface* dest)
{
	if (image != NULL)
	{
		SDL_BlitSurface(image, NULL, dest, &pos);
	}
}
