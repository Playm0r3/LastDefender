#ifndef GRID
#define GRID

#ifndef TILE_SIZE
	#define TILE_SIZE (32)
#endif

#include <vector>

#include "game_object.h"

enum TileType {
	GRASS,
	ROAD,
	TOWER,
};

class Tile : public GameObject {

public:
	TileType type;
	Color col; // permet de dissiner de la couleur du type

	Tile();
	Tile(float x = 0.f, float y = 0.f, TileType type = GRASS, Color col = GREEN);
	~Tile() = default;

	void Draw();
	void DrawSprite();

	TileType GetType() const;
	void SetType(TileType newType);

};

enum GridType {
	PLAIN,
};

class Grid : public GameObject {

public:
	std::vector<std::vector<Tile*>> tiles;

	int xMax;
	int yMax;

	Grid();
	Grid(float x = 0, float y = 0);
	~Grid();

	void Draw();
	void DrawSprite();

	Tile* GetTile(int _x, int _y);

	void SetTrack(std::string fileMap);

	GridType GetType();
	void SetType(GridType newType);
	
};

#endif