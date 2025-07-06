/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:07:34 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/27 19:49:49 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

enum HarlStatus {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
} ;

class Harl {

public:
	Harl();
	~Harl();

	void	complain(std::string level);	

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
} ;

struct HarlLevel {
	const std::string& status;

	HarlLevel(const std::string& status);
} ;
