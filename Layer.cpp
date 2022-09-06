#include "Layer.hpp"

#include <iostream>
#include <vector>
#include <random>

Layer::Layer(int a, int b, activationTypeOptions type) : activationFunction(type) {
    nodesIn = a;
    nodesOut = b;
    setStartingWeightsAndBiases();
}

std::vector<double> Layer::calculateOutput(std::vector<double> input) {
    std::vector<double> output;
    for (int i = 0; i < nodesOut; i++) {
        double o = biases[i];
        for (int j = 0; j < nodesIn; j++) {
            o += input[j] * weights[i][j];
        }
        output.push_back(o);
    }
    return activationFunction.Activate(output);
}

void Layer::setStartingWeightsAndBiases() {
    std::random_device rd;
    std::mt19937 e{rd()};
    std::normal_distribution<double> dist{0, 1};

    for (int i = 0; i < nodesOut; i++) {
        std::vector<double> temp;
        for (int j = 0; j < nodesIn; j++) {
            temp.push_back(dist(e));
        }
        weights.push_back(temp);
    }
    biases.assign(nodesOut, 0);
}