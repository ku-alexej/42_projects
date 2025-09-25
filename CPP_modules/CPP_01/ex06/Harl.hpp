/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:41:53 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/10 18:45:27 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
	public:
		Harl();
		~Harl();
		void	complain( std::string level );
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

int	getLevel(std::string level);

#endif