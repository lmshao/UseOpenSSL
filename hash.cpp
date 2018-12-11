//
// Created by Liming Shao on 2018/12/10.
//

#include "hash.h"
#include <stdio.h>

#include <sstream>
#include <iostream>

#include "openssl/md5.h"
#include "openssl/sha.h"

std::string md5(const std::vector<unsigned char> &in) {
    unsigned char md[MD5_DIGEST_LENGTH];
    std::string digest, tmp;
    std::stringstream ss;

    if (MD5(&in[0], in.size(), md) == nullptr) {
        std::cout << "MD5 error." << std::endl;
        return digest;
    }

    for (unsigned char c : md) {
        ss << std::hex << (int) c << std::endl;
        ss >> tmp;
        digest += tmp;
    }

    return digest;
}

std::string sha1(const std::vector<unsigned char> &in) {
    unsigned char md[SHA_DIGEST_LENGTH];
    std::string digest, tmp;
    std::stringstream ss;

    if (SHA1(&in[0], in.size(), md) == nullptr) {
        std::cout << "SHA1 error." << std::endl;
        return digest;
    }

    for (unsigned char c : md) {
        ss << std::hex << (int) c << std::endl;
        ss >> tmp;
        digest += tmp;
    }

    return digest;
}

std::string sha256(const std::vector<unsigned char> &in) {
    unsigned char md[SHA256_DIGEST_LENGTH];
    std::string digest, tmp;
    std::stringstream ss;

    if (SHA256(&in[0], in.size(), md) == nullptr) {
        std::cout << "SHA1 error." << std::endl;
        return digest;
    }

    for (unsigned char c : md) {
        ss << std::hex << (int) c << std::endl;
        ss >> tmp;
        digest += tmp;
    }

    return digest;
}

std::string sha512(const std::vector<unsigned char> &in) {
    unsigned char md[SHA512_DIGEST_LENGTH];
    std::string digest, tmp;
    std::stringstream ss;

    if (SHA512(&in[0], in.size(), md) == nullptr) {
        std::cout << "SHA512 error." << std::endl;
        return digest;
    }

    for (unsigned char c : md) {
        ss << std::hex << (int) c << std::endl;
        ss >> tmp;
        digest += tmp;
    }

    return digest;
}
