//
// Created by Pankaj Birat on 13/12/18.
//

#ifndef DSA_GRAPH_H
#define DSA_GRAPH_H

#endif //DSA_GRAPH_H

#include "graph.hpp"
#include "../../common/headers.hpp"
#include "edge.hpp"

template <class T>
class unweighted_graph : public graph<T> {
public:
    unweighted_graph(int numVertex): graph<T>(numVertex) {

    }
    void addEdge(int source, int destination) {
        vertex[source].push_back(edge<T>(source, destination));
    }
    vector<pair<T,int> > shortestPath(int source);
    vector<T> dfs();
    vector<T> bfs();
};