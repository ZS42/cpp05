/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:28:50 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/13 13:31:58 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream> //to open, read and write froma file

class ShrubberyCreationForm : public AForm
{
    std::string target;
    public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &object);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &object);
		~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};

#endif