/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:06:45 by zsyyida           #+#    #+#             */
/*   Updated: 2023/10/27 19:55:04 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    const std::string _name;
    int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &object);
        Bureaucrat &operator=(const Bureaucrat &object);
        ~Bureaucrat();
        std::string getName()const;
        int getGrade()const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
				{
					return ("Error: Grade is too high.");
				}

        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
				{
					return ("Error: Grade is too low.");
				}

        };
};

// This operator overload needs 2 operands bc global and not inside class
// rhs means right hand side
std::ostream &operator<<( std::ostream& os, const Bureaucrat& rhs );

#endif