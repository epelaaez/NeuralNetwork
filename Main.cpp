#include "NeuralNetwork.hpp"

#include <iostream>
#include <vector>

int main() {
    Layer layer1(2, 3);

    std::cout << "\nWeights:\n";
    for (std::vector<double> i: layer1.weights) {
        for (double j: i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nBiases:\n";
    for(double i: layer1.biases) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "\nOutput:\n";
    std::vector<double> input{1, 1};
    std::vector<double> output = layer1.calculateOutput(input);
    for(double i: output) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    
    NeuralNetwork nn(2, {2, 3, 4}, 2);
    std::cout << "\nNeural Network with ";
    std::cout << nn.numberInputNodes << " input nodes, ";
    std::cout << nn.numberHiddenLayers << " hidden layers, and ";
    std::cout << nn.numberOutputNodes << " output nodes.\n";

    output = nn.computeOutput({1, 1});
    std::cout << "\nProduces output: ";
    for(double i: output) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}