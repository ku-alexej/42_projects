/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:34:33 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/21 13:49:30 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Fox {
	public:
		Fox() : _name("Amazing Red Fox") { return ; }
		Fox(Fox const &src) { *this = src; }
		~Fox() { return ; }
		Fox &operator=(Fox const &src) {
			if (this != &src) {
				this->_name = src.getName();
			}
			return *this;
		}
		std::string getName() const { return (this->_name); }
	private:
		std::string _name;
};

std::ostream &operator<<(std::ostream &out, Fox const &src) {
	out << src.getName();
	return out;
}


template <typename T>
void ft_print(T const &x) {
	std::cout << "ft_print:  '" << x << "'" << std::endl;
}

template <typename T>
int	ft_print2(T const &x) {
	std::cout << "ft_print2: '" << x << "'" << std::endl;
	return 0;
}

template <typename T>
void change(T &x) {
	x += 100;
}

int main() {
	{
		std::cout << std::endl << "TEST: Array of ints and ft_print" << std::endl;
		int arr[] = {1, 2, 3, 4, 5, -1, 0, -22222};
		iter(arr, 8, ft_print<int>);
	}
	{
		std::cout << std::endl << "TEST: Array of strings and ft_print" << std::endl;
		std::string arr[] = {"Carrot", "Fox", "42", "Lemon", "Apple"};
		iter(arr, 5, ft_print<std::string>);
	}
	{
		std::cout << std::endl << "TEST: Array of ints and ft_print2" << std::endl;
		int arr[] = {1, 2, 3, 4, 5, -1, 0, -22222};
		iter(arr, 8, ft_print2<int>);
	}
	{
		std::cout << std::endl << "TEST: Array of ints,change and print" << std::endl;
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
		iter(arr, 8, ft_print<const int>);
		iter(arr, 8, change<int>);
		std::cout << "After change:" << std::endl;
		iter(arr, 8, ft_print<const int>);
	}
	{
		std::cout << std::endl << "TEST: Array of Foxes and ft_print" << std::endl;
		Fox arr[] = {Fox(), Fox(), Fox(), Fox(), Fox()};
		iter(arr, 5, ft_print<Fox>);
	}

	std::cout << std::endl;	
	return 0;
}
