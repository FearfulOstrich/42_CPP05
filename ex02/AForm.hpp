/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:48 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/03 12:34:13 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_gradeSign;
	const unsigned int	_gradeExecute;
	
	// Constructors
	AForm(const std::string& name,\
		unsigned int sign_grade, unsigned int exec_grade);
	AForm(const AForm& other);
	
public:
	// Destructors
	virtual ~AForm();

	// Operator overload
	AForm&	operator=(const AForm& other);

	// Accessors (getters should return by value or const-reference)
	const std::string&	getName(void) const;
	bool				getIsSigned(void) const;
	unsigned int		getGradeSign(void) const;
	unsigned int		getGradeExecute(void) const;
	
	// Member functions
	void			beSigned(const Bureaucrat& assignee);
	virtual void	execute(const Bureaucrat& executor) const = 0;
	
	//Exceptions
	class GradeTooHighException: public std::exception
	{
	public:
		const char*	what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif
