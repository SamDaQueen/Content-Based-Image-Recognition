//
//  texture.cpp
//  project-2
//
//  Created by Anish Satalkar on 2/13/22.
//

#include "texture.hpp"
#include "filter.hpp"
#include <iostream>

#define TXT_HISTOGRAM_BUCKET_SIZE 16
#define RG_X 16
#define RG_Y 16

int extractFeatures(cv::Mat srcImage, int *features){
    int i, j;
    int idx = 0;
    for(i = 0; i < srcImage.rows; i++){
        for (j = 0; j < srcImage.cols; j++) {
            idx = (int) srcImage.at<cv::Vec3b>(i,j)[0] / TXT_HISTOGRAM_BUCKET_SIZE;
            features[idx] += 1;
        }
    }
    return 0;
}

int initialiseIntArray(int *features){
    for(int i = 0; i < 16 ; i++){
        features[i] = 0;
    }
    return 0;
}

int* getTextureHistogram(cv::Mat &srcImage){
    int *features = new int[TXT_HISTOGRAM_BUCKET_SIZE];
    initialiseIntArray(features);
    cv::Mat sobelXOutput(srcImage.size(), CV_16SC3);
    sobelX3x3(srcImage, sobelXOutput);
    
    cv::Mat sobelYOutput(srcImage.size(), CV_16SC3);
    sobelY3x3(srcImage, sobelYOutput);
    
    cv::Mat magnitudeOutput(srcImage.size(), CV_16SC3);
    
    magnitude(sobelXOutput, sobelYOutput, magnitudeOutput);
    
    cv::Mat dst;
    cv::convertScaleAbs(magnitudeOutput, dst);
    
//    cv::imshow("magnitude", dst);
    
    cv::Mat grayscaleMagnitude(srcImage.size(), CV_8UC3);
    grayscale(dst, grayscaleMagnitude);
    
//    cv::imshow("grayscale", grayscaleMagnitude);
    
    extractFeatures(grayscaleMagnitude, features);
    
    return features;
}

float distance1DHistogram(int *histOne, int *histTwo, int histSize) {
    float distance = 0;
    for (int i = 0 ; i < histSize; i++) {
        distance += (histOne[i] - histTwo[i]) * (histOne[i] - histTwo[i]);
    }
    return distance / histSize;
}

cv::Mat rgHistogram(cv::Mat &srcImage){
    // The data type should be such that each bin must accomodate 640*512 values. CV_32SC1 serves this purpose.
    cv::Mat rgHistogram(RG_X, RG_Y, CV_32SC1);
    rgHistogram = 0;
    
    int i, j;
    float r,g;
    unsigned char R, G, B;
    int rIdx;
    int gIdx;
    for (i = 0; i < srcImage.rows; i++) {
        for (j = 0; j < srcImage.cols; j++) {
            
            R = srcImage.at<cv::Vec3b>(i,j)[0];
            G = srcImage.at<cv::Vec3b>(i,j)[1];
            B = srcImage.at<cv::Vec3b>(i,j)[2];
            
            r = (float) R / (R + G + B + 1);
            g = (float) G / (R + G + B + 1);
            
            rIdx = r * RG_X;
            gIdx = g * RG_Y;
            
            rgHistogram.at<int32_t>(rIdx, gIdx) += 1;
        }
    }
    
    return rgHistogram;
    
}

float rgHistogramDistance(cv::Mat &histOne, cv::Mat &histTwo, int xdim, int ydim) {
    std::cout << histOne << std::endl;
    std::cout << histTwo << std::endl;
    int i, j;
    float distance = 0;
    for (i = 0 ; i < ydim; i++) {
        for (j = 0; j < xdim; j++) {
            if(histOne.at<int32_t>(i,j) != histTwo.at<int32_t>(i,j)){
                std::cout << "not the same i,j " << i << "," << j << std::endl;
                std::cout << "hist 1 : " << histOne.at<int32_t>(i,j) << std::endl;
                std::cout << "hist 2 : " << histTwo.at<int32_t>(i,j) << std::endl;
                
            }
            distance += (histOne.at<int32_t>(i,j) - histTwo.at<int32_t>(i,j)) *
            (histOne.at<int32_t>(i,j) - histTwo.at<int32_t>(i,j));
        }
    }
    return distance / (RG_X * RG_Y);
}
