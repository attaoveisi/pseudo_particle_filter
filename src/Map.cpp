#include "Map.h"

void Map::get_world_size(double world_size) {
    this->world_size = world_size;
}

void Map::get_landmarks(double landmarks_matrix[][]){
    this->landmarks = landmarks_matrix;
}
