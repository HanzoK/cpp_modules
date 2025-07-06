/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:56:02 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/03 18:08:55 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();

	void addContact(const Contact& contact);
	void searchContact() const;
	void clearContacts();

private:
	Contact contacts[8];
	int contactIndex;
	int totalContacts;
};
