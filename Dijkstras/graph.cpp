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

    

    while (getline(file, line)) {
        int edgeId, startNode, endNode;
        double weight;
        istringstream iss(line);
        if (iss >> edgeId >> source >> endNode >> weight) {
            startNode++;
            endNode++;

            Edge* reverseEdge = new Edge;
            reverseEdge->destination = endNode;
            reverseEdge->weight = weight;

            if (adjacencyLists[startNode]) {                //missing something
                adjacencyLists[startNode] = new Edge[numEdges];
            }

            int j = 0;
            while (adjacencyLists[startNode][j].destination != 0) {
                j++;
            }
            adjacencyLists[startNode][j] = *reverseEdge;

            if (direction == "undirected") {
                Edge* reverseEdge = new Edge;
                edge->destination = startNode;
                edge->weight = weight;

                if (adjacencyLists[endNode]) {                //missing something
                adjacencyLists[endNode] = new Edge[numEdges];
            }

            int j = 0;
            while (adjacencyLists[endNode][j].destination != 0) {
                j++;
            }
            adjacencyLists[endNode][j] = *edge;
            }

        } else {
            cerr << "Invalid Input" << endl;
        }
        
    }
    
}