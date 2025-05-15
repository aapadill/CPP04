/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:59:26 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/15 20:04:26 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(AMateria const &other): _type(other._type)
{
}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* uses generic materia on" << target.getName() << " *" << std::endl;
}