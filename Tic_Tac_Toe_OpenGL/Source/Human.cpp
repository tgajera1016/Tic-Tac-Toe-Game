#pragma once

#include <Human.h>

/**
* \brief Default destuctor
*/
Human::~Human() { /* nothing to be cleared */ }

/**
* \brief Constrcutor
* \param name
* \param marker
*/
Human::Human(const std::string name, MarkerType marker)
	: _name(name), _marker(marker) { }

/**
* \brief Name of the human player
* \return std::string
*/
const std::string Human::getName()
{
	return _name;
}

/**
* \brief Marker tyoe of the human player
* \return enum Marker Type
*/
MarkerType Human::getMarker()
{
	return _marker;
}

/**
* \brief Human player move
* \return int
*/
int Human::makeMove()
{
	int index;
	std::cout << std::endl << "Enter number (1-9) to select a tile: ";
	std::cin >> index;
	return index;
}
