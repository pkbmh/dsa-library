//
// Created by Pankaj Birat on 28/11/18.
//

#include "headers.hpp"

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
