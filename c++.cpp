#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
    public:
    vector<vector<int>> vertices;
    int numberOfNodes;
    Graph(int _numberOfNodes):vertices(_numberOfNodes+1, vector<int>(0)), numberOfNodes(_numberOfNodes+1) {}

    void addEdge(int vertex, int data){
        vertices.at(vertex).push_back(data);
    }

    void printVertices(){
        int i=0;
        for(auto &vertex: vertices){
            cout<<i;
            for(auto &edge:vertex){
                cout<<"->"<<edge;
            }
            cout<<endl;
            i++;
        }
    }

    int size(){
        return numberOfNodes-1;
    }
    
    void dfs(int node){
        vector<int> visited(numberOfNodes,0);
        discover(node, visited);
    }
    void discover(int node, vector<int> &visited){
        visited[node]=1;
        cout<<node<<endl;
        for(auto &item:vertices[node]){
            if(!visited[item]){
                discover(item, visited);
            }
        }
    }
};

int main()
{
    Graph *graph=new Graph(4);
    graph->addEdge(1, 2);
    graph->addEdge(0, 2);
    graph->addEdge(0, 1);
    graph->addEdge(2, 0);
    graph->addEdge(2, 3);
    graph->addEdge(3, 3);
    graph->dfs(2);
    return 0;
}




