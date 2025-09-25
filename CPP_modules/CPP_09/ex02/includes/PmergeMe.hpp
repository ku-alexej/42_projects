/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:48:56 by akurochk          #+#    #+#             */
/*   Updated: 2025/01/17 10:54:46 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <ctime>
# include <iomanip>
# include <algorithm>

# define RED     "\033[31m"
# define RESET   "\033[0m"

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();

        void run(int ac, char **av);

    private:
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        std::vector<int>    _v;
        std::deque<int>     _d;
        double              _vTime;
        double              _dTime;

        void runV(int ac, char **av);
        void runD(int ac, char **av);
        void showResults(int ac, char **av);
};

#endif
