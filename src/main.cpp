#include "Base.h"
#include "Robot.h"
#include "Map.h"
//#include "include/matplotlibcpp.h" //Graph Library
//namespace plt = matplotlibcpp;

/*
void visualization(int n, Robot robot, int step, std::vector<Robot> p, std::vector<Robot> pr)
{
	//Draw the robot, landmarks, particles and resampled particles on a graph
	
    //Graph Format
    plt::title("MCL, step " + std::to_string(step));
    plt::xlim(0, 100);
    plt::ylim(0, 100);

    //Draw particles in green
    for (int i = 0; i < n; i++) {
        plt::plot({ p[i].x }, { p[i].y }, "go");
    }

    //Draw resampled particles in yellow
    for (int i = 0; i < n; i++) {
        plt::plot({ pr[i].x }, { pr[i].y }, "yo");
    }

    //Draw landmarks in red
    for (int i = 0; i < sizeof(robot.landmarks) / sizeof(robot.landmarks[0]); i++) {
        plt::plot({ robot.landmarks[i][0] }, { robot.landmarks[i][1] }, "ro");
    }
    
    //Draw robot position in blue
    plt::plot({ robot.x }, { robot.y }, "bo");

	//Save the image and close the plot
    plt::save("./Images/Step" + std::to_string(step) + ".png");
    plt::clf();
}
 */

int main()
{
    Base base;
    // Landmarks
    Map map;
    // Map size in meters
    double map_size = 100.0;
    map.get_world_size(map_size);
    int num_landmarks = 8;
    std::vector<std::vector<double>> landmarks { { 20.0, 20.0 },
                                                 { 20.0, 80.0 },
                                                 { 20.0, 50.0 },
                                                 { 50.0, 20.0 },
                                                 { 50.0, 80.0 },
                                                 { 80.0, 80.0 },
                                                 { 80.0, 20.0 },
                                                 { 80.0, 50.0 } };
    for (int i = 0; i < num_landmarks; i++){
        std::cout << landmarks[i][0] << "\t" << landmarks[i][1] << std::endl;
    }

    map.get_landmarks(landmarks, num_landmarks);

    map.print_map();

    //Initialize myrobot object and Initialize a measurment vector
    Robot myrobot = Robot();
    myrobot.get_world_size(map);
    myrobot.get_landmarks(map);

    myrobot.print_robot();

    // Measurement vector
    std::vector<double> z;

    //Iterating 50 times over the set of particles
    int steps = 100;
    // Create a set of particles
    int n = 1000;
    std::vector<Robot> p(n);
    std::vector<Robot> p2(n);
    std::vector<Robot> p3(n);

    //std::cout << p[0].sense_noise << std::endl;

    for (int i = 0; i < n; i++) {
        p[i].set_noise(0.05, 0.05, 5.0);
        //std::cout << p[i].show_pose() << std::endl;
    }

    for (int t = 0; t < steps; t++) {

        //Move the robot and sense the environment afterwards
        myrobot.move(0.1, 5.0);
        z = myrobot.sense();
        //std::cout << z[0] << "\t" << z[1] << "\t" << z[2] << "\t" << z[3] << "\t" << z[4] << "\t" << z[5] << "\t" << z[6] << "\t" << z[7] << std::endl;
        // Simulate a robot motion for each of these particles
        for (int i = 0; i < n; i++) {
            p[i].move(0.1, 5.0);
            p2[i] = p[i];
            //std::cout << p[i].show_pose() << std::endl;
        }


        //std::cout << p[0].show_pose() << std::endl;
        //Generate particle weights depending on robot's measurement
        std::vector<double> w(n);
        for (int i = 0; i < n; i++) {
            w[i] = p[i].measurement_prob(z);
            //cout << w[i] << endl;
        }

        //Resample the particles with a sample probability proportional to the importance weight
        std::vector<Robot> p3(n);
        int index = base.gen_real_random() * n;
        //cout << index << endl;
        double beta = 0.0;
        double mw = base.max(w, n);
        //cout << mw;
        for (int i = 0; i < n; i++) {
            beta += base.gen_real_random() * 2.0 * mw;
            while (beta > w[index]) {
                beta -= w[index];
                index = base.mod((index + 1), n);
            }
            p3[i] = p[index];
        }
        for (int k=0; k < n; k++) {
            p[k] = p3[k];
            //cout << p[k].show_pose() << endl;
        }

        //####   DON'T MODIFY ANYTHING ABOVE HERE! ENTER CODE BELOW ####

        //Evaluate the error by priting it in this form:
        // cout << "Step = " << t << ", Evaluation = " << ErrorValue << endl;
        std::cout << "Step = " << t << ", Evaluation = " << p3[0].evaluation(myrobot, p, n) << std::endl;

        //Graph the position of the robot and the particles at each step
        //visualization(n, myrobot, t, p2, p3);


    } //End of Steps loop

    return 0;
}
