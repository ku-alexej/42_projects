/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:35 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 14:24:32 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

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
