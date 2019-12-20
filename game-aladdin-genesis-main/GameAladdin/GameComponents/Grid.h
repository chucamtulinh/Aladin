#ifndef GRID_H
#define GRID_H

#include <vector>
#include <algorithm>
#include "define.h"
#include "..\GameObjects\GameObject.h"
#include "..\GameObjects\Camera.h"
using namespace std;

#define GRID_CELL_WIDTH (WINDOW_WIDTH/4.0f)
#define GRID_CELL_HEIGHT (WINDOW_HEIGHT/4.0f)

#define GRID_CELL_MAX_ROW 15
#define GRID_CELL_MAX_COLUMN 11


class Grid
{
private:
	vector<GameObject*> cellsStaticObj[GRID_CELL_MAX_ROW][GRID_CELL_MAX_COLUMN];
	RECT _bound = { 0, 0, (long)GRID_CELL_WIDTH, (long)GRID_CELL_HEIGHT };

protected:
	static vector<GameObject*> _listDynamicObject;

public:
	Grid();
	~Grid();

	void InsertStaticObject(GameObject *gameObject);
	void GetListObject(vector<GameObject*>& ListObj, Camera * camera);
	static void InsertDynamicObject(GameObject *gameObject);
	static void RemoveDynamicObject(GameObject *gameObject);
	void RemoveStaticObject(GameObject *gameObject);
};

#endif // !GRID_H
