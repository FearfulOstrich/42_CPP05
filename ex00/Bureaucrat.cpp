/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:27:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/11 10:57:15 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade)
	: _name(name)
	, _grade(grade)
{
	std::cout << "Bureaucrat Default Constructor called." << std::endl;
	if (grade == 0)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name)
{
	std::cout << "Bureaucrat Copy Constructor called." << std::endl;
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called." << std::endl;
	return ;
}

/*==============================================================================
	Operator overloads.
==============================================================================*/

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat assignment operator called." << std::endl;
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

/*==============================================================================
	Getters.
==============================================================================*/

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/*==============================================================================
	Setters.
==============================================================================*/

void	Bureaucrat::setGrade(unsigned int grade)
{
	if (grade == 0)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	this->_grade = grade;
	return ;
}

/*==============================================================================
	Member functions.
==============================================================================*/

void	Bureaucrat::promote(void)
{
	if (this->_grade == 1)
		throw (GradeTooHighException());
	this->_grade--;
	return ;
}

void	Bureaucrat::demote(void)
{
	if (_grade == 150)
		throw (GradeTooLowException());
	this->_grade++;
	return ;
}

/*==============================================================================
	Exceptions
==============================================================================*/

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}