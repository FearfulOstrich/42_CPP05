/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:33:34 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/30 21:29:13 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		try
		{
			Form	form;
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			Form	form("form1", 150, 100);
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			Form	form("formNull", 151, 150);
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			Form	form("form400", 150, 0);
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	std::cout << "=========================" << std::endl << std::endl;
	{
		try
		{
			Bureaucrat	bob("bob", 1);
			Form		form;
			
			std::cout << bob << std::endl;
			std::cout << form << std::endl;
			bob.signForm(form);
			std::cout << form << std::endl;
			bob.signForm(form);
			std::cout << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			Bureaucrat	bob("bob", 12);
			Form		form("topForm", 10, 10);
			std::cout << bob << std::endl;
			std::cout << form << std::endl;
			bob.signForm(form);
			std::cout << form << std::endl << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			Bureaucrat	bob("bob", 11);
			Form		form("topForm", 10, 10);
			bob.promote();
			bob.signForm(form);
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	return (0);
}