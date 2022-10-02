/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:49:00 by antoine           #+#    #+#             */
/*   Updated: 2022/10/01 11:57:32 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
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
	void	execute(const Bureaucrat& executor) c`onst;
};

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& obj);

#endif
