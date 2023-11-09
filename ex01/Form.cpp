/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:42:59 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/09 15:27:48 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException ::what() const throw()
{
	return ("Grade is too high.");
}

const char* Form::GradeTooLowException ::what() const throw()
{
	return ("Grade is too low.");
}

Form::Form() : _name("name"), _signStatus(0), _gradeSign(1), _gradeExecute(2)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(std::string name, bool a, int b, int c) : _name(name), _signStatus(a), _gradeSign(b), _gradeExecute(c)
{
	setFormName(name);
	setSignStatus(a);
	setGradeSign(b);
	setGradeExecute(c);
	// const_cast<std::string&>(this->_name) = name;
	// this->_signStatus = a;
	// const_cast<int&>(this->_gradeSign) = b;
	// const_cast<int&>(this->_gradeExecute) = c;
	std::cout << Form::getFormName() << " form parametric constructor called." << std::endl;
}

Form::Form(const Form &object)
{
	*this = object;
	std::cout << "Form copy constructor called." << std::endl;
}

Form &Form::operator=(const Form &object)
{
	if (this != &object)
	{
		const_cast<std::string&>(this->_name) = object.getFormName();
		_grade = object._grade;
	}
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}

void Form::beSigned(Bureaucrat)
{

}

std::string Form::getFormName()
{
	return (this->_name);
}

bool Form::getSignStatus()
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

void Form::beSigned(Bureaucrat)
{

}

std::ostream &operator<<( std::ostream& os, const Form& rhs )
{
	os << rhs.getFormName() << " form sign grade " << rhs.getGradeSign() << " form execute grade " << rhs.getGradeSign() << rhs.getSignStatus()
	return os;
}