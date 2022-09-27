#include "NeuralNetwork.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<std::vector<double>> fileToArray(std::string);

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

    double cost = nn.costFunction.calculateCost(output, {0, 1});
    std::cout << "\nWith cost from {0, 1}: " << cost;
    std::cout << "\n";

    std::vector<std::vector<double>> trainingData = fileToArray("data/train.csv");
    std::vector<std::vector<double>> trainingAnswers = fileToArray("data/train_answers.csv");

    double overallCost = nn.costFromData(trainingData, trainingAnswers);
    std::cout << "\nCost from training data: " << overallCost;

    return 0;
}

std::vector<std::vector<double>> fileToArray(std::string fileName) {
    std::fstream file;
    file.open(fileName, std::fstream::in);

    std::vector<std::vector<double>> data;
    std::vector<double> row;
    std::string line, word;

    while(std::getline(file, line)) {
        row.clear();
        std::stringstream str(line);
        while(std::getline(str, word, ','))
        row.push_back(std::stod(word));
        data.push_back(row);
    }

    return data;
}