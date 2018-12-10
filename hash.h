//
// Created by Liming Shao on 2018/12/10.
//

#ifndef USEOPENSSL_HASH_H
#define USEOPENSSL_HASH_H

#include <string>

std::string md5(const unsigned char *in,  int len);

std::string sha1(const unsigned char *in, int len);

std::string sha256(const unsigned char *in, int len);

std::string sha512(const unsigned char *in, int len);


#endif //USEOPENSSL_HASH_H
