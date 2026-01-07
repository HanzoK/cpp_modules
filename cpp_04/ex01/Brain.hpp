/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:58:00 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 15:51:53 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain {
public:
Brain();
    Brain(const Brain& copy);
    Brain& operator=(const Brain& copy);
    ~Brain();

    std::string getIdea(int idx) const;
    void setIdea(int idx, const std::string& idea);
	void setIdea(int idx, const char* cstr);

private:
    std::string ideas[100];	
};
