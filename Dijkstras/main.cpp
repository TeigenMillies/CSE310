#include "graph.h"

int main(int argc, char* argv[]) {
    // Extract graph filename and direction from command-line arguments
    //string graphFilename = "network01.txt";
    //string direction = "undirected";
    string graphFilename = argv[1];
    string direction = argv[2];
    
    // Create an instance of the Graph class
    Graph *graph = new Graph();

    // Load the graph from the specified file
    if (!graph->loadGraph(graphFilename, direction)) {
        cerr << "Failed to load the graph." << endl;
        return 1;
    }
    
    // Process queries until the "stop" query is received
    while(true) {
        // Read the next query from the user
        string query;
        cin >> query;

        // Check the type of query
        if (query == "find") {
            // Read source, destination, and flag from user
            int source, destination, flag;
            cin >> source;
            cin >> destination;
            cin >> flag;

            // Run Dijkstra's algorithm on the graph
            graph->runDijkstra(source, destination, flag);
        }
        else if(query == "write") {
            // Read action, source, and destination from user
            string action;
            int source, destination;
            cin >> action;
            cin >> source;
            cin >> destination;

            // Write the path based on the action
            graph->writePath(source, destination);
        }
        else if (query == "stop") {
            // Exit the program
            return 0;
        }
        else if (query == "plist")
            graph->printAdjacencyLists();
        else
            // Invalid query, print an error message
            cout << "Invalid query. Please use 'find', 'write', or 'stop'." << endl;
    }
}
