/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:36:52 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/10 10:41:05 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// never put try catch block in constructor or may have leaks
// must put in main here so that if catch is called by throw in
// constructor it isn't constructed
int main()
{
	std::cout << "[WHEN CAN SIGN]" << std::endl;
	try
	{
		Bureaucrat Z("Cindy", 5);
		Form A("Application", false, 20, 50);
		std::cout << A << std::endl;
		A.beSigned(Z);
		std::cout << A << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << "[WHEN CAN'T SIGN]" << std::endl;
	try
	{
		Bureaucrat Y("Ralph", 15);
		Form B("Termination", false, 14, 50);
		std::cout << B << std::endl;
		B.beSigned(Y);
		std::cout << B << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Form Error: " << e.what() << '\n';
	}
	std::cout << "[WHEN OUT OF BOUNDS]" << std::endl;
	try
	{
		Bureaucrat X("Jessica", 15);
		Form C("Complaint", false, 155, 500);
		std::cout << C << std::endl;
		C.beSigned(X);
		std::cout << C << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Form Error: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat W("Jessica", 15);
		Form D("Complaint", false, 0, 50);
		std::cout << D << std::endl;
		D.beSigned(W);
		std::cout << D << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Form Error: " << e.what() << '\n';
	}
	return 0;
}