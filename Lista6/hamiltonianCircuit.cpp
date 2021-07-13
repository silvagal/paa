#include <iostream>
#include <vector>

#define GRAPH_DIMENSION 6

typedef std::vector<std::vector<int>> matrix;

typedef struct vertex{
    bool visited;
} vertex;

typedef struct graph {
    matrix matrix_adj;
    std::vector<vertex> vertices;
} graph;

void printMatrix(matrix& matrix, int lines, int columns){
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

void generateGraph(graph& my_graph){
    std::vector<vertex> v(GRAPH_DIMENSION);
    for (int i = 0; i < GRAPH_DIMENSION; ++i)
        v[i].visited = false;

    my_graph.matrix_adj = {  //has solution
            {0,1,1,0,0,0},
            {1,0,1,0,1,1},
            {1,1,0,1,0,0},
            {0,0,1,0,1,0},
            {0,1,0,1,0,1},
            {1,1,0,0,1,0}
    };

//    my_graph.matrix_adj = {   //does not has solution
//            {0,1,1,0,0,0},
//            {1,0,0,1,0,0},
//            {1,0,0,1,1,1},
//            {0,1,1,0,0,0},
//            {0,0,1,0,0,1},
//            {0,0,1,0,1,0}
//    };
    my_graph.vertices = v;
}

std::vector<int> getAdjacencies(graph& my_graph, int vertex_idx){
    std::vector<int> adjacencies;
    for (int i = 1; i < GRAPH_DIMENSION; ++i)
        if (my_graph.matrix_adj[vertex_idx][i])
                adjacencies.push_back(i);
    return adjacencies;
}

bool hamiltonianCircuit(graph& my_graph, std::vector<int>& solution, int vertex_idx, int nodes_visited){
    if (nodes_visited == GRAPH_DIMENSION)
        if (my_graph.matrix_adj[solution[GRAPH_DIMENSION - 1]][0]) {
            solution[nodes_visited] = 0;
            return true;
        }
    std::vector<int> adjacent = getAdjacencies(my_graph, vertex_idx);
    for(int i=0;i<adjacent.size();i++) {
        if (!my_graph.vertices[adjacent[i]].visited) {
            my_graph.vertices[adjacent[i]].visited = true;
            solution[nodes_visited] = adjacent[i];
            if (hamiltonianCircuit(my_graph, solution, adjacent[i], nodes_visited + 1))
                return true;
            my_graph.vertices[adjacent[i]].visited = false;
            solution[nodes_visited] = -1;
        }
    }
    return false;
}

int main(){
    bool find_solution;
    graph my_graph;
    std::vector<int> solution(GRAPH_DIMENSION + 1, -1);

    generateGraph(my_graph);
    solution[0] = 0;
    my_graph.vertices[0].visited = true;

    std::cout << "Graph's matrix of adjacency: \n";
    printMatrix(my_graph.matrix_adj, GRAPH_DIMENSION, GRAPH_DIMENSION);
    find_solution = hamiltonianCircuit(my_graph, solution, 0, 1);

    if (find_solution) {
        std::cout << "\nsolution: ";
        for (auto i : solution)
            std::cout << "[" << i << "]" << " ";
    }
    else
        std::cout << "Impossible to find a solution";

    return 0;
}