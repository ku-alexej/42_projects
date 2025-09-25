/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:57 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/18 14:25:10 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void testOne() {
	std::cout << "============ Test 1 ============" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void testTwo() {
	std::cout << "============ Test 2 ============" << std::endl;
	
	ICharacter*	chosenOne = new Character("Chosen One");
	ICharacter*	forceOfEvel = new Character("Force of Evel");
	AMateria*	ice = new Ice();

	chosenOne->equip(new Ice());
	chosenOne->equip(ice);
	chosenOne->equip(new Cure());
	chosenOne->equip(new Ice());
	
	forceOfEvel->equip(new Cure());
	forceOfEvel->equip(new Cure());
	forceOfEvel->equip(new Cure());

	chosenOne->printData();
	forceOfEvel->printData();
	
	chosenOne->use(-1, *forceOfEvel);
	chosenOne->use(0, *forceOfEvel);
	chosenOne->use(1, *forceOfEvel);
	chosenOne->use(2, *forceOfEvel);
	chosenOne->use(3, *forceOfEvel);
	chosenOne->use(4, *forceOfEvel);

	chosenOne->use(1, *forceOfEvel);
	chosenOne->use(1, *forceOfEvel);

	forceOfEvel->use(0, *chosenOne);
	forceOfEvel->use(1, *chosenOne);
	forceOfEvel->use(2, *chosenOne);
	forceOfEvel->use(3, *chosenOne);
	forceOfEvel->use(4, *chosenOne);

	forceOfEvel->use(1, *chosenOne);
	forceOfEvel->use(1, *chosenOne);

	chosenOne->unequip(1);
	chosenOne->unequip(-4);
	chosenOne->printData();

	chosenOne->use(1, *forceOfEvel);
	chosenOne->equip(new Cure());
	chosenOne->printData();

	delete ice;
	delete chosenOne;
	delete forceOfEvel;
}

void testThree() {
	std::cout << "============ Test 3 ============" << std::endl;
	
	IMateriaSource	*src = new MateriaSource();
	ICharacter		*fox = new Character("Fox");
	ICharacter		*bunny = new Character("Bunny");
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	fox->printData();
	fox->equip(src->createMateria("ice"));
	fox->equip(src->createMateria("cure"));
	fox->equip(src->createMateria("ice"));
	fox->printData();
	fox->equip(src->createMateria("cure"));
	fox->printData();

	fox->use(0, *bunny);
	fox->use(1, *bunny);
	fox->use(2, *bunny);
	fox->use(3, *bunny);
	fox->use(4, *bunny);

	delete src;
	delete fox;
	delete bunny;
}

int main() {
	testOne();
	testTwo();
	testThree();	
	
	return 0;
}
