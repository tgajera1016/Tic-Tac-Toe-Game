#pragma once

#include <Player.h>
#include <iostream>

/**
* \brief Human player
*/
class Human : public Player
{
public:

	/**
	* \brief Default destuctor
	*/
	virtual ~Human();

	/**
	* \brief Constrcutor
	* \param name
	* \param marker
	*/
	Human(const std::string name, MarkerType marker);

	/**
	* \brief Name of the human player
	* \return std::string
	*/
	virtual const std::string getName() override;
	
	/**
	* \brief Marker tyoe of the human player
	* \return enum Marker Type
	*/
	virtual MarkerType getMarker() override;

	/**
	* \brief Human player move
	* \return int
	*/
	virtual int makeMove() override;

protected:
	
	/**
	* \brief Name of the human player
	*/
	const std::string _name;

	/**
	* \brief Marker of the human player
	*/
	const MarkerType _marker;
};