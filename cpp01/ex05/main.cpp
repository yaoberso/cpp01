#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Error : arg" << std::endl;
		return(1);
	}
	std::string level = argv[1];
	Harl harl;
	harl.complain(level);
}