#include "Game.h"
#include <iostream>
#pragma once

/**
* \brief Default destructor
*/
Game::~Game() { /* nothing to clean */ }

/**
* \brief Default constructor
*/
Game::Game()
	: _player1(nullptr), _player2(nullptr)
{
	initializeGameBoard();
}

/**
* \brief Initialize the game board
*/
void Game::initializeGameBoard()
{
	_board = std::make_unique<Board>();
	
}

/**
* \brief Set player-1 instance
*/
void Game::setPlayer1(Player* player)
{
	_player1 = std::unique_ptr<Player>(player);
}

/**
* \brief Set player-2 instance
*/
void Game::setPlayer2(Player* player)
{
	_player2 = std::unique_ptr<Player>(player);
}

/**
* \brief Start the Tic Tac Toe game
*/
void Game::startGame()
{
	while (_nMoves != _totalMoves)
	{
		{
			while (true)
			{
				auto move = _player1->makeMove();
				if (_board->isValidMove(move))
				{
					_board->selectBlock(move, _player1->getMarker());
					std::cout << "Player1 move -> " << move << std::endl;
					++_nMoves;
					break;
				}
				else
				{
					if (_nMoves == _totalMoves)
					{
						std::cout << std::endl << "************** No Winner **************" << std::endl;
						return;
					}
					std::cout << "Player1 move -> " << move << " is not a valid move. Try again!!"<< std::endl;
				}
			}
		}

		// check for winner
		auto winner = _board->whoIsWinner();
		if (winner == _player1->getMarker())
		{
			std::cout << std::endl;
			std::cout << "***********************************************************" << std::endl;
			std::cout << "************** Player1 " << "( " << _player1->getName() << " )" << " is Winner **************" << std::endl;
			std::cout << "***********************************************************" << std::endl;
			return;
		}
		else if (winner == _player2->getMarker())
		{
			std::cout << std::endl;
			std::cout << "***********************************************************" << std::endl;
			std::cout << "************** Player2 " << "( " << _player2->getName() << " )" << " is Winner **************" << std::endl;
			std::cout << "***********************************************************" << std::endl;
			return;
		}
			

		{
			while (true)
			{
				auto move = _player2->makeMove();
				if (_board->isValidMove(move))
				{
					_board->selectBlock(move, _player2->getMarker());
					std::cout << "Player2 move -> " << move << std::endl;
					++_nMoves;
					break;
				}
				else
				{
					if (_nMoves == _totalMoves)
					{
						std::cout << std::endl << "************** No Winner **************" << std::endl;
						return;
					}
					std::cout << "Player2 move -> " << move << " is not a valid move. Try again!!" << std::endl;
				}
			}
		}
	}
}

/**
* \brief Start the Tic Tac Toe game on the different thread
*/
std::thread Game::start()
{
	return std::thread(&Game::startGame, this);
}