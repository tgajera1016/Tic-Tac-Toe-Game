
#include "Canvas.h"

/**
* \brief Static instance of a canvas
*/
std::unique_ptr<Canvas> Canvas::_instance;

/**
* \brief Default destructor
*/
Canvas::~Canvas() { /* nothing to be cleared */ }

/**
* \brief Default constructor, protected for singleton object
*/
Canvas::Canvas()
	: _width(0),
	_height(0),
	_defaultPointSize(10),
	_defaultLineWidth(3.0),
	_defaultBackgroundColor{ 1.0f, 1.0f, 1.0f, 1.0f },
	_viewportMode(ViewPortMode::Single) { }

/**
* \brief Clear the canvas to the background color
*/
void Canvas::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

/**
* \brief Show the canvas on the screen
*/
void Canvas::swapBuffers()
{
	glutSwapBuffers();
}

/**
* \brief Trigger a window refresh event to redraw the canvas
*/
void Canvas::refresh()
{
	glutPostRedisplay();
}

/**
* \brief Singleton canvas instance
*/
Canvas& Canvas::GetInstance()
{
	return *_instance.get();
}

/**
* \brief Set the singleton canvas instance
*/
void Canvas::SetInstance(Canvas* instance)
{
	_instance.reset(instance);
}

/**
* \brief Receive a window refresh event and redraw the entire canvas
*/
void DisplayFunc()
{
	Canvas::GetInstance().display();
}

/**
* \brief Receive window resize events
*/
void ReshapeFunc(int width, int height)
{
	Canvas::GetInstance().reshape(width, height);
}

/**
* \brief Receive and process mouse input events
*/
void MouseFunc(int button, int state, int x, int y)
{
	Canvas::GetInstance().onMouseButton(button, state, x, y);
}

/**
* \brief Create a canvas of a specific initial size displaying the given text string in the title bar
*/
void Canvas::create(GLuint width, GLuint height, const std::string& title)
{
	_width = width;
	_height = height;
	glutInitWindowSize(_width, _height);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(title.c_str());
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glClearColor(_defaultBackgroundColor[0], _defaultBackgroundColor[1], _defaultBackgroundColor[2], _defaultBackgroundColor[3]);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(_defaultPointSize);
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(_defaultLineWidth);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(DisplayFunc);
	glutReshapeFunc(ReshapeFunc);
	glutMouseFunc(MouseFunc);
	SetInstance(this);
}
