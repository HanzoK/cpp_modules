/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:04:01 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 16:38:26 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/*int main() {*/
/*    IMateriaSource* src = new MateriaSource();*/
/*    src->learnMateria(new Ice());*/
/*    src->learnMateria(new Cure());*/
/**/
/*    ICharacter* me = new Character("me");*/
/*    AMateria* tmp;*/
/*    tmp = src->createMateria("ice");*/
/*    me->equip(tmp);*/
/*    tmp = src->createMateria("cure");*/
/*    me->equip(tmp);*/
/**/
/*    ICharacter* bob = new Character("bob");*/
/*    me->use(0, *bob);*/
/*    me->use(1, *bob);*/
/**/
/*    me->unequip(0);*/
/*    me->use(0, *bob); // should do nothing*/
/*    delete bob;*/
/*    delete me;*/
/*    delete src;*/
/*    return 0;*/
/*}*/

static void section(const char* t){ 
	std::cout << "\n== " << t << " ==\n"; 
}

int main() {
    section("1) Interfaces + cloning (subject sample)");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());   // learns template (stores a clone)
    src->learnMateria(new Cure());  // learns template (stores a clone)

    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    // create from class blueprints and equip
    me->equip(src->createMateria("ice"));   // slot 0
    me->equip(src->createMateria("cure"));  // slot 1

    // exact subject output (2 lines)
	std::cout << "\n";
    me->use(0, *bob); // * shoots an ice bolt at bob *
    me->use(1, *bob); // * heals bob's wounds *

    section("2) unequip() does NOT delete (later use on that slot is invalid)");
    me->unequip(0);        
    me->use(0, *bob);      // no output (slot now empty)
    me->use(1, *bob);      // cure should still work

    section("3) Deep copy (copy-ctor) — independent inventories");
    Character alice("Alice");
    alice.equip(src->createMateria("ice"));
    alice.equip(src->createMateria("cure"));

    Character aliceCopy(alice);  // deep copy

    Character tgtA("tA"), tgtB("tB");
	std::cout << "\n";
    std::cout << "[Alice]\n";
    alice.use(0, tgtA); // ice
    alice.use(1, tgtA); // cure
	std::cout << "\n";
    std::cout << "[AliceCopy]\n";
    aliceCopy.use(0, tgtB); // ice
    aliceCopy.use(1, tgtB); // cure

    // change original class; copy must stay unchanged
    alice.unequip(0);
	std::cout << "\n";
    std::cout << "[Alice after unequip(0)]\n";
    alice.use(0, tgtA); // no output
    alice.use(1, tgtA); // cure
	std::cout << "\n";
    std::cout << "[AliceCopy unchanged]\n";
    aliceCopy.use(0, tgtB); // ice
    aliceCopy.use(1, tgtB); // cure

    // cleanup
    delete bob;
    delete me;
    delete src;
    return 0;
}
