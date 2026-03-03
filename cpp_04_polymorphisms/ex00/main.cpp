/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/08 12:33:10 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

/*
Polymorphism allows objects of different types to be treated as objects of a
common base type, while still calling the appropriate derived class methods.
*/
int	main(void)
{
 	std::cout << std::endl;
	std::cout << "############### PDF tests ###############" << std::endl;
	
	const Animal* meta = new Animal("Howard");
	const Animal* j = new Dog("DogDog");
	const Animal* i = new Cat("CatCat");
	
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	//this can be in any order, different with instantiated objects like below
	delete meta;
	delete j;
	delete i;
	
/*	std::cout << std::endl;
	std::cout << "############### Other tests ###############" << std::endl;
	
	Animal human("Howard");
	Dog dog("DogDog");
	Cat cat("CatCat");
	WrongAnimal wronghuman("ScreamHoward");
	WrongCat wrongcat("ScreamCatCat");

	std::cout << std::endl;
	std::cout << "Human type: " << human.getType() << std::endl;
	std::cout << "Dog type: " << dog.getType() << std::endl;
	std::cout << "Cat type: " << cat.getType() << std::endl;
	std::cout << "Human sound: ";
	human.makeSound();
	std::cout << "Dog sound: ";
	dog.makeSound();
	std::cout << "Cat sound: ";
	cat.makeSound();
	std::cout << "WrongHuman type: " << wronghuman.getType() << std::endl;
	std::cout << "WrongCat type: " << wrongcat.getType() << std::endl;
	std::cout << "WrongHuman sound: ";
	wronghuman.makeSound();
	std::cout << "WrongCat sound: ";
	wrongcat.makeSound(); //direct function call on wrongcat (object type)
	
	const WrongAnimal* wrongCat2 = new WrongCat("WrongCatCat"); 
	wrongCat2->makeSound(); //call through a pointer
	std::cout << std::endl; */

	std::cout << std::endl;
	std::cout << "# Polymorphism #############################################" << std::endl;
	std::cout << "############################################################" << std::endl;
	
	/*
	Direct Object Calls works because:
	- Compiler knows **exact type** at compile time (`WrongCat`)
	- No polymorphism involved - direct function call
	- **Static binding** resolves to `WrongCat::makeSound()`
	*/
	std::cout << std::endl;
	std::cout << "############### Direct Object Calls ###############" << std::endl;
	WrongCat wrongcat2("ScreamCatCat");
	wrongcat2.makeSound();

	/*
	Pointer Calls (Without Virtual) calls the base class function because:
	- Compiler only sees `WrongAnimal*` type
	- **No virtual keyword** = static binding
	- Always calls `WrongAnimal::makeSound()`
	*/
	std::cout << std::endl;
	std::cout << "############### Pointer Calls (No Virtual) ###############" << std::endl;
	const WrongAnimal* ptrWrongCat = new WrongCat("ScreamCatCat");
	ptrWrongCat->makeSound();
	delete ptrWrongCat;

	/*
	Pointer Calls (With Virtual) calls the derived class function because:
	- Compiler sees Animal* type but uses virtual table lookup
	- Virtual keyword = dynamic binding
	- Runtime checks actual object type (Cat) and calls Cat::makeSound()
	*/
	std::cout << std::endl;
	std::cout << "############### Pointer Calls (With Virtual) ###############" << std::endl;
	const Animal* ptrCat = new Cat("ScreamCatCat");
	ptrCat->makeSound();
	delete ptrCat;
	std::cout << std::endl;

	return 0;
}
