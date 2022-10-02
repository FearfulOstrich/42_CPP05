/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:10:32 by antoine           #+#    #+#             */
/*   Updated: 2022/10/01 11:57:19 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	const std::string	_target;
protected:

public:
	// Constructors
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);

	// Destructors
	virtual ~PresidentialPardonForm();

	// Operator overload
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

	// Accessors (getters should return by value or const-reference)
	const std::string&	getTarget(void) const;

	// Member functions
	void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& obj);

#endif
