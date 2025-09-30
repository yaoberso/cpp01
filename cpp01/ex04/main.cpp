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
    	file_mod += file.substr(start, pos - start); // texte avant s1
    	file_mod += s2;                              // remplacer s1 par s2
    	start = pos + s1.length();                   // avancer le curseur
    	pos = file.find(s1, start);                  // chercher la prochaine occurrence
	}
	file_mod += file.substr(start);
	return (file_mod);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		return (0);
	}
	std::string filename = argv[1];
	std::ifstream infile(filename);
	if (!infile.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir le fichier !" << std::endl;
        return (1);
	}
	std::string file_content((std::istreambuf_iterator<char>(infile)),
                         std::istreambuf_iterator<char>());
	std::string file_replace = sr_and_rp(file_content, argv[2], argv[3]);
	std::string outname = filename + ".replace";
	std::ofstream outfile(outname);
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