#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template <typename T>
class Graph{
    public:
        vector<vector<pair<int, T>>> vertices;
        int numberOfNodes{0};
        bool cycleDetected{false};

        Graph(int _numberOfNodes):vertices(_numberOfNodes+1, vector<pair<int, T>>(0)), numberOfNodes(_numberOfNodes+1) {}

        void addEdge(int vertex, int adj, T data){
            vertices.at(vertex).push_back(make_pair(adj, data));
        }

        void printVertices(){
            int i=0;
            for(auto &vertex: vertices){
                cout<<i;
                for(auto &edge:vertex){
                    cout<<"->"<<edge.first<<" & "<<edge.second;
                }
                cout<<endl;
                i++;
            }
        }

        int size(){
            return numberOfNodes-1;
        }
        
        void dfs(int node){
            vector<int> visited(numberOfNodes+1,0);
            discover(node, visited);
           for(int i=0;i<numberOfNodes;i++){
               if(!visited[i]){
                   discover(i, visited);
               }
           }
        }

        void discover(int node, vector<int> &visited){
            visited[node]=1;
            cout<<node<<endl;
            for(auto &item:vertices[node]){
                if(item.first==node){
                    cycleDetected=true;
                }
                if(!visited[item.first]){
                    discover(item.first, visited);
                }
            }
        }

        bool detectCycles(int node){
           dfs(node);
           return cycleDetected?true:false;
        }
};

int main()
{
    Graph<int> *graph=new Graph<int>(2);
    graph->addEdge(0, 1, 5);
    graph->addEdge(1, 0, 2);
    graph->addEdge(2, 2, 4);
     bool cycle=graph->detectCycles(2);
     cout<<cycle<<endl;
    return 0;
}




