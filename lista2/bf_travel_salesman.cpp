#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>


typedef std::vector<std::vector<int>> matrix;

int BFTSP(const matrix& graph, int starting_point, std::vector<int>& optimal_path){

    std::vector<int> aux_path = optimal_path;
    std::vector<int> vertex;
    for (int i = 0; i < graph.size(); i++)
        if (i != starting_point)
            vertex.push_back(i);

    int min_path = std::numeric_limits<int>::max();
    do {
        int current_path_cost = 0;
        int k = starting_point;
        for (int i = 0; i < vertex.size(); i++) {
            current_path_cost += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_path_cost += graph[k][starting_point];
        min_path = std::min(min_path, current_path_cost);
    } while (std::next_permutation(vertex.begin(), vertex.end()));
    return min_path;
}


int main()
{
    matrix graph = { { 0, 10, 15, 20 },
                     { 10, 0, 35, 25 },
                     { 15, 35, 0, 30 },
                     { 20, 25, 30, 0 } };
    int starting_point = 0;
    std::vector<int> optimal_path(graph.size(), -1);
    optimal_path[0] = 0;
    std::cout << "minimum cost: " << BFTSP(graph, optimal_path[0], optimal_path) << std::endl;
    return 0;
}