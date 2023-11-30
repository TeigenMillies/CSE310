#include "graph.h"

int main(int argc, char* argv[]) {
    // Extract graph filename and direction from command-line arguments
    string graphFilename = argv[1];
    string direction = argv[2];
    /*
    // Create an instance of the Graph class
    graph = new Graph()

    // Load the graph from the specified file
    if not graph.loadGraph(graphFilename, direction)
        print "Failed to load the graph."
        return 1

    // Process queries until the "stop" query is received
    while true
        // Read the next query from the user
        query = readInput()

        // Check the type of query
        if query is "find"
            // Read source, destination, and flag from user
            source, destination, flag = readInput()

            // Run Dijkstra's algorithm on the graph
            graph.runDijkstra(source, destination, flag)

        else if query is "write"
            // Read action, source, and destination from user
            action, source, destination = readInput()

            // Write the path based on the action
            graph.writePath(source, destination)

        else if query is "stop"
            // Exit the program
            return 0

        else
            // Invalid query, print an error message
            print "Invalid query. Please use 'find', 'write', or 'stop'."

    */
}
