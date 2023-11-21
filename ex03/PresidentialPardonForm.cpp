/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:28:08 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/19 22:36:45 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon form", false, 25, 5)
{
	_target = target;
	std::cout << "PresidentialPardonForm parametric constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &object)
{
	*this = object;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &object)
{
	if (this != &object)
	{
		this->_target = object._target;
	}
	std::cout << "PresidentialPardonForm copy assignment operator called." << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (canExecute(executor) == true)
    {
	    executor.executeForm(*this);
        std::cout << RED << _target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl; 
    }
}

std::string PresidentialPardonForm::getTarget() const
{
	return(_target);
}