/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:54 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 17:05:07 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &other);
		virtual ~Dog();

		Dog &operator=(const Dog &other);

		virtual void makeSound() const;
		void setType(std::string type);
		void addIdea(std::string idea);
		void getIdeas() const;
		void setIdea(int index, std::string idea);

		
	private:
		Brain *_brain;
};

#endif