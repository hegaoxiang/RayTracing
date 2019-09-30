#include "GLRender.h"
#include<fstream>
#include <cstdio>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

using namespace rapidjson;
GLRender g_GLRender;

//#define _CRT_SECURE_NO_WARNINGS
GLRender::GLRender(void)
{
	
}

GLRender::~GLRender(void)
{
}

bool GLRender::CreateGLContext(HDC pDC)
{
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 32;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int nPixelFormat = ChoosePixelFormat(pDC, &pfd);

	int  letWindowsChooseThisPixelFormat;
	letWindowsChooseThisPixelFormat = ChoosePixelFormat(pDC, &pfd);
	SetPixelFormat(pDC, letWindowsChooseThisPixelFormat, &pfd);

	
	int attribs[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		WGL_CONTEXT_FLAGS_ARB, 0,
		0
	};
	HGLRC tempContext = wglCreateContext(pDC);
	wglMakeCurrent(pDC, tempContext);

	if (!gladLoadGL())
	{
		MessageBox(NULL, L"Failed to initialize OpenGL context", L"", MB_OK);
	}
	auto func = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
	m_hrc = func(pDC, 0, attribs);

	if (!m_hrc)
	{
		MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);
	}
	else
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(tempContext);
		wglMakeCurrent(pDC, m_hrc);
	}
	
	return false;
}

void GLRender::PrepareScene(HDC hDC)
{	//


	FILE* fp = fopen("C://Users//‘¨–°œ…//source//repos//LearnOpengl//Edit//test.json", "rb"); 

	char readBuffer[500];
	FileReadStream is(fp, readBuffer , sizeof(readBuffer));

	fclose(fp);

	Document document;

	document.ParseStream(is);
	assert(document.IsObject());
	assert(document.HasMember("Red"));
	assert(document["Red"].IsFloat());

	GLfloat red = document["Red"].GetFloat();
	GLfloat green = document["Green"].GetFloat();
	GLfloat blue = document["Blue"].GetFloat();
	GLfloat alpha = document["Alpha"].GetFloat();

	glClearColor(red, green, blue, alpha);
}

void GLRender::Reshape(HDC hDC, int w, int h)
{
	try
	{
		glGetError();
		glViewport(0, 0, w, h);
	}
	catch (const std::exception&)
	{

	}
	
}

void GLRender::DrawScene(HDC hDC)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SwapBuffers(hDC);
}

void GLRender::DestroyScene(HDC hDC)
{
}

void GLRender::SetData()
{
}
