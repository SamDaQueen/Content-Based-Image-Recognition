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

int greyscale(Mat &src, Mat &dst) {
  // loop over rows and cols
  for (unsigned int i = 0; i < src.rows; i++) {
    for (unsigned int j = 0; j < src.cols; j++) {
      Vec3b value = src.at<Vec3b>(i, j);  // get the pixel at (i, j)
      unsigned char gray =
          (value[1] + value[2]) / 2;  // get gray value from red and green
      dst.at<Vec3b>(i, j) = {
          gray, gray,
          gray};  // assign dst pixel at (i, j) with gray color in all channels
    }
  }

  return 0;
}

int sobelX3x3(Mat &src, Mat &dst) {
  Vec3i result = {0, 0, 0};  // to store the result for r, g, b

  // first apply 3x1 filter [1; 2; 1]
  for (unsigned int color = 0; color < 3; color++)  // loop through the channels
  {
    // loop over rows and cols
    for (unsigned int i = 1; i < src.rows - 1; i++) {
      for (unsigned int j = 0; j < src.cols; j++) {
        // calculate pixel value for r, g, b
        result[color] = src.at<Vec3b>(i - 1, j)[color] +
                        src.at<Vec3b>(i, j)[color] * 2 +
                        src.at<Vec3b>(i + 1, j)[color];

        dst.at<Vec3s>(i, j)[color] = result[color] / 4;
      }
    }
  }

  Mat sobel(src.size(), CV_16SC3);

  // then apply 1x3 filter [-1 0 1]
  for (unsigned int color = 0; color < 3; color++)  // loop through the channels
  {
    // loop over rows and cols
    for (unsigned int i = 0; i < sobel.rows; i++) {
      for (unsigned int j = 1; j < sobel.cols - 1; j++) {
        // calculate pixel value for r, g, b
        result[color] = dst.at<Vec3s>(i, j - 1)[color] * -1 +
                        dst.at<Vec3s>(i, j + 1)[color];

        sobel.at<Vec3s>(i, j)[color] = result[color];
      }
    }
  }

  dst = sobel;

  return 0;
}

int sobelY3x3(Mat &src, Mat &dst) {
  Vec3i result = {0, 0, 0};  // to store the result for r, g, b

  // first apply 3x1 filter [1; 0; -1]
  for (unsigned int color = 0; color < 3; color++)  // loop through the channels
  {
    // loop over rows and cols
    for (unsigned int i = 1; i < src.rows - 1; i++) {
      for (unsigned int j = 0; j < src.cols; j++) {
        // calculate pixel value for r, g, b
        result[color] = src.at<Vec3b>(i - 1, j)[color] +
                        src.at<Vec3b>(i + 1, j)[color] * -1;

        dst.at<Vec3s>(i, j)[color] = result[color];
      }
    }
  }

  Mat sobel(src.size(), CV_16SC3);

  // then apply 1x3 filter [1 2 1]
  for (unsigned int color = 0; color < 3; color++)  // loop through the channels
  {
    // loop over rows and cols
    for (unsigned int i = 0; i < sobel.rows; i++) {
      for (unsigned int j = 1; j < sobel.cols - 1; j++) {
        // calculate pixel value for r, g, b
        result[color] = dst.at<Vec3s>(i, j - 1)[color] +
                        dst.at<Vec3s>(i, j)[color] * 2 +
                        dst.at<Vec3s>(i, j + 1)[color];

        sobel.at<Vec3s>(i, j)[color] = result[color] / 4;
      }
    }
  }

  dst = sobel;

  return 0;
}

int magnitude(Mat &sx, Mat &sy, Mat &dst) {
  Vec3i result = {0, 0, 0};  // to store the result for r, g, b

  for (unsigned int color = 0; color < 3; color++)  // loop through the channels
  {
    // loop over rows and cols
    for (unsigned int i = 0; i < sx.rows; i++) {
      for (unsigned int j = 0; j < sx.cols; j++) {
        // calculate pixel value for r, g, b
        result[color] =
            sqrt(sx.at<Vec3s>(i, j)[color] * sx.at<Vec3s>(i, j)[color] +
                 sy.at<Vec3s>(i, j)[color] * sy.at<Vec3s>(i, j)[color]);

        dst.at<Vec3b>(i, j)[color] = (unsigned char)result[color];
      }
    }
  }
  return 0;
}

int extractFeatures(Mat &src, vector<float> &image_data) {
  unsigned int idx = 0;
  for (unsigned int i = 0; i < src.rows; i++) {
    for (unsigned int j = 0; j < src.cols; j++) {
      idx = (unsigned int)src.at<Vec3b>(i, j)[0] / NUM_BINS;
      image_data[idx]++;
    }
  }

  return 0;
}

int textureHist(Mat &src, vector<float> &image_data) {
  Mat sobelXOutput(src.size(), CV_16SC3);
  sobelX3x3(src, sobelXOutput);

  Mat sobelYOutput(src.size(), CV_16SC3);
  sobelY3x3(src, sobelYOutput);

  Mat magnitudeOutput(src.size(), CV_16SC3);
  magnitude(sobelXOutput, sobelYOutput, magnitudeOutput);

  Mat dst;
  convertScaleAbs(magnitudeOutput, dst);

  // imshow("magnitude", dst);

  Mat grayscaleMagnitude(src.size(), CV_8UC3);
  greyscale(dst, grayscaleMagnitude);

  // imshow("grayscale", grayscaleMagnitude);

  extractFeatures(grayscaleMagnitude, image_data);

  float sum = 0.0f;
  for (unsigned int i = 0; i < image_data.size(); i++) {
    sum += image_data[i];
  }

  for (unsigned int i = 0; i < image_data.size(); i++) {
    image_data[i] = image_data[i] / sum;
  }

  return 0;
}

int colorHist(Mat &src, vector<float> &image_data) {
  float r, g;
  unsigned char R, G, B;
  unsigned int rIdx;
  unsigned int gIdx;
  for (unsigned int i = 0; i < src.rows; i++) {
    for (unsigned int j = 0; j < src.cols; j++) {
      R = src.at<Vec3b>(i, j)[0];
      G = src.at<Vec3b>(i, j)[1];
      B = src.at<Vec3b>(i, j)[2];

      r = (float)R / (R + G + B + 1);
      g = (float)G / (R + G + B + 1);

      rIdx = r * RG_X;
      gIdx = g * RG_Y;

      image_data[rIdx * NUM_BINS + gIdx]++;
    }
  }

  float sum = 0.0f;
  for (unsigned int i = 0; i < image_data.size(); i++) {
    sum += image_data[i];
  }

  for (unsigned int i = 0; i < image_data.size(); i++) {
    image_data[i] = image_data[i] / sum;
  }

  return 0;
}

int multiHist(Mat &src, vector<float> &image_data) {
  // Divide into five parts, four quadrants and the center
  // vector<Mat> q(5);
  // q[0] = src(Range(src.rows / 4, 3 * src.rows / 4),
  //            Range(src.cols / 4, 3 * src.cols / 4));
  // q[1] = src(Range(0, src.rows / 2), Range(0, src.cols / 2));
  // q[2] = src(Range(0, src.rows / 2), Range(src.cols / 2, src.cols));
  // q[3] = src(Range(src.rows / 2, src.rows), Range(0, src.cols / 2));
  // q[4] = src(Range(src.rows / 2, src.rows), Range(src.cols / 2, src.cols));

  // imshow("q0", q[0]);
  // imshow("q1", q[1]);
  // imshow("q2", q[2]);
  // imshow("q3", q[3]);
  // imshow("q4", q[4]);

  // vector<vector<float>> q_data(5, vector<float>(NUM_BINS * NUM_BINS, 0));

  // for (unsigned int i = 0; i < 5; i++) {
  //   colorHist(q[i], q_data[i]);
  // }

  // for (unsigned int i = 0; i < q_data[0].size(); i++) {
  //   image_data.push_back(q_data[0][i]);
  // }

  // for (unsigned int i = 1; i < 5; i++) {
  //   image_data.insert(image_data.end(), q_data[i].begin(), q_data[i].end());
  // }

  // Divide into top and bottom half
  Mat q1 = src(Range(0, src.rows / 2), Range(0, src.cols));
  Mat q2 = src(Range(src.rows / 2, src.rows), Range(0, src.cols));

  vector<float> q1_data(NUM_BINS * NUM_BINS, 0);
  vector<float> q2_data(NUM_BINS * NUM_BINS, 0);

  colorHist(q1, q1_data);
  colorHist(q2, q2_data);

  for (unsigned int i = 0; i < q1_data.size(); i++) {
    image_data.push_back(q1_data[i]);
  }
  for (unsigned int i = 0; i < q2_data.size(); i++) {
    image_data.push_back(q2_data[i]);
  }

  return 0;
}

int centerHist(Mat &src, vector<float> &image_data) {
  Mat center_image = src(Range(src.rows / 3, 2 * src.rows / 3),
                         Range(src.cols / 3, 2 * src.cols / 3));

  vector<float> texture_data(NUM_BINS, 0);
  vector<float> color_data(NUM_BINS * NUM_BINS, 0);

  textureHist(center_image, texture_data);
  colorHist(center_image, color_data);

  for (unsigned int i = 0; i < texture_data.size(); i++) {
    image_data.push_back(texture_data[i]);
  }

  for (unsigned int i = 0; i < color_data.size(); i++) {
    image_data.push_back(color_data[i]);
  }

  return 0;
}