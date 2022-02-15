//
//  texture.hpp
//  project-2
//
//  Created by Anish Satalkar on 2/13/22.
//

#ifndef texture_hpp
#define texture_hpp

#include <stdio.h>
#include <opencv2/core.hpp>

/*
 Calculates the sum of squared difference between the 2 1D histograms.
 distance = 1/N(sum((hi - ji)^2))
 */
float distance1DHistogram(int* histOne, int* histTwo, int histSize);

/*
 Calculates the features of the input image.
 Returns a float array of features.
 */
int* getTextureHistogram(cv::Mat &srcImage);

cv::Mat rgHistogram(cv::Mat &srcImage);

float rgHistogramDistance(cv::Mat &histOne, cv::Mat &histTwo, int xdim, int ydim);

#endif /* texture_hpp */
