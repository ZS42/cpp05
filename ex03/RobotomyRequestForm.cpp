/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:28:30 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/19 20:24:05 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", false, 72, 45)
{
	_target = target;
	std::cout << "RobotomyRequestForm parametric constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &object)
{
	*this = object;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &object)
{
	if (this != &object)
	{
		this->_target = object._target;
	}
	std::cout << "RobotomyRequestForm copy assignment operator called." << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    std::cout << "some drilling noises" << std:: endl;
    srand(time(NULL));
    int i = std::rand();
    if (i % 2 == 0)
        std::cout << RED << _target << " has been robotomised" << RESET << std::endl;
    else
        std::cout << RED << _target << " robotomy failed" << RESET << std::endl;
    executor.executeForm(*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return(_target);
}