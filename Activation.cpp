#include "Activation.hpp"

#include <vector>
#include <cmath>
#include <algorithm>

Activation::Activation(activationTypeOptions type) {
    activationType = type;
}

std::vector<double> Activation::Activate(std::vector<double> input) {
    std::vector<double> output;
    double o;
    switch(activationType) {
        case Sigmoid:
            for (double i: input) {
                o = 1 / (1 + std::exp(-i));
                output.push_back(o);
            }
            break;
        case TanH:
            for (double i: input) {
                o = (std::exp(i) - std::exp(-i)) / (std::exp(i) + std::exp(-i));
                output.push_back(o);
            }
            break;
        case ReLU:
            for (double i: input) {
                o = std::max(i, 0.0);
                output.push_back(o);
            }
            break;
    }
    return output;
}