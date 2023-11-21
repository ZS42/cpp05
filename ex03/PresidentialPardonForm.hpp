/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:27:56 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/15 15:59:39 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream> //to open, read and write froma file
#include <string>

class PresidentialPardonForm : public AForm
{
    std::string _target;
    public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &object);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &object);
		~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};