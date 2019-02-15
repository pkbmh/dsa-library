//
// Created by Pankaj Birat on 13/12/18.
//

#ifndef DSA_GRAPH_TRAVERSER_H
#define DSA_GRAPH_TRAVERSER_H

#endif //DSA_GRAPH_TRAVERSER_H

#include "unweighted_graph.hpp"

template <class T>
class graph_traverser {
public:
    static void dfs(unweighted_graph<T> graph);
    static void bfs(unweighted_graph<T> graph);
};