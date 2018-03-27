#pragma once

#include <string>
#include <MarkerTypes.h>

/**
 * \brief Player abstract class
 */
class Player
{
public:

	/**
	 * \brief Default destructor
	 */
	virtual ~Player();

	/**
	 * \brief Name of the player
	 * \return std::string
	 */
	virtual const std::string getName();

	/**
	 * \brief Marker of the player
	 * \return ennum Marker Type
	 */
	virtual MarkerType getMarker();

	/**
	 * \brief Move 
	 * \return int
	 */
	virtual int makeMove();

protected:

	/**
	 * \brief Name of the player
	 */
	std::string _name{ "Default name" };

	/**
	 * \brief Marker of the player
	 */
	MarkerType _marker{ MarkerType::None };
};