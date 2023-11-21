/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:36:52 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/19 21:11:51 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// never put try catch block in constructor or may have leaks
// must put in main here so that if catch is called by throw in
// constructor it isn't constructed
int main()
{
	std::cout << BOLDGREEN << "[WHEN CAN EXECUTE SHRUBBERY CREATION]" << RESET << std::endl;
	try
	{
		Bureaucrat Z("Cindy", 5);
		ShrubberyCreationForm A("Home");
		std::cout << BLUE << A << RESET << std::endl;
		A.beSigned(Z);
		A.execute(Z);
		std::cout << BLUE << A << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << BOLDGREEN << "[WHEN CAN'T EXECUTE SHRUBBERY CREATION]" << RESET << std::endl;
	try
	{
		Bureaucrat Z("Candy", 138);
		ShrubberyCreationForm A("Home");
		std::cout << BLUE << A << RESET << std::endl;
		A.beSigned(Z);
		A.execute(Z);
		std::cout << BLUE << A << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << BOLDGREEN << "[WHEN CAN EXECUTE PRESIDENTIAL PARDON]" << RESET << std::endl;
	try
	{
		Bureaucrat Y("Lawrence", 5);
		PresidentialPardonForm B("Murder");
		std::cout << BLUE << B << RESET << std::endl;
		B.beSigned(Y);
		B.execute(Y);
		std::cout << BLUE << B << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << BOLDGREEN << "[WHEN CAN'T EXECUTE PRESIDENTIAL PARDON]" << RESET << std::endl;
	try
	{
		Bureaucrat Y("Larry", 6);
		PresidentialPardonForm B("Murder");
		std::cout << BLUE << B << RESET << std::endl;
		B.beSigned(Y);
		B.execute(Y);
		std::cout << BLUE << B << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	std::cout << BOLDGREEN << "[WHEN CAN EXECUTE ROBOTOMY REQUEST]" << RESET << std::endl;
	try
	{
		Bureaucrat X("Patrick", 5);
		RobotomyRequestForm C("Droid");
		std::cout << BLUE << C << RESET << std::endl;
		C.beSigned(X);
		C.execute(X);
		std::cout << BLUE << C << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << BOLDGREEN << "[WHEN CAN'T EXECUTE ROBOTOMY REQUEST]" << RESET << std::endl;
	try
	{
		Bureaucrat X("Patricia", 46);
		RobotomyRequestForm C("Droid");
		std::cout << BLUE << C << RESET << std::endl;
		C.beSigned(X);
		C.execute(X);
		std::cout << BLUE << C << RESET << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

}