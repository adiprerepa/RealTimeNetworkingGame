#include "GameDraw.h"

#include "Texture.h"
#include "Window.h"

#include <algorithm>

// init wallcount to 0, resize objs for 2 players
GameDraw::state::state()
{
	wallcount = 0;
	objs.resize(2);
}

// update objs, makes sure ID is less than objs.size(), resizes objs if s > than size
void GameDraw::state::update(ID i, texID t, SDL_Rect r, unsigned int s)
{
	if (s < objs.size())
	{
		objs.resize(s);
	}
	if (objs.size() < i)
	{
		printf("ID greater than allocated GameDraw object vector size. Update skipped.");
		return;
	}

	objs[i].t = t;
	objs[i].r = r;
}

void GameDraw::state::loadwalls(std::vector<obj> walls)
{
	wallcount = walls.size();
	objs.resize(2 + wallcount);

	std::copy(walls.begin(), walls.end(), objs.begin() + 2);
}

// simple enough
void GameDraw::state::draw()
{
	Render::drawRect(objs[0].r, { 255, 0, 0, 255 }); // soon to be replaced with texture
	Render::drawRect(objs[1].r, { 0, 0, 255, 255 }); // ^

	auto i = objs.begin() + 2;
	while (i < objs.begin() + 2 + wallcount) // i is in wall-range
	{
		Render::drawRect(i->r, WALLCOLOR);
		++i;
	}
	while (i < objs.end()) // i is in dynamic memory obj range
	{
		TextureManager::render(i->t, { i->r.x, i->r.y });
	}
}

// i'm lazy
void GameDraw::runlocal()
{
}