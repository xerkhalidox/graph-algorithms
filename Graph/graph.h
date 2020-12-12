#include <iostream>
#include <vector>
#include <utility>
#include <queue>

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

    void doDFS(int node)
    {
        std::vector<int> visited(numberOfNodes + 1, 0);
        dfs(node, visited);
        for (int i = 0; i < numberOfNodes; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited);
            }
        }
    }

    void dfs(int node, std::vector<int> &visited)
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
                dfs(item.first, visited);
            }
        }
    }

    void doBFS(int node)
    {
        std::vector<int> visited(numberOfNodes + 1, 0);
        bfs(node, visited);
        for (int i = 0; i < numberOfNodes; i++)
        {
            if (!visited[i])
            {
                bfs(i, visited);
            }
        }
    }

    void bfs(int node, std::vector<int> &visited)
    {
        std::queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int currNode = q.front();
            std::cout << currNode << std::endl;
            visited[currNode] = 1;
            q.pop();
            for (auto &item : vertices[currNode])
            {
                if (!visited[item.first])
                {
                    q.push(item.first);
                }
            }
        }
    }

    bool detectCycles(int node)
    {
        doDFS(node);
        return cycleDetected ? true : false;
    }
};