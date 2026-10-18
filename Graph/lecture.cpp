#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    // adjacency list
    unordered_map<int, vector<int>> adjList;
    // direction=1 ->directed graph
    // direction=0 ->undirected graph

    void addEdge(int u, int v, bool direction)
    {
        if (direction == 1)
        {
            // directed edge to u->v ,v->u
            adjList[u].push_back(v);
        }
        else
        {
            // undirected edge
            //  u--v equivalent to u->v,v->u
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    
    void printAdjacencyList(){
        for(auto i :adjList){
            // i ->recored or pair of key and value 
            // i.first->int 
            //i.second->vector<int>
            cout<<i.first<<": ";
            cout<<"{";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<"}"<<endl;
        }
    }

};

int main()
{
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
   // g.addEdge(1,2,1);

    // graph looks like 0->1->2->3->4
    
    g.printAdjacencyList();


    return 0;
}