/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:23:23 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/27 15:02:51 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl {
public:
	Harl();
	~Harl();

	void	complain(std::string level);

private:
	void	debug(void);
	void	info (void);
	void	warning(void);
	void	error(void);
} ;

struct HarlLevel {
	const std::string& status;
	void (Harl::*handler)();

	HarlLevel(const std::string& status, void (Harl::*handler)());
} ;
