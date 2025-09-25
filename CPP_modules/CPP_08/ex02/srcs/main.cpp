/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:05:17 by akurochk          #+#    #+#             */
/*   Updated: 2024/11/05 14:28:52 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main() {
	{
		std::cout << "=== Subject test 1 ===" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "=== Subject test 2 ===" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	{
		std::cout << "=== Revers test 1  ===" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(200);
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Last: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Last: " << mstack.top() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(700);
		mstack.push(9);
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "=== Revers test 2  ===" << std::endl;
		std::list<int> mstack;
		mstack.push_back(1);
		mstack.push_back(200);
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Last: " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Last: " << mstack.back() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(700);
		mstack.push_back(9);
		std::list<int>::reverse_iterator it = mstack.rbegin();
		std::list<int>::reverse_iterator ite = mstack.rend();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	{
		std::cout << "=== Const test 1   ===" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(200);
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Last: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Last: " << mstack.top() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(700);
		mstack.push(9);
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "=== Const test 2   ===" << std::endl;
		std::list<int> mstack;
		mstack.push_back(1);
		mstack.push_back(200);
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Last: " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Last: " << mstack.back() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(700);
		mstack.push_back(9);
		std::list<int>::const_iterator it = mstack.begin();
		std::list<int>::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	return 0;
}
