/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:57 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/18 14:44:19 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void baseTest() {
	std::cout << "========== baseTest ==========" << RESET << std::endl;
	const Animal*	i = new Dog();
	const Animal*	j = new Cat();
	delete i;
	delete j;
}

void arrayTest() {
	std::cout << "========== arrayTest =========" << RESET << std::endl;
	const int	n = 6;
	Animal*		animals[n];
	
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < n; i++) {
		delete animals[i];
	}
}

void deepCopyTest1() {
	std::cout << "======= deepCopyTest 1 =======" << RESET << std::endl;
	Cat*	cat = new Cat();
	Cat*	cat2 = new Cat(*cat);

	cat->makeSound();
	std::cout << "cat brain : ";
	cat->getIdeas();
	std::cout << std::endl;
	cat2->makeSound();
	std::cout << "cat2 brain: ";
	cat2->getIdeas();
	std::cout << std::endl;

	delete cat;
	delete cat2;
}

void deepCopyTest2() {
	std::cout << "======= deepCopyTest 2 =======" << RESET << std::endl;
	Dog	dog;
	Dog	tmp = dog;
		
	dog.makeSound();
	std::cout << "Type: " << dog.getType() << ". Dog brain : ";
	dog.getIdeas();
	std::cout << std::endl;
	tmp.makeSound();
	std::cout << "Type: " << tmp.getType() << ". Dog brain : ";
	tmp.getIdeas();
	std::cout << std::endl;
}

void deepCopyTest3() {
	std::cout << "======= deepCopyTest 3 =======" << RESET << std::endl;
	Cat*	cat = new Cat();
	cat->addIdea("I'm a cat");
	cat->addIdea("Foooood!");
	cat->addIdea("Scratch scratch");
	cat->addIdea("Meh...");
	Cat*	cat2 = new Cat(*cat);

	cat->setType("Original cat");
	cat->makeSound();
	std::cout << "Type: " << cat->getType() << ". Cat brain : ";
	cat->getIdeas();
	std::cout << std::endl;
	cat2->setType("Copy --- cat");
	cat2->makeSound();
	std::cout << "Type: " << cat2->getType() << ". Cat brain : ";
	cat2->getIdeas();
	std::cout << std::endl;

	cat->setIdea(0, "I'm the original one");
	cat->makeSound();
	std::cout << "Type: " << cat->getType() << ". Cat brain : ";
	cat->getIdeas();
	std::cout << std::endl;
	cat2->makeSound();
	std::cout << "Type: " << cat2->getType() << ". Cat brain : ";
	cat2->getIdeas();
	std::cout << std::endl;

	delete cat;
	delete cat2;
}

void deepCopyTest4() {
	std::cout << "======= deepCopyTest 4 =======" << RESET << std::endl;
	Dog	dog5;
	{
		dog5.addIdea("I'm a dog");
		dog5.addIdea("Food!");
		dog5.addIdea("Bones!!!");
		Dog	tmp2 = dog5;
		
		dog5.setType("Original dog");
		dog5.makeSound();
		std::cout << "Type: " << dog5.getType() << ". Dog brain : ";
		dog5.getIdeas();
		std::cout << std::endl;
		tmp2.setType("Assigned dog");
		tmp2.makeSound();
		std::cout << "Type: " << tmp2.getType() << ". Dog brain : ";
		tmp2.getIdeas();
		std::cout << std::endl;

		dog5.setIdea(0, "I'm the original one");
		dog5.makeSound();
		std::cout << "Type: " << dog5.getType() << ". Dog brain : ";
		dog5.getIdeas();
		std::cout << std::endl;
		tmp2.makeSound();
		std::cout << "Type: " << tmp2.getType() << ". Dog brain : ";
		tmp2.getIdeas();
		std::cout << std::endl;

		tmp2 = dog5;
		dog5.makeSound();
		std::cout << "Type: " << dog5.getType() << ". Dog brain : ";
		dog5.getIdeas();
		std::cout << std::endl;
		tmp2.makeSound();
		std::cout << "Type: " << tmp2.getType() << ". Dog brain : ";
		tmp2.getIdeas();
		std::cout << std::endl;
		
	}
}

int main()
{
	baseTest();
	arrayTest();
	deepCopyTest1();
	deepCopyTest2();
	deepCopyTest3();
	deepCopyTest4();
	
	std::cout << "=========== Test 5 ===========" << RESET << std::endl;

	// Animal class now abstract.
	// So we can't create an instance of an abstract class.
	
	// Animal*	animal = new Animal();
	// animal->makeSound();
	// delete animal;

	Animal*	animal2 = new Dog();
	animal2->makeSound();
	delete animal2;
	
	return 0;
}
