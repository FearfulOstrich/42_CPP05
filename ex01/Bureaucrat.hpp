/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:27:05 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/30 10:23:11 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string&	_name;
	unsigned int		_grade;
protected:

public:
	// Constructors
	Bureaucrat(const std::string name = "Unknown", unsigned int grade = 150);
	Bureaucrat(const Bureaucrat& other);

	// Destructors
	virtual ~Bureaucrat();

	// Operator overload
	Bureaucrat&	operator=(const Bureaucrat& other);

	// Accessors (getters should return by value or const-reference)
	const std::string&	getName(void) const;
	unsigned int		getGrade(void) const;
	void				setGrade(unsigned int grade);
	
	// Member functions
	void	promote(void);
	void	demote(void);
	void	signForm(Form& form) const;

	// Exceptions
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

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
