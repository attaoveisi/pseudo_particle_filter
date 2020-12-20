#include "Map.h"

void Map::get_world_size(const double val) {
    this->world_size = val;
}

void Map::get_landmarks(const std::vector<std::vector<double>> landmarks, int val){
    this->num_landmarks = val;
    for(int i = 0; i < val; i++){
        this->landmarks[i][0] = landmarks[i][0];
        this->landmarks[i][1] = landmarks[i][1];
    }
}

void Map::print_map() {
    for (int i = 0; i < num_landmarks; i++){
        std::cout << landmarks[i][0] << "\t" << landmarks[i][1] << std::endl;
    }
        std::cout << "Robot indicates the world size as: " << world_size << std::endl;
}
