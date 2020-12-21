#ifndef SRC_ROBOT_H
#define SRC_ROBOT_H

#include "Base.h"
#include "Map.h"

class Robot: public Base {
public:

    Robot();

    ~Robot() override;

    void set(double new_x, double new_y, double new_orient);

    void set_noise(double new_forward_noise, double new_turn_noise, double new_sense_noise);

    std::vector<double> sense();

    void move(double turn, double forward);

    std::string show_pose();

    std::string read_sensors();

    double measurement_prob(std::vector<double> measurement);

    void get_world_size(Map &map);

    void get_landmarks(Map &map);

    double x{}, y{}, orient{}; //robot poses
    double forward_noise{}, turn_noise{}, sense_noise{}; //robot noises

    double world_size;

    int num_landmarks;

    std::vector<std::vector<double>> landmarks;

    void print_robot(){
        for (int i = 0; i < num_landmarks; i++){
            std::cout << landmarks[i][0] << "\t" << landmarks[i][1] << std::endl;
        }
        std::cout << "Robot indicates the world size as: " << world_size << std::endl;
    }

private:
    double gen_gauss_random(double mean, double variance);

    double gaussian(double mu, double sigma, double x);
};


#endif //SRC_ROBOT_H
