#pragma once

#include <Canvas.h>
#include <Glut.h>
#include <vector>
#include <Block.h>

/**
 * \brief Game canvas
 */
class GameCanvas : public Canvas
{
	/**
	* \brief Block container
	*/
	std::vector<Block> _blockContainer;

public:

	/**
	* \brief Constructor
	*/
	GameCanvas();

	/**
	* \brief Destructor
	*/
	virtual ~GameCanvas();
	
	/**
	* \brief Receive window display events
	*/
	virtual void display() override;
	
	/**
	* \brief Receive window resize events
	*/
	void reshape(GLuint width, GLuint height) override;
	
	/**
	* \brief Draw shapes using given marker type
	*/
	void drawShape(MarkerType markerType, int width, int height) const;
	
	/**
	* \brief Receive mouse events
	*/
	virtual void onMouseButton(int button, int state, int x, int y) override;
	
	/**
	* \brief clear the canvas
	*/
	void clear() override;
	
	/**
	* \brief select a canvas from vector of blocks using given index
	*/
	void selectBlock(int index, MarkerType type);
	
	/**
	* \brief Check whether given index block is available to select
	*/
	bool isBlockAvailable(int index);
	
	/**
	* \brief check for winner
	*/
	MarkerType whoIsWinner();
};