/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:29:28 by antoine           #+#    #+#             */
/*   Updated: 2022/09/30 19:21:00 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

Form::Form(const std::string& name,\
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

Form::Form(const Form& other)
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

Form::~Form(void)
{
	std::cout << "Form Destructor called." << std::endl;
	return ;
}

/*==============================================================================
	Operator overloads.
==============================================================================*/

Form&	Form::operator=(const Form& other)
{
	std::cout << "Form assignment operator called." << std::endl;
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
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

const std::string&	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

unsigned int	Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

unsigned int	Form::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

/*==============================================================================
	Setters.
==============================================================================*/

/*==============================================================================
	Member functions.
==============================================================================*/

void	Form::beSigned(const Bureaucrat* assignee)
{
	if (assignee->getGrade() > this->_gradeSign)
		throw (GradeTooLowException());
	this->_isSigned = true;
	return ;	
}

/*==============================================================================
	Exceptions
==============================================================================*/

const char*	Form::GradeTooHighException::what() const throw()
{
	std::cout << "In Form::GradeTooHighException what definition." << std::endl;
	return ("Grade too high.");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	std::cout << "In Form::GradeTooLowException what definition." << std::endl;
	return ("Grade too low.");
}