#include <iostream>
#include "hash.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    std::string str = "Hello";
    std::vector<unsigned char> vec(str.begin(), str.end());

    std::cout << md5(vec) << std::endl;
    std::cout << sha1(vec) << std::endl;
    std::cout << sha256(vec) << std::endl;
    std::cout << sha512(vec) << std::endl;

}
