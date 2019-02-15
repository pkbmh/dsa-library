//
// Created by Pankaj Birat on 20/12/18.
//

#ifndef DSA_EDGE_H
#define DSA_EDGE_H

#endif //DSA_EDGE_H

template <class T>
class edge {
protected:
    T source;
    T destination;
    edge(T source, T destination) {
        this->source = source;
        this->destination = destination;
    }
public:
    T getSource() {
        return source;
    }
    T getDestination(){
        return destination;
    }
};