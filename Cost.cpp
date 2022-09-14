#include "Cost.hpp"

#include <cmath>

Cost::Cost(costTypeOptions type) {
    costFunctionType = type;
}

double Cost::calculateCost(std::vector<double> predictedVector, std::vector<double> expectedVector) {
    double cost;
    switch(costFunctionType) {
        case MeanSquare:
            cost = 0;
            for (int i = 0; i < predictedVector.size(); i++) {
                cost += std::pow(predictedVector[i] - expectedVector[i], 2);
            }
            cost = cost / predictedVector.size();
            break;
        case CrossEntropy:
            // the expectedVector should be all 0s and 1s
            cost = 0;
            for (int i = 0; i < predictedVector.size(); i++) {
                double z = (expectedVector[i] == 1) ? log(predictedVector[i]) : log(1 - predictedVector[i]);
                cost -= isnan(z) ? 0 : z;
            }
            break;
    }
    return cost;
}