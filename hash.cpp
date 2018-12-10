//
// Created by Liming Shao on 2018/12/10.
//

#include "hash.h"
#include <stdio.h>

#include <sstream>
#include <iostream>

#include "openssl/md5.h"
#include "openssl/sha.h"

std::string md5(const unsigned char *in, int len) {
    unsigned char md[MD5_DIGEST_LENGTH];
    std::string digest, tmp;
    std::stringstream ss;

    if (in == nullptr || len < 0) {
        std::cout << "md5 param err." << std::endl;
        return digest;
    }

    if (MD5(in, (size_t)len, md) == nullptr) {
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

std::string sha1(const unsigned char *in, int len) {
    unsigned char md[SHA_DIGEST_LENGTH];
    std::string digest, tmp;
    std::stringstream ss;

    if (in == nullptr || len < 0) {
        std::cout << "sha1 param err." << std::endl;
        return digest;
    }

    if (SHA1(in, (size_t)len, md) == nullptr) {
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

std::string sha256(const unsigned char *in, int len) {
    unsigned char md[SHA256_DIGEST_LENGTH];
    std::string digest, tmp;
    std::stringstream ss;

    if (in == nullptr || len < 0) {
        std::cout << "sha1 param err." << std::endl;
        return digest;
    }

    if (SHA256(in, (size_t)len, md) == nullptr) {
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

std::string sha512(const unsigned char *in, int len) {
    unsigned char md[SHA512_DIGEST_LENGTH];
    std::string digest, tmp;
    std::stringstream ss;

    if (in == nullptr || len < 0) {
        std::cout << "sha512 param err." << std::endl;
        return digest;
    }

    if (SHA512(in, (size_t)len, md) == nullptr) {
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
