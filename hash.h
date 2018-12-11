//
// Created by Liming Shao on 2018/12/10.
//

#ifndef USEOPENSSL_HASH_H
#define USEOPENSSL_HASH_H

#include <string>
#include <vector>

std::string md5(const std::vector<unsigned char> &in);

std::string sha1(const std::vector<unsigned char> &in);

std::string sha256(const std::vector<unsigned char> &in);

std::string sha512(const std::vector<unsigned char> &in);

#endif //USEOPENSSL_HASH_H
