#include "NeuralNetwork.hpp"

#include <vector>

NeuralNetwork::NeuralNetwork(int nInput, std::vector<int> layersSizes, int nOutput, activationTypeOptions activationType, costTypeOptions costType) : costFunction(costType) {
    numberInputNodes = nInput;
    numberHiddenLayers = layersSizes.size();
    numberOutputNodes = nOutput;

    int previousSize = numberInputNodes;
    for (int i: layersSizes) {
        hiddenLayers.push_back(Layer(previousSize, i, activationType));
        previousSize = i;
    }
    hiddenLayers.push_back(Layer(previousSize, numberOutputNodes));
}

std::vector<double> NeuralNetwork::computeOutput(std::vector<double> input) {
    for (Layer l: hiddenLayers) {
        input = l.calculateOutput(input); 
    }
    return input;
}

double NeuralNetwork::costFromData(std::vector<std::vector<double>> inputs, std::vector<std::vector<double>> expected) {
    double overallCost = 0;
    for (int i = 0; i < inputs.size(); i++) {
        std::vector<double> output = computeOutput(inputs[i]);
        overallCost += costFunction.calculateCost(output, expected[i]);
    }
    return overallCost / inputs.size();
}