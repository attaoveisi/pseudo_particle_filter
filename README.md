# pseudo_particle_filter
This is a 2D implementation of MCL for localization of a robot with a known map using particle filters. This is being developed and not finished yet (SW may be unstable at several commits).

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

In his implementation, the robot is inside a cyclic map of size (100,100) , can move forwards, rotate left/right and measure its distance to eight landmarks as shown below:

![image](https://user-images.githubusercontent.com/17289954/102711450-22cad300-42ba-11eb-84d8-4c51829378be.png)

and with range finder sensors

![image](https://user-images.githubusercontent.com/17289954/102711470-4857dc80-42ba-11eb-9a75-2cebd4ff9b72.png)

we will spread the particles uniformly e.g.,

![image](https://user-images.githubusercontent.com/17289954/102711509-8bb24b00-42ba-11eb-9bda-21828b9ab088.png)


## The logic of the code

First, as an initialization phase, a set of particles are generated and randomly distributed in the world (map). Then, importance-weight is calculated based on the actual measurement from robot (*z_t*):

![image](https://user-images.githubusercontent.com/17289954/102715635-24ef5a80-42d7-11eb-9dc0-0dc43e36327b.png)

and the corresponding particle (virtual) measurements:

![image](https://user-images.githubusercontent.com/17289954/102715688-70a20400-42d7-11eb-905b-02714a256a88.png)

The mismatch between the two indicates the particle's importance weight. Next, the resampling process takes place, where the normalized weights (*alpha*) decide the survival chance of the particles as

![image](https://user-images.githubusercontent.com/17289954/102715969-fd00f680-42d8-11eb-8807-e8ea4479a035.png)

However, the max operator for the weights are not used and a rather random process should be employed.

## An example

The results of localization convergence is shown below for a world of size 100x100 and eight landmarks:

![image](https://user-images.githubusercontent.com/17289954/102865982-d953c280-4436-11eb-92da-8b5ebd169573.png)
![image](https://user-images.githubusercontent.com/17289954/102868101-0c4b8580-443a-11eb-903a-41f9b5dc7708.png)
![image](https://user-images.githubusercontent.com/17289954/102868159-208f8280-443a-11eb-8645-c456fe272d42.png)
![image](https://user-images.githubusercontent.com/17289954/102868215-31d88f00-443a-11eb-9f4b-fd089b31be47.png)
![image](https://user-images.githubusercontent.com/17289954/102868243-3ac96080-443a-11eb-8b0c-894c600a8b3c.png)
![image](https://user-images.githubusercontent.com/17289954/102868304-50d72100-443a-11eb-8048-2dc67d0e2391.png)
![image](https://user-images.githubusercontent.com/17289954/102868333-5af91f80-443a-11eb-8b72-30dd33a14b6d.png)
![image](https://user-images.githubusercontent.com/17289954/102868402-6fd5b300-443a-11eb-9b03-6b3840b20dd8.png)
![image](https://user-images.githubusercontent.com/17289954/102868457-80862900-443a-11eb-8e8e-fad1e66e7a37.png)
![image](https://user-images.githubusercontent.com/17289954/102868539-985dad00-443a-11eb-9680-60dfbd11ba20.png)
![image](https://user-images.githubusercontent.com/17289954/102868596-a7dcf600-443a-11eb-82dc-a0aeff0915a8.png)
![image](https://user-images.githubusercontent.com/17289954/102868692-c642f180-443a-11eb-8976-5942ba2f7592.png)
![image](https://user-images.githubusercontent.com/17289954/102868722-d35fe080-443a-11eb-9dda-f1e582bc0fc6.png)



