#include "ShrubberyCreationForm.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("ShrubberyCreation", 145, 137)
	, _target(target)
{
	std::cout << "ShrubberyCreationForm Default Constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other)
	, _target(other.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called." << std::endl;
	*this = other;
	return ;
}

/*==============================================================================
	Destructor.
==============================================================================*/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
	return ;
}

/*==============================================================================
	Operator overloads.
==============================================================================*/

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
	if (this != &other)
	{
		// Copy all attributes
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& obj)
{
	os << static_cast<const Form&>(obj);
	return (os);
}

/*==============================================================================
	Getters.
==============================================================================*/

const std::string&	getTarget(void) const
{
	return (this->_target);
}

/*==============================================================================
	Setters.
==============================================================================*/

/*==============================================================================
	Member functions.
==============================================================================*/

void	execute(const Bureaucrat& executor) const
{
	ofstream	outfile;

	if (executor.getGrade() > this->_gradeExecute)
		throw (Form::GradeTooLowException());
	if (this->_isSigned == false)
		throw (Form::FormNotSignedException());
	outfile.open(this->_target + "_shrubbery");
	if (outfile.is_open())
	{
		outfile << "des arbres ASCII";
		outfile.close();
	}
	else
		std::cerr << "Could not open file." << std::endl;
	return ;
}