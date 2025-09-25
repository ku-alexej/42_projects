/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:25:25 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/28 17:07:54 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

void	testVector() {
	std::cout << "============ TEST vector ============" << std::endl;
	std::vector<int> container;

	for (int i = -10; i <= 10; i++) {
		container.push_back(i * 2);
		std::cout << container.back() << " ";
	}
	std::cout << std::endl;

	try {
		int target = -12;
		std::cout << "Looking for: " << target << std::endl;
		std::vector<int>::iterator it = easyfind(container, target);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		int target = 17;
		std::cout << "Looking for: " << target << std::endl;
		std::vector<int>::iterator it = easyfind(container, target);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void	testList() {
	std::cout << "============ TEST list   ============" << std::endl;
	std::list<int> container;

	for (int i = -10; i <= 10; i++) {
		container.push_back(i * 3);
		std::cout << container.back() << " ";
	}
	std::cout << std::endl;

	try {
		int target = -12;
		std::cout << "Looking for: " << target << std::endl;
		std::list<int>::iterator it = easyfind(container, target);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		int target = 40;
		std::cout << "Looking for: " << target << std::endl;
		std::list<int>::iterator it = easyfind(container, target);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void	testDeque() {
	std::cout << "============ TEST deque  ============" << std::endl;
	std::deque<int> container;

	for (int i = -10; i <= 10; i++) {
		container.push_back(i * 4);
		std::cout << container.back() << " ";
	}
	std::cout << std::endl;

	try {
		int target = -12;
		std::cout << "Looking for: " << target << std::endl;
		std::deque<int>::iterator it = easyfind(container, target);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		int target = 50;
		std::cout << "Looking for: " << target << std::endl;
		std::deque<int>::iterator it = easyfind(container, target);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;	
}

void	testSet() {
	std::cout << "============ TEST set    ============" << std::endl;
	std::set<int> container;

	for (int i = -10; i <= 10; i++) {
		container.insert(i * 5);
		std::cout << *container.find(i * 5) << " ";
	}
	std::cout << std::endl;

	try {
		int target = -30;
		std::cout << "Looking for: " << target << std::endl;
		std::set<int>::iterator it = easyfind(container, target);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		int target = 44;
		std::cout << "Looking for: " << target << std::endl;
		std::set<int>::iterator it = easyfind(container, target);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}

int		main(void) {
	std::cout << std::endl;
	testVector();
	testList();
	testDeque();
	testSet();
	return (0);
}
