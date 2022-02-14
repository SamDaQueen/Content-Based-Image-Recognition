/**
 * @file distance.hpp
 * @author Samreen
 * @brief Header file for the distance metric functions
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <vector>

using namespace cv;
using namespace std;

/**
 * @brief Caluclate the distance between two vectors using sum of squared
 * distance method
 *
 * @param image1_data the feature set of the first image
 * @param image2_data the feature set of the second image
 * @return float the error between the images
 */
float SSD(vector<float> image1_data, vector<float> image2_data);

/**
 * @brief Caluclate the distance between two vectors using sum of absolute
 * distance method
 *
 * @param image1_data the feature set of the first image
 * @param image2_data the feature set of the second image
 * @return float the error between the images
 */
float SAD(vector<float> image1_data, vector<float> image2_data);