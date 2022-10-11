/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:33:34 by aalleon           #+#    #+#             */
/*   Updated: 2022/10/11 12:05:55 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	Intern		stagios;
	Bureaucrat	bob("Bob", 100);
	Bureaucrat	lenny("Lenny", 50);
	Bureaucrat	jenny("Jenny", 5);
	AForm*		sForm;	
	AForm*		rForm;
	AForm*		pForm;

	std::cout << stagios << std::endl;
	std::cout << std::endl;
	try
	{
		sForm = stagios.makeForm("wrong name", "You");
	}
	catch (std::exception& e)
	{
		std::cout << "could not create form because " << e.what() << std::endl;
	}
	std::cout << std::endl;
	sForm = stagios.makeForm("Shrubbery creation", "Townhall");
	std::cout << std::endl;
	rForm = stagios.makeForm("Robotomy request", "R2D2");
	std::cout << std::endl;
	pForm = stagios.makeForm("Presidential pardon", "Zizou");
	std::cout << std::endl;
	std::cout << bob << std::endl;
	std::cout << lenny << std::endl;
	std::cout << jenny << std::endl;
	std::cout << *sForm << std::endl;
	std::cout << *rForm << std::endl;
	std::cout << *pForm << std::endl;

	bob.signForm(*sForm);
	std::cout << std::endl;
	bob.executeForm(*sForm);
	std::cout << std::endl;
	bob.signForm(*rForm);
	std::cout << std::endl;
	lenny.signForm(*rForm);
	std::cout << std::endl;
	lenny.executeForm(*rForm);
	std::cout << std::endl;
	jenny.executeForm(*rForm);
	std::cout << std::endl;
	jenny.executeForm(*rForm);
	std::cout << std::endl;
	jenny.executeForm(*rForm);
	std::cout << std::endl;
	jenny.executeForm(*pForm);
	std::cout << std::endl;
	jenny.signForm(*pForm);
	std::cout << std::endl;
	jenny.executeForm(*pForm);
	std::cout << std::endl;
	
	delete sForm;
	delete rForm;
	delete pForm;
	return (0);
}