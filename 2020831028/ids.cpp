#include <bits/stdc++.h>

using namespace std;

// Function to perform Depth First Search (DFS)
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

        // If target node is found, return true
        if (currentNode == targetNode)
        {
            return true;
        }

        // Visit all adjacent nodes
        for (int neighbor : adjacencyList[currentNode])
        {
            if (!visited[neighbor])
            {
                nodeStack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    // Target node not found
    return false;
}

// Function to perform Iterative Deepening Search (IDS)
bool iterativeDeepeningSearch(int startNode, int targetNode, vector<vector<int>> &adjacencyList)
{
    int maxDepth = adjacencyList.size(); // Maximum depth to explore

    for (int depth = 0; depth <= maxDepth; depth++)
    {
        stack<int> nodeStack;
        vector<bool> visited(adjacencyList.size(), false);

        nodeStack.push(startNode);
        visited[startNode] = true;

        while (!nodeStack.empty())
        {
            int currentNode = nodeStack.top();
            nodeStack.pop();

            // If target node is found, return true
            if (currentNode == targetNode)
            {
                return true;
            }

            // Check if the current depth is within the limit
            if (depth > 0 && depth >= nodeStack.size())
            {
                continue;
            }

            // Visit all adjacent nodes
            for (int neighbor : adjacencyList[currentNode])
            {
                if (!visited[neighbor])
                {
                    nodeStack.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    // Target node not found
    return false;
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
        {9},    // Node 5 is connected to node 9
        {},     // Node 6 has no connections
        {},     // Node 7 has no connections
        {},     // Node 8 has no connections
        {}      // Node 9 has no connections
    };

    int startNode = 0;
    int targetNode = 9;

    // Perform Depth First Search (DFS)
    bool dfsResult = depthFirstSearch(startNode, targetNode, adjacencyList);
    cout << "DFS Result: " << (dfsResult ? "Found" : "Not Found") << endl;

    // Perform Iterative Deepening Search (IDS)
    bool idsResult = iterativeDeepeningSearch(startNode, targetNode, adjacencyList);
    cout << "IDS Result: " << (idsResult ? "Found" : "Not Found") << endl;

    return 0;
}
