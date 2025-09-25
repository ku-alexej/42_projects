/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:49:14 by akurochk          #+#    #+#             */
/*   Updated: 2025/01/17 12:27:10 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->_v = other._v;
        this->_vTime = other._vTime;
        this->_d = other._d;
        this->_dTime = other._dTime;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

// ========== TOOLS ===========

static int getJacobsthal(int n) {
	if (n < 2)
		return (n);
	return (getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2));
}

// static void compareResults(std::vector<int> v, std::deque<int> d) {
//     if (v.size() != d.size())
//         throw std::logic_error("Error: different results in two sequences");

//     std::vector<int>::iterator it_v = v.begin();
//     std::deque<int>::iterator it_d = d.begin();

//     while (it_v != v.end() || it_d != d.end()) {
//         if (*it_v != *it_d)
//             throw std::logic_error("Error: different results in two sequences");
//         it_v++;
//         it_d++;
//     }
// }

void PmergeMe::showResults(int ac, char **av) {

    // compareResults(_v, _d);

    std::cout << "Before:";
    for (size_t i = 1; i < (size_t)ac; i++)
        std::cout << " " << av[i];
    std::cout << std::endl;

    std::cout << "After: ";
    for (size_t i = 0; i < _v.size(); i++)
        std::cout << " " << _v[i];
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _v.size()
        << " elements with std::vector : " << std::fixed << std::setprecision(5) << _vTime << " sec" << std::endl;
    std::cout << "Time to process a range of " << _d.size()
        << " elements with std::deque :  " << std::fixed << std::setprecision(5) << _dTime << " sec" << std::endl;

}

// ========== VECTOR ==========

static std::vector<int> getIndexOrderV(size_t size) {
    std::vector<int> order;

    if (size < 1)
        return order;

    int jac = 2;
    int next = getJacobsthal(jac++);

    while (next < static_cast<int>(size)) {
        order.push_back(next);
        next = getJacobsthal(jac++);
    }

    next = size;
    while (order.size() < size) {
        if (std::find(order.begin(), order.end(), next) == order.end())
            order.push_back(next);
        next--;
    }

    return (order);
}

static void collectPairsV(std::vector<int> &sequence, std::vector<std::pair<int, int> > &pairs) {
    for (std::vector<int>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
        int a = *it;
        if (++it == sequence.end()) 
            break;
        int b = *it;
        if (a < b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }
}

static void sortPairsMergeInsertionV(std::vector<std::pair<int, int> > &pairs, size_t size) {
    if (size <= 1)
        return ;

    std::vector<std::pair<int, int> > l;
    std::vector<std::pair<int, int> > r;
    std::vector<std::pair<int, int> >::iterator it = pairs.begin();

    for (size_t i = 0; i < size / 2; i++)
        l.push_back(*it++);
    for (size_t i = size / 2; i < size; i++)
        r.push_back(*it++);

    pairs.clear();

    sortPairsMergeInsertionV(l, l.size());
    sortPairsMergeInsertionV(r, r.size());

    while (!r.empty() && !l.empty()) {
        if (l.front().first < r.front().first) {
            pairs.push_back(l.front());
            l.erase(l.begin());
        } else {
            pairs.push_back(r.front());
            r.erase(r.begin());
        }
    }

    while (!l.empty()) {
        pairs.push_back(l.front());
        l.erase(l.begin());
    }

    while (!r.empty()) {
        pairs.push_back(r.front());
        r.erase(r.begin());
    }
}

static void sortIntoMainChainV(std::vector<int> &mainChain, std::vector<std::pair<int, int> > &pairs, int tail) {
    std::vector<int> waitList;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        mainChain.push_back(it->first);
        waitList.push_back(it->second);
    }

    if (tail != -1)
        waitList.push_back(tail);

    mainChain.insert(mainChain.begin(), waitList.front());
    std::vector<int> order = getIndexOrderV(waitList.size() - 1);

    if (order.empty())
        return ;

    for (std::vector<int>::iterator it_o = order.begin(); it_o != order.end(); ++it_o) {
        std::vector<int>::iterator it_w = waitList.begin();
        std::advance(it_w, *it_o);
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), *it_w);
        mainChain.insert(pos, *it_w);
    }

}

static std::vector<int> sortV(std::vector<int> sequence) {
    if (sequence.size() <= 1)
        return (sequence);

    int tail = -1;
    if (sequence.size() % 2 != 0) {
        tail = sequence.back();
        sequence.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    collectPairsV(sequence, pairs);

    sortPairsMergeInsertionV(pairs, pairs.size());

    std::vector<int> sorted;
    sortIntoMainChainV(sorted, pairs, tail);

    return (sorted);
}


void PmergeMe::runV(int ac, char **av) {
    clock_t             start = clock();
    clock_t             end;
    std::vector<int>    sequence;

    for (int i = 1; i < ac; i++)
        sequence.push_back(std::atoi(av[i]));
    _v = sortV(sequence);
    end = clock();

    _vTime = double(end - start) / CLOCKS_PER_SEC;
}

// ========== DEQUE ===========

static std::deque<int> getIndexOrderD(size_t size) {
    std::deque<int> order;

    if (size < 1)
        return order;

    int jac = 2;
    int next = getJacobsthal(jac++);

    while (next < static_cast<int>(size)) {
        order.push_back(next);
        next = getJacobsthal(jac++);
    }

    next = size;
    while (order.size() < size) {
        if (std::find(order.begin(), order.end(), next) == order.end())
            order.push_back(next);
        next--;
    }

    return (order);
}

static void collectPairsD(std::deque<int> &sequence, std::deque<std::pair<int, int> > &pairs) {
    for (std::deque<int>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
        int a = *it;
        if (++it == sequence.end()) 
            break;
        int b = *it;
        if (a < b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }
}

static void sortPairsMergeInsertionD(std::deque<std::pair<int, int> > &pairs, size_t size) {
    if (size <= 1)
        return ;

    std::deque<std::pair<int, int> > l;
    std::deque<std::pair<int, int> > r;
    std::deque<std::pair<int, int> >::iterator it = pairs.begin();

    for (size_t i = 0; i < size / 2; i++)
        l.push_back(*it++);
    for (size_t i = size / 2; i < size; i++)
        r.push_back(*it++);

    pairs.clear();

    sortPairsMergeInsertionD(l, l.size());
    sortPairsMergeInsertionD(r, r.size());

    while (!r.empty() && !l.empty()) {
        if (l.front().first < r.front().first) {
            pairs.push_back(l.front());
            l.erase(l.begin());
        } else {
            pairs.push_back(r.front());
            r.erase(r.begin());
        }
    }

    while (!l.empty()) {
        pairs.push_back(l.front());
        l.erase(l.begin());
    }

    while (!r.empty()) {
        pairs.push_back(r.front());
        r.erase(r.begin());
    }
}

static void sortIntoMainChainD(std::deque<int> &mainChain, std::deque<std::pair<int, int> > &pairs, int tail) {
    std::deque<int> waitList;
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        mainChain.push_back(it->first);
        waitList.push_back(it->second);
    }

    if (tail != -1)
        waitList.push_back(tail);

    mainChain.insert(mainChain.begin(), waitList.front());
    std::deque<int> order = getIndexOrderD(waitList.size() - 1);

    if (order.empty())
        return ;

    for (std::deque<int>::iterator it_o = order.begin(); it_o != order.end(); ++it_o) {
        std::deque<int>::iterator it_w = waitList.begin();
        std::advance(it_w, *it_o);
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), *it_w);
        mainChain.insert(pos, *it_w);
    }

}

static std::deque<int> sortD(std::deque<int> sequence) {
    if (sequence.size() <= 1)
        return (sequence);

    int tail = -1;
    if (sequence.size() % 2 != 0) {
        tail = sequence.back();
        sequence.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    collectPairsD(sequence, pairs);

    sortPairsMergeInsertionD(pairs, pairs.size());

    std::deque<int> sorted;
    sortIntoMainChainD(sorted, pairs, tail);

    return (sorted);
}


void PmergeMe::runD(int ac, char **av) {
    clock_t             start = clock();
    clock_t             end;
    std::deque<int>     sequence;

    for (int i = 1; i < ac; i++)
        sequence.push_back(std::atoi(av[i]));
    _d = sortD(sequence);
    end = clock();

    _dTime = double(end - start) / CLOCKS_PER_SEC;
}

// ========== RUN =============

void PmergeMe::run(int ac, char **av) {
    runV(ac, av);
    runD(ac, av);
    showResults(ac, av);
}
