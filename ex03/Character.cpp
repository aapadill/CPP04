/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:48:03 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/15 20:56:40 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr; //"The inventory is empty at construction"
	std::cout << "Character " << _name << " created" << std::endl;
}

Character::Character(Character const &other): _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	std::cout << "Character " << _name << " copied" << std::endl;
}

Character &Character::operator=(Character const &other)
{
	//basically replacing the current object with the other one
	if (this != &other)
	{
        for (int i = 0; i < 4; ++i)
            delete _inventory[i]; //delete everything in the inventory
        _name = other._name;
        for (int i = 0; i < 4; ++i)
		{
            if (other._inventory[i]) //does other have a saved materia?
                _inventory[i] = other._inventory[i]->clone(); //clone it
            else
                _inventory[i] = nullptr; //if not, null
        }
    }
    return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i]; //avoid leaks
	std::cout << "Character " << _name << " destroyed" << std::endl;
}

std::string const &Character::getName() const
{
	return _name;
}

//equip
//unequip
//use

