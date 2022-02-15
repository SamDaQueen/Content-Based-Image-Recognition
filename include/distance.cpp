/**
 * @file distance.cpp
 * @author Samreen
 * @brief Implements the header file distance.hpp
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "distance.hpp"

float SSD(vector<float> image1_data, vector<float> image2_data) {
  float error = 0.0f;
  for (unsigned int i = 0; i < image1_data.size(); i++) {
    error +=
        (image1_data[i] - image2_data[i]) * (image1_data[i] - image2_data[i]);
  }

  return error / image1_data.size();
}

float SAD(vector<float> image1_data, vector<float> image2_data) {
  float error = 0.0f;
  for (unsigned int i = 0; i < image1_data.size(); i++) {
    error += abs(image1_data[i] - image2_data[i]);
  }

  return error;
}
