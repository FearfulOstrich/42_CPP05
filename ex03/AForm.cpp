/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:57:00 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/03 12:22:34 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

AForm::AForm(const std::string& name,\
			unsigned int sign_grade, unsigned int exec_grade)
	: _name(name)
	, _isSigned(false)
	, _gradeSign(sign_grade)
	, _gradeExecute(exec_grade)
{
	std::cout << "Form Default Constructor called." << std::endl;
	if (sign_grade == 0 || exec_grade == 0)
		throw (GradeTooHighException());
	else if (sign_grade > 150 || exec_grade > 150)
		throw (GradeTooLowException());
	return ;
}

AForm::AForm(const AForm& other)
	: _name(other.getName())
	, _gradeSign(other.getGradeSign())
	, _gradeExecute(other.getGradeExecute())
{
	std::cout << "Form Copy Constructor called." << std::endl;
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

AForm::~AForm(void)
{
	std::cout << "Form Destructor called." << std::endl;
	return ;
}

/*==============================================================================
	Operator overloads.
==============================================================================*/

AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "Form assignment operator called." << std::endl;
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << "[Form " << obj.getName() << "]";
	os << "Signed: " << obj.getIsSigned() << ";";
	os << "SignGrade: " << obj.getGradeSign() << ";";
	os << "ExecGrade: " << obj.getGradeExecute() << ";";
	return (os);
}

/*==============================================================================
	Getters.
==============================================================================*/

const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

unsigned int	AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

unsigned int	AForm::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

/*==============================================================================
	Setters.
==============================================================================*/

/*==============================================================================
	Member functions.
==============================================================================*/

void	AForm::beSigned(const Bureaucrat& assignee)
{
	if (assignee.getGrade() > this->_gradeSign)
		throw (GradeTooLowException());
	this->_isSigned = true;
	return ;	
}

/*==============================================================================
	Exceptions
==============================================================================*/

const char*	AForm::GradeTooHighException::what() const throw()
{
	// std::cout << "In Form::GradeTooHighException what definition." << std::endl;
	return ("Grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	// std::cout << "In Form::GradeTooLowException what definition." << std::endl;
	return ("Grade too low");
}