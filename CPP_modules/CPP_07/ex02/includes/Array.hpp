/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:29:56 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/21 15:54:31 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <ctime>
# include <cstdlib>

template <typename T>
class Array {
	public:
		Array() : _arr(NULL), _size(0) {}
		Array(unsigned int n) : _arr(new T[n]()), _size(n) {}
		Array(const Array &other) : _arr(NULL), _size(0) {
			*this = other;
		}
		~Array() { 
			delete [] _arr;
		}

		Array &operator=(const Array &other) {
			if (this != &other) {
				delete [] this->_arr;
				this->_size = other._size;
				this->_arr = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_arr[i] = other._arr[i];
			}
			return (*this);
		}

		T &operator[](unsigned int i) {
			if (i >= (this->_size))
				throw std::out_of_range("Error: index out of range");
			return (this->_arr[i]);
		}

		unsigned int size() const {
			return (this->_size);
		}

	private:
		T				*_arr;
		unsigned int	_size;
};

#endif
