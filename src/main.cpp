#include "Base.h"
#include "Robot.h"
#include "Map.h"
//namespace plt = matplotlibcpp;

/*
void visualization(int n, Robot robot, int step, Robot p[], Robot pr[])
{
	//Draw the robot, landmarks, particles and resampled particles on a graph
	
    //Graph Format
    plt::title("MCL, step " + to_string(step));
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
    for (int i = 0; i < sizeof(landmarks) / sizeof(landmarks[0]); i++) {
        plt::plot({ landmarks[i][0] }, { landmarks[i][1] }, "ro");
    }
    
    //Draw robot position in blue
    plt::plot({ robot.x }, { robot.y }, "bo");

	//Save the image and close the plot
    plt::save("./Images/Step" + to_string(step) + ".png");
    plt::clf();
}
*/


int main()
{
    Base base;
    // Landmarks
    Map map;
    // Map size in meters
    int map_size = 100;
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
    myrobot.set_noise(5.0, 0.1, 5.0);
    myrobot.set(30.0, 50.0, M_PI / 2.0);

    // Measurement vector
    std::vector<double> z;

    //Iterating 50 times over the set of particles
    int steps = 50;
    // Create a set of particles
    int n = 1000;
    Robot p[n];

    for (int i = 0; i < n; i++) {
        p[i].set_noise(0.05, 0.05, 5.0);
        //cout << p[i].show_pose() << endl;
    }

    for (int t = 0; t < steps; t++) {

        //Move the robot and sense the environment afterwards
        myrobot = myrobot.move(0.1, 5.0);
        z = myrobot.sense();

        // Simulate a robot motion for each of these particles
        Robot p2[n];
        for (int i = 0; i < n; i++) {
            p2[i] = p[i].move(0.1, 5.0);
            p[i] = p2[i];
        }

        //Generate particle weights depending on robot's measurement
        double w[n];
        for (int i = 0; i < n; i++) {
            w[i] = p[i].measurement_prob(z);
            //cout << w[i] << endl;
        }

        //Resample the particles with a sample probability proportional to the importance weight
        Robot p3[n];
        int index = base.gen_real_random() * n;
        //cout << index << endl;
        double beta = 0.0;
        double mw = p3[0].max(w, n);
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

    } //End of Steps loop

    return 0;
}