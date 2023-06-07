#include <iostream>
#include "graph.cpp"
#include "graph.h"
using namespace std;

int main()
{
    bool direction = true;
    Graph graph(direction);

    graph.addVertice('A');
    graph.addVertice('B');
    graph.addVertice('C');
    graph.addVertice('D');
    graph.addVertice('E');

    graph.addEdge('A', 'B');
    graph.addEdge('A', 'D');
    graph.addEdge('A', 'E');

    graph.addEdge('B', 'A');
    graph.addEdge('B', 'D');
    graph.addEdge('B', 'C');

    graph.addEdge('C', 'D');
    graph.addEdge('D', 'A');

    graph.addEdge('E', 'C');
    graph.addEdge('E', 'A');

    graph.neighbours('A');
    graph.neighbours('B');

    cout << "Removing Edge A and D" << endl;
    graph.removeEdge('A', 'D');
    graph.neighbours('A');

    cout << "The outdegree of A is " << graph.outdegree('A');
    cout << "Number of Vertice: " << graph.numVertices() << endl;
    cout << "Is B and A neighbour: " << graph.neighbour('A', 'B') << endl;

    // Print the indegree and degree of vertex 'A'
    cout << "Indegree of vertex A:: " << graph.indegree('A') << endl;
    cout << "Degree of vertex A: " << graph.degree('A') << endl;

    // Remove vertex 'B' and print the updated graph information

    graph.removeVertice('B');
    cout << "Number of vertices after removing B: " << graph.numVertices() << endl;
    cout << "Number of edges after removing B: " << graph.numEdges() << endl;

    return 0;
}

// #include <iostream>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

// using namespace std;

// class Graph
// {
// private:
//     unordered_map<int, unordered_set<int>> adjacencyList;
//     bool directed;

// public:
//     Graph(bool isDirected = false)
//     {
//         directed = isDirected;
//     }

//     bool isEmpty()
//     {
//         return adjacencyList.empty();
//     }

//     bool isDirected()
//     {
//         return directed;
//     }

//     void addVertex(int newVertex)
//     {
//         if (adjacencyList.find(newVertex) == adjacencyList.end())
//         {
//             adjacencyList[newVertex] = unordered_set<int>();
//         }
//     }

//     void addEdge(int vertex1, int vertex2)
//     {
//         addVertex(vertex1);
//         addVertex(vertex2);

//         adjacencyList[vertex1].insert(vertex2);

//         if (!directed)
//         {
//             adjacencyList[vertex2].insert(vertex1);
//         }
//     }

//     void removeVertex(int vertexToRemove)
//     {
//         if (adjacencyList.find(vertexToRemove) != adjacencyList.end())
//         {
//             for (auto &pair : adjacencyList)
//             {
//                 pair.second.erase(vertexToRemove);
//             }
//             adjacencyList.erase(vertexToRemove);
//         }
//     }

//     void removeEdge(int vertex1, int vertex2)
//     {
//         if (adjacencyList.find(vertex1) != adjacencyList.end())
//         {
//             adjacencyList[vertex1].erase(vertex2);
//         }
//         if (!directed && adjacencyList.find(vertex2) != adjacencyList.end())
//         {
//             adjacencyList[vertex2].erase(vertex1);
//         }
//     }

//     int numVertices()
//     {
//         return adjacencyList.size();
//     }

//     int numEdges()
//     {
//         int count = 0;
//         for (const auto &pair : adjacencyList)
//         {
//             count += pair.second.size();
//         }
//         if (!directed)
//         {
//             count /= 2;
//         }
//         return count;
//     }

//     int indegree(int vertex)
//     {
//         int count = 0;
//         for (const auto &pair : adjacencyList)
//         {
//             if (pair.second.find(vertex) != pair.second.end())
//             {
//                 count++;
//             }
//         }
//         return count;
//     }

//     int outdegree(int vertex)
//     {
//         if (adjacencyList.find(vertex) != adjacencyList.end())
//         {
//             return adjacencyList[vertex].size();
//         }
//         return 0;
//     }

//     int degree(int vertex)
//     {
//         return indegree(vertex) + outdegree(vertex);
//     }

//     vector<int> neighbours(int vertex)
//     {
//         vector<int> result;
//         if (adjacencyList.find(vertex) != adjacencyList.end())
//         {
//             for (const auto &neighbour : adjacencyList[vertex])
//             {
//                 result.push_back(neighbour);
//             }
//         }
//         return result;
//     }

//     bool neighbour(int vertex1, int vertex2)
//     {
//         if (adjacencyList.find(vertex1) != adjacencyList.end())
//         {
//             return adjacencyList[vertex1].find(vertex2) != adjacencyList[vertex1].end();
//         }
//         return false;
//     }
// };

// // Test program
// int main()
// {
//     Graph graph(true);

//     graph.addVertex(1);
//     graph.addVertex(2);
//     graph.addVertex(3);
//     graph.addVertex(4);

//     graph.addEdge(1, 2);
//     graph.addEdge(2, 3);
//     graph.addEdge(3, 1);
//     graph.addEdge(4, 1);

//     cout << "Number of vertices: " << graph.numVertices() << endl;
//     cout << "Number of edges: " << graph.numEdges() << endl;
//     cout << "Vertex 1 indegree: " << graph.indegree(1) << endl;
// }