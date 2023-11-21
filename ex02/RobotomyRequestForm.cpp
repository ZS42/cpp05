/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:28:30 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/21 13:58:10 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", false, 72, 45)
{
	_target = target;
	std::cout << "RobotomyRequestForm parametric constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &object): AForm("Robotomy Request Form", false, 72, 45)
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
	executor.executeForm(*this);
    if (canExecute(executor))
	{
    	srand(time(NULL));
		std::cout << "some drilling noises" << std:: endl;
    	int i = std::rand();
    	if (i % 2 == 0)
    	    std::cout << RED << _target << " has been robotomised" << RESET << std::endl;
    	else
    	    std::cout << RED << _target << " robotomy failed" << RESET << std::endl;
	}
}

std::string RobotomyRequestForm::getTarget() const
{
	return(_target);
}