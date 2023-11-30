#include "graph.h"
#include "minheap.h"

using namespace std;
const double DOUBLE_MAX = 99999999.0;

Graph::Graph() {
    adjacencyLists = nullptr;
    numVertices = 0;
    numEdges = 0;
    source = -1;
    isDirected = false;
}
Graph::~Graph() {
    if (adjacencyLists) {
        for (int i = 0; i < numVertices; i++) {
            free (adjacencyLists[i]);
        }
        free (adjacencyLists);
    }
}

bool Graph::loadGraph (const string& filename, const string& direction) {
    ifstream file(filename);

    if(file.bad()){
        cout << "Failed to open the graph file." << endl;
        return false;
    }

    // Read the first line from the file
    string line;
    if (getline(file, line)) {
        // Parse the first line to get the number of vertices and edges
        int n, m;
        istringstream iss(line);
        if (iss >> n >> m) {
            numVertices = n + 1;
            numEdges = m;

            // Allocate memory for adjacencyLists
            adjacencyLists = new Edge*[numVertices];
            for (int i = 0; i < numVertices - 1; i++) {
                adjacencyLists[i] = nullptr;
            }
            // Allocate memory for extractedVertices, relaxedVertices, predecessor, and distance
            extractedVertices = new double[numVertices];
            relaxedVertices = new double[numVertices];
            predecessor = new int[numVertices];
            distance = new double[numVertices];
            for(int i = 0; i < numVertices - 1; i++) {
                extractedVertices[i] = -1;
                relaxedVertices[i] = -1;
            }
        }
        else {
            cerr << "Invalid format for the first line in the input file." << endl;
            return false;
        }
    } else {
        cerr << "Input file is empty" << endl;
        return false;
    }
    // Close the file and reopen it to read the content again
    file.close();
    file.open(filename, ios::in);

    // Check if the file is successfully reopened
    if (!file) {
        cerr << "Failed to reopen the graph file." << endl;
        return false;
    }

    // Read the first line again to skip it
    getline(file, line);
    
    // Loop through the remaining lines to read edges and build adjacency lists
    while (getline(file, line)) {
        int edgeId, startNode, endNode = 0;
        double weight = 0;
        istringstream iss(line);
        // Parse the line to get edge information
        if (iss >> edgeId >> startNode >> endNode >> weight) {
            startNode++;
            endNode++;

            // Check if node IDs are valid
            if (startNode > numVertices || endNode > numVertices || startNode < 1 || endNode < 1) {
                cerr << "Invalid node IDs in the input file." << endl;
                return false;
            }

            // Create a new edge
            Edge* edge = new Edge;
            edge->destination = endNode;
            edge->weight = weight;

            // Add edge to the adjacency list            
            if (adjacencyLists[startNode] == nullptr) {                
                adjacencyLists[startNode] = new Edge[numEdges];
            }

            int j = 0;
            // Find the next available slot in the adjacency list
            while (adjacencyLists[startNode][j].destination != 0) {
                j++;
            }

            // Add the edge to the list
            adjacencyLists[startNode][j] = *edge;

            // If the graph is undirected, add the reverse edge
            if (direction == "undirected") {
                Edge* reverseEdge = new Edge;
                reverseEdge->destination = startNode;
                reverseEdge->weight = weight;

                if (adjacencyLists[endNode] == nullptr) {
                adjacencyLists[endNode] = new Edge[numEdges];
                }

                j = 0;
                // Find the next available slot in the adjacency list
                while (adjacencyLists[endNode][j].destination != 0) {
                    j++;
                }
                // Add the reverse edge to the list
                adjacencyLists[endNode][j] = *reverseEdge;

                // Deallocate memory for the reverse edge
                free(reverseEdge);
            }
            // Deallocate memory for the edge
            free(edge);

        } else {
            cerr << "Invalid format for edge in the input file." << endl;
            return false;
        }
        
    }
    // Set the graph direction
    if (direction == "undirected")
        isDirected = false;
    else
        isDirected = true;
    
    // Close the file
    file.close();
    return true;
}

void Graph::printAdjacencyLists() {
    // Loop through each vertex in the graph
    for (int v = 0; v < numVertices - 1; v++) {
        cout << "Adjacency list for vertex " << v << ": ";

        // Check if the adjacency list for the current vertex exists
        if (adjacencyLists[v] != nullptr) {
            int j = 0;

            // Loop through each edge in the adjacency list
            while (adjacencyLists[v][j].destination != 0) {
                // Print the destination vertex and edge weight
                cout << "(" << adjacencyLists[v][j].destination << ", " << adjacencyLists[v][j].weight << ") ";

                //Move to the next edge in the list
                j++;
            }
        }
        // Print the predecessor value for the current vertex
        cout << "Predecessor: " << predecessor[v];
        cout << endl;
    }
}