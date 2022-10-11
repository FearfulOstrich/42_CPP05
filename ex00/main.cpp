/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:33:34 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/11 10:56:04 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	bob("bob", 1);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\t-----------------------------" << std::endl;
	try
	{
		Bureaucrat	tom("tom", 12);
		std::cout << tom << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\t-----------------------------" << std::endl;
	try
	{
		Bureaucrat	sid("sid", 151);
		std::cout << sid << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\t-----------------------------" << std::endl;
	try
	{
		Bureaucrat	lola("lola", 12);
		std::cout << lola << std::endl;
		lola.promote();
		std::cout << lola << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\t-----------------------------" << std::endl;
	try
	{
		Bureaucrat	sam("sam", 31);
		std::cout << sam << std::endl;
		sam.demote();
		std::cout << sam << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\t-----------------------------" << std::endl;
	try
	{
		Bureaucrat	tina("tina", 150);
		tina.demote();
		std::cout << tina << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\t-----------------------------" << std::endl;
	try
	{
		Bureaucrat	pol("pol", 1);
		pol.promote();
		std::cout << pol << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}