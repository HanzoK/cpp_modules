/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:57:46 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 16:00:39 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] implanted!" << std::endl;
}

Brain::Brain(const Brain& copy) {
    std::cout << "[Brain] duplicated!" << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = copy.ideas[i];
}

Brain& Brain::operator=(const Brain& copy) {
    std::cout << "[Brain] implanted!" << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 100; ++i)
            ideas[i] = copy.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] nuked!" << std::endl;
}

std::string Brain::getIdea(int idx) const {
    if (idx < 0 || idx >= 100) 
		return "Beep Boop! Invalid index.";
	if (ideas[idx].empty())
		return "Nothing to see here. Buddy";
    return ideas[idx];
}

void Brain::setIdea(int idx, const std::string& idea) {
    if (idx < 0 || idx >= 100) {	
		std::cout << "Beep Boop. Chose an index out of bounds. Shame on you." << std::endl;
		return;
	}
	if (idea.empty()) {
		ideas[idx] = "Head empty. No thoughts.";
		return;
	}
    ideas[idx] = idea;
}

void Brain::setIdea(int idx, const char* cstr) {
	if (cstr == NULL) {
		setIdea(idx, std::string(""));
	} else {
		setIdea(idx, std::string(cstr));
	}
}
