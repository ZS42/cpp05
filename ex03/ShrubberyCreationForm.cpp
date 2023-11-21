/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:28:44 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/19 18:58:54 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery creation form", false, 145, 137)
{
	_target = target;
	std::cout << "ShrubberyCreationForm parametric constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &object)
{
	*this = object;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &object)
{
	if (this != &object)
	{
		this->_target = object._target;
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called." << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}
std::string ShrubberyCreationForm::getTarget() const
{
	return(_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream file;
	file.open(filename.c_str());
	if (!file.is_open())
		std::cerr << "File not created!";
	else
	{
		file << 
 		"                 **** \n"
        "               ******** \n"
        "               **  ****** \n"
        "                *   ******     ****** \n"
        "                    ******   ********* \n"
        "                     ****  *****   *** \n"
        "                     ***  ***     ** \n"
        "               *************       * \n"
        "             ****************** \n"
        "            *****   H*****H******* \n"
        "            ***     H-___-H  ********* \n"
        "             ***    H     H      ******* \n"
        "              **    H-___-H        ***** \n"
        "                *   H     H         **** \n"
        "                    H     H         *** \n"
        "                    H-___-H         ** \n"
        "                    H     H         * \n"
        "                    H-___-H";
	file.close();
	executor.executeForm(*this);
	}
}
