/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:28:50 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/19 20:34:09 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream> //to open, read and write froma file
#include <cstring>

class ShrubberyCreationForm : public AForm
{
    std::string _target;
    public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &object);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &object);
		~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};

#endif