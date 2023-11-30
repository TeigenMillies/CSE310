#include "graph.h"

int main(int argc, char* argv[]) {
    // Extract graph filename and direction from command-line arguments
    string graphFilename = argv[1];
    string direction = argv[2];
    
    // Create an instance of the Graph class
    Graph *graph = new Graph();

    // Load the graph from the specified file
    if (!graph->loadGraph(graphFilename, direction)) {
        cerr << "Failed to load the graph." << endl;
        return 1;
    }
    graph->printAdjacencyLists();

    // Process queries until the "stop" query is received
    /*
    while (true) {

    }
    */
}
