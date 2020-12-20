#ifndef SRC_MAP_H
#define SRC_MAP_H
#include <vector>
#include <iostream>

class Map {
public:
    void get_world_size(const double val);
    void get_landmarks(std::vector<std::vector<double>> landmarks, int val);
    void print_map();

private:
    int num_landmarks;
    double world_size;
    std::vector<std::vector<double>> landmarks;

    friend class Robot;
};


#endif //SRC_MAP_H
