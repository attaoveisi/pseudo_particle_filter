#include "Map.h"

void Map::get_world_size(double val) {
    this->world_size = val;
}

void Map::get_landmarks(double array[][2], int val){
    this->num_landmarks = val;
    for(int i = 1; i < val; i++){
        this->landmarks[i][0] = array[i][0];
        this->landmarks[i][1] = array[i][1];
    }
}
