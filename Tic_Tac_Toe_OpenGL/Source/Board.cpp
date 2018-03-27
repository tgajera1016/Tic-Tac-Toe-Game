#pragma once

#include <Board.h>

/**
* \brief Default destructor
*/
Board::~Board() { /* nothing to be cleared */ }

/**
* \brief Default constructor
*/
Board::Board()
{
	_gameCanvas = std::make_unique<GameCanvas>();
	_gameCanvas->create(300, 300, "Tic Tac Toe Game - OpenGL");
}

/**
* \brief Clear all the blocks
*/
void Board::reset() const
{
	_gameCanvas->clear();
}

/**
* \brief Check whether move is valid is not
* \param index
* \return true/false
*/
bool Board::isValidMove(int index) const
{
	return _gameCanvas->isBlockAvailable(index);
}

/**
* \brief Check for winner
* \return MarkerType (Circle, Cross)
*/
MarkerType Board::whoIsWinner() const
{
	return _gameCanvas->whoIsWinner();
}

/**
* \brief Select a block using given index
* \param index
* \param marker
*/
void Board::selectBlock(int index, MarkerType marker) const
{
	if (_gameCanvas == nullptr)
		return;

	_gameCanvas->selectBlock(index, marker);
}
