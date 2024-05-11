/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:24:59 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/13 14:27:24 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) : vec_time(0), list_time(0)
{
    if (ac < 2)
    {
        std::cerr << "Error: Missing input sequence" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < ac; ++i)
    {
        std::istringstream iss(av[i]);
        int num;
        if (!(iss >> num) || num <= 0)
        {
            std::cerr << "Error: Input sequence contains non-positive integer(s) or characters" << std::endl;
            exit(EXIT_FAILURE);
        }
        vec_container.push_back(num);
        list_container.push_back(num);
    }
}

PmergeMe::PmergeMe(const PmergeMe &other) : vec_container(other.vec_container), list_container(other.list_container), vec_time(other.vec_time), list_time(other.list_time) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &Other)
{
    if (this != &Other)
    {
        vec_container = Other.vec_container;
        list_container = Other.list_container;
        vec_time = Other.vec_time;
        list_time = Other.list_time;
    }
    return *this;
}

void PmergeMe::run()
{
    std::cout << "Before: ";
    displaySequence(vec_container);

    clock_t start_vec = clock();
    fordJohnsonSortVector(); // Utilizziamo l'algoritmo Ford-Johnson per std::vector
    mergeInsertSortVector(); // Eseguiamo il merge-insert sort
    clock_t end_vec = clock();
    vec_time = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

    clock_t start_list = clock();
    fordJohnsonSortList();   // Utilizziamo l'algoritmo Ford-Johnson per std::list
    mergeInsertSortList();   // Eseguiamo il merge-insert sort
    clock_t end_list = clock();
    list_time = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    displaySequence(vec_container);

    std::cout << "Time to process a range of " << vec_container.size() << " elements with std::vector: ";
    displayTimeDifference(vec_time);
    std::cout << "Time to process a range of " << list_container.size() << " elements with std::list: ";
    displayTimeDifference(list_time);
}


void PmergeMe::displaySequence(const std::vector<int>& sequence)
{
    for (size_t i = 0; i < sequence.size(); ++i)
        std::cout << sequence[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::displaySequence(const std::list<int>& sequence) 
{
    for (std::list<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::displayTimeDifference(double elapsed_time_seconds)
{
    double elapsed_time_microseconds = elapsed_time_seconds * 1;
    std::cout.precision(6);
    std::cout << std::fixed << elapsed_time_microseconds << " microseconds" << std::endl;
}

void PmergeMe::mergeInsertSortVector()
{
    clock_t start = clock();
    std::sort(vec_container.begin(), vec_container.end());
    clock_t end = clock();
    vec_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::mergeInsertSortList()
{
    clock_t start = clock();
    list_container.sort();
    clock_t end = clock();
    list_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::fordJohnsonSortVector()
{
    sortAdjacent(vec_container);
}

void PmergeMe::fordJohnsonSortList()
{
    std::vector<int> temp(list_container.begin(), list_container.end());
    sortAdjacent(temp);
    list_container.assign(temp.begin(), temp.end());
}

void PmergeMe::sortAdjacent(std::vector<int>& sequence)
{
    for (size_t i = 0; i < sequence.size() - 1; i += 2) 
    {
        if (sequence[i] > sequence[i + 1]) 
            std::swap(sequence[i], sequence[i + 1]);
    }
}
