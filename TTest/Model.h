#pragma once
#include <vector>
#include <string>
#include"Math.h"
class Model
{
public:

	std::vector<Vec3f> m_verts;
	std::vector<Vec3f> m_norms;;
	std::vector<std::vector<int>> m_faces;

	Model(const char* filename);
	~Model();
	int NumVerts();
	int NumFaces();
	Vec3f Vert(int i);
	std::vector<int> Face(int idx);
};

