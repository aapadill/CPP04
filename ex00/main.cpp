/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:04:56 by aapadill          #+#    #+#             */
/*   Updated: 2025/05/13 12:08:54 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal      *meta      = nullptr;
    Animal      *dog       = nullptr;
    Animal      *cat       = nullptr;
    WrongAnimal *wrongMeta = nullptr;
    WrongAnimal *wrongCat  = nullptr;

    try
	{
        std::cout << "============ constructors" << std::endl;
        meta = new Animal();
        dog  = new Dog();
        cat  = new Cat();

        std::cout << "============ tests" << std::endl;
        std::cout << dog->getType()  << std::endl;
        std::cout << cat->getType()  << std::endl;
        std::cout << meta->getType() << std::endl;

        cat->makeSound();
        dog->makeSound();
        meta->makeSound();

        std::cout << "\n============ wrong animal" << std::endl;
        wrongMeta = new WrongAnimal();
        wrongCat  = new WrongCat();

        std::cout << wrongMeta->getType() << std::endl;
        wrongMeta->makeSound();

        std::cout << wrongCat->getType() << std::endl;
        wrongCat->makeSound();
    }
    catch (const std::bad_alloc &e)
	{
        std::cerr << "Allocation failed: " << e.what() << std::endl;
        delete meta;
        delete dog;
        delete cat;
        delete wrongMeta;
        delete wrongCat;
        return 1;
    }
    std::cout << "\n============ destructors" << std::endl;
    delete meta;      // safe: meta != nullptr
    delete dog;       // safe: dog  != nullptr
    delete cat;       // safe: cat  != nullptr
    delete wrongMeta; // safe even if wrongMeta is nullptr
    delete wrongCat;  // safe even if wrongCat  is nullptr
	std::cout << "============ end" << std::endl;
    return 0;
}
