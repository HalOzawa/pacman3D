#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/CsvReader.h"

const int STAGE_X{ 15 };
const int STAGE_Y{ 15 };
//int stage[STAGE_X][STAGE_Y]
//{
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage")
{
	CsvReader csv;
	csv.Load("map.csv");

	int STAGE_X = csv.GetWidth();
	int STAGE_Y = csv.GetHeight();

	for (int i = 0; i < STAGE_Y; i++)
	{
		vector<int> sdata(STAGE_X, 0);
		stageData_.push_back(sdata);
	}
	//vector<vector<int>> stageData_(STAGE_Y, vector<int>(STAGE_X, 0));

	for (int j = 0; j < STAGE_Y; j++)
	{
		for (int i = 0; i < STAGE_X; i++)
		{
			stageData_[j][i] = csv.GetValue(i, j);
		}
	}
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("floor.fbx");
	assert(hFloor_ >= 0);
	hWall_ = Model::Load("Wall.fbx");
	assert(hWall_ >= 0);
	Camera::SetPosition({ 6.5, 10, -5 });
	Camera::SetTarget({ 6.5, 0, 5.5 });
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };

	for (int z = 0; z < 15; z++) {
		for (int x = 0; x < 15; x++) {
			floorTrans.position_ = { (float)x, 0, (float)(14 - z) };
			//if (x == 0 || z == 0 || x == 14 || z == 14) {
			//	Model::SetTransform(hBlock_, floorTrans);
			//	Model::Draw(hBlock_);
			//}
			//else {
			//	Model::SetTransform(hFloor_, floorTrans);
			//	Model::Draw(hFloor_);
			//}
			if (stageData_[z][x] == 1) {
				Model::SetTransform(hWall_, floorTrans);
				Model::Draw(hWall_);
			}
			else {
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}
	}
	//for (int i = 0; i < STAGE_X; i++)
	//{
	//	float x = i;
	//	for (int j = 0; j < STAGE_Y; j++)
	//	{
	//		float y = j;
	//		if ( x== 0 || y == 0 || x == 14 || y == 14)
	//		{
	//			floorTrans.position_ = { x,0,y };
	//			Model::SetTransform(hWall_, floorTrans);
	//			Model::Draw(hWall_);
	//		}
	//		else
	//		{
	//			floorTrans.position_ = { x,0,y };
	//			Model::SetTransform(hFloor_, floorTrans);
	//			Model::Draw(hFloor_);
	//		}
	//	}
	//}
	
}

void Stage::Release()
{
}
