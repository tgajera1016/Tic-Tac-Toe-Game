#pragma once

#include <Computer.h>

/**
* \brief Constrcutor
* \param name
* \param marker
*/
Computer::Computer(const std::string name, MarkerType marker)
	: _name(name), _marker(marker) { }

/**
* \brief Default destuctor
*/
Computer::~Computer() { /* nothing to be cleared */ }

/**
* \brief Name of the computer player
* \return std::string
*/
const std::string Computer::getName()
{
	return _name;
}

/**
* \brief Marker tyoe of the computer player
* \return enum Marker Type
*/
MarkerType Computer::getMarker()
{
	return _marker;
}

/**
* \brief Computer player move
* \return int
*/
int Computer::makeMove()
{
	return rand()%10;
}
