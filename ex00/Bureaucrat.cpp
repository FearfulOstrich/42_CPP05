/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:27:11 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/28 17:32:05 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

Bureaucrat::Bureaucrat(const std::string name, unsigned int rank)
	: _name(name)
	, _rank(rank)
{
	std::cout << "Bureaucrat Default Constructor called." << std::endl;
	if (rank == 0)
		throw (GradeTooHighException());
	else if (rank > 150)
		throw (GradeTooHighException());
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
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
	{
		this->_name = other.getName();
		this->_rank = other.getRank();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getRank() << ".";
	return (os);
}

/*==============================================================================
	Getters.
==============================================================================*/

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getRank(void) const
{
	return (this->_rank);
}

/*==============================================================================
	Setters.
==============================================================================*/

void	Bureaucrat::setName(const std::string& name)
{
	this->_name = name;
	return ;
}

void	Bureaucrat::setRank(unsigned int rank)
{
	if (rank == 0)
		throw (GradeTooHighException());
	else if (rank > 150)
		throw (GradeTooLowException());
	this->_rank = rank;
	return ;
}

/*==============================================================================
	Member functions.
==============================================================================*/

void	Bureaucrat::promote(void)
{
	if (this->_rank == 1)
		throw (GradeTooHighException());
	this->_rank--;
	return ;
}

void	Bureaucrat::demote(void)
{
	if (_rank == 150)
		throw (GradeTooLowException());
	this->_rank++;
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