/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:35 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 15:49:40 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# include "color.hpp"

class Animal {
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
	
		Animal &operator=(const Animal &other);

		virtual void makeSound() const;
		std::string getType() const;
		
	protected:
		std::string _type;
};

#endif
