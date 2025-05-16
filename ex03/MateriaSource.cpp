/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:38:27 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/15 21:43:39 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_prototypes[i] = nullptr;
	std::cout << "MateriaSource created" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._prototypes[i])
			_prototypes[i] = other._prototypes[i]->clone();
		else
			_prototypes[i] = nullptr;
	}
	std::cout << "MateriaSource copied" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete _prototypes[i];
			if (other._prototypes[i])
				_prototypes[i] = other._prototypes[i]->clone();
			else
				_prototypes[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete _prototypes[i];
	std::cout << "MateriaSource destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_prototypes[i])
		{
			_prototypes[i] = m->clone();
			std::cout << "Learned materia: " << m->getType() << " materia" << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materia" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_prototypes[i] && _prototypes[i]->getType() == type)
		{
			std::cout << "Created materia: " << type << " materia" << std::endl;
			return _prototypes[i]->clone();
		}
	}
	std::cout << "Materia not found: " << type << std::endl;
	return nullptr;
}
