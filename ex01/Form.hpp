/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:29:25 by antoine           #+#    #+#             */
/*   Updated: 2022/10/11 11:02:28 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string&	_name;
	bool				_isSigned;
	const unsigned int	_gradeSign;
	const unsigned int	_gradeExecute;
	
protected:

public:
	// Constructors
	Form(const std::string& name = "noNameForm",\
			unsigned int sign_grade = 150, unsigned int exec_grade = 150);
	Form(const Form& other);

	// Destructors
	virtual ~Form();

	// Operator overload
	Form&	operator=(const Form& other);

	// Accessors (getters should return by value or const-reference)
	const std::string&	getName(void) const;
	bool				getIsSigned(void) const;
	unsigned int		getGradeSign(void) const;
	unsigned int		getGradeExecute(void) const;
	
	// Member functions
	void	beSigned(const Bureaucrat* assignee);

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

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif
