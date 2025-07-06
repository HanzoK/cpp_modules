/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:14:24 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/21 17:17:17 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

std::string replaceAll(const std::string& str,
                       const std::string& from,
                       const std::string& to)
{
    std::string result;
    std::size_t lastPos = 0;
    std::size_t pos;
    while ((pos = str.find(from, lastPos)) != std::string::npos) {
        // substring from last position to current position and append to result
        result.append(str.substr(lastPos, pos - lastPos));
        // append replacement
        result.append(to);
        // update last position
        lastPos = pos + from.length();
    }
    // append the remaining part of the string
    result.append(str.substr(lastPos));
    return result;
}
