/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:01:06 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 16:31:56 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        materias[i] = NULL;
    std::cout << "[MateriaSource] constructed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i) {
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = NULL;
    }
    std::cout << "[MateriaSource] copy-constructed" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "[MateriaSource] assigned" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete materias[i];
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
	    	    materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete materias[i];
    std::cout << "[MateriaSource] destructed" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) 
		return;
    for (int i = 0; i < 4; ++i) {
        if (!materias[i]) {
            materias[i] = m->clone();
			delete m;
            /*std::cout << "[MateriaSource] learned " << m->getType() << std::endl;*/
            return ;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	if (type.empty()) {
		std::cout << "...You want to equip a nothing? Well, you do you." << std::endl;
		return 0;
	}
    for (int i = 0; i < 4; ++i) {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return 0;
}
