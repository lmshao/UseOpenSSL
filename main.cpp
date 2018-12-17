#include <iostream>
#include "hash.h"
#include "base64.h"
#include "hmac.h"

int main()
{
    std::string str = "Hello", out;
    std::vector<unsigned char> vec(str.begin(), str.end()), out2;

    std::cout << "Hash Test:" << std::endl;
    std::cout << "text: " << str << std::endl;
    std::cout << "MD5(text):\n\t" << md5(vec) << std::endl;
    std::cout << "SHA1(text):\n\t" << sha1(vec) << std::endl;
    std::cout << "SHA256(text):\n\t" << sha256(vec) << std::endl;
    std::cout << "SHA512(text):\n\t" << sha512(vec) << std::endl;

    std::cout << "\nBase64 Test:" << std::endl;
    std::cout << "text: " << str << std::endl;
    base64Encode(vec, out);
    std::cout << "Base64(text): " <<out << std::endl;
    base64Decode(out, out2);
    std::cout << "Base64Decode: " <<std::string(out2.begin(), out2.end()) << std::endl;


    std::vector<unsigned char> key = {'1', '2', '3', '4', '5', '6', '7', '8'};
    std::cout << "\nHmac Hash Test:" << std::endl;
    std::cout << "text:\t" << str << std::endl;
    std::cout << "key:\t" << std::string(key.begin(), key.end()) << std::endl;
    std::cout << "Hmac-MD5(text, key):\t" << hmacMD5(vec, key) << std::endl;
    std::cout << "Hmac-SHA1(text, key):\t" << hmacSHA1(vec, key) << std::endl;
    std::cout << "Hmac-SHA256(text, key):\t" << hmacSHA256(vec, key) << std::endl;
    std::cout << "Hmac-SHA512(text, key):\t" << hmacSHA512(vec, key) << std::endl;

    return 0;
}
