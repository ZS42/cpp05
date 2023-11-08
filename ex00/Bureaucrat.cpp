/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:35:42 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/08 09:46:17 by zsyyida          ###   ########.fr       */
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

// Bureaucrat::Bureaucrat(): _name(name), _grade(grade)
// {
// 	std::cout << "Bureaucrat default constructor called." << std::endl;
// 	setName("name");
// 	try
// 	{
// 		_grade = getGrade();
// 		if (_grade < 1 || _grade > 150)
// 			throw (_grade);
// 	}
// 	catch (const Bureaucrat::GradeTooHighException& e)
// 	{
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	catch (const Bureaucrat::GradeTooLowException& e)
// 	{
// 		std::cerr << "Error: " << e.what() << std::endl;
// 	}

// 	// grade = 0;
// }

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << Bureaucrat::getName() << " bureaucrat parametric constructor called." << std::endl;
	// setName(name);
	try
	{
		// setGrade(grade);
		// this->grade = getGrade();
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
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
		// this->_name = object._name;
		this->_grade = object._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << Bureaucrat::getName() << "  bureaucrat destructor called." << std::endl;
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
	catch(const Bureaucrat::GradeTooHighException& e)
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
			throw GradeTooLowException();/* code */
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

// For simple things like int can pass dirctly otherwise pass parameters of overload as reference
std::ostream &operator<<(std::ostream& os, const Bureaucrat& rhs )
{
	os << rhs.getName() << " bureaucrat grade " << rhs.getGrade() << std::endl;
	return os;
}