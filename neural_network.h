#pragma once
#include <vector>
class nueral_network
{
    protected:
    int size;
    std::vector<float> weight;
    std::vector<float> bias;
    std::vector<float> input;
    std::vector<float> output;
    std::vector<float> weight_gradient;
    std::vector<float> bias_gradient;

public:
    nueral_network(int size, int initial_weight, int initial_bias);

    void forward_propagation(std::vector<float> input);
    
    void back_propagation(std::vector<float> output);

};