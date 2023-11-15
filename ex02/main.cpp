/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:36:52 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/15 16:50:06 by zsyyida          ###   ########.fr       */
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
	std::cout << "[WHEN CAN EXECUTE SHRUBBERY CREATION]" << std::endl;
	try
	{
		Bureaucrat Z("Cindy", 5);
		ShrubberyCreationForm A("Home");
		std::cout << A << std::endl;
		A.beSigned(Z);
		A.execute(Z);
		std::cout << A << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "[WHEN CAN EXECUTE PRESIDENTIAL PARDON]" << std::endl;
	try
	{
		Bureaucrat Y("Lawrence", 5);
		PresidentialPardonForm B("Murder");
		std::cout << B << std::endl;
		B.beSigned(Y);
		B.execute(Y);
		std::cout << B << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "[WHEN CAN EXECUTE ROBOTOMY REQUEST]" << std::endl;
	try
	{
		Bureaucrat X("Patrick", 5);
		RobotomyRequestForm C("Droid");
		std::cout << C << std::endl;
		C.beSigned(X);
		C.execute(X);
		std::cout << C << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
// 	std::cout << "[WHEN CAN'T SIGN]" << std::endl;
// 	try
// 	{
// 		Bureaucrat Y("Ralph", 15);
// 		Form B("Termination", false, 14, 50);
// 		std::cout << B << std::endl;
// 		B.beSigned(Y);
// 		std::cout << B << std::endl;

// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Form Error: " << e.what() << '\n';
// 	}
// 	std::cout << "[WHEN OUT OF BOUNDS]" << std::endl;
// 	try
// 	{
// 		Bureaucrat X("Jessica", 15);
// 		Form C("Complaint", false, 155, 500);
// 		std::cout << C << std::endl;
// 		C.beSigned(X);
// 		std::cout << C << std::endl;

// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Form Error: " << e.what() << '\n';
// 	}

// 	try
// 	{
// 		Bureaucrat W("Jessica", 15);
// 		Form D("Complaint", false, 0, 50);
// 		std::cout << D << std::endl;
// 		D.beSigned(W);
// 		std::cout << D << std::endl;

// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Form Error: " << e.what() << '\n';
// 	}
// 	return 0;
}