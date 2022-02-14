/**
 * @file genFeatures.hpp
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
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

int baseline(Mat &src, vector<float> &image_data);
int histogram(Mat &src, vector<float> &image_data);
int multiHist(Mat &src, vector<float> &image_data);
int textureHist(Mat &src, vector<float> &image_data);
int colorHist(Mat &src, vector<float> &image_data);