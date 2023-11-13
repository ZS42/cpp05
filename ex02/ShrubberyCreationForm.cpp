/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:28:44 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/13 13:37:53 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery creation form", false, 145, 137)
{
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
		this->target = object.target;
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called." << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->target = this->target.append("_shrubbery");
	this->target.open(this->target, ios::out);
	if (!this->target) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
				           _-_
				    /~~   ~~\
				 /~~         ~~\
				{               }
				 \  _-     -_  /
				   ~  \\ //  ~
				_- -   | | _- _
				  _ -  | |   -_
				      // \\

                         ****
                         ********
                        **  ******
                         *   ******     ******
                             ******   *********
                              ****  *****   ***
                              ***  ***     **
                        *************       *
                      ******************
                     *****   H*****H*******
                     ***     H-___-H  *********
                      ***    H     H      *******
                       **    H-___-H        *****
                         *   H     H         ****
                             H     H         ***
                             H-___-H         **
                             H     H         *
                             H-___-H
	my_file.close();
	}
}