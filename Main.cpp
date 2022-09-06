#include "Layer.hpp"

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
    
    return 0;
}