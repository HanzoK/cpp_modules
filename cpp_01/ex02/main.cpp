/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:44:11 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/25 21:04:39 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout	<< std::endl << "Memory addresses of:" << std::endl << std::endl
				<< "string variable: " << &str << std::endl
				<< "stringPTR:       " << stringPTR << std::endl
				<< "stringREF:       " << &stringREF << std::endl << std::endl;

	std::cout	<< "Value of:" << std::endl << std::endl
				<< "string variable: " << str << std::endl
				<< "stringPTR:       " << *stringPTR << std::endl
				<< "stringREF:       " << stringREF << std::endl;
	return 0;
}
