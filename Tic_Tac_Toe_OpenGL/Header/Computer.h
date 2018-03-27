#pragma once

#include <string>
#include <Player.h>

/**
 * \brief Computer player
 */
class Computer : public Player
{
public:

	/**
	 * \brief Default destuctor
	 */
	virtual ~Computer();

	/**
	 * \brief Constrcutor
	 * \param name 
	 * \param marker 
	 */
	Computer(const std::string name, MarkerType marker);

	/**
	 * \brief Name of the computer player
	 * \return std::string
	 */
	virtual const std::string getName() override;

	/**
	 * \brief Marker tyoe of the computer player
	 * \return enum Marker Type
	 */
	virtual MarkerType getMarker() override;

	/**
	 * \brief Computer player move
	 * \return int 
	 */
	virtual int makeMove() override;

protected:

	/**
	 * \brief Name of the computer player
	 */
	const std::string _name;

	/**
	 * \brief Marker of the computer player
	 */
	const MarkerType _marker;
};