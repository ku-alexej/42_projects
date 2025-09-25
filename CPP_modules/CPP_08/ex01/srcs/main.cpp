/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:05:41 by akurochk          #+#    #+#             */
/*   Updated: 2024/11/05 13:05:29 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

std::vector<int> randommNumbers(unsigned int n) {
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::vector<int> v;
	
	for (unsigned int i = 0; i < n; ++i) {
		int x = std::rand();
		int y = std::rand();
		
		if (y % 2 == 0)
			v.push_back(x);
		else
			v.push_back((-1) * x);
	}
	return (v);
}

void	printVector(std::vector<int> v) {
	std::cout << "Vector: (";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it;
		if (it != v.end() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << ")" << std::endl;
}

void	testSubject() {
	std::cout << "========== Subject test     ==========" << std::endl;

	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "--------------------------------------" << std::endl;
}

void	testCombo(Span *sp, int num) {
	try {
		std::cout << "shortestSpan():\t" << sp->shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "longestSpan():\t" << sp->longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "addNumber(" << num << "):\t";
		sp->addNumber(num);
		std::cout << "OK" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;
}

void	testNumbs(unsigned int n) {
	std::cout << "========== Test n-size full ==========" << std::endl;
	std::cout << "n = " << n << std::endl;
	Span sp(n);
	std::vector<int> v = randommNumbers(n);
	// printVector(v);

	try {
		sp.addNumbers(v.begin(), v.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	testCombo(&sp, 1);

	std::cout << std::endl;
}


void	testManualOne() {
	std::cout << "========== Test Span()      ==========" << std::endl;
	Span sp = Span();

	testCombo(&sp, 1);
	
	std::cout << std::endl;
}

void	testManualTwo() {
	std::cout << "========== Test Span(1)     ==========" << std::endl;
	Span sp = Span(1);

	testCombo(&sp, 1);
	testCombo(&sp, -1);
	
	std::cout << std::endl;
}

void	testManualThree() {
	std::cout << "========== Test Span(5)     ==========" << std::endl;
	Span sp = Span(5);

	testCombo(&sp, 1);
	testCombo(&sp, 5);
	testCombo(&sp, -10);
	testCombo(&sp, 10);
	testCombo(&sp, 1);
	testCombo(&sp, 78);
	testCombo(&sp, 8);
	
	std::cout << std::endl;
}

int main()
{
	testSubject();
	testNumbs(5);
	testNumbs(10);
	testNumbs(5);
	testNumbs(30);
	testNumbs(30);
	testNumbs(10000);
	testNumbs(100000);
	testNumbs(1000000);
	testManualOne();
	testManualTwo();
	testManualThree();
	
	return (0);
}