#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Graph{
    public:
    vector<vector<int>> vertices;
    Graph(int numberOfNodes):vertices(numberOfNodes, vector<int>(0)){}

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
};

int main()
{
    Graph *graph=new Graph(2);
    graph->addEdge(0,5);
    graph->addEdge(0,4);
    graph->addEdge(1,6);
    graph->addEdge(2,6);
    graph->printVertices();
    return 0;
}



