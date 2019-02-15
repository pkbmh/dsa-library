//
// Created by Pankaj Birat on 20/12/18.
//

#ifndef DSA_WEIGHTED_EDGE_H
#define DSA_WEIGHTED_EDGE_H

#endif //DSA_WEIGHTED_EDGE_H

#include "edge.hpp"

template <class T>
class weighted_edge: public edge<T> {
private:
    double weight;
public:
    weighted_edge(T source, T destination, double weight) : edge<T>(source, destination) {
        this->weight = weight;
    }

    double getWeight() {
        return weight;
    }
};