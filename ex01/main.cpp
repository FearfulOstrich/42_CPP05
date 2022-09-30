/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:33:34 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/30 10:36:57 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		Form	form;

		try
		{
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			form = Form("form1", 150, 100);
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			form = Form("formNull", 151, 150);
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			form = Form("form400", 150, 0);
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	std::cout << "=========================" << std::endl << std::endl;
	{
		Bureaucrat	bob;
		Form		form;
		
		try
		{
			bob = Bureaucrat("bob", 1);
			bob.signForm(form);
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			bob = Bureaucrat("bob", 12);
			form = Form("topForm", 10, 10);
			bob.signForm(form);
			std::cout << form << std::endl << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
		try
		{
			bob = Bureaucrat("bob", 11);
			form = Form("topForm", 10, 10);
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