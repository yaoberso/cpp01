#include <iostream>
#include <string>
#include <fstream>
//std::ifstream tata
//std::ofstream(file, std::)

std::string	sr_and_rp(std::string file, std::string s1, std::string s2)
{
	std::string file_mod;
	size_t pos = file.find(s1, 0);
	size_t start = 0;
	while (pos != std::string::npos)
	{
    	file_mod += file.substr(start, pos - start);
    	file_mod += s2;
    	start = pos + s1.length();
    	pos = file.find(s1, start);
	}
	file_mod += file.substr(start);
	return (file_mod);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments." << std::endl;
		return (1);
	}
	if (std::string(argv[2]).empty())
	{
    	std::cerr << "Error : second arg (s1) can't be empty" << std::endl;
    	return (1);
	}
	std::string filename = argv[1];
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
        return (1);
	}
	std::string file_content((std::istreambuf_iterator<char>(infile)),
                         std::istreambuf_iterator<char>());
	std::string file_replace = sr_and_rp(file_content, argv[2], argv[3]);
	std::string outname = filename + ".replace";
	std::ofstream outfile(outname.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
        return (1);
	}
	outfile << file_replace;
	infile.close();
	outfile.close();
	return (0);
}