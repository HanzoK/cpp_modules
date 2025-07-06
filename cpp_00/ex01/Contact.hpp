/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:54:33 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/25 21:40:26 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact {
public:

	//Setters
	void setFirstName(std::string& first_name);
	void setLastName(std::string& last_name);
	void setNickname(std::string& nick_name);
	void setPhoneNumber(std::string& phone_number);
	void setDarkestSecret(std::string& darkest_secret);

	//Getters
	const std::string& getFirstName() const ;
	const std::string& getLastName() const ;
	const std::string& getNickName() const ;
	const std::string& getPhoneNumber() const ;
	const std::string& getDarkestSecret() const ;

private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
} ;

