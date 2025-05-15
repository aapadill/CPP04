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

int main()
{
    const int N = 4;
    Animal* array[N] = {};   //all to nullptr
    Dog*    dog1    = nullptr;
    Dog*    dog2    = nullptr;

    try 
	{
        std::cout << "=== building array ===" << std::endl;
        for (int i = 0; i < N/2; ++i)
		{
            std::cout << "--- dog " << i << " ---" << std::endl;
            array[i] = new Dog();
        }
        for (int i = N/2; i < N; ++i)
		{
            std::cout << "--- cat " << i << " ---" << std::endl;
            array[i] = new Cat();
        }

        std::cout << "\n=== deep-copy test ===" << std::endl;
        std::cout << "\n--- dog1 (copy of array[0]) ---" << std::endl;
        dog1 = new Dog(*static_cast<Dog*>(array[0]));
        dog1->getBrain().setIdea(0, "chase the cat");

        std::cout << "\n--- dog2 (copy of dog1) ---" << std::endl;
        dog2 = new Dog(*dog1);

        std::cout << "\n--- initial ideas ---" << std::endl;
        std::cout << "dog1 idea[0]: " << dog1->getBrain().getIdea(0) << std::endl;
        std::cout << "dog2 idea[0]: " << dog2->getBrain().getIdea(0) << std::endl;

        std::cout << "\n--- changing dog2's idea[0] ---" << std::endl;
        dog2->getBrain().setIdea(0, "eat a bone");

        std::cout << "--- after modification ---" << std::endl;
        std::cout << "dog1 idea[0]: " << dog1->getBrain().getIdea(0) << std::endl;
        std::cout << "dog2 idea[0]: " << dog2->getBrain().getIdea(0) << std::endl;
    }
    catch (const std::bad_alloc &e)
	{
        std::cerr << "Allocation failed: " << e.what() << std::endl;
        for (int i = 0; i < N; ++i)
            delete array[i];
        delete dog1;
        delete dog2;
        return 1;
    }

    std::cout << "\n=== deleting array ===" << std::endl;
    for (int i = 0; i < N; ++i)
	{
        std::cout << "--- deleting array[" << i << "] as Animal ---" << std::endl;
        delete array[i];
    }

    std::cout << "\n=== deleting deep copies ===" << std::endl;
    delete dog1;
    delete dog2;

    std::cout << "\n=== end ===" << std::endl;
    return 0;
}