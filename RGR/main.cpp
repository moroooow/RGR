#include "RBTree.h"
#include "algorithm"
#include "sstream"

using namespace rbtree;

std::string ltrim(const std::string& s);
std::string rtrim(const std::string& s);
std::string trim(const std::string& s);

void showMenu();
int countCharacters(const std::string& str, char character);

int main()
{
	system("chcp 1251>nul");
	RBTree dictionary;
	int option;
	std::string line;
	std::string delimiter = ":";
	do
	{
		try
		{
			showMenu();
			std::cin >> option;
			std::cout << std::endl;
			switch (option)
			{
			case 1:
			{
				std::cout << "Enter the element : ";
				std::cin.ignore();
				std::getline(std::cin, line);
				std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c) {
					return std::tolower(c);
					});
				size_t pos = line.find(delimiter);
				int c = countCharacters(line, ':');
				if (pos == std::string::npos || c != 1)
				{
					throw RBTreeException("INALID FORMAT!");
				}
				std::string word = line.substr(0, pos);
				word = trim(word);
				std::string translationString = line.substr(pos + delimiter.size());
				std::string translation;
				std::stringstream ss(trim(translationString));
				std::list<std::string> lst;
				while (std::getline(ss, translation, ','))
				{
					translation = trim(translation);
					lst.push_back(translation);
				}
				dictionary.insertElement(word, lst);
				break;
			}
			case 2:
			{

				std::cout << "Enter the element : ";
				std::cin.ignore();
				std::getline(std::cin, line);
				std::string tmp = trim(line);
				std::cout << "Search a " << line << " in dictionary: " << dictionary.searchElement(tmp) << "\n";
				break;
			}
			case 3:
			{
				std::cout << "Enter the element : ";
				std::cin.ignore();
				std::getline(std::cin, line);
				line = trim(line);
				if (dictionary.searchElement(line))
				{
					std::cout << "Delete a " << line << " in dictionary\n";
					dictionary.deleteElement(line);
				}
				else
				{
					throw RBTreeException("<ELEMENT NOT FOUND>");
				}
				break;
			}
			case 4:
			{
				dictionary.printTree(std::cout);
				std::cout << std::endl;
				break;
			}
			case 5:
			{
				std::cout << "Enter the element : ";
				std::cin.ignore();
				std::getline(std::cin, line);
				std::list<std::string> tmp=dictionary.getTranslateByKey(line);
				std::cout << tmp;
				std::cout << std::endl;
				break;
			}
			case 6:
			{
				std::cout << "Exit the programm!!!";
				break;
			}
			default:
			{
				std::cout << "Incorrectly selected option\n";
				break;
			}
			}
		}
		catch (RBTreeException& e)
		{
			std::cerr << e.what() << std::endl;
		};

	} while (option != 6);

}

void showMenu()
{
	std::cout << "Menu:\n";
	std::cout << "1.Add an element of the English-Russian dictionary in the format : \" enWord : ruWord1, ruWord2 \"\n";
	std::cout << "2.Search an element \n";
	std::cout << "3.Remove an element\n";
	std::cout << "4.Print a dictionary\n";
	std::cout << "5.Print translates by key\n";
	std::cout << "6.Exit\n";
}

int countCharacters(const std::string& str, char character)
{
	int count = 0;
	for (char c : str)
	{
		if (c == character)
		{
			count++;
		}
	}
	return count;
}

std::string ltrim(const std::string& s)
{
	auto it = std::find_if(s.begin(), s.end(), [](char ch) {
		return !std::isspace((unsigned char)ch);
		});
	return std::string(it, s.end());
}

std::string rtrim(const std::string& s)
{
	auto it = std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace((unsigned char)ch);
		});
	return std::string(s.begin(), it.base());
}

std::string trim(const std::string& s)
{
	return rtrim(ltrim(s));
}