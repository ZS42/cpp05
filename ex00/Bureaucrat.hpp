/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:06:45 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/07 14:27:16 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	const std::string _name;
	int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &object);
		Bureaucrat &operator=(const Bureaucrat &object);
		~Bureaucrat();
		void setName(std::string name);
		std::string getName()const;
		void setGrade(int grade);
		int getGrade()const;
		void incrementGrade();
		void decrementGrade();
		// We make a user-defined exception class and inherit it from the exception class.
		// We use the virtual function to overload the what() function and return the exception.
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