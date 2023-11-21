/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:28:37 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/19 20:29:15 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream> //to open, read and write from a file
#include <cstring> //add c and remove .h to include c libaray in c++
#include <ctime> //for time
#include <cstdlib> // for rand, srand

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