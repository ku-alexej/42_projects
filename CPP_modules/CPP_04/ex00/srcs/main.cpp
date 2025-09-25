/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:57 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 15:35:10 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	
	{
		const Animal* meta = new Animal();
		std::cout << std::endl;
		const Animal* i = new Dog();
		std::cout << std::endl;
		const Animal* j = new Cat();
		std::cout << std::endl;
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << std::endl;

		meta->makeSound();
		i->makeSound();
		j->makeSound();
		std::cout << std::endl;
		
		delete meta;
		std::cout << std::endl;
		delete i;
		std::cout << std::endl;
		delete j;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	{
		const WrongAnimal* meta = new WrongAnimal();
		std::cout << std::endl;
		const WrongAnimal* i = new WrongCat();
		std::cout << std::endl;
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;

		meta->makeSound();
		i->makeSound();
		std::cout << std::endl;
		
		delete meta;
		std::cout << std::endl;
		delete i;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;

	{
		const Animal* meta = new Animal();
		std::cout << std::endl;
		const Dog* i = new Dog();
		std::cout << std::endl;
		const Animal* j = new Dog(*i);
		std::cout << std::endl;
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << std::endl;

		meta->makeSound();
		i->makeSound();
		j->makeSound();
		std::cout << std::endl;
		
		delete meta;
		std::cout << std::endl;
		delete i;
		std::cout << std::endl;
		delete j;
	}
	
	std::cout << std::endl;
	
	return 0;
}
