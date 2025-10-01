#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>
#include <iomanip>

class Harl{
	public:
		Harl();
		~Harl();
		void complain( std::string level );
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
		typedef void (Harl::*f)(void);
    	static const std::string levels[4];
    	static const f action[4];
};

#endif