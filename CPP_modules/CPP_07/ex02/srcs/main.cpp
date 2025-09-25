/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:33:13 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/21 15:55:13 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750
int	main() {
	Array<int> arr(5);
	Array<int> arr2(10);

	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i + 100;
	for (unsigned int i = 0; i < arr2.size(); i++)
		arr2[i] = i + 200;

	std::cout << "TEST: elements" << std::endl;
	try {
		std::cout << "Try to print arr:  ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Try to print arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Try to print arr with len more then size: ";
		for (unsigned int i = 0; i < arr.size() + 2; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		std::cout << "TEST: = operator" << std::endl;
		std::cout << "Array<int> arr3 = arr" << std::endl;
		Array<int> arr3 = arr;
		std::cout << "Try to print arr3: ";
		for (unsigned int i = 0; i < arr3.size(); i++)
			std::cout << arr3[i] << " ";
		std::cout << std::endl;
		std::cout << "Try to print arr:  ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
		std::cout << "Change arr" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
			arr[i] = i + 500;
		std::cout << "Try to print arr3: ";
		for (unsigned int i = 0; i < arr3.size(); i++)
			std::cout << arr3[i] << " ";
		std::cout << std::endl;
		std::cout << "Try to print arr:  ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		std::cout << "TEST: copy constructor" << std::endl;
		std::cout << "Array<int> arr4(arr2)" << std::endl;
		Array<int> arr4(arr2);
		std::cout << "Try to print arr4: ";
		for (unsigned int i = 0; i < arr4.size(); i++)
			std::cout << arr4[i] << " ";
		std::cout << std::endl;
		std::cout << "Try to print arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;
		std::cout << "Change arr2" << std::endl;
		for (unsigned int i = 0; i < arr2.size(); i++)
			arr2[i] = i + 900;
		std::cout << "Try to print arr4: ";
		for (unsigned int i = 0; i < arr4.size(); i++)
			std::cout << arr4[i] << " ";
		std::cout << std::endl;
		std::cout << "Try to print arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		std::cout << "TEST: construction without param" << std::endl;
		std::cout << "Array<int> arr5" << std::endl;
		Array<int> arr5;
		std::cout << "Size of arr5: " << arr5.size() << std::endl;
		std::cout << "Try to print arr5[0]: ";
		std::cout << arr5[0] << std::endl;

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "TEST: main from subject" << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));

		for (int i = 0; i < MAX_VAL; i++) {
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}

		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}

		try {
			numbers[-2] = 0;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		
		try {
			numbers[MAX_VAL] = 0;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		delete [] mirror;
	}

	return (0);
}
