#include "Map.h"

void Map::get_world_size(const double val) {
    world_size = val;
}

void Map::get_landmarks(const std::vector<std::vector<double>> &array, const int val){
    num_landmarks = val;
    for(int i = 0; i < val; i++){
        landmarks.push_back({array[i][0], array[i][1]});
    }
}

void Map::print_map() {
    for (int i = 0; i < num_landmarks; i++){
        std::cout << landmarks[i][0] << "\t" << landmarks[i][1] << std::endl;
    }
        std::cout << "Robot indicates the world size as: " << world_size << std::endl;
}
