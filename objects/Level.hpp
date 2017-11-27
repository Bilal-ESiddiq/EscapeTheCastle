#pragma once
#include<vector>
#include"GameObject.hpp"
#include"Room.hpp"
using namespace std;
class Level
{
public:

	vector<GameObject> WorldObjects;
	GameObject* Room;
	Level();
	~Level();
};

