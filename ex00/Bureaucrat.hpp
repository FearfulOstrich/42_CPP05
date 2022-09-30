/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:27:05 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/29 17:17:09 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
# define _BUREAUCRAT_HPP_

# include <iostream>
# include <stdexcept>

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
