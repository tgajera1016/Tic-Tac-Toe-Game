#pragma once

/**
 * \brief Viewport structure
 */
struct Viewport
{
	int x;
	int y;
	int width;
	int height;

	/**
	 * \brief Default constructor
	 */
	Viewport(): x(0), y(0), width(0), height(0) { }

	/**
	 * \brief Parameterized constructor
	 * \param _x 
	 * \param _y 
	 * \param _width 
	 * \param _height 
	 */
	Viewport(int _x, int _y, int _width, int _height)
	{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
	}
};