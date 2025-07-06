/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:54:48 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/03 19:33:17 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string& first_name) {
	(*this).first_name = first_name;
}

void	Contact::setLastName(std::string& last_name) {
	this->last_name = last_name;
}

void	Contact::setNickname(std::string& nick_name) {
	(*this).nick_name = nick_name;
}

void	Contact::setPhoneNumber(std::string& phone_number) {
	this->phone_number = phone_number;
}

void	Contact::setDarkestSecret(std::string& darkest_secret) {
	(*this).darkest_secret = darkest_secret;
}

const std::string& Contact::getFirstName() const {
	return this->first_name;
}

const std::string& Contact::getLastName() const {
	return (*this).last_name;
}

const std::string& Contact::getNickName() const {
	return this->nick_name;
}

const std::string& Contact::getPhoneNumber() const {
	return (*this).phone_number;
}

const std::string& Contact::getDarkestSecret() const {
	return darkest_secret;
}

