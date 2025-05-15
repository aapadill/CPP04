/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:33:06 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/15 20:56:58 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(Ice const &other);
		Ice &operator=(Ice const &other);
		virtual ~Ice();

		virtual AMateria *clone() const override; //clone uses Materia interface
		virtual void use(ICharacter &target) override; //target uses Character interface
};

