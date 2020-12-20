#ifndef SRC_MAP_H
#define SRC_MAP_H
#include <vector>
using std::vector;

class Map {
public:
    int num_landmarks;
    double world_size;
    void get_world_size(double val);
    void get_landmarks(double array[][2], int val);
    double landmarks[][2];


};


#endif //SRC_MAP_H
