/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:44:08 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/15 20:56:28 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4]; //"The Character possesses an inventory of 4 slots, which means 4 Materias at most"

	public:
		Character() = delete;
		Character(std::string const &name);
		Character(Character const &other);
		Character &operator=(Character const &other);
		virtual ~Character();

		virtual std::string const &getName() const override;
		virtual void equip(AMateria* m) override;
		virtual void unequip(int idx) override;
		virtual void use(int idx, ICharacter& target) override;
};

