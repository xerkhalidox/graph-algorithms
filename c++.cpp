#include "Graph/graph.h"

using namespace std;

int main()
{
    Graph<char> *graph = new Graph<char>(2);
    graph->addEdge(0, 1, 'k');
    graph->addEdge(1, 0, 'h');
    graph->addEdge(2, 2, 'a');
    graph->printVertices();
    return 0;
}
