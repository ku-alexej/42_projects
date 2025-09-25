/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:05:43 by akurochk          #+#    #+#             */
/*   Updated: 2024/10/30 14:30:54 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		~Span();

		Span &operator=(const Span &other);

		void			addNumber(int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			print() const;
		void			addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	private:
		std::vector<int>	_v;
		unsigned int		_n;
};

#endif
