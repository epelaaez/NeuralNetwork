#include <vector>

enum activationTypeOptions {
    Sigmoid,
    TanH,
    ReLU,
};

class Activation {
    public:
        activationTypeOptions activationType;

        Activation(activationTypeOptions);
        std::vector<double> Activate(std::vector<double>);
};