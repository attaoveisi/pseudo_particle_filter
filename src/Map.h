#ifndef SRC_MAP_H
#define SRC_MAP_H
#include <vector>
using std::vector;

class Map {
public:
    double landmarks[num_landmarks][2];
    double world_size{0};
    void get_world_size(double world_size);
    void get_landmarks(double landmarks_matrix[][]);
    int num_landmarks{1};

};


#endif //SRC_MAP_H
