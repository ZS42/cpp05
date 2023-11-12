/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:25:44 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/13 00:25:46 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat; //since Form and Bureaucrat class are cross referencing each other


class AForm
{
	const std::string _name;
	bool	_signStatus;
	const int	_gradeSign;
	const int	_gradeExecute;
	public:
		AForm();
		AForm(std::string name, bool a, int b, int c);
		AForm(const AForm &object);
		AForm &operator=(const AForm &object);
		// virtual so that compiler knows to looks for children classes destructors first
		virtual~AForm();
		void beSigned(Bureaucrat& bureaucrat);
		std::string getFormName() const;
		bool getSignStatus() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		void setFormName(std::string name);
		void setSignStatus(bool signStatus);
		void setGradeSign(const int gradeSign);
		void setGradeExecute(const int gradeExecute);
		// making it equal to zero makes it a pure virtual function
        // and makes the class abstract so it cant be instantiated
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

// This operator overload needs 2 operands bc global and not inside class
// rhs means right hand side
std::ostream &operator<<( std::ostream& os, const Form& rhs );

#endif