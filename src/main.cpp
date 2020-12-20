#include "Robot.h"
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
    // Landmarks
    Map map;
    map.landmarks = { { 20.0, 20.0 }, { 20.0, 80.0 }, { 20.0, 50.0 },
                      { 50.0, 20.0 }, { 50.0, 80.0 }, { 80.0, 80.0 },
                      { 80.0, 20.0 }, { 80.0, 50.0 } };

    // Map size in meters
    map.world_size = 100.0;

    return 0;
}