#pragma once

#include <memory>
#include <Board.h>
#include <thread>
#include <Computer.h>

/**
 * \brief Tic Tac Toe Game class
 */
class Game
{
	/**
	 * \brief Player-1 instance
	 */
	std::unique_ptr<Player> _player1;

	/**
	* \brief Player-2 instance
	*/
	std::unique_ptr<Player> _player2;

	/**
	* \brief Board instance
	*/
	std::unique_ptr<Board> _board;

	/**
	 * \brief Total moves required to finish the Tic Tac Toe game
	 */
	const unsigned int _totalMoves = 9;

	/**
	* \brief Counter of the number of moves
	*/
	unsigned int _nMoves;

	/**
	* \brief Start the Tic Tac Toe game
	*/
	void startGame();

	/**
	* \brief Initialize the game board
	*/
	void initializeGameBoard();

public:

	/**
	* \brief Default destructor
	*/
	~Game();

	/**
	* \brief Default constructor
	*/
	Game();

	/**
	* \brief Set player-1 instance
	*/
	void setPlayer1(Player* player);

	/**
	* \brief Set player-2 instance
	*/
	void setPlayer2(Player* player);

	/**
	* \brief Start the Tic Tac Toe game on the different thread
	*/
	std::thread start();
};