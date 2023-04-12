#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

bool greater(std::pair<char, int>& a, std::pair<char, int>& b);
void countSymbols(std::vector<std::string> symbols, std::map <char, int> countEverySymbol, std::vector<std::pair<char, int>> resultVector);

void countSymbols(std::vector<std::string> symbols, std::map <char, int> countEverySymbol, std::vector<std::pair<char, int>> resultVector)
{
	for (int i = 0; i < symbols.size(); ++i)
	{
		for (int j = 0; j < symbols[i].size(); ++j)
		{
			if (countEverySymbol.size() == 0)
			{
				countEverySymbol.insert(std::pair<char, int>(symbols[i][j], 0));
			}
			else
			{
				for (auto& it : countEverySymbol)
				{
					if (symbols[i][j] == it.first)
					{
						++it.second;
					}
					else
					{
						countEverySymbol.insert(std::pair<char, int>(symbols[i][j], 0));
					}
				}
			}
		}
	}

	for (auto& it : countEverySymbol)
	{
		if (it.second == 0)
		{
			++it.second;
		}
	}


	std::cout << "This program count every symbol in file\n\n";
	std::cout << "Make your choice\n";
	std::cout << "1. Print result by english alphabet\n";
	std::cout << "2. Print result in decrease order\n";
	int choice = 0;
	std::cin >> choice;
	if (choice == 1)
	{
		for (auto& it : countEverySymbol)
		{
			std::cout << "Symbol '" << it.first << "' - quantity '" << it.second << "'\n";
		}
		
	}
	else
	{
		for (auto& it : countEverySymbol)
		{
			resultVector.push_back(std::pair<char, int>(it.first, it.second));
		}
		std::sort(resultVector.begin(), resultVector.end(), greater);
		for (int i = 0; i < resultVector.size(); ++i)
		{
			std::cout << resultVector[i].first << ", " << resultVector[i].second << std::endl;
		}
	}
}

bool greater(std::pair<char, int>& a, std::pair<char, int>& b)
{
	return a.second > b.second;
}

int main()
{
    std::string symbol;
	//you can place any text file in derictory to count every symbol in it
    std::string fileName = "c:\\test\\testfile.txt";
    std::ifstream fopen(fileName);
	std::vector<std::string> symbols;
	std::map <char, int> countEverySymbol;
	std::vector<std::pair<char,int>> resultVector;

	if (!fopen.is_open())
	{
		std::cout << "Error open " << fileName.substr(fileName.find_last_of("\\") + 1, std::string::npos) << " file" << std::endl;
		perror("");
	}
	else
	{
		while (std::getline(fopen, symbol))
		{
			symbols.push_back(symbol);
		}
		std::cout << "Information about " << fileName.substr(fileName.find_last_of("\\") + 1, std::string::npos) << " file" << std::endl;
		countSymbols(symbols, countEverySymbol, resultVector);

	}
	fopen.close();


    return 0;
}
