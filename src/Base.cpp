#include "Base.h"

double Base::gen_real_random()
{
    // Generate real random between 0 and 1
    std::uniform_real_distribution<double> real_dist(0.0, 1.0); //Real
    // Random Generators
    std::random_device rd;
    std::mt19937 gen(rd());
    return real_dist(gen);
}

double Base::mod(double first_term, double second_term)
{
    // Compute the modulus
    return first_term - (second_term)*floor(first_term / (second_term));
}

double Base::max(double arr[], int n)
{
    // Identify the max element in an array
    double max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}