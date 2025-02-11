#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


int main(int argc, char **argv)
{
     std::string filename;
     std::string filenamereplace;
     std::string toreplace;
     std::string replace;

    if (argc != 4)
        return (std::cerr << argv[0] << ": Wrong Argument Count" << std::endl, 1);

    filename = argv[1];
    toreplace = argv[2];
    replace = argv[3];
    filenamereplace = filename + ".replace";

    std::ifstream istrm(filename, std::ios::in);
    if (!istrm.is_open())
        return (std::cout << "failed to open " << filename << '\n', 1);

    std::ostringstream ostream;
    ostream << istrm.rdbuf();
    std::string entireFile = ostream.str();
    istrm.close();

    int index = 0;
    int replacelen = replace.length();
    while (1)
	{
		index = entireFile.find(toreplace, index);
		if (index > entireFile.length())
			break ;
		entireFile.erase(index, toreplace.length());
		entireFile.insert(index, replace);
		index += replacelen;
	}
    std::ofstream ostrm(filenamereplace, std::ios::out);
    if (!ostrm.is_open())
        return (std::cout << "failed to open " << filenamereplace<< '\n', 1);
    else
    {
		ostrm << entireFile;
		ostrm.close();
	}
}