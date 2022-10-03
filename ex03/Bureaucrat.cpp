/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:27:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/03 12:15:36 by aalleon          ###   ########.fr       */
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
	// std::cout << "in promote" << std::endl;
	if (this->_grade == 1)
		throw (GradeTooHighException());
	this->_grade--;
	return ;
}

void	Bureaucrat::demote(void)
{
	// std::cout << "in demote" << std::endl;
	if (_grade == 150)
		throw (GradeTooLowException());
	this->_grade++;
	return ;
}

void	Bureaucrat::signForm(AForm& form) const
{
	if (form.getIsSigned() == true)
	{
		std::cout << this->_name << " couldn't sign " << form.getName();
		std::cout << " because it's already signed." << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << ".";
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << "." << std::endl;
	}
	return ;
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	if (form.getIsSigned() == false)
	{
		std::cerr << form.getName() << " needs to be signed before execution.";
		std::cerr << std::endl;
		return ;
	}
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName();
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName();
		std::cout << " because " << e.what() << "." << std::endl;
	}
	return ;
}

/*==============================================================================
	Exceptions
==============================================================================*/

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	// std::cout << "In GradeTooHighException what definition." << std::endl;
	return ("Grade too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	// std::cout << "In GradeTooLowException what definition." << std::endl;
	return ("Grade too low.");
}