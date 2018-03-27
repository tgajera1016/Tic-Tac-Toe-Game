#pragma once

#include <memory>
#include <GameCanvas.h>

/**
 * \brief Board contains a game canvas
 */
class Board
{
	/**
	 * \brief Game canvas OpenGL
	 */
	std::unique_ptr<GameCanvas> _gameCanvas;

public:

	/**
	 * \brief Default constructor
	 */
	Board();

	/**
	 * \brief Default destructor
	 */
	~Board();

	/**
	 * \brief Clear all the blocks
	 */
	void reset() const;

	/**
	 * \brief Check whether move is valid is not
	 * \param index 
	 * \return true/false
	 */
	bool isValidMove(int index) const;

	/**
	 * \brief Check for winner 
	 * \return MarkerType (Circle, Cross)
	 */
	MarkerType whoIsWinner() const;

	/**
	 * \brief Select a block using given index
	 * \param index 
	 * \param marker 
	 */
	void selectBlock(int index, MarkerType marker) const;
};