#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#include "algorithm.h"
#include "graph.h"
using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    if (argc != 2)
    {
        cout<<"Должен быть только input.txt файл"<<endl;
        return 1;
    }
    const char* name = argv[1];
    ifstream file(name);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    Graph graph(file);
    file.close();

    BFS bfs(graph);
    set<Node*> visited;
    vector<set<Node*>> components;

    for (Node* node : graph.getNodes()) {
        if (visited.find(node) == visited.end()) {
            set<Node*> component;
            queue<Node*> q;
            q.push(node);
            visited.insert(node);

            while (!q.empty()) {
                Node* current = q.front();
                q.pop();
                component.insert(current);

                for (auto it = current->nb_begin(); it != current->nb_end(); ++it) {
                    Node* neighbor = *it;
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }

            components.push_back(component);
        }
    }
    for (size_t i = 0; i < components.size(); ++i) {
        string outputFilename = "out" + to_string(i+1) + ".txt";
        graph.writeComponentToFile(outputFilename, components[i]);
    }

    cout << "Программа завершена!" << endl;

    return 0;
}
