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
	void setRenderer(SDL_Renderer* renderer);
	bool loadImage(std::string filename);
	void setPos(int x, int y);
	void move(int x, int y);
	void draw();

	private:
	SDL_Renderer* ren;
	SDL_Texture* image;
	SDL_Rect pos;
};
#endif
