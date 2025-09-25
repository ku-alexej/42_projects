/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:05:13 by akurochk          #+#    #+#             */
/*   Updated: 2024/11/05 14:01:58 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container> {

	public:
		MutantStack() : std::stack<T, container>() {}
		MutantStack(const MutantStack &other) : std::stack<T, container>(other) {}
		~MutantStack() {}
		
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other)
				std::stack<T, container>::operator=(other);
			return (*this);
		}

		typedef typename container::iterator iterator;
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		typedef typename container::const_iterator const_iterator;
		const_iterator begin() const { return (this->c.begin()); }
		const_iterator end() const { return (this->c.end()); }

		typedef typename container::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }

		typedef typename container::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const { return (this->c.rbegin()); }
		const_reverse_iterator rend() const { return (this->c.rend()); }
};

#endif
