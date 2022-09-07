#include "NeuralNetwork.hpp"

#include <vector>

NeuralNetwork::NeuralNetwork(int nInput, std::vector<int> layersSizes, int nOutput, activationTypeOptions activationType) {
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