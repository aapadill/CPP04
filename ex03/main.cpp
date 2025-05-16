/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:53:30 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/16 14:09:16 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *alice = new Character("Alice");
	ICharacter *bob   = new Character("Bob");

	AMateria *m1 = src->createMateria("ice");
	AMateria *m2 = src->createMateria("cure");

	alice->equip(m1);
	alice->equip(m2);

	alice->use(0, *bob);
	alice->use(1, *bob);

	//deep‐copy test on characters
	Character copyAlice(*static_cast<Character*>(alice));
	std::cout << "\n-- equip more on original --\n";
	AMateria *m3 = src->createMateria("ice");
	alice->equip(m3);
	std::cout << "-- original uses slot 2 --\n";
	alice->use(2, *bob);
	std::cout << "-- copy uses slot 2 (should do nothing) --\n";
	copyAlice.use(2, *bob);

	delete src;
	delete alice;
	delete bob;
	//equipped Materias are deleted by character’s destructor

	return 0;
}
