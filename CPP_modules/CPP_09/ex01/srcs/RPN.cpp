/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:59:22 by akurochk          #+#    #+#             */
/*   Updated: 2024/11/18 15:02:51 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool isOperator(const char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

static void useOperator(std::stack<int> &stack, const char c) {
	long	temp;
	long	a;
	long	b;

	if (stack.size() < 2)
		throw std::invalid_argument("Error: not enough operands");

	temp = 0;
	b = stack.top();
	stack.pop();
	a = stack.top();
	stack.pop();

	switch (c) {
		case '+' :
			temp = a + b;
			break;
		case '-' :
			temp = a - b;
			break;
		case '*' :
			temp = a * b;
			break;
		case '/' :
			if (b == 0)
				throw std::runtime_error("Error: division by zero");
			temp = a / b;
			break;
	}	

	if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
		throw std::overflow_error("Error: int overflow");
	stack.push(temp);
}

static bool isOperand(const char c) {
	return (c >= '0' && c <= '9');
}

static void useOperand(std::stack<int> &stack, const char c) {
	int	operand;

	operand = c - '0';
	stack.push(operand);
}

static void printResult(std::stack<int> &stack) {
	if (stack.size() > 1)
		throw std::invalid_argument("Error: not enough operators");
	std::cout << stack.top() << std::endl;
}

void	calculate(const std::string &expression) {
	std::stack<int> stack;

	if (expression.empty())
		throw std::invalid_argument("Error: empty expression");
	if (expression.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::invalid_argument("Error");
	for (size_t i = 0; i < expression.length(); i++) {
		if (isOperator(expression.at(i))) {
			useOperator(stack, expression.at(i));
			if (i + 1 < expression.length() && expression.at(i + 1) != ' ')
				throw std::invalid_argument("Error: operator must be followed by a space or end of expression");
		}
		if (isOperand(expression.at(i))) {
			useOperand(stack, expression.at(i));
			if (i + 1 < expression.length() && expression.at(i + 1) != ' ')
				throw std::invalid_argument("Error: operand must be a number in range 0-9 and be followed by a space or end of expression");
		}
	}
	printResult(stack);
}
