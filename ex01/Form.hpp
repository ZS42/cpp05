/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:25:44 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/09 15:16:51 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	const std::string _name;
	bool	_signStatus;
	const int	_gradeSign;
	const int	_gradeExecute;
	public:
		Form();
		Form(std::string name, bool a, int b, int c);
		Form(const Form &object);
		Form &operator=(const Form &object);
		~Form();
		void beSigned(Bureaucrat);
		std::string getFormName();
		bool getSignStatus();
		int getGradeSign() const;
		int getGradeExecute() const;
		void setFormName(std::string name);
		void setSignStatus(bool signStatus);
		void setGradeSign(const int gradeSign);
		void setGradeExecute(const int gradeExecute);
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
std::ostream &operator<<( std::ostream& os, const Bureaucrat& rhs );

#endif