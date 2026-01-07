/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:14 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 15:41:21 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* beast = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output cat sound
	j->makeSound();
	beast->makeSound();

	delete i;
	delete j;
	delete beast;
	return 0;
}

/*int main()*/
/*{*/
/*    std::cout << "-- Correct polymorphism --" << std::endl;*/
/*    const Animal* beast = new Animal();*/
/*    const Animal* j = new Dog();*/
/*    const Animal* i = new Cat();*/
/*    std::cout << j->getType() << " \n";*/
/*    std::cout << i->getType() << " \n";*/
/*    i->makeSound(); // cat sound*/
/*    j->makeSound(); // dog sound*/
/*    beast->makeSound();*/
/*    delete beast;*/
/*    delete j;*/
/*    delete i;*/
/**/
/*    std::cout << "\n-- Without virtual (Wrong) --" << std::endl;*/
/*    const WrongAnimal* wrongbeast = new WrongAnimal();*/
/*    const WrongAnimal* wrongcat = new WrongCat();*/
/*    std::cout << wrongcat->getType() << " \n";*/
/*    wrongcat->makeSound(); // wrong animal sound, not WrongCat*/
/*    wrongbeast->makeSound();*/
/**/
/*    delete wrongcat;*/
/*	delete wrongbeast;*/
/**/
/*    return 0;*/
/*}*/
/**/
