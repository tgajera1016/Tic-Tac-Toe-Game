#include "Player.h"

/**
* \brief Default destructor
*/
Player::~Player() { /* nothing to be cleared */ }

/**
* \brief Name of the player
* \return std::string
*/
const std::string Player::getName()
{
	return _name;
}

/**
* \brief Marker of the player
* \return ennum Marker Type
*/
MarkerType Player::getMarker()
{
	return _marker;
}

/**
* \brief Move
* \return int
*/
int Player::makeMove()
{
	return 0;
}