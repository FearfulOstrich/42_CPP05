/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:49:00 by antoine           #+#    #+#             */
/*   Updated: 2022/10/03 12:34:34 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	const std::string	_target;
protected:

public:
	// Constructors
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	// Destructors
	virtual ~ShrubberyCreationForm();

	// Operator overload
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

	// Accessors (getters should return by value or const-reference)
	const std::string&	getTarget(void) const;
	
	// Member functions
	void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& obj);

#endif
