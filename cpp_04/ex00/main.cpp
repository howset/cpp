/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/04 18:09:05 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int	main(void)
{
	std::cout << "############### PDF tests ###############" << std::endl;
	std::cout << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
	
	std::cout << "############### Other tests ###############" << std::endl;
	std::cout << std::endl;
	
	Animal human("Howard");
	Dog dog("DogDog");
	Cat cat("CatCat");
	WrongAnimal wronghuman("ScreamHoward");
	WrongCat wrongcat("ScreamCatCat");

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
	wrongcat.makeSound();
	return 0;
}
