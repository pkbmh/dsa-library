//
// Created by Pankaj Birat on 20/12/18.
//

#ifndef DSA_GRAPH_H
#define DSA_GRAPH_H
#include "../../common/headers.hpp"
#include "edge.hpp"

#endif //DSA_GRAPH_H
template <class T>
class graph {
protected:
    int numVertex;
public:
    vector<vector<edge<T> > > vertex;

    graph(int numVertex):numVertex(numVertex){
        vertex.reserve(numVertex);
    }

    virtual void addEdge(T source, T destination)=0;
    virtual vector<pair<T,int> > shortestPath(T source)=0;
    vector<T> dfs(const T &source);
    vector<T> bfs(const T &source);

private:
    vector<T> _dfs(const T &source, vector<T> &result, unordered_set<T> &visited);
    vector<T> _bfs(const T &source, vector<T> &result, unordered_set<T> &visited);
};

template <class T>
vector<T> graph<T>::dfs(const T &source) {
    vector<T> result(numVertex);
    unordered_set<T> visited;
    _dfs(source, result, visited);
    visited.clear();
}
template <class T>
vector<T> graph<T>::_dfs(const T &source, vector<T> &result, unordered_set<T> &visited) {
    if(visited.find(source) == visited.end()) {
        visited.insert(source);
        for(T t : )
    }
}

template <class T>
vector<T> graph<T>::bfs(const T &source) {
    vector<T> result(numVertex);
    unordered_set<T> visited;
    _bfs(source, result, visited);
    visited.clear();
}
template <class T>
vector<T> graph<T>::_bfs(const T &source, vector<T> &result, unordered_set<T> &visited) {

}