//
// Created by Pankaj Birat on 13/12/18.
//

#ifndef DSA_GRAPH_H
#define DSA_GRAPH_H

#endif //DSA_GRAPH_H

#include "../../common/headers.hpp"

template <class T>
class unweighted_graph {
private:
    vector<vector<T> > vertex;
    int numVertex;
public:
    unweighted_graph(int numVertex) {
        this->numVertex = numVertex;
        vertex.reserve(numVertex);
    }
    void addEdge(int source, int destination);
    vector<pair<T,int> > shortestPath(int source);
    vector<T> dfs();
    vector<T> bfs();
};