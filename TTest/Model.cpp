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
				Vec3f v;
				for (int i = 0; i < 3; i++) 
					iss >> v[i];
				m_verts.push_back(v);
			}
			if (line.substr(0, 3) == "vn ") {
				iss >> trash>>trash;
				Vec3f n;
				for (int i = 0; i < 3; i++)
					iss >> n[i];
				m_norms.push_back(n);
			}
			else if (line.substr(0, 2) == "f ") {
				iss >> trash;
				std::vector<int> f;
				int idx, itrash;
				Vec3f norm;
				while (iss >> idx >> trash >> itrash >> trash >> itrash) {
					idx--; // in wavefront obj all indices start at 1, not zero
					itrash--;
					f.push_back(idx);
					f.push_back(itrash);
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

Vec3f Model::Vert(int i)
{
	return m_verts[i];
}

std::vector<int> Model::Face(int idx)
{
	return m_faces[idx];
}
