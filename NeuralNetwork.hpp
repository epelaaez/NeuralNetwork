#include "Layer.hpp"
#include "Cost.hpp"

#include <vector>

class NeuralNetwork {
    public:
        int numberInputNodes, numberOutputNodes, numberHiddenLayers;
        std::vector<Layer> hiddenLayers;
        Cost costFuncion;

        NeuralNetwork(int, std::vector<int>, int, activationTypeOptions = Sigmoid, costTypeOptions = MeanSquare);
        std::vector<double> computeOutput(std::vector<double>);
};