#ifndef _ALGORITHM_H
#define _ALGORITHM_H
#include "graph.h"
class BFS
{
    const Graph& graph;
public:
    typedef set<Node*>::const_iterator node_iterator;
    BFS(const Graph& agraph) : graph(agraph) {}
    static bool connected(Node* begin, Node* end);
};
#endif
