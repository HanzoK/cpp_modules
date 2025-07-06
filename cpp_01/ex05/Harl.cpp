/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:23:27 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/27 17:38:33 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

HarlLevel::HarlLevel(const std::string& status, void (Harl::*handler)()) :
	status(status), handler(handler) {}

void	Harl::complain(std::string level) {
	HarlLevel levels[] = {
		HarlLevel("DEBUG", &Harl::debug),
		HarlLevel("INFO", &Harl::info),
		HarlLevel("WARNING", &Harl::warning),
		HarlLevel("ERROR", &Harl::error)
	};

	for (int i = 0; i < 4; i++) {
		if (levels[i].status == level) {
			(this->*(levels[i].handler))();
			return;
		}
	}
	std::cout << "What kind of level is this?!" << level << std::endl;
}

void	Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
