/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:24:21 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/03 12:35:12 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreation", 145, 137)
	, _target(target)
{
	std::cout << "ShrubberyCreationForm Default Constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
	, _target(other.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called." << std::endl;
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
	return ;
}

/*==============================================================================
	Operator overloads.
==============================================================================*/

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
	if (this != &other)
	{
		// Copy all attributes
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& obj)
{
	os << static_cast<const AForm&>(obj);
	return (os);
}

/*==============================================================================
	Getters.
==============================================================================*/

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

/*==============================================================================
	Setters.
==============================================================================*/

/*==============================================================================
	Member functions.
==============================================================================*/

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream	outfile((this->_target + "_shrubbery").c_str());
	std::ifstream	tree_file("tree1.txt");

	if (executor.getGrade() > this->_gradeExecute)
		throw (AForm::GradeTooLowException());
	if (outfile.is_open() && tree_file.is_open())
		outfile << tree_file.rdbuf();
	else
		std::cerr << "Could not open file." << std::endl;
	outfile.close();
	tree_file.close();
	return ;
}