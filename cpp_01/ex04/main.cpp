/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:12:03 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/21 17:21:29 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "replacer.hpp"

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cout 	<< "Nice try! Do it like this: "
					<< argv[0]
                  	<< " <filename> <s1> <s2>\n";
        return 1;
    }
    const std::string filename = argv[1];
    const std::string s1       = argv[2];
    const std::string s2       = argv[3];
    if (s1.empty()) {
        std::cerr << "Error: search string (s1) must not be empty\n";
        return 1;
    }
    std::ifstream ifs(filename.c_str());
    if (!ifs) {
        std::cerr << "Error: cannot open input file '"
                  << filename << "'\n";
        return 1;
    }
    const std::string outName = filename + ".replace";
    std::ofstream ofs(outName.c_str());
    if (!ofs) {
        std::cerr << "Error: cannot create output file '"
                  << outName << "'\n";
        return 1;
    }
    // Read entire file into single string
    std::ostringstream buffer;
    buffer << ifs.rdbuf();
    const std::string content = buffer.str();
    // replace all occurrences of s1 with s2
    const std::string result = replaceAll(content, s1, s2);
    ofs << result;
    return 0;
}
