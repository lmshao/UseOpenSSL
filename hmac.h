//
// Created by LimingShao on 2018/12/11.
//

#ifndef USEOPENSSL_HMAC_H
#define USEOPENSSL_HMAC_H

#include <string>
#include <vector>

std::string hmacMD5(const std::vector<unsigned char> &in, const std::vector<unsigned char> &key);

std::string hmacSHA1(const std::vector<unsigned char> &in, const std::vector<unsigned char> &key);

std::string hmacSHA256(const std::vector<unsigned char> &in, const std::vector<unsigned char> &key);

std::string hmacSHA512(const std::vector<unsigned char> &in, const std::vector<unsigned char> &key);

#endif //USEOPENSSL_HMAC_H
