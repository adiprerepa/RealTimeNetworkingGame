#pragma once

#include "Color.h"
#include "Constants.h"

#include "SDL2/SDL_rect.h"

namespace Window
{
	void init();
	void update();
	void destroy();

	extern int count;
};

struct SDL_Texture;
struct SDL_Surface;

namespace Render
{
	SDL_Texture * createTextureFromSurface(SDL_Surface * surface);

	void drawRect(SDL_Rect rect, Color color, bool centered);

	void blit(SDL_Texture * tex, SDL_Rect rect, bool centered);

	void blitEx(SDL_Texture * tex, SDL_Rect rect, double angle, SDL_Point spincenter, bool centered);
};