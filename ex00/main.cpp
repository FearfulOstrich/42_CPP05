/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:33:34 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/30 14:35:02 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	bob;
	
	try
	{
		bob = Bureaucrat("bob", 1);
		std::cout << bob << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		bob = Bureaucrat("tom", 12);
		std::cout << bob << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		bob = Bureaucrat("sid", 151);
		std::cout << bob << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		bob = Bureaucrat("Lola", 12);
		std::cout << bob << std::endl << std::endl;
		bob.promote();
		std::cout << bob << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		bob = Bureaucrat("Sam", 31);
		std::cout << bob << std::endl << std::endl;
		bob.demote();
		std::cout << bob << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		bob = Bureaucrat("Tina", 150);
		bob.demote();
		std::cout << bob << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		bob = Bureaucrat("Pol", 1);
		bob.promote();
		std::cout << bob << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	return (0);
}