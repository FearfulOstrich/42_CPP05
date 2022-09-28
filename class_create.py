#!/usr/bin/env python3

"""
Created on Tue Aug 16 21:32:54 2022
@author: Alexandre
"""

import sys

def create_hpp(classname, folder):

    header_file = """#ifndef _{0}_HPP_
# define _{0}_HPP_

# include <iostream>

class {1}
{{
private:

protected:

public:
\t// Constructors
\t{1}();
\t{1}(const {1}& other);

\t// Destructors
\tvirtual ~{1}();

\t// Operator overload
\t{1}&	operator=(const {1}& other);

\t// Accessors (getters should return by value or const-reference)
\t// Member functions
}};

std::ostream&\toperator<<(std::ostream& os, const {1}& obj);

#endif
""".format(classname.upper(), classname)

    with open(f"{folder}/{classname}.hpp", "w") as f:
        f.write(header_file)
    print(f"{classname}.hpp created")


def create_cpp(classname, folder):
    class_file = """#include "{0}.hpp"

/*==============================================================================
	Constructors.
==============================================================================*/

{0}::{0}(void)
{{
\tstd::cout << "{0} Default Constructor called." << std::endl;
\treturn ;
}}

{0}::{0}(const {0}& other)
{{
\tstd::cout << "{0} Copy Constructor called." << std::endl;
\t*this = other;
\treturn ;
}}

/*==============================================================================
	Destructor.
==============================================================================*/

{0}::~{0}(void)
{{
\tstd::cout << "{0} Destructor called." << std::endl;
\treturn ;
}}

/*==============================================================================
	Operator overloads.
==============================================================================*/

{0}&\t{0}::operator=(const {0}& other)
{{
\tstd::cout << "{0} assignment operator called." << std::endl;
\tif (this != &other)
\t{{
\t\t// Copy all attributes
\t}}
\treturn (*this);
}}

std::ostream&\toperator<<(std::ostream& os, const {0}& obj)
{{
\tos << "something";
\treturn (os);
}}

/*==============================================================================
	Getters.
==============================================================================*/

/*==============================================================================
	Setters.
==============================================================================*/

/*==============================================================================
	Member functions.
==============================================================================*/

""".format(classname)

    with open(f"{folder}/{classname}.cpp", "w") as f:
        f.write(class_file)
    print(f"{classname}.cpp created")

if __name__ == "__main__":

    for classname in sys.argv[2:]:
        create_hpp(classname, sys.argv[1])
        create_cpp(classname, sys.argv[1])
