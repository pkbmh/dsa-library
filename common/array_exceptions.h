//
// Created by Pankaj Birat on 28/11/18.
//

#ifndef SPOJ_EXCEPTIONS_H
#define SPOJ_EXCEPTIONS_H

#include "../common/headers.h"

class array_index_out_of_bound : public runtime_error
{
public:
    explicit array_index_out_of_bound(char const* const message) throw() : runtime_error(message){
    }

    char const* what() const noexcept override {
        return runtime_error::what();
    };
};

class negative_index_exception : public runtime_error {
public:
    explicit negative_index_exception(char const* const message) throw() : runtime_error(message){
    }

    char const* what() const noexcept override {
        return runtime_error::what();
    };
};

#endif //SPOJ_EXCEPTIONS_H
