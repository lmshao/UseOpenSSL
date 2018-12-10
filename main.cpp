#include <iostream>
#include "hash.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    const char *str = "Hello";

    std::cout << md5((const unsigned char*)str, (int)strlen(str)) << std::endl;
    std::cout << sha1((const unsigned char*)str, (int)strlen(str)) << std::endl;
    std::cout << sha256((const unsigned char*)str, (int)strlen(str)) << std::endl;
    std::cout << sha512((const unsigned char*)str, (int)strlen(str)) << std::endl;

}
