#ifndef SRC_ROBOT_H
#define SRC_ROBOT_H

#include "Base.h"
#include "Map.h"

class Robot: public Base {
public:
    Robot();

    explicit Robot(Map map);

    ~Robot() override;

    void set(double new_x, double new_y, double new_orient, Map map);

    void set_noise(double new_forward_noise, double new_turn_noise, double new_sense_noise);

    vector<double> sense(Map map);

    Robot move(double turn, double forward, Map map);

    std::string show_pose();

    std::string read_sensors(Map map);

    double measurement_prob(vector<double> measurement, Map map);

    double x{}, y{}, orient{}; //robot poses
    double forward_noise{}, turn_noise{}, sense_noise{}; //robot noises

private:
    double gen_gauss_random(double mean, double variance);

    double gaussian(double mu, double sigma, double x);

    double evaluation(Robot r, Robot p[], int n, Map map);
};


#endif //SRC_ROBOT_H