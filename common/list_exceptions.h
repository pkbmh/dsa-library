//
// Created by Pankaj Birat on 28/11/18.
//

#ifndef DSA_LIST_EXCEPTIONS_H
#define DSA_LIST_EXCEPTIONS_H

#endif //DSA_LIST_EXCEPTIONS_H

#include "headers.h"

class no_such_element_exception : public runtime_error
{
public:
    explicit no_such_element_exception(char const* const message) throw() : runtime_error(message){
    }

    char const* what() const noexcept override {
        return runtime_error::what();
    };
};
