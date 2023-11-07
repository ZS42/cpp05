/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:35:42 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/07 14:29:39 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException ::what() const throw()
{
	return ("Error: Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException ::what() const throw()
{
	return ("Error: Grade is too low.");
}

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
	setName("name");
	try
	{
		_grade = getGrade();
		if (_grade < 1 || _grade > 150)
			throw (_grade);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// grade = 0;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Bureaucrat parametric constructor called." << std::endl;
	setName(name);
	try
	{
		setGrade(grade);
		// this->grade = getGrade();
		if (grade < 1 || grade > 150)
			throw (grade);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &object)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = object;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &object)
{
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	if (this != &object)
	{
		this->_name = object._name;
		this->_grade = object._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

void Bureaucrat::setName(std::string name)
{
	_name = name;
}

std::string Bureaucrat::getName()const
{
	return (this->_name);
}

void Bureaucrat::setGrade(int grade)
{
	_grade = grade;
}

int Bureaucrat::getGrade()const
{
	return (this->_grade);
}
void Bureaucrat::incrementGrade()
{
	(this->_grade)--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	(this->_grade)++;
	if (this->_grade > 150)
		throw GradeTooLowException();
}

// For simple things like int can pass dirctly otherwise pass parameters of overload as reference
std::ostream &operator<<(std::ostream& os, const Bureaucrat& rhs )
{
	os << rhs.getName() << "bureaucrat grade " << rhs.getGrade() << std::endl;
	return os;
}