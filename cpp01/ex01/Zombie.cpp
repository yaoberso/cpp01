#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Constructor called !" << std::endl;
	return;
}

Zombie::~Zombie()
{
	std::cout << "Destructor called !" << std::endl;
	return;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
	return;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}