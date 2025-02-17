#include <cctype>
#include <cstdio>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	for (int i = 1; argv[i]; i++) {
		for (int j = 0; argv[i][j]; j++) {
			argv[i][j] = std::toupper(argv[i][j]);
		}
		std::cout << argv[i];
		if (argv[i + 1])
			std::cout << " ";
	}
}
