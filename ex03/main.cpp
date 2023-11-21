/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:36:52 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/21 14:09:49 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

// never put try catch block in constructor or may have leaks
// must put in main here so that if catch is called by throw in
// constructor it isn't constructed
int main()
{
	std::cout << BOLDGREEN << "[FOR ROBOTOMY REQUEST]" << RESET << std::endl;
	try
	{
		Intern someRandomIntern;
		Bureaucrat Z("Cindy", 5);
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << BOLDGREEN << "[FOR SHRUBBERY CREATION]" << RESET << std::endl;
	try
	{
		Intern anotherRandomIntern;
		Bureaucrat X("Calvin", 5);
		AForm* scf;
		scf = anotherRandomIntern.makeForm("shrubbery creation", "Blender");
		delete scf;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << BOLDGREEN << "[FOR PRESEDENTIAL PARDON]" << RESET << std::endl;
	try
	{
		Intern yetanotherRandomIntern;
		Bureaucrat W("Chris", 5);
		AForm* ppf;
		ppf = yetanotherRandomIntern.makeForm("presidential pardon", "Sender");
		delete ppf;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << BOLDGREEN << "[FOR NONEXISTENT REQUEST]" << RESET << std::endl;
	try
	{
		Intern otherRandomIntern;
		Bureaucrat Y("Candy", 5);
		AForm* nrf;
		nrf = otherRandomIntern.makeForm("nonexistent request", "Lender");
		delete nrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}