/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:29:25 by antoine           #+#    #+#             */
/*   Updated: 2022/10/01 11:57:07 by antoine          ###   ########.fr       */
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
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_gradeSign;
	const unsigned int	_gradeExecute;
	
	// Constructors
	Form(const std::string& name,\
		unsigned int sign_grade, unsigned int exec_grade);
	Form(const Form& other);
protected:

public:
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
	class FormNotSignedException: public std::exception
	{
		public:
			const char* what() const throw();
	}
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif
