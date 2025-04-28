#ifndef _GRAPH_H
#define _GRAPH_H
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

class Error{

};

class Node{
    typedef set<Node*>::const_iterator node_iterator;
    string name;
    set <Node*> neighbours;
    void addNeighbours(Node* neighbours);
    void removeNeighbours(Node* neighbours);
public:
    Node(const string& aname) : name(aname) {}
    const std::set<Node*>& getNeighbors() const {return neighbours;}
    const string& getName() const {return name; }
    node_iterator nb_begin() const {return neighbours.begin(); }
    node_iterator nb_end() const {return neighbours.end(); }
    friend class Graph;
};

class Graph{
    set<Node*> nodes;
    typedef set<Node*>::const_iterator node_iterator;
    void addEdge(Node* begin, Node* end);
public:
    Graph() {}
    ~Graph();
    Graph(ifstream& file);
    Node* getOrCreate(const string& name);
    const set<Node*>& getNodes() const { return nodes; }
    void addNode(Node* node);
    void removeNode(Node* node);
    void removeEdge(Node* begin, Node* end);
    node_iterator begin() const {return nodes.begin(); }
    node_iterator end() const {return nodes.end();}
    Node* findNode(const string& name) const;
    void addEdgeString(string start, string finish);
    void writeComponentToFile(const string& filename, const set<Node*>& component);
};

#endif
