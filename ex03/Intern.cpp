/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:43:12 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/21 14:17:36 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char* Intern::InvalidFormException ::what() const throw()
{
	return ("Intern cannot create because it is not a valid Form");
}

Intern::Intern()
{
    std::cout << "Intern parametric constructor called." << std::endl;
}

Intern::Intern::Intern (const Intern &object)
{
    *this = object;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &object)
{
    (void) object;
    std::cout << "Intern copy assignment operator called." << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called." << std::endl;
}

AForm *makeShrubberyCreationForm(std::string target)
{
    return(new ShrubberyCreationForm(target));
}

AForm *makeRobotomyRequestForm(std::string target)
{
    return(new RobotomyRequestForm(target));
}

AForm *makePresidentialPardonForm(std::string target)
{
    return(new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    //declares an array of function pointers that takes std::string argument(refer ex06 in module01)
    AForm *(*fnForm[3])(std::string) = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
    int type;

    // Make an array of all possible forms
    const std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    type = 0;
    try
    {
        while (type < 3 && form[type].compare(formName))
	    	type++;
        if (type == 3)
			throw (Intern::InvalidFormException());
        std::cout << BOLDBLUE << "Intern creates " << formName << " form" << RESET << std::endl;
        return ((fnForm[type])(target));
    }
    catch(const std::exception& e)
    {
        std::cerr << BOLDBLUE << e.what() << RESET << '\n';
    }
    return (NULL);
}