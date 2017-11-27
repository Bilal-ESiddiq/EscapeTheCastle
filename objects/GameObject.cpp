#include "GameObject.hpp"



GameObject::GameObject(string Name, string texName)
{
	objectName = Name;
	loadAssImp(Name.c_str() , indices, vertices, uvs, normals);
	Texture = texName;
}

void GameObject::Draw()
{

}

GameObject::~GameObject()
{

}
