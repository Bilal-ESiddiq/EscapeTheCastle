#pragma once
#include "GameObject.hpp"
class Room :
	public GameObject
{
public:
	Room(string name, string texName);
	~Room();
};

