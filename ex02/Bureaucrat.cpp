/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:35:42 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/13 00:22:14 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException ::what() const throw()
{
	return ("Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException ::what() const throw()
{
	return ("Grade is too low.");
}

Bureaucrat::Bureaucrat(): _name("name"), _grade(100)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
		setName(name);
		setGrade(grade);
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
	std::cout << Bureaucrat::getName() << " bureaucrat parametric constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &object)
{
	*this = object;
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &object)
{
	if (this != &object)
	{
		const_cast<std::string&>(this->_name) = object.getName();
		_grade = object._grade;
	}
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << Bureaucrat::getName() << " bureaucrat destructor called." << std::endl;
}

std::string Bureaucrat::getName()const
{
	return (this->_name);
}

int Bureaucrat::getGrade()const
{
	return (this->_grade);
}
void Bureaucrat::incrementGrade()
{
	try
	{
		(this->_grade)--;
		if (this->_grade < 1)
			throw GradeTooHighException();{/* code */}
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		(this->_grade)++;
		if (this->_grade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

void Bureaucrat::setName(std::string name)
{
	const_cast<std::string&>(this->_name) = name;
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		if (this->getGrade() <= form.getGradeSign())
			std::cout << this->_name << " signed " << form.getFormName() << std::endl;
		else
			throw (AForm::GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign form [" << form.getFormName() << "] because " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		if (this->getGrade() <= form.getGradeExecute())
			std::cout << this->_name << " execited " << form.getFormName() << std::endl;
		else
			throw (AForm::GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute form [" << form.getFormName() << "] because " << e.what() << '\n';
	}
}

// For simple things like int can pass dirctly otherwise pass parameters of overload as reference
std::ostream &operator<<(std::ostream& os, const Bureaucrat& rhs )
{
	os << rhs.getName() << " bureaucrat grade " << rhs.getGrade();
	return os;
}