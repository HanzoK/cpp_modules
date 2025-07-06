/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:07:29 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/27 20:12:14 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv) {
	Harl harlFilter;
	
	if (argc < 2 || argc > 2 || argc == 1) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}
	if (argv[1] != std::string("DEBUG") &&
		argv[1] != std::string("INFO") &&
		argv[1] != std::string("WARNING") &&
		argv[1] != std::string("ERROR")) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	harlFilter.complain(argv[1]);
	return 0;
}
