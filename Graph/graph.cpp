#include <iostream>
#include <fstream>
#include "graph.h"
#include "algorithm.h"

using namespace std;

Graph::Graph(ifstream& file)
{
    if(!file.is_open())
    {
        throw Error();
    }

    string heading;
    getline(file, heading);
    string sNode, tNode;
    while(file)
    {
        file>>sNode>>tNode;
        addEdgeString(sNode, tNode);
    }
}

void Graph::addNode(Node* node)
{
    nodes.insert(node);
}

void Graph::removeNode(Node* node)
{
    nodes.erase(node);
    for (std::set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        (*it)->removeNeighbours(node);
    }
}

void Graph::addEdge(Node* begin, Node* end)
{
    if(nodes.find(begin) == nodes.end())
        throw Error();
    if(nodes.find(end) == nodes.end())
        throw Error();
    begin->addNeighbours(end);
    end->addNeighbours(begin);
}

void Graph::addEdgeString(string start, string finish)
{
    Node* source = getOrCreate(start);
    Node* target = getOrCreate(finish);
    addEdge(source, target);
}


void Graph::removeEdge(Node* begin, Node* end)
{
    if(nodes.find(begin) == nodes.end())
        throw Error();
    if(nodes.find(end) == nodes.end())
        throw Error();
    begin->removeNeighbours(end);
    end->removeNeighbours(begin);
}

void Node::addNeighbours(Node* neighbour)
{
    if(neighbour == 0)
        throw Error();
    neighbours.insert(neighbour);
    neighbour->neighbours.insert(this);
}

void Node::removeNeighbours(Node* neighbour)
{
    if(neighbour == 0 || neighbour == this)
        throw Error();
    neighbours.erase(neighbour);
    neighbour->neighbours.erase(this);
}

Node* Graph::getOrCreate(const string& name)
{
    Node* existingNode = findNode(name);
    if (existingNode != nullptr) {
        return existingNode;
    }
    Node* newNode = new Node(name);
    nodes.insert(newNode);
    return newNode;
}

Node* Graph::findNode(const string& name) const
{
    for (Node* node : nodes) {
        if (node->getName() == name) {
            return node;
        }
    }
    return nullptr;
}

Graph::~Graph()
{
    for(Node* node : nodes) {
        delete node;
    }
}

void Graph::writeComponentToFile(const string& filename, const set<Node*>& component) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Ошибка в открытии файла: " << filename << endl;
        return;
    }

    out << "Sourse"<<"\t"<<"Target"<<'\n';

    set<pair<string, string>> writtenEdges;

    for (Node* node : component) {
        for (auto it = node->nb_begin(); it != node->nb_end(); ++it) {
            Node* neighbor = *it;
            if (writtenEdges.find({node->getName(), neighbor->getName()}) == writtenEdges.end() &&
                writtenEdges.find({neighbor->getName(), node->getName()}) == writtenEdges.end()) {
                out << node->getName() << "\t" << neighbor->getName() << "\n";
                writtenEdges.insert({node->getName(), neighbor->getName()});
            }
        }
    }

    out.close();
}
