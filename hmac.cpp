//
// Created by LimingShao on 2018/12/11.
//
#include "hmac.h"

#include <iostream>
#include <sstream>
#include <iomanip>

#include <openssl/sha.h>
#include "openssl/hmac.h"

std::string hmac(const std::vector<unsigned char> &in, const std::vector<unsigned char> &key, const EVP_MD *evpMd) {
    unsigned char m[EVP_MAX_MD_SIZE];
    unsigned int len;
    std::string digest, tmp;
    std::stringstream ss;

    if (HMAC(evpMd, &key[0], (int)key.size(), &in[0], in.size(), m, &len) == nullptr) {
        std::cout << "HMAC error." << std::endl;
        return digest;
    }

    for (int i=0; i < len; i++) {
        ss << std::setfill('0') << std::setw(2) << std::hex << (int) m[i] << std::endl;
        ss >> tmp;
        digest += tmp;
    }

    return digest;
}

std::string hmacMD5(const std::vector<unsigned char> &in, const std::vector<unsigned char> &key) {
    return hmac(in, key, EVP_md5());
}

std::string hmacSHA1(const std::vector<unsigned char> &in, const std::vector<unsigned char> &key) {
    return hmac(in, key, EVP_sha1());
}

std::string hmacSHA256(const std::vector<unsigned char> &in, const std::vector<unsigned char> &key) {
    return hmac(in, key, EVP_sha256());
}

std::string hmacSHA512(const std::vector<unsigned char> &in, const std::vector<unsigned char> &key) {
    return hmac(in, key, EVP_sha512());
}