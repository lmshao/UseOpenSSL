//
// Created by LimingShao on 2018/12/11.
//

#include <iostream>
#include "base64.h"

#include "openssl/evp.h"
#include "openssl/bio.h"
#include "openssl/pem.h"

bool base64Encode(const std::vector<unsigned char> &in, std::string &out) {
    BIO *bio, *b64;
    BUF_MEM *bptr = nullptr;

    if (in.empty()) {
        std::cout << "base64Encode input is empty." << std::endl;
        return false;
    }

    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    bio = BIO_new(BIO_s_mem());
    BIO_push(b64, bio);

    BIO_write(b64, &in[0], (int)in.size());
    BIO_flush(b64);

    BIO_get_mem_ptr(bio, &bptr);
    out.assign(bptr->data, bptr->length);

    BIO_free_all(b64);
    return true;
}

bool base64Decode(const std::string &in, std::vector<unsigned char> &out) {
    BIO *bio, *b64;
    int size;
    char *buff;

    if (in.empty()) {
        std::cout << "base64Decode input is empty." << std::endl;
        return false;
    }

    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    bio = BIO_new_mem_buf(in.c_str(), (int)in.length());
    BIO_push(b64, bio);

    buff = new char[in.length()];
    size = BIO_read(b64, buff, (int)in.length());

    out.assign(buff, buff + size);
    BIO_free_all(bio);
    delete[] buff;
    return true;
}
