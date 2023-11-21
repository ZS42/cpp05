/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:43:12 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/21 11:19:54 by zsyyida          ###   ########.fr       */
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
    return(new ShrubberyCreationForm(target));
}

AForm *makePresidentialPardonForm(std::string target)
{
    return(new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target) 
{
    //declares an array of function pointers that takes std::string argument(refer ex06 in module01)
    AForm *(*fnForm[3])(std::string) = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
    int type;

    // Make an array of all possible forms
    const std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    // Since switch statements only work with integers we need to convert the input strings to integers
    type = 0;
    try
    {
        while (type < 3 && form[type].compare(formName))
	    	type++;
        std::cout << "Intern creates " << formName << std::endl;
        return ((fnForm[type])(target));
        if (type == 2)
			throw (Intern::InvalidFormException());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // while (type < 3 && form[type].compare(formName))
    // {
	// 	type++;
    //     std::cout << "Intern creates " << formName << std::endl;
    //     return ((fnForm[type])(target));
    // }
    // try
    // {
    //     std::cout << "Intern creates " << formName << std::endl;
    //     switch (type)
    //     {
    //         case 0:
    //             fnForm[0] = &makeShrubberyCreationForm(target);
    //         case 1:
    //             fnForm[1] = makeRobotomyRequestForm(target);
    //         case 2:
    //             fnForm[2] = makePresidentialPardonForm(target);
    //     }
    //     if (i == 2)
	// 			throw (Intern::InvalidFormException());
    // }            
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // return ((fnForm[type])(target));
}