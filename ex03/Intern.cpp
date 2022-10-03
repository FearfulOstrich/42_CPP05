/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:58:06 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/03 15:28:24 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor called." << std::endl;
	return ;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern Copy Constructor called." << std::endl;
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called." << std::endl;
	return ;
}

/*==============================================================================
	Operator overloads.
==============================================================================*/

Intern&	Intern::operator=(const Intern& other)
{
	std::cout << "Intern assignment operator called." << std::endl;
	if (this != &other)
	{
		// Copy all attributes
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Intern& obj)
{
	(void)obj;
	os << "just a random intern.";
	return (os);
}

/*==============================================================================
	Getters.
==============================================================================*/

/*==============================================================================
	Setters.
==============================================================================*/

/*==============================================================================
	Member functions.
==============================================================================*/

AForm*	Intern::_makeShrubberyCreationForm(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_makeRobotomyRequestForm(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_makePresidentialPardonForm(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& form, const std::string& target)
{
	t_form_map	map[3] = {{"Shrubbery creation", 
								&Intern::_makeShrubberyCreationForm},
							{"Robotomy request", 
								&Intern::_makeRobotomyRequestForm},
							{"Presidential pardon",
								&Intern::_makePresidentialPardonForm}
						};
	
	for (int i = 0; i < 3; i++)
	{
		if (form == map[i].name)
		{
			std::cout << "Intern created " << form << " form." << std::endl;
			return ((this->*(map[i].f))(target));
		}
	}
	std::cout << form << " form not found." << std::endl;
	return (NULL);
}