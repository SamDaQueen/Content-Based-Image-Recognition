/**
 * @file distance.hpp
 * @author Samreen
 * @brief
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

float SSD(vector<float> image1, vector<float> image2);