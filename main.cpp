#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Graph {
public:
    Graph();
    int numberOfNodes = 0;
    map<int, vector<int>> adjacentList;

    void addVertex(int node);
    void addEdge(int node1, int node2);
    void showConnections();
};

Graph::Graph() {
    
}

void Graph::addVertex(int node) {
    if (adjacentList.find(node) == adjacentList.end()) {
        adjacentList[node] = {};
        numberOfNodes++;
    } else {
        return;
    }
}

void Graph::addEdge(int node1, int node2) {
    // undirected Graph
    adjacentList[node1].push_back(node2);
    adjacentList[node2].push_back(node1);
}

void Graph::showConnections() {
    vector<int> allNodes;
    for (int i = 0; i < numberOfNodes; i++)
        allNodes.push_back(i);
    for (int node: allNodes) {
        vector<int> nodeConnections = adjacentList[node];
        string connections = "";
        for (int vertex: nodeConnections)
            connections += to_string(vertex) + " ";
        cout << to_string(node) + "-->" + connections << endl;
    }
    
}


int main(){
    Graph *myGraph = new Graph();
    myGraph->addVertex(0);
    myGraph->addVertex(0);
    myGraph->addVertex(1);
    myGraph->addVertex(2);
    myGraph->addVertex(3);
    myGraph->addVertex(4);
    myGraph->addVertex(5);
    myGraph->addVertex(6);
    myGraph->addEdge(3, 1);
    myGraph->addEdge(3, 4);
    myGraph->addEdge(4, 2);
    myGraph->addEdge(4, 5);
    myGraph->addEdge(1, 2);
    myGraph->addEdge(1, 0);
    myGraph->addEdge(0, 2);
    myGraph->addEdge(6, 5);
    myGraph->showConnections();

    // Edge List
    vector<vector<int>> graph = {{0, 2}, {2, 3}, {2, 1}, {1, 3}};
    
    // Adjacent List (goes with index)
    graph = {{2}, {2, 3}, {0, 1, 3}, {1, 2}};
    
    // Adjacent Matrix if Node x has a connection to Node y -> 0 means no| 1 means yes
    // outer index is x
    // inner index is y
    graph = {
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    
    cout << endl;
    return 0;
}