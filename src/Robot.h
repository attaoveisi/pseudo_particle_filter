#ifndef SRC_ROBOT_H
#define SRC_ROBOT_H

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdexcept> // throw errors
#include <random> //C++ 11 Random Numbers
#include "Base.h"
#include "Map.h"

using namespace std;

// Random Generators
random_device rd;
mt19937 gen(rd());

class Robot: public Base {
public:
    Robot(Map map);

    virtual ~Robot();

    void set(double new_x, double new_y, double new_orient, Map map);

    void set_noise(double new_forward_noise, double new_turn_noise, double new_sense_noise);

    vector<double> sense(Map map);

    Robot move(double turn, double forward, Map map);

    string show_pose();

    string read_sensors();

    double measurement_prob(vector<double> measurement, Map map);

    double x, y, orient; //robot poses
    double forward_noise, turn_noise, sense_noise; //robot noises

private:
    double gen_gauss_random(double mean, double variance);

    double gaussian(double mu, double sigma, double x);

    double evaluation(Robot r, Robot p[], int n, Map map);
};


#endif //SRC_ROBOT_H
