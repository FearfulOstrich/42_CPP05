/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:38:32 by antoine           #+#    #+#             */
/*   Updated: 2022/10/11 12:10:43 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequest", 72, 45)
	, _target(target)
{
	std::srand(std::time(NULL));
	std::cout << "RobtomyRequestForm Default Constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
	, _target(other.getTarget())
{
	std::srand(std::time(NULL));
	std::cout << "RobotomyRequestForm Copy Constructor called." << std::endl;
	*this = other;
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
		this->_isSigned = other.getIsSigned();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& obj)
{
	os << static_cast<const AForm&>(obj);
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

bool	RobotomyRequestForm::generateRandBool(void) const
{
	return (std::rand() % 2);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->_gradeExecute)
		throw (AForm::GradeTooLowException());
	std::cout << "Crash!Bang!Doiiing!Crac!Bunk!Klon!Chtonk!Paf!" << std::endl;
	if (generateRandBool() == true)
		std::cout << this->_target << "'s robotomy was successful.";
	else
		std::cout << "Robotomy failed.";
	std::cout << std::endl;
	return ;
}
