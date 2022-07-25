#include "item.h"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;
void itemInit()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
}

void itemQuit()
{
	SDL_Quit();
	IMG_Quit();
}

item::item()
{
	pos.x = 30;
	pos.y = 60;
	image = NULL;
	pos.w = 100;
	pos.h = 100;
	std:cout << pos.w << ", " << pos.h << endl;
}

item::~item()
{
	if (image != NULL)
	{
		SDL_DestroyTexture(image);
	}
}

bool item::loadImage(std::string filename)
{
	if (image!=NULL)
	{
		SDL_DestroyTexture(image);
	}
       	SDL_Surface* temp= IMG_Load(filename.c_str());
	if (temp != NULL) 
	{
		image = SDL_CreateTextureFromSurface(ren, temp);
		SDL_FreeSurface(temp);
		if (image != NULL) 
		{
			return true;
		}
	}
	return false;
}

void item::setRenderer (SDL_Renderer* dest)
{
	ren = dest;
}

void item::draw()
{
	if (image != NULL)
	{
		SDL_RenderCopy(ren, image, NULL, &pos);
	}
	else {
		std::cout << "Help, image is NULL at draw()" << endl;
	}
}
