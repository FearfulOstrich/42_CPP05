/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:27:05 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/28 17:34:10 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
# define _BUREAUCRAT_HPP_

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int		_rank;
protected:

public:
	// Constructors
	Bureaucrat(const std::string name, unsigned int rank = 150);
	Bureaucrat(const Bureaucrat& other);

	// Destructors
	virtual ~Bureaucrat();

	// Operator overload
	Bureaucrat&	operator=(const Bureaucrat& other);

	// Accessors (getters should return by value or const-reference)
	const std::string&	getName(void) const;
	unsigned int		getRank(void) const;
	void				setName(const std::string& name);
	void				setRank(unsigned int rank);
	
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
