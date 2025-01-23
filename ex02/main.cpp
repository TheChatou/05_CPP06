/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:26 by fcoullou          #+#    #+#             */
/*   Updated: 2025/01/23 17:44:53 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base_class.hpp"
#include "A_class.hpp"
#include "B_class.hpp"
#include "C_class.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>

#define	RAND_NB	6

Base*		generate(void)
{
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return NULL;
}

void		identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << CYAN << "* : \t[ A ]" << RESET;
	else if (dynamic_cast<B*>(p))
		std::cout << YELLOW << "* : \t[ B ]" << RESET;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "* : \t[ C ]" << RESET;
	else
		std::cerr << RED << "Houston, we have a problem !" << RESET;
		
	std::cout << std::endl;
}

//	ONE-LINE VERSION //////////////////////////////////////////////////////////////////////
void		identify(Base &p)
{
	try { A a = dynamic_cast<A&>(p); std::cout << CYAN << "& : \t[ A ]" << RESET << std::endl; return; }
	catch ( const std::exception &e) { std::cout << RED_STRIKE  << "\t| A |" << RESET << std::endl; }

	try { B b = dynamic_cast<B&>(p); std::cout << YELLOW << "& : \t[ B ]" << RESET << std::endl; return; }
	catch ( const std::exception &e) { std::cout << RED_STRIKE  << "\t| B |" << RESET << std::endl; }
	
	try { C c = dynamic_cast<C&>(p); std::cout << GREEN << "& : \t[ C ]" << RESET << std::endl; return; }
	catch ( const std::exception &e) { std::cout << RED_STRIKE  << "\t| C |" << RESET << std::endl; }
}

//	MULTI-LINE VERSION /////////////////////////////////////////////////////////////////////
// void		identify(Base &p)
// {
// 	try
// 	{
// 		A a = dynamic_cast<A&>(p);
// 		std::cout << CYAN << "& : \t[ A ]" << RESET << std::endl;
// 		return;
// 	}
// 	catch ( const std::exception &e)
// 	{
// 		std::cout << RED_STRIKE  << "\t| A |" << RESET << std::endl;
// 	}

// 	try
// 	{
// 		B b = dynamic_cast<B&>(p);
// 		std::cout << YELLOW << "& : \t[ B ]" << RESET << std::endl;
// 		return;
// 	}
// 	catch ( const std::exception &e)
// 	{
// 		std::cout << RED_STRIKE  << "\t| B |" << RESET << std::endl;
// 	}
	
// 	try
// 	{
// 		C c = dynamic_cast<C&>(p);
// 		std::cout << GREEN << "& : \t[ C ]" << RESET << std::endl;
// 		return;
// 	}
// 	catch ( const std::exception &e)
// 	{
// 		std::cout << RED_STRIKE  << "\t| C |" << RESET << std::endl;
// 	}
// }

int	main()
{
    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires avec l'heure actuelle

	Base	*bases[RAND_NB];

	for (int i = 0; i < RAND_NB; i++)
	{
		bases[i] = generate();
		identify(bases[i]);
		identify(*bases[i]);
		std::cout << std::endl;
	}	
	return 0;
};