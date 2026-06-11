/*
Problem: Graphs Introduction
        Building, Inserting edge
Link: NA
Difficulty: Easy
Approach: -
Time Complexity: -
Note:
    A graph class stores the number of nodes present in the graph and the adjacenecy matrix of the graph,
    which is basically a 2D matrix of max size VxV where neighbours of each node are stored in a list<int>

    basically tells what node is connected to what other node

    if it is a weighted graph => then instead of passing neighbour to a node's adj list, pass a pair {neighbour, weight},
    so if a pair exists => that edge exists => what's the weight for that edge? you have it paired the neighbour
    => vector<pair<int, int>> adjList


    alternatively, a VxV matrix can also be maintained for weighted/non-weight, directed/undirected graphs too
    where in for eg: an edge between u and v will have adjMat[u][v] = 1;
    eg:
            for the graph: 
                0 --- 1
                |     |
                |     |
                2 --- 3
            
            edges:
                (0,1)
                (0,2)
                (1,3)
                (2,3)
            
            adjMat:
                     0 1 2 3
                 -----------
                 0 | 0 1 1 0
                 1 | 1 0 0 1
                 2 | 1 0 0 1
                 3 | 0 1 1 0

*/

#include<bits/stdc++.h>
using namespace std;

// GRAPH CLASS
class Graph{
    int V;
    vector<list<int>> adjList;       // SC = O(2V)

public:
    // CONSTRUCTING
    Graph(int V){
        this->V = V;
        adjList.resize(V);
    }

    // ADDING AN EDGE (assuming an undirected unweighted graph)
    void addEdge(int u, int v){
        adjList[u].push_back(v);     // add v to u's neighbour
        adjList[v].push_back(u);     // add u to v's neighbour (not reqd if directed)
                                    // also, SC = O(V) instead of 2V for directed
    }

    // PRINT ADJACENCY LIST
    void printAdjMat(){
        for (int i=0; i<V; i++){
            cout << i << " : ";
            for (auto& neigh : adjList[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.printAdjMat();

    return 0;
}