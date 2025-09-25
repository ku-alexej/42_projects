/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:41:49 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/17 16:45:40 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# include "color.hpp"

class Brain {
	public:
		Brain();
		Brain(const Brain &other);
		virtual ~Brain();

		Brain &operator=(const Brain &other);

		void addIdea(std::string idea);
		void getIdeas();
		void setIdea(int index, std::string idea);

	private:
		std::string _ideas[100];
};

#endif
