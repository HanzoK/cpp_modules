/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:23:19 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/27 17:09:58 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl Harl1;

	if (argc < 2)
	{
		std::cout << "input needed." << std::endl;
		return 1;
	}
	else if (argc > 2)
	{
		std::cout << "Only 1 argument please." << std::endl;
		return 1;
	}
	Harl1.complain(argv[1]);
	return 0;
}
