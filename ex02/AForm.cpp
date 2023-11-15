/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:42:59 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/15 16:49:20 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::UnsignedException ::what() const throw()
{
	return ("Form not signed.");
}

const char* AForm::AlreadySignedException ::what() const throw()
{
	return ("Form already signed.");
}

const char* AForm::GradeTooHighException ::what() const throw()
{
	return ("Bureacrat grade is too high.");
}

const char* AForm::GradeTooLowException ::what() const throw()
{
	return ("Bureaucrat grade is too low.");
}

AForm::AForm() : _name("name"), _signStatus(0), _gradeSign(1), _gradeExecute(2)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw(AForm::GradeTooHighException());
	else if (_gradeSign > 150 || _gradeExecute > 150)
		throw(AForm::GradeTooLowException());
	std::cout << "Form default constructor called." << std::endl;
}

AForm::AForm(std::string name, bool a, int b, int c) : _name(name), _signStatus(a), _gradeSign(b), _gradeExecute(c)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw(AForm::GradeTooHighException());
	else if (_gradeSign > 150 || _gradeExecute > 150)
		throw(AForm::GradeTooLowException());

	std::cout << AForm::getFormName() << " form parametric constructor called." << std::endl;
}

AForm::AForm(const AForm &object): _name(object._name), _signStatus(object._signStatus), _gradeSign(object._gradeSign), _gradeExecute(object._gradeExecute)
{
	*this = object;
	std::cout << "AForm copy constructor called." << std::endl;
}

AForm &AForm::operator=(const AForm &object)
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

AForm::~AForm()
{
	std::cout << "Form destructor called." << std::endl;
}

std::string AForm::getFormName() const
{
	return (this->_name);
}

bool AForm::getSignStatus() const
{
	return (this->_signStatus);
}

int AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int AForm::getGradeExecute() const
{
	return (this->_gradeExecute);
}

void AForm::setFormName(std::string name)
{
	const_cast<std::string&>(this->_name) = name;
}

void AForm::setSignStatus(bool signStatus)
{
	this->_signStatus = signStatus;
}

void AForm::setGradeSign(const int gradeSign)
{
	const_cast<int&>(this->_gradeSign) = gradeSign;
}

void AForm::setGradeExecute(const int gradeExecute)
{
	const_cast<int&>(this->_gradeExecute) = gradeExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->getSignStatus() != true)
	{
		bureaucrat.signForm(*this);
		if (bureaucrat.getGrade() <= this->getGradeSign())
		{
			this->setSignStatus(true);
		}
		else
			throw (AForm::AlreadySignedException());
	}
}

bool	AForm::canExecute(Bureaucrat const& bureaucrat)
{
	if (this->getSignStatus() != true)
	{
		throw(AForm::UnsignedException());
	}
	if (bureaucrat.getGrade() <= this-> getGradeExecute())
		return (true);
	else
		return (false);
}

std::ostream &operator<<( std::ostream& os, const AForm& rhs )
{
	os << "AForm: [" << rhs.getFormName() << "] form sign grade: [" << rhs.getGradeSign() << "] form execute grade: [" << rhs.getGradeExecute() << "] signed [" << rhs.getSignStatus() << "]";
	return (os);
}