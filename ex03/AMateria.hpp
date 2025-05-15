/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:59:22 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/15 20:09:03 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ICharacter;

class AMateria //abstract class aka interface
{
	protected:
		std::string _type;

	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &other);
		AMateria &operator=(AMateria const &other);
		virtual ~AMateria();

		std::string const &getType() const; //returns the materia type
		virtual AMateria *clone() const = 0; //pure virtual
		virtual void use(ICharacter &target);
};
