#include <vector>

enum costTypeOptions {
    MeanSquare,
    CrossEntropy,
};

class Cost {
    public:
        costTypeOptions costFunctionType;

        Cost(costTypeOptions);
        double calculateCost(std::vector<double>, std::vector<double>);
};