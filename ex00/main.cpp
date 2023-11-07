/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:36:52 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/07 13:52:20 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat("Ahmed", 0);
	Bureaucrat("Katniss", 100);
	Bureaucrat("Zaheer", 158);
	// try
	// {
	// 	throw (0);
	// }

	// catch (const Bureaucrat::GradeTooHighException& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	// catch (const Bureaucrat::GradeTooLowException& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	// try
	// {
	// 	Bureaucrat("Ahmed", 100);
	// 	throw (100);
	// }

	// catch (const Bureaucrat::GradeTooHighException& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	// catch (const Bureaucrat::GradeTooLowException& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	// try
	// {
	// 	Bureaucrat("Ahmed", 158);
	// 	throw (158);
	// }

	// catch (const Bureaucrat::GradeTooHighException& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	// catch (const Bureaucrat::GradeTooLowException& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }
	return 0;
}