/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:10:36 by antoine           #+#    #+#             */
/*   Updated: 2022/10/01 11:57:27 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form("PresidentialPardon", 25, 5)
	, _target(target)
{
	std::cout << "PresidentialPardonForm Default Constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: Form(other)
	, _target(other.getTarget())
{
	std::cout << "PresidentialPardonForm Copy Constructor called." << std::endl;
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Destructor called." << std::endl;
	return ;
}

/*==============================================================================
	Operator overloads.
==============================================================================*/

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm assignment operator called." << std::endl;
	if (this != &other)
	{
		// Copy all attributes
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& obj)
{
	os << static_cast<const Form&>(obj);
	return (os);
}

/*==============================================================================
	Getters.
==============================================================================*/

const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

/*==============================================================================
	Setters.
==============================================================================*/

/*==============================================================================
	Member functions.
==============================================================================*/

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->_gradeExecute)
		throw (Form::GradeTooLowException());
	if (this->_isSigned == false)
		throw (Form::FormNotSignedException());
	std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox.";
	std::cout << std::endl;
	return ;
}