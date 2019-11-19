#pragma once
#include <vector>
#include <string>
#include"Math.h"
class Model
{
public:
	std::vector<Vec3> m_verts;
	std::vector<std::vector<int>> m_faces;

	Model(const char* filename);
	~Model();
	int NumVerts();
	int NumFaces();
	Vec3 Vert(int i);
	std::vector<int> Face(int idx);
};

