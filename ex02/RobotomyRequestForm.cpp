/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:38:32 by antoine           #+#    #+#             */
/*   Updated: 2022/10/01 11:47:55 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("RobotomyRequest", 72, 45)
	, _target(target)
{
	std::cout << "RobtomyRequestForm Default Constructor called." << std::endl;
	std::srand(std::ctime(NULL));
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: Form(other)
	, _target(other.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called." << std::endl;
	*this = other;
	std::srand(std::ctime(NULL));
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor called." << std::endl;
	return ;
}

/*==============================================================================
	Operator overloads.
==============================================================================*/

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
	if (this != &other)
	{
		// Copy all attributes
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& obj)
{
	os << static_cast<const Form&>(obj);
	return (os);
}

/*==============================================================================
	Getters.
==============================================================================*/

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

/*==============================================================================
	Setters.
==============================================================================*/

/*==============================================================================
	Member functions.
==============================================================================*/

static bool	RobotomyRequestForm::generateRandBool(void)
{
	return (std::rand() % 2);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor)
{
	if (executor.getGrade() > this->_gradeExecute)
		throw (Form::GradeTooLowException());
	if (this->_isSigned == false)
		throw (Form::FormNotSignedException());
	std::cout << "Crash!Bang!Doiiing!Crac!Bunk!Klon!Chtonk!Paf!" << std::endl;
	if (RobotomyRequestForm::generateRandBool() == true)
		std::cout << this->_target << "'s robotomy was successful.";
	else
		std::cout << "Robotomy failed.";
	std::cout << std::endl;
	return ;
}
