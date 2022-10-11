/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:58:04 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/11 12:01:05 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	//Member functions
	AForm*	_makeShrubberyCreationForm(const std::string& target) const;
	AForm*	_makeRobotomyRequestForm(const std::string& target) const;
	AForm*	_makePresidentialPardonForm(const std::string& target) const;
	
protected:

public:
	// Constructors
	Intern();
	Intern(const Intern& other);

	// Destructors
	virtual ~Intern();

	// Operator overload
	Intern&	operator=(const Intern& other);

	// Accessors (getters should return by value or const-reference)
	// Member functions
	AForm*	makeForm(const std::string& form, const std::string& target);

	// Exceptions
	class FormNotFoundException: public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

typedef struct s_form_map
{
	std::string	name;
	AForm*		(Intern::*f)(const std::string& target) const;
}	t_form_map;

std::ostream&	operator<<(std::ostream& os, const Intern& obj);

#endif
