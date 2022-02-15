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

#include <iostream>

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

float intersection(vector<float> image1_data, vector<float> image2_data) {
  float error = 0.0f;
  for (unsigned int i = 0; i < image1_data.size(); i++) {
    error += min(image1_data[i], image2_data[i]);
  }
  float sum1 = 0.0f;
  for (unsigned int i = 0; i < image1_data.size(); i++) {
    sum1 += image1_data[i];
  }
  float sum2 = 0.0f;
  for (unsigned int i = 0; i < image2_data.size(); i++) {
    sum2 += image2_data[i];
  }
  error /= max(sum1, sum2);
  error = 1 - error;
  return error;
}
