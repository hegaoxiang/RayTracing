#pragma once
#include<Windows.h>
#include"test.h"
#include <glad/glad.h>

#pragma comment (lib, "opengl32.lib")
class GLRender
{
public:
	GLRender(void);
	virtual ~GLRender(void);
	bool CreateGLContext(HDC hDC); 	// Creates OpenGL Rendering Context
	void PrepareScene(HDC hDC);		// Scene preparation stuff
	void Reshape(HDC hDC, int w, int h);	// Changing viewport
	void DrawScene(HDC hDC);		// Draws the scene
	void DestroyScene(HDC hDC);		// Cleanup

protected:
	void SetData();	                        // Creates VAO and VBOs and fill them with data

protected:
	HGLRC	 m_hrc;                        // OpenGL Rendering Context 
	int* m_pProgram;	               // Program
	int* m_pVertSh;		       // Vertex shader
	int* m_pFragSh;		       // Fragment shader

	GLuint m_vaoID[2];			// two vertex array objects, one for each drawn object
	GLuint m_vboID[3];			// three VBOs

	PFNWGLCREATECONTEXTATTRIBSARBPROC CreateContextAttribsARB;
};

