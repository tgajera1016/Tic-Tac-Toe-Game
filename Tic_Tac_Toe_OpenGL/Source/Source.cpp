#include <iostream>
#include <Game.h>
#include <thread>
#include <future>
#include <Human.h>
#include <memory>

int main(int argc, char** argv)
{
	// Initialize GLUT with command line arguments
	glutInit(&argc, argv);

	// Create a game instance
	auto game = std::make_unique<Game>();

	// set player-1 (human)
	game->setPlayer1(new Human("Human", MarkerType::Cross));

	// set player-2 (computer)
	game->setPlayer2(new Computer("Computer", MarkerType::Cirlce));

	// start game on seperate thread
	auto thread = game->start();

	// glut event processing loop
	glutMainLoop();
	
	// block the current thread
	thread.join();

	return 0;
}
