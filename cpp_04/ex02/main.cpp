/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 16:33:30 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

/*
Polymorphism allows objects of different types to be treated as objects of a
common base type, while still calling the appropriate derived class methods.
*/
int	main(void)
{
/* 	std::cout << std::endl;
	std::cout << "############### PDF tests ###############" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << "idontknowwhythislineishere" << std::endl;
	std::cout << i->getType() << "idontknowwhythislineishere" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	
	std::cout << std::endl; */

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
	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################" << std::endl;
	
	std::cout << std::endl;
	std::cout << "############### PDF tests ###############" << std::endl;
	//order of const & dest
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	delete j;//should not create a leak
	std::cout << std::endl;
	delete i;
	
	std::cout << std::endl;
	std::cout << "############### Create Animal Array ###############" << std::endl;
	Animal *animals[6];
	//create, make sound & delete in a loop
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog("dogdog");
		else
			animals[i] = new Cat("catcat");
		std::cout << "Constr loop: " << i << "." << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		animals[i]->makeSound();
		delete (animals[i]);
		std::cout << "Destr loop: " << i << "." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "############### Brain Array 1 ###############" << std::endl;
	std::string arr[6] = {"Arr1", "Arr2", "Arr3", "Arr4", "Arr5", "Arr6"};
	Brain *brain = new Brain(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 10; i++)
	{
		if (!brain->getIdeas(i).empty())
			std::cout << brain->getIdeas(i) << std::endl;
		else
			std::cout << "Idea " << i << " is empty" << std::endl;
	}
	std::cout << "############### Brain Array 2 ###############" << std::endl;
	Brain *brain2 = new Brain();
	for (int i = 0; i < 10; i++)
	{
		if (!brain2->getIdeas(i).empty())
			std::cout << brain2->getIdeas(i) << std::endl;
		else
			std::cout << "Idea " << i << " is empty" << std::endl;
	}
	delete (brain);
	delete (brain2);

	std::cout << std::endl;
	std::cout << "############### Deep Copying ###############" << std::endl;
	Dog ori("OriginalDogDog");
	ori.getBrain()->setIdeas("Hunt CatCat", 0);
	ori.getBrain()->setIdeas("Eat CatCat", 1);
	ori.getBrain()->setIdeas("Eat CatCat again", 2);
	
	// std::cout << "###############Copy Const ###############" << std::endl;
	Dog copy1(ori); //copy const, no name

	// std::cout << "############### Assignment Op ###############" << std::endl;
	// std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
	Dog copy2("Copy2DogDog"); //
	copy2 = ori; //assignment op
	
	std::cout << std::endl;
	std::cout << "Pre-mod:" << std::endl;
	std::cout << "Original: " << ori.getBrain()->getIdeas(1) << std::endl;
	std::cout << "Copy1: " << copy1.getBrain()->getIdeas(1) << std::endl;

	std::cout << std::endl;
	std::cout << "Modify original" << std::endl;
	ori.getBrain()->setIdeas("Love CatCat ", 1);

	std::cout << std::endl;
	std::cout << "Post mod:" << std::endl;
	std::cout << "Original: " << ori.getBrain()->getIdeas(1) << std::endl;
	std::cout << "Copy1: " << copy1.getBrain()->getIdeas(1) << std::endl;

	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################" << std::endl;

	std::cout << std::endl;
	std::cout << "############### Instantiation ###############" << std::endl;
	//Animal animal; //Cant compile
	//Animal* animal = new Animal(); //Cant compile
	Animal* dog = new Dog("DogDog"); //Works ok
	Animal* cat = new Cat("CatCat"); //Works ok
	dog->makeSound(); //Works ok
	cat->makeSound(); //Works ok
	delete dog; //Works ok
	delete cat; //Works ok
	// Animal* ani_mals[4];
	// ani_mals[0] = new Dog("DogDogs"); //Works ok
	// ani_mals[1] = new Cat("CatCats"); //Works ok
	// ani_mals[0]->makeSound(); //Works ok
	// ani_mals[1]->makeSound(); //Works ok
	
	std::cout << std::endl;
	return 0;
}
