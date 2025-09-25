/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:40 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 17:03:41 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &other);
		virtual ~Cat();

		Cat &operator=(const Cat &other);

		virtual void makeSound() const;
		void setType(std::string type);
		void addIdea(std::string idea);
		void getIdeas() const;
		void setIdea(int index, std::string idea);
	
	private:
		Brain *_brain;
};

#endif
