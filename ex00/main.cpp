/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:36:52 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/08 09:48:35 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat A("Ahmed", 1);
	std::cout << A << std::endl;
	A.incrementGrade();
	std::cout << A << std::endl;
	Bureaucrat B("Katniss", 150);
	std::cout << B << std::endl;
	B.decrementGrade();
	std::cout << B << std::endl;
	Bureaucrat C("Zaheer", 100);
	std::cout << C << std::endl;
	C.incrementGrade();
	std::cout << C << std::endl;
	C.decrementGrade();
	std::cout << C << std::endl;
	return 0;
}