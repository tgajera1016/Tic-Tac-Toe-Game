#pragma once

#include <Viewport.h>
#include <MarkerTypes.h>

/**
 * \brief Block structure contains viewport to draw a marker 
 */
struct Block
{
	/**
	 * \brief OpenGL Viewport 
	 */
	Viewport viewport;

	/**
	 * \brief Marker type (circle, Cross)
	 */
	MarkerType markerType;

	/**
	 * \brief Constructor
	 * \param _viewport 
	 * \param _markerType 
	 */
	Block(Viewport _viewport, MarkerType _markerType)
	{
		viewport = _viewport;
		markerType = _markerType;
	}
};