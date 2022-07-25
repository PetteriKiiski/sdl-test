#ifndef IMAGESANDITEMS
#define IMAGESANDITEMS
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
void ItemInit();
void ItemQuit();
class item
{
	public:
	item();
	virtual ~item();
	bool loadImage(std::string filename);
	void draw(SDL_Surface* dest);

	private:
	SDL_Surface* image;
	SDL_Rect pos;
};
#endif
