#include <iostream>
#include <string>
#include <fstream>
#include "employees.h"
#include "bin_manip.h"

int main() {
    std::string str;
    EmployeesArray array;

    while (true) {
		std::cin >> str;
		if (!str.compare("exit")) {
	    	break;
		}
		else if (!str.compare("add")) {
	    	std::cin >> array;
		}
		else if (!str.compare("load")) {
	    	std::string filename;
	    	std::cin >> filename;
	    	std::ifstream stream(filename);
	    	stream >> array;
		}
		else if (!str.compare("save")) {
	    	std::string filename;
	    	std::cin >> filename;
	    	std::ofstream stream(filename);
	    	stream << array;
		}
		else if (!str.compare("list")) {
	    	std::cout << array;
		}
	
    }
    return 0;
}
