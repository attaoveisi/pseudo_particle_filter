# pseudo_particle_filter
An implementation of MCL

## Bayes filtering
The powerful Monte Carlo localization algorithm estimates the posterior distribution of a robot’s position and orientation based on sensory information. This process is known as a recursive Bayes filter.

In mobile robot localization, it’s important to be acquainted with the following definitions:

  - **Dynamical system**: The mobile robot and its environment
  - **State**: The robot’s pose, including its position and orientation
  - **Measurements**: Perception data(e.g. laser scanners) and odometry data(e.g. rotary encoders)

The goal of Bayes filtering is to estimate a probability density over the state space conditioned on the measurements. The probability density, or also known as **posterior** is called the **belief** and is denoted as: 

![image](https://user-images.githubusercontent.com/17289954/102710884-e39a8300-42b5-11eb-9975-501ec12d04f9.png)

with *X_t* and *Z_{1,..,t}* being the state at time step *t* and observation upto *t*. The conditional probablity is defined as:


![image](https://user-images.githubusercontent.com/17289954/102710980-b0a4bf00-42b6-11eb-8ad1-511045868a30.png)


cosidering this shorty intro (refer to [this paper](http://robots.stanford.edu/papers/thrun.robust-mcl.pdf) for a detailed explanation), we can use the following **MCL** algorithm: 

![image](https://user-images.githubusercontent.com/17289954/102711316-e8ad0180-42b8-11eb-8734-f4953f18c9e3.png)







