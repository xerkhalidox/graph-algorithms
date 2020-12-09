#include <iostream>
#include <vector>
#include <utility>

template <typename T>
class Graph
{
private:
    std::vector<std::vector<std::pair<int, T>>> vertices;
    int numberOfNodes{0};
    bool cycleDetected{false};

public:
    Graph(int _numberOfNodes) : vertices(_numberOfNodes + 1, std::vector<std::pair<int, T>>(0)), numberOfNodes(_numberOfNodes + 1) {}

    void addEdge(int vertex, int adj, T data)
    {
        vertices.at(vertex).push_back(std::make_pair(adj, data));
    }

    void printVertices()
    {
        int i = 0;
        for (auto &vertex : vertices)
        {
            std::cout << i;
            for (auto &edge : vertex)
            {
                std::cout << "->" << edge.first << " & " << edge.second;
            }
            std::cout << std::endl;
            i++;
        }
    }

    int size()
    {
        return numberOfNodes - 1;
    }

    void dfs(int node)
    {
        std::vector<int> visited(numberOfNodes + 1, 0);
        discover(node, visited);
        for (int i = 0; i < numberOfNodes; i++)
        {
            if (!visited[i])
            {
                discover(i, visited);
            }
        }
    }

    void discover(int node, std::vector<int> &visited)
    {
        visited[node] = 1;
        std::cout << node << std::endl;
        for (auto &item : vertices[node])
        {
            if (item.first == node)
            {
                cycleDetected = true;
            }
            if (!visited[item.first])
            {
                discover(item.first, visited);
            }
        }
    }

    bool detectCycles(int node)
    {
        dfs(node);
        return cycleDetected ? true : false;
    }
};