#include <iostream>

int main(void)
{
	std::string	str;
	str = "hello";
	std::cout << str.size() - 10 << std::endl;
	str.replace(9, str.size() - 9, ".");
	std::cout << str << std::endl;
}