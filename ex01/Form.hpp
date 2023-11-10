/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:25:44 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/09 22:47:58 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat; //since Form and Bureaucrat class are cross referencing each other


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
		void beSigned(Bureaucrat& bureaucrat);
		std::string getFormName() const;
		bool getSignStatus() const;
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
std::ostream &operator<<( std::ostream& os, const Form& rhs );

#endif