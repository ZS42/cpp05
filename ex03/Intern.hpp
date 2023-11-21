/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:43:18 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/21 10:55:22 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern (const Intern &old_obj);
        Intern &operator=(const Intern &obj);
        ~Intern();
        AForm *makeForm(std::string formName, std::string target);
        class InvalidFormException : public std::exception
		{
			public:
				const char *what() const throw();
		}; 
};
