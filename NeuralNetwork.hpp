#include "Layer.hpp"

#include <vector>

class NeuralNetwork {
    public:
        int numberInputNodes, numberOutputNodes, numberHiddenLayers;
        std::vector<Layer> hiddenLayers;

        NeuralNetwork(int, std::vector<int>, int, activationTypeOptions = Sigmoid);
        std::vector<double> computeOutput(std::vector<double>);
};