/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:52:14 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 16:11:59 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

  int main() {
   // const Animal* a = new Animal(); // <-- cannot instantiate abstract class

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
    delete dog;
    delete cat;
    return 0;
/*int main() {*/
/*    const int N = 6;*/
/*    Animal* animals[N];*/
/*    // half Dogs, half Cats*/
/*    for (int i = 0; i < N; ++i) {*/
/*        if (i < N/2)*/
/*            animals[i] = new Dog();*/
/*        else*/
/*            animals[i] = new Cat();*/
/*    }*/
/*    // clean up*/
/*    for (int i = 0; i < N; ++i)*/
/*        delete animals[i];*/
/**/
/*    std::cout << "\n-- Deep copy test --" << std::endl;*/
/*    Dog origDog;*/
/*    origDog.getBrain()->setIdea(0, "Chase cats");*/
/**/
/*    Dog copyDog = origDog;*/
/*    copyDog.getBrain()->setIdea(0, "Eat bone");*/
/**/
/*    std::cout << "Original Dog idea[0]: " << origDog.getBrain()->getIdea(0) << std::endl;*/
/*    std::cout << "Copied Dog idea[0]:   " << copyDog.getBrain()->getIdea(0) << std::endl;*/
/**/
/*    Cat origCat;*/
/*    origCat.getBrain()->setIdea(42, "Climb tree");*/
/**/
/*    Cat copyCat;*/
/*    copyCat = origCat;*/
/*    copyCat.getBrain()->setIdea(42, "Sleep all day");*/
/**/
/*    std::cout << "Original Cat idea[42]: " << origCat.getBrain()->getIdea(42) << std::endl;*/
/*    std::cout << "Copied Cat idea[42]:   " << copyCat.getBrain()->getIdea(42) << std::endl;*/
/**/
/*    return 0;*/
/*}*/
