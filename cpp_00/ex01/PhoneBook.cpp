/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:54:13 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/25 21:01:00 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactIndex(0), totalContacts(0) {}
PhoneBook::~PhoneBook() {}

void printColumns(){
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|\n";
}

void printContacts(const Contact& contact)
{
	std::cout << "First Name: "    << contact.getFirstName()    << "\n";
	std::cout << "Last Name: "     << contact.getLastName()     << "\n";
	std::cout << "Nickname: "      << contact.getNickName()     << "\n";
	std::cout << "Phone Number: "  << contact.getPhoneNumber()  << "\n";
	std::cout << "Darkest Secret: "<< contact.getDarkestSecret()<< "\n";
}

void PhoneBook::addContact(const Contact& contact)
{
	contacts[contactIndex] = contact;
	contactIndex = (contactIndex + 1) % 8;
	if (totalContacts < 8)
		++totalContacts;
}

void PhoneBook::searchContact() const
{
	int idx;

	if (totalContacts == 0)
	{
		std::cout << "\nSeriously? Did you really try looking up something that doesn't exist?\n";
		return;
	}
	printColumns();
	for (int i = 0; i < totalContacts; ++i)
	{
		std::string first = contacts[i].getFirstName();
		std::string last = contacts[i].getLastName();
		std::string nick = contacts[i].getNickName();
		if (first.length() > 10) 
			first = first.substr(0, 9) + ".";
		if (last.length() > 10)
			last = last.substr(0, 9) + ".";
		if (nick.length() > 10)
			nick = nick.substr(0, 9) + ".";
		std::cout << "|";
	  	std::cout << std::setw(10) << i << "|";
	  	std::cout << std::setw(10) << first << "|";
		std::cout << std::setw(10) << last << "|";
		std::cout << std::setw(10) << nick << "|\n";
	}
    std::cout << "Enter index to choose your victim: ";
    if (!(std::cin >> idx) || idx < 0 || idx >= totalContacts)
	{
        std::cin.clear();
        std::cin.ignore(1028, '\n');
        std::cout << "Are you sure you know what you're doing, mortal? Try again.\n";
        return;
    }
    std::cin.ignore(1028, '\n');
    const Contact& contact = contacts[idx];
	printContacts(contact);
}

void PhoneBook::clearContacts()
{
    contactIndex = 0;
    totalContacts = 0;
}
