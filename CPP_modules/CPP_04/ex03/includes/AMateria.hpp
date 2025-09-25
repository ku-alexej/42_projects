/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:41:18 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/18 12:49:27 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		virtual ~AMateria();
		
		AMateria &operator=(const AMateria &other);

		const std::string &getType() const;
		
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
