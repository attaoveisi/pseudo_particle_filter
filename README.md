# pseudo_particle_filter
An implementation of MCL

## Bayes filtering
The powerful Monte Carlo localization algorithm estimates the posterior distribution of a robot’s position and orientation based on sensory information. This process is known as a recursive Bayes filter.

In mobile robot localization, it’s important to be acquainted with the following definitions:

  - **Dynamical system**: The mobile robot and its environment
  - **State**: The robot’s pose, including its position and orientation
  - **Measurements**: Perception data(e.g. laser scanners) and odometry data(e.g. rotary encoders)

The goal of Bayes filtering is to estimate a probability density over the state space conditioned on the measurements. The probability density, or also known as posterior is called the belief and is denoted as: 

![equation](Bel(X_t)=P(X_t | Z_{1,...,t}
