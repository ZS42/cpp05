/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:28:37 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/15 16:39:01 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream> //to open, read and write froma file
#include <string>

class RobotomyRequestForm : public AForm
{
    std::string _target;
    public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &object);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &object);
		~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};