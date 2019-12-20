#include "Grid.h"
#include <unordered_map>
using namespace std;
vector<GameObject*> Grid::_listDynamicObject;
Grid::Grid()
{
}

Grid::~Grid()
{
	for (int i = 0; i < GRID_CELL_MAX_ROW; i++)
		for (int j = 0; j < GRID_CELL_MAX_COLUMN; j++)
		{
			cellsStaticObj[i][j].clear();			
		}
	_listDynamicObject.clear();
}

void Grid::GetListObject(vector<GameObject*>& ListObj, Camera * camera)
{
	ListObj.clear();

	unordered_map<int, GameObject*> mapObject;

	float _left, _right, _top, _bottom;
	camera->GetBound(_top, _right, _bottom, _left);

	int bottom = (int)(_bottom / GRID_CELL_HEIGHT);
	int top = (int)(_top / GRID_CELL_HEIGHT);

	int left = (int)(_left / GRID_CELL_WIDTH);
	int right = (int)(_right / GRID_CELL_WIDTH);

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			for (UINT k = 0; k < cellsStaticObj[i][j].size(); k++)
			{
				if (cellsStaticObj[i][j].at(k)->IsVisible()) // còn tồn tại
				{
					if (mapObject.find(cellsStaticObj[i][j].at(k)->GetId()) == mapObject.end()) // ko tìm thấy
						mapObject[cellsStaticObj[i][j].at(k)->GetId()] = cellsStaticObj[i][j].at(k);
				}
				else
				{
					cellsStaticObj[i][j].erase(cellsStaticObj[i][j].begin() + k); // xóa luôn
				}
			}

	for (auto& x : mapObject)
	{
		ListObj.push_back(x.second);
	}
	for (auto i = _listDynamicObject.begin(); i != _listDynamicObject.end(); i++)
	{
		
			ListObj.push_back(*i);
	}
}


void Grid::InsertStaticObject(GameObject *gameObject)
{
	RECT bound = gameObject->GetBound();
	int top = (int)(bound.top / GRID_CELL_HEIGHT);
	int bottom = (int)(bound.bottom / GRID_CELL_HEIGHT);
	int left = (int)(bound.left / GRID_CELL_WIDTH);
	int right = (int)(bound.right / GRID_CELL_WIDTH);

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			cellsStaticObj[i][j].push_back(gameObject);
}

void Grid::InsertDynamicObject(GameObject * gameObject)
{
	_listDynamicObject.push_back(gameObject);
}

void Grid::RemoveDynamicObject(GameObject * gameObject)
{
	for (size_t i = 0; i < _listDynamicObject.size(); i++)
	{
		if (_listDynamicObject[i] == gameObject)
		{
			delete _listDynamicObject[i];
			_listDynamicObject.erase(_listDynamicObject.begin() + i);
			i--;
			break;
		}
	}
}

void Grid::RemoveStaticObject(GameObject * gameObject)
{
	RECT bound = gameObject->GetBound();
	int top = (int)(bound.top / GRID_CELL_HEIGHT);
	int bottom = (int)(bound.bottom / GRID_CELL_HEIGHT);
	int left = (int)(bound.left / GRID_CELL_WIDTH);
	int right = (int)(bound.right / GRID_CELL_WIDTH);

	for (int k = top; k <= bottom; k++)
		for (int j = left; j <= right; j++)
			for (size_t i = 0; i < cellsStaticObj[k][j].size(); i++)
			{
				if (cellsStaticObj[k][j][i] == gameObject)
				{
					delete cellsStaticObj[k][j][i];
					cellsStaticObj[k][j].erase(cellsStaticObj[k][j].begin() + i);
					i--;
					break;
				}
			}
}
