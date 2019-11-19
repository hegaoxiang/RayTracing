#include "Model.h"
#include <iostream>
#include <fstream>
#include <sstream>

Model::Model(const char* filename)
	:m_verts(),m_faces()
{
	
	std::ifstream in(filename, std::ifstream::in);
	if (in.is_open()) {
		std::string line;
		while (std::getline(in, line))
		{
			char trash;
			std::istringstream iss(line);
			if (line.substr(0, 2) == "v ") {
				iss >> trash;
				Vec3 v;
				for (int i = 0; i < 3; i++) 
					iss >> v[i];
				m_verts.push_back(v);
			}
			else if (line.substr(0, 2) == "f ") {
				iss >> trash;
				std::vector<int> f;
				int idx, itrash;
				while (iss >> idx >> trash >> itrash >> trash >> itrash) {
					idx--; // in wavefront obj all indices start at 1, not zero
					f.push_back(idx);
				}
				m_faces.push_back(f);
			}
		}

		in.close();
	}

	// std::cout << "# v#" << m_verts.size() << std::endl;
}

Model::~Model()
{
}

int Model::NumVerts()
{
	return (int)m_verts.size();
}

int Model::NumFaces()
{
	return (int)m_faces.size();
}

Vec3 Model::Vert(int i)
{
	return m_verts[i];
}

std::vector<int> Model::Face(int idx)
{
	return m_faces[idx];
}
