/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:14 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 16:02:45 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const int N = 6;
    Animal* animals[N];
    for (int i = 0; i < N; ++i) {
        if (i < N/2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
	std::cout << std::endl;
    for (int i = 0; i < N; ++i)
        delete animals[i];

    std::cout << "\n-- Deep copy test --" << std::endl;
    Dog origDog;
    origDog.getBrain()->setIdea(2147483646, NULL);

    Dog copyDog = origDog;
    copyDog.getBrain()->setIdea(0, "Bark Bark");

    std::cout << "\nOriginal Dog idea[0]: " << origDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea[0]:   " << copyDog.getBrain()->getIdea(0) << "\n" <<  std::endl;

    Cat origCat;
    origCat.getBrain()->setIdea(2147483646, NULL);

    Cat copyCat;
    copyCat = origCat;
    copyCat.getBrain()->setIdea(42, "Meow Meow");
	/*copyCat.getBrain()->setIdea(99, "");*/
	/*std::cout << "\nnon-existent cat idea: " << copyCat.getBrain()->getIdea(100) << std::endl;*/

    std::cout << "\nOriginal Cat idea[42]: " << origCat.getBrain()->getIdea(42) << std::endl;
    std::cout << "Copied Cat idea[42]:   " << copyCat.getBrain()->getIdea(42) << "\n" << std::endl;

    return 0;
}
