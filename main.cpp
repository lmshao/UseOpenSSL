#include <iostream>
#include "hash.h"
#include "base64.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    std::string str = "Hello", out;
    std::vector<unsigned char> vec(str.begin(), str.end()), out2;

    std::cout << md5(vec) << std::endl;
    std::cout << sha1(vec) << std::endl;
    std::cout << sha256(vec) << std::endl;
    std::cout << sha512(vec) << std::endl;

    base64Encode(vec, out);
    std::cout << out << std::endl;
    base64Decode(out, out2);
    std::cout << std::string(out2.begin(), out2.end()) << std::endl;

    return 0;
}
