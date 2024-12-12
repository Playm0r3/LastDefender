#include <raylib.h>
#include <vector>
#include <algorithm>

#include "grid.h"

Tile::Tile() : GameObject(0.f, 0.f), type(GRASS), col(GREEN)
{
}

Tile::Tile(float x, float y, TileType _type, Color color) : GameObject(x, y), type(_type), col(color)
{
}

void Tile::Draw()
{
	Vector2 position = GetComponent<TransformComponent>()->position;
	DrawRectangle(position.x, position.y, TILE_SIZE, TILE_SIZE, col);
}

TileType Tile::GetType() const
{
	return type;
}

void Tile::SetType(TileType newType)
{
	type = newType;
}

Grid::Grid() : GameObject(0.f, 0.f), xMax(11), yMax(11)
{
	for (int x = 0; x < 11; x++)
		for (int y = 0; y < 11; y++)
			tiles[x][y] = new Tile(x * TILE_SIZE, y * TILE_SIZE);
}

Grid::Grid(float _x, float _y) : GameObject(0.f, 0.f), xMax(_x), yMax(_y)
{
	for (int x = 0; x < _x; x++)
		for (int y = 0; y < _y; y++)
			tiles[x][y] = new Tile(x * TILE_SIZE, y * TILE_SIZE);
}

Grid::~Grid()
{
	for (int x = 0; x < xMax; x++)
		for (int y = 0; y < yMax; y++)
			delete tiles[x][y];

	tiles.clear();
}

void Grid::Draw()
{
	for (int x = 0; x < xMax; x++)
		for (int y = 0; y < yMax; y++)
			tiles[x][y]->Draw();
}

Tile* Grid::GetTile(int x, int y)
{
	return tiles[x][y];
}