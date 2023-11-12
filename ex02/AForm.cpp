/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:42:59 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/10 10:33:12 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException ::what() const throw()
{
	return ("Bureacrat grade is too high.");
}

const char* Form::GradeTooLowException ::what() const throw()
{
	return ("Bureaucrat grade is too low.");
}

Form::Form() : _name("name"), _signStatus(0), _gradeSign(1), _gradeExecute(2)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw(Form::GradeTooHighException());
	else if (_gradeSign > 150 || _gradeExecute > 150)
		throw(Form::GradeTooLowException());
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(std::string name, bool a, int b, int c) : _name(name), _signStatus(a), _gradeSign(b), _gradeExecute(c)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw(Form::GradeTooHighException());
	else if (_gradeSign > 150 || _gradeExecute > 150)
		throw(Form::GradeTooLowException());

	std::cout << Form::getFormName() << " form parametric constructor called." << std::endl;
}

Form::Form(const Form &object): _name(object._name), _signStatus(object._signStatus), _gradeSign(object._gradeSign), _gradeExecute(object._gradeExecute)
{
	*this = object;
	std::cout << "Form copy constructor called." << std::endl;
}

Form &Form::operator=(const Form &object)
{
	if (this != &object)
	{
		const_cast<std::string&>(this->_name) = object.getFormName();
		this->_signStatus = object._signStatus;
		const_cast<int&>(this->_gradeSign) = object._gradeSign;
		const_cast<int&>(this->_gradeExecute) = object._gradeExecute;
	}
	std::cout << "Form copy assignment operator called." << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}

std::string Form::getFormName() const
{
	return (this->_name);
}

bool Form::getSignStatus() const
{
	return (this->_signStatus);
}

int Form::getGradeSign() const
{
	return (this->_gradeSign);
}

int Form::getGradeExecute() const
{
	return (this->_gradeExecute);
}

void Form::setFormName(std::string name)
{
	const_cast<std::string&>(this->_name) = name;
}

void Form::setSignStatus(bool signStatus)
{
	this->_signStatus = signStatus;
}

void Form::setGradeSign(const int gradeSign)
{
	const_cast<int&>(this->_gradeSign) = gradeSign;
}

void Form::setGradeExecute(const int gradeExecute)
{
	const_cast<int&>(this->_gradeExecute) = gradeExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->getSignStatus() != true)
	{
		bureaucrat.signForm(*this);
		if (bureaucrat.getGrade() <= this->getGradeSign())
		{
			this->setSignStatus(true);
		}
		// else
			// throw (Form::GradeTooLowException());
	}
}

std::ostream &operator<<( std::ostream& os, const Form& rhs )
{
	os << "Form: [" << rhs.getFormName() << "] form sign grade: [" << rhs.getGradeSign() << "] form execute grade: [" << rhs.getGradeSign() << "] signed [" << rhs.getSignStatus() << "]";
	return (os);
}