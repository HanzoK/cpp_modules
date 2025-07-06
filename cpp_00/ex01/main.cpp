/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:05:14 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/26 14:18:53 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main() {
    PhoneBook phonebook;
    std::string command;
    std::cout << "Greetings, mortal! Welcome to the PhoneBook of DoOooOOooooom!\n";
    while (std::cin) {
        std::cout << "\nChoose between these commands: ADD, SEARCH, EXIT\n";
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD") {
            Contact newContact;
            std::string input;

            std::cout << "Enter your first name, mortal: ";
            std::getline(std::cin, input);
			if (input.empty()) {
				std::cout << "Your parents never gave you a first name? Now that's a first. HAH!\n";
				continue;
			}
            newContact.setFirstName(input);

            std::cout << "Now the last name: ";
            std::getline(std::cin, input);
			if (input.empty()) {
				std::cout << "Humans are always given a last name. What are you trying to pull off here?\n";
				continue;
			}
            newContact.setLastName(input);

            std::cout << "Got a nickname?: ";
            std::getline(std::cin, input);
			if (input.empty()) {
				std::cout << "Poor you. You must not have been popular if nobody gave you a nickname...\n";
				continue;
			}
            newContact.setNickname(input);

            std::cout << "Give me your phone number: ";
            std::getline(std::cin, input);
			if (input.empty()) {
				std::cout << "You don't have a phone? Have you been hiding under a rock?\n";
				continue;
			}
            newContact.setPhoneNumber(input);

            std::cout << "Lastly, what is your darkest, most untold secret?: ";
            std::getline(std::cin, input);
			if (input.empty()) {
				std::cout << "That's fine. Keep your secrets for yourself. I'll keep this phonebook to myself.\n";
				continue;
			}
            newContact.setDarkestSecret(input);

            phonebook.addContact(newContact);
            std::cout << "A new victim has been created! Welcome to Hell!\n";
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            std::cout << "We will see each other soon enough again... *evil laugh*\n";
            break;
        } else if (command.empty()) {
            continue;
        } else {
            std::cout << "What are you trying to do? You can't cheat death!\n";
        }
    }
    return 0;
}
