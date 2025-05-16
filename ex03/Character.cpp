/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:48:03 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/15 21:34:19 by aapadill         ###   ########.fr       */
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

void Character::equip(AMateria* m)
{
	if (m == nullptr)
        return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _name << " equips " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << _name << "'s inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		_inventory[idx] = nullptr;
		std::cout << _name << " unequips slot " << idx << std::endl;
	}
	else
		std::cout << _name << " cannot unequip slot " << idx << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		_inventory[idx]->use(target);
	}
	else
		std::cout << _name << " cannot use slot " << idx << std::endl;
}

