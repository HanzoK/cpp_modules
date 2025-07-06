/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:26:45 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/24 14:30:51 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		for (size_t j = 0; j < str.length(); j++) {
				if (static_cast<unsigned char>(str[j]) > 127)
				{
					std::cout << "Nice try. But no non-ASCIIs accepted." << std::endl;
					return 1;
				}
				str[j] = std::toupper(str[j]);
		}
		std::cout << str;
	}
	std::cout << std::endl;
	return 0;
}
