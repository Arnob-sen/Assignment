#include <bits/stdc++.h>

using namespace std;

// Function to perform Depth-Limited Search (DLS)
bool depthLimitedSearch(int currentNode, int targetNode, int remainingDepth, vector<vector<int>> &adjacencyList)
{
    // If the remaining depth is 0 and the current node matches the target node, return true
    if (remainingDepth == 0 && currentNode == targetNode)
    {
        return true; // Target node found within the depth limit
    }
    // If the remaining depth is greater than 0, continue exploring the graph
    if (remainingDepth > 0)
    {
        // Explore all neighbors of the current node
        for (int neighbor : adjacencyList[currentNode])
        {
            // Recursively perform DLS on the neighbor nodes with decreased depth limit
            if (depthLimitedSearch(neighbor, targetNode, remainingDepth - 1, adjacencyList))
            {
                return true; // Target node found in the subtree
            }
        }
    }
    return false; // Target node not found within the depth limit
}

// Function to perform Depth-First Search (DFS)
bool depthFirstSearch(int startNode, int targetNode, vector<vector<int>> &adjacencyList)
{
    stack<int> nodeStack;
    vector<bool> visited(adjacencyList.size(), false);

    nodeStack.push(startNode);
    visited[startNode] = true;

    while (!nodeStack.empty())
    {
        int currentNode = nodeStack.top();
        nodeStack.pop();

        // If the current node matches the target node, return true
        if (currentNode == targetNode)
        {
            return true; // Target node found
        }

        // Visit all adjacent nodes of the current node
        for (int neighbor : adjacencyList[currentNode])
        {
            if (!visited[neighbor])
            {
                nodeStack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false; // Target node not found
}

int main()
{
    // Example usage
    vector<vector<int>> adjacencyList = {
        {1, 2}, // Node 0 is connected to nodes 1 and 2
        {3, 4}, // Node 1 is connected to nodes 3 and 4
        {5},    // Node 2 is connected to node 5
        {6, 7}, // Node 3 is connected to nodes 6 and 7
        {8},    // Node 4 is connected to node 8
        {},     // Node 5 has no outgoing edges
        {},     // Node 6 has no outgoing edges
        {},     // Node 7 has no outgoing edges
        {}      // Node 8 has no outgoing edges
    };

    int startNode = 0;
    int targetNode = 8;
    int depthLimit = 3;

    // Perform Depth-Limited Search (DLS)
    bool foundDLS = depthLimitedSearch(startNode, targetNode, depthLimit, adjacencyList);

    // Perform Depth-First Search (DFS)
    bool foundDFS = depthFirstSearch(startNode, targetNode, adjacencyList);

    cout << "Depth-Limited Search: " << (foundDLS ? "Target found" : "Target not found") << endl;
    cout << "Depth-First Search: " << (foundDFS ? "Target found" : "Target not found") << endl;

    return 0;
}
