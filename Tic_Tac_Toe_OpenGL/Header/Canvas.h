#pragma once

#include <string>
#include <memory>
#include <Glut.h>
#include <ViewportModes.h>

/**
 * \brief OpenGL Canvas
 */
class Canvas
{
protected:
	/**
	* \brief Default constructor, protected for singleton object
	*/
	Canvas();

	/**
	* \brief Disable copy constructor for singleton object
	*/
	Canvas(const Canvas&) = delete;

	/**
	* \brief Disable assignment operator for singleton object
	*/
	Canvas& operator=(const Canvas&) = delete;

	/**
	* \brief Trigger a window refresh event to redraw the canvas
	*/
	static void refresh();

	/**
	* \brief Clear the canvas to the background color
	*/
	virtual void clear();

	/**
	* \brief Show the canvas on the screen
	*/
	static void swapBuffers();

	/**
	* \brief Set the singleton canvas instance
	*/
	static void SetInstance(Canvas* instance);
	
	/**
	* \brief Canvas width
	*/
	GLuint _width;

	/**
	* \brief Canvas height
	*/
	GLuint _height;
	
	/**
	* \brief Default point size
	*/
	GLfloat _defaultPointSize;
	
	/**
	* \brief Default line width
	*/
	GLfloat _defaultLineWidth;
	
	/**
	* \brief Default background color
	*/
	GLfloat _defaultBackgroundColor[4];
	
	/**
	* \brief Static instance of a canvas
	*/
	static std::unique_ptr<Canvas> _instance;
	
	/**
	* \brief Viewport mode
	*/
	ViewPortMode _viewportMode;


public:
	/**
	* \brief Default destructor
	*/
	virtual ~Canvas();
	
	/**
	* \brief Singleton canvas instance
	*/
	static Canvas& GetInstance();
	
	/**
	* \brief Create a canvas of a specific initial size displaying the given text string in the title bar
	*/
	void create(GLuint width, GLuint height, const std::string& title);
	
	/**
	* \brief Receive window resize events
	*/
	virtual void reshape(GLuint width, GLuint height) = 0;
	
	/**
	* \brief Receive a window refresh event and redraw the entire canvas
	*/
	virtual void display() = 0;
	
	/**
	* \brief Receive and process mouse input events
	*/
	virtual void onMouseButton(int button, int state, int x, int y) = 0;
};