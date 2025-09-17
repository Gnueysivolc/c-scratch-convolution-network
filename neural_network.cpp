#include <iostream>
#include <vector>
#include "neural_network.h"
#include "matrix.h"



neural_network::neural_network(int size, int initial_weight, int initial_bias)
    : size(size),
      weight(size, static_cast<float>(initial_weight)),
      bias(size, static_cast<float>(initial_bias)),
      input(size, 0.0f),
      output(size, 0.0f),
      weight_gradient(size, 0.0f),
      bias_gradient(size, 0.0f) {}

  void forward_propagation(std::vector<float> input){




  }





























































































