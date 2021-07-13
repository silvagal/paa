#include <ctime>
#include <iostream>
#include <numeric>
#include <vector>

#define NUMBER_OF_VERTICES 5
#define NUMBER_OF_COLORS 3

typedef std::vector<std::vector<int>> matrix;

typedef struct vertex{
    int color;
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

void printColoredGraph(graph& my_graph){
    std::cout << std::endl;
    int cont = 1;
    for (auto i : my_graph.vertices) {
        std::cout << "Vertex [" << cont++ << "] - color[" <<  i.color << "]\n";
    }
}

void generateGraph(graph& my_graph){
    my_graph.matrix_adj = {
            {0,1,1,0,0},
            {1,0,0,1,1},
            {1,0,0,0,0},
            {0,1,0,0,1},
            {0,1,0,1,0}
    };
//    matrix aux_matrix(NUMBER_OF_VERTICES , std::vector<int> (NUMBER_OF_VERTICES, 0));
    std::vector<vertex> v(NUMBER_OF_VERTICES);
    for (int i = 0; i < NUMBER_OF_VERTICES; ++i) {
//        for (int j = 0; j < NUMBER_OF_VERTICES; ++j)
//            aux_matrix[i][j] = rand() % 2;
//        my_graph.matrix_adj = aux_matrix;
        v[i].color = -1;
    }
    my_graph.vertices = v;
}

bool isColorAvailable(graph& my_graph, int vertex_idx, std::vector<int>& colors, int color_idx){
    for (int c = vertex_idx - 1; c >= 0; --c)
        if (my_graph.matrix_adj[vertex_idx][c])
            if (my_graph.vertices[c].color == colors[color_idx])
                return false;
    return true;
}

bool graphColoring(graph& my_graph, std::vector<int>& colors, int vertex_idx){
    if(vertex_idx == NUMBER_OF_VERTICES)
        return true;
    for (int c = 0; c < NUMBER_OF_COLORS; ++c) {
        if (isColorAvailable(my_graph, vertex_idx, colors, c)){
            my_graph.vertices[vertex_idx].color = colors[c];
            if (graphColoring(my_graph, colors, vertex_idx + 1))
                return true;
            my_graph.vertices[vertex_idx].color = 0;
        }
    }
    return false;
}

int main(){
    srand((unsigned) time(nullptr));
    bool find_solution;

    // initializes colors' value
    std::vector<int> colors(NUMBER_OF_COLORS);
    std::iota (std::begin(colors), std::end(colors), 0);

    // generates the graph
    graph my_graph;
    generateGraph(my_graph);

    printMatrix(my_graph.matrix_adj, NUMBER_OF_VERTICES, NUMBER_OF_VERTICES);
    find_solution = graphColoring(my_graph, colors, 0);
    if (find_solution)
        printColoredGraph(my_graph);
    else
        std::cout << "Impossible to find a solution";

    return 0;
}