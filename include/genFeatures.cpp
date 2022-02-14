/**
 * @file genFeatures.cpp
 * @author Samreen
 * @brief Implements the header file genFeatures.hpp
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "genFeatures.hpp"

int baseline(Mat &src, vector<float> &image_data) {
  for (unsigned int i = src.rows / 2 - 4; i <= src.rows / 2 + 4; i++) {
    for (unsigned int j = src.cols / 2 - 4; j <= src.cols / 2 + 4; j++) {
      for (unsigned int color = 0; color < 3; color++) {
        image_data.push_back(src.at<Vec3b>(i, j)[color]);
      }
    }
  }
  return 0;
}