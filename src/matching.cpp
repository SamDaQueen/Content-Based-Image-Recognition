/**
 * @file matching.cpp
 * @author Samreen
 * @brief Use the feature set stored in a csv to match a target image with all
 * the images in the directory to generate top n results
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 * Reference taken from readfiles.cpp @author Bruce A. Maxwell
 *
 */

#include <dirent.h>

#include <iostream>
#include <map>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "csv_util.h"
#include "distance.hpp"
#include "genFeatures.hpp"

using namespace std;
using namespace cv;

void resizeImage(Mat &src, Mat &dst, unsigned int n) {
  unsigned int width = 1024 / n;
  unsigned int height = 512 * width / 640;
  resize(src, dst, Size(width, height));
}

int main(int argc, const char *argv[]) {
  // if (argc < 6) {
  //   cout << "Please input <filename> <target image path> <distance method>"
  //           " <feature> <feature set file> <number of images to be found>";
  //   return -1;
  // }

  char target[256];
  char method[256];
  char feature[256];
  char feature_file[256];
  unsigned int n;
  FILE *fp;
  DIR *dirp;
  struct dirent *dp;

  // get the target image name
  strcpy(target, argv[1]);
  cout << "Target image name: " << target << endl;

  // get the distance mthod name
  strcpy(method, argv[2]);
  cout << "Distance method: " << method << endl;

  // get the method name
  strcpy(feature, argv[3]);
  cout << "Feature name: " << feature << endl;

  // get the feature file path
  strcpy(feature_file, argv[4]);
  cout << "Feature file path: " << feature_file << endl;

  // get the number of images to match
  sscanf(argv[5], "%d", &n);
  cout << "Number of images to match: " << n << endl;

  // read the file and get the images and features
  vector<char *> image_names;
  vector<std::vector<float>> image_data;

  Mat target_image = imread(target, IMREAD_COLOR);

  // create a map for storing image names with the error
  typedef map<float, string> ErrorMap;
  ErrorMap errors;

  vector<float> target_data;

  if (!strcmp(feature, "texcol")) {
    vector<float> target_texture(NUM_BINS, 0);
    vector<float> target_color(NUM_BINS * NUM_BINS, 0);
    textureHist(target_image, target_texture);
    colorHist(target_image, target_color);

    vector<vector<float>> image_data_tex;
    vector<vector<float>> image_data_col;

    strcpy(feature_file, "data/texture.csv");
    read_image_data_csv(feature_file, image_names, image_data_tex, false);
    strcpy(feature_file, "data/color.csv");
    read_image_data_csv(feature_file, image_names, image_data_col, false);

    if (!strcmp(method, "ssd")) {
      for (unsigned int i = 0; i < image_data_tex.size(); i++) {
        errors[SSD(target_texture, image_data_tex[i]) +
               SSD(target_color, image_data_col[i])] = image_names[i];
      }
    } else {
      for (unsigned int i = 0; i < image_data_tex.size(); i++) {
        errors[SAD(target_texture, image_data_tex[i]) +
               SAD(target_color, image_data_col[i])] = image_names[i];
      }
    }

  } else if (!strcmp(feature, "center")) {
    vector<float> target_data;
    centerHist(target_image, target_data);

    vector<float> target_texture(&target_data[0], &target_data[NUM_BINS]);
    vector<float> target_color(&target_data[NUM_BINS],
                               &target_data[NUM_BINS * NUM_BINS + NUM_BINS]);

    strcpy(feature_file, "data/center.csv");
    read_image_data_csv(feature_file, image_names, image_data, false);

    for (unsigned int i = 0; i < image_data.size(); i++) {
      vector<float> image_data_tex(&image_data[i][0], &image_data[i][NUM_BINS]);
      vector<float> image_data_col(
          &image_data[i][NUM_BINS],
          &image_data[i][NUM_BINS * NUM_BINS + NUM_BINS]);

      errors[0.75f * intersection(target_texture, image_data_tex) +
             0.25f * intersection(target_color, image_data_col)] =
          image_names[i];
    }

  } else if (!strcmp(feature, "multi")) {
    read_image_data_csv(feature_file, image_names, image_data, false);
    multiHist(target_image, target_data);

    for (unsigned int i = 0; i < image_names.size(); i++) {
      // vector<float> temp(&target_data[0], &target_data[NUM_BINS * NUM_BINS]);

      // cout << "temps size:" << temp.size() << endl;
      // for (int k = 0; k < temp.size(); k++) {
      //   cout << temp[k] << " ";
      // }

      float error =
          0.7 *
          SSD(vector<float>(&target_data[0], &target_data[NUM_BINS * NUM_BINS]),
              vector<float>(&image_data[i][0],
                            &image_data[i][NUM_BINS * NUM_BINS]));

      error +=
          0.3 * SSD(vector<float>(&target_data[NUM_BINS * NUM_BINS],
                                  &target_data[NUM_BINS * NUM_BINS * 2]),
                    vector<float>(&image_data[i][NUM_BINS * NUM_BINS],
                                  &image_data[i][NUM_BINS * NUM_BINS * 2]));

      // for (unsigned int j = 1; j < 5; j++) {
      //   error +=
      //       0.2 *
      //       SSD(vector<float>(&target_data[NUM_BINS * NUM_BINS * j],
      //                         &target_data[NUM_BINS * NUM_BINS * (j + 1)]),
      //           vector<float>(&image_data[i][NUM_BINS * NUM_BINS * j],
      //                         &image_data[i][NUM_BINS * NUM_BINS * (j +
      //                         1)]));
      // }

      errors[error] = image_names[i];
    }

  } else {
    read_image_data_csv(feature_file, image_names, image_data, false);

    if (!strcmp(feature, "baseline")) {
      baseline(target_image, target_data);
    } else if (!strcmp(feature, "texture")) {
      for (unsigned int i = 0; i < NUM_BINS; i++) {
        target_data.push_back(0);
      }
      textureHist(target_image, target_data);
    } else if (!strcmp(feature, "histogram")) {
      for (unsigned int i = 0; i < NUM_BINS * NUM_BINS; i++) {
        target_data.push_back(0);
      }
      colorHist(target_image, target_data);
    }
    cout << "Done creating target image features" << endl;
    if (!strcmp(method, "ssd")) {
      for (unsigned int i = 0; i < image_names.size(); i++) {
        errors[SSD(target_data, image_data[i])] = image_names[i];
      }
    } else {
      for (unsigned int i = 0; i < image_names.size(); i++) {
        errors[SAD(target_data, image_data[i])] = image_names[i];
      }
    }
  }

  ErrorMap::iterator pos = errors.begin();
  resizeImage(target_image, target_image, n);

  unsigned int i;
  for (pos++, i = 0; i < n; ++pos, i++) {
    cout << "Image file: " << pos->second << " Error: " << pos->first << endl;
    Mat new_image = imread(pos->second);
    resizeImage(new_image, new_image, n);
    hconcat(target_image, new_image, target_image);
  }

  // show image
  imshow("Matching images: First image is target image", target_image);

  // wait for a keystroke q
  char key = waitKey(10);
  while (key != 'q') {
    key = waitKey(10);
  }

  cout << "Terminating...";

  return 0;
}