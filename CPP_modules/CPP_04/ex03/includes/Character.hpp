/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:55:05 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/18 13:20:14 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &other);
		virtual ~Character();
		
		Character &operator=(const Character &other);

		const std::string &getName() const;
		
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		void printData();
};

#endif
