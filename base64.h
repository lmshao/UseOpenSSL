//
// Created by LimingShao on 2018/12/11.
//

#ifndef USEOPENSSL_BASE64_H
#define USEOPENSSL_BASE64_H

#include <string>
#include <vector>

bool base64Encode(const std::vector<unsigned char> &in, std::string &out);

bool base64Decode(const std::string &in, std::vector<unsigned char> &out);

#endif //USEOPENSSL_BASE64_H
