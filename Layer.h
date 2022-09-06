#include <vector>
#include "Activation.h"

class Layer {
    public:
        int nodesIn, nodesOut;
        std::vector<std::vector<double>> weights;
        std::vector<double> biases;
        Activation activationFunction;

        Layer(int, int, activationTypeOptions = Sigmoid);
        std::vector<double> calculateOutput(std::vector<double>);

    private:
        void setStartingWeightsAndBiases();
};