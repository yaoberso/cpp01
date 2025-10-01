#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void Harl::_debug()
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}

void Harl::_info()
{
	std::cout << "[ INFO ]" << std::endl << "cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void Harl::_warning()
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	return ;
}

void Harl::_error()
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

const std::string _level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

const   Harl::f Harl::action[4] = 
{
    &Harl::_debug,
    &Harl::_info,
    &Harl::_warning,
    &Harl::_error
};

void Harl::complain(std::string level)
{
	int index = -1;
	for(int i = 0; i < 4; i++)
	{
		if (level == _level[i])
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	switch(index)
	{
		case(0):
			_debug();
		case(1):
			_info();
		case(2):
			_warning();
		case(3):
			_error();
			break;
	}
}