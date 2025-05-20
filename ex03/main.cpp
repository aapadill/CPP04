/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:53:30 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/16 15:14:09 by aapadill         ###   ########.fr       */
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
	IMateriaSource* src	  = nullptr;
	ICharacter*	 alice	= nullptr;
	ICharacter*	 bob	  = nullptr;
	Character*	  copyAlice= nullptr;
	Ice *		ice = new Ice();
	Cure *		cure = new Cure();

	try
	{
		//1) build the materia source and learn spells
		std::cout << "--- materia source test ---\n";
		src = new MateriaSource();
		src->learnMateria(ice);
		src->learnMateria(cure);

		//test learning more than 4
		std::cout << "\n-- learning more than 4 materias --\n";
		src->learnMateria(ice);
		src->learnMateria(cure);
		std::cout << "-- fifth materia incoming --\n";
		src->learnMateria(ice);

		//2) create two characters
		std::cout << "\n--- character test ---\n";
		alice = new Character("Alice");
		bob   = new Character("Bob");

		//3) create some materias by type
		std::cout << "\n--- materia creation test ---\n";
		AMateria* m1 = src->createMateria("ice");
		AMateria* m2 = src->createMateria("cure");
		std::cout << "-- invalid materia creation incoming --\n";
		AMateria* m3 = src->createMateria("fire");

		//4) equip materias
		std::cout << "\n-- Alice equips materias --\n";
		alice->equip(m1);
		alice->equip(m2);
		std::cout << "-- invalid equip (nullptr) incoming --\n";
		alice->equip(m3);

		//5) use them
		std::cout << "\n-- Alice uses slot 0 and 1 on Bob --\n";
		alice->use(0, *bob); //ice
		alice->use(1, *bob); //cure

		//6) edge‐cases: invalid slots
		std::cout << "\n-- Invalid uses (should do nothing) --\n";
		alice->use(-1, *bob);
		alice->use(99, *bob);

		//7)unequip and reuse
		std::cout << "\n-- Unequip slot 1 and try to use --\n";
		alice->unequip(1); //cure
		delete m2;
		m2 = nullptr;
		alice->use(1, *bob);

		//8) deep‐copy test
		std::cout << "\n--- Deep‐copy test ---\n";
		copyAlice = new Character(*static_cast<Character*>(alice));
	
		std::cout << "\n--- Original equips another ice ---\n";
		AMateria* m4 = src->createMateria("ice");
		alice->equip(m4);
		alice->use(2, *bob);

		std::cout << "\n--- Copy tries slot 2 (should do nothing) ---\n";
		copyAlice->use(2, *bob);
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Allocation failed: " << e.what() << std::endl;
	}
	// cleanup
	delete src;
	delete alice;
	delete bob;
	delete copyAlice;
	delete ice;
	delete cure;
	return 0;
}
