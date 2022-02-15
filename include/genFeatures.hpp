/**
 * @file genFeatures.hpp
 * @author Samreen
 * @brief Header file for generating the features of an image
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

#define NUM_BINS 16
#define RG_X 16
#define RG_Y 16

using namespace cv;
using namespace std;

/**
 * @brief Creates a feature vector of the 9x9 square at the center of an image
 *
 * @param src input image
 * @param image_data output vector to store image features to
 * @return int 0 if operation was succesful
 */
int baseline(Mat &src, vector<float> &image_data);

/**
 * @brief Creates a feature vector using histograms of multiple sections of the
 * image
 *
 * @param src input image
 * @param image_data output vector to store image features to
 * @return int 0 if operation was succesful
 */
int multiHist(Mat &src, vector<float> &image_data);

/**
 * @brief Creates a feature vector of the texture of the image
 *
 * @param src input image
 * @param image_data output vector to store image features to
 * @return int 0 if operation was succesful
 */
int textureHist(Mat &src, vector<float> &image_data);

/**
 * @brief Creates a feature vector of the color histogram of the image
 *
 * @param src input image
 * @param image_data output vector to store image features to
 * @return int 0 if operation was succesful
 */
int colorHist(Mat &src, vector<float> &image_data);

/**
 * @brief Creates a feature vector of the rg histogram of the center of the
 * image
 *
 * @param src input image
 * @param image_data output vector to store image features to
 * @return int 0 if operation was succesful
 */
int centerHist(Mat &src, vector<float> &image_data);