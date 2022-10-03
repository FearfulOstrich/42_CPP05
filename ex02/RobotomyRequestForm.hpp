/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:35:20 by antoine           #+#    #+#             */
/*   Updated: 2022/10/03 12:37:48 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	const std::string	_target;
protected:

public:
	// Constructors
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);

	// Destructors
	virtual ~RobotomyRequestForm();

	// Operator overload
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

	// Accessors (getters should return by value or const-reference)
	const std::string&	getTarget(void) const;

	// Member functions
	bool	generateRandBool(void) const;
	void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& obj);

#endif
