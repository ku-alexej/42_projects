/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceUtils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:07:27 by akurochk          #+#    #+#             */
/*   Updated: 2024/07/10 17:09:28 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void		argvChecker(int argc, char **argv);
void		fileCheckerIn(std::ifstream &file, std::string filename);
void		fileCheckerOut(std::ofstream &file, std::string filename);
std::string	replaceLoop(std::string &buffer, std::string &s1, std::string &s2);
