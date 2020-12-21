#include "Robot.h"

Robot::~Robot() {}

Robot::Robot(){
    // Constructor
    x = gen_real_random() * world_size; // robot's x coordinate
    y = gen_real_random() * world_size; // robot's y coordinate
    orient = gen_real_random() * 2.0 * M_PI; // robot's orientation

    forward_noise = 0.0; //noise of the forward movement
    turn_noise = 0.0; //noise of the turn
    sense_noise = 0.0; //noise of the sensing
}

void Robot::set(double new_x, double new_y, double new_orient){
    // Set robot new position and orientation
    if (new_x < 0 || new_x >= world_size){
        throw std::invalid_argument("X coordinate out of bound");
    }

    if (new_y < 0 || new_y >= world_size){
        throw std::invalid_argument("Y coordinate out of bound");
    }

    if (new_orient < 0 || new_orient >= 2 * M_PI){
        throw std::invalid_argument("Orientation must be in [0..2pi]");
    }


    x = new_x;
    y = new_y;
    orient = new_orient;
}
void Robot::set_noise(double new_forward_noise, double new_turn_noise, double new_sense_noise){
    // Simulate noise, often useful in particle filters
    forward_noise = new_forward_noise;
    turn_noise = new_turn_noise;
    sense_noise = new_sense_noise;
}

std::vector<double> Robot::sense(){
    // Measure the distances from the robot toward the landmarks
    std::vector<double> z(num_landmarks);
    double dist;

    for (int i = 0; i < num_landmarks; i++) {
        dist = sqrt(pow((x - landmarks[i][0]), 2) + pow((y - landmarks[i][1]), 2));
        dist += gen_gauss_random(0.0, sense_noise);
        z[i] = dist;
    }
    return z;
}

void Robot::move(double turn, double forward){
    if (forward < 0){
        throw std::invalid_argument("Robot cannot move backward");
    }

    // turn, and add randomness to the turning command
    this->orient = this->orient + turn + gen_gauss_random(0.0, turn_noise);
    this->orient = mod(this->orient, 2 * M_PI);

    // move, and add randomness to the motion command
    double dist = forward + gen_gauss_random(0.0, forward_noise);
    this->x = this->x + (cos(this->orient) * dist);
    this->y = this->y + (sin(this->orient) * dist);
    //std::cout << this->x << std::endl;
    // cyclic truncate
    this->x = mod(this->x, world_size);
    //std::cout << this->x << std::endl;
    this->y = mod(this->y, world_size);

    // set particle
    //Robot res;
    //res.set(x, y, orient);
    //res.set_noise(forward_noise, turn_noise, sense_noise);
}

std::string Robot::show_pose() {
    // Returns the robot current position and orientation in a string format
    return "[x=" + std::to_string(x) + " y=" + std::to_string(y) + " orient=" + std::to_string(orient) + "]";
}

std::string Robot::read_sensors(){
    // Returns all the distances from the robot toward the landmarks
    std::vector<double> z = sense();
    std::string readings = "[";
    for (int i = 0; i < z.size(); i++) {
        readings += std::to_string(z[i]) + " ";
    }
    readings[readings.size() - 1] = ']';

    return readings;
}

double Robot::measurement_prob(std::vector<double> measurement){
    // Calculates how likely a measurement should be
    double prob = 1.0;
    double dist;

    for (int i = 0; i < num_landmarks; i++) {
        dist = sqrt(pow((x - landmarks[i][0]), 2) + pow((y - landmarks[i][1]), 2));
        prob *= gaussian(dist, sense_noise, measurement[i]);
    }

    return prob;
}

double Robot::gen_gauss_random(double mean, double variance){
    // Gaussian random
    std::normal_distribution<double> gauss_dist(mean, variance);
    // Random Generators
    std::random_device rd;
    std::mt19937 gen(rd());
    return gauss_dist(gen);
}

double Robot::gaussian(double mu, double sigma, double x){
// Probability of x for 1-dim Gaussian with mean mu and var. sigma
return exp(-(pow((mu - x), 2)) / (pow(sigma, 2)) / 2.0) / sqrt(2.0 * M_PI * (pow(sigma, 2)));
}

double Robot::evaluation(Robot r, std::vector<Robot> p, int n)
{
    //Calculate the mean error of the system
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        //the second part is because of world's cyclicity
        double dx = mod((p[i].x - r.x + (world_size / 2.0)), world_size) - (world_size / 2.0);
        double dy = mod((p[i].y - r.y + (world_size / 2.0)), world_size) - (world_size / 2.0);
        double err = sqrt(pow(dx, 2) + pow(dy, 2));
        sum += err;
    }
    return sum / n;
}

void Robot::get_world_size(Map &map){
    world_size = map.world_size;
}

void Robot::get_landmarks(Map &map){
    num_landmarks = map.num_landmarks;
    for(int i = 0; i < this->num_landmarks; i++){
        if (i == 0) {
            std::cout << "The map landmarks are being copied to robot landmarks..." << std::endl;
        }
        landmarks.push_back({map.landmarks[i][0], map.landmarks[i][1]});
        std::cout << " Landmark " << i << " = " << map.landmarks[i][0] << "\t" << map.landmarks[i][1] << " is copied!" << std::endl;
    }
}