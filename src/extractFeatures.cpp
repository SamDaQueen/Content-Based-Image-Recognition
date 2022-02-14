/**
 * @file extractFeatures.cpp
 * @author Samreen
 * @brief
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <dirent.h>

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

#include "csv_util.h"
#include "genFeatures.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
  if (argc < 3) {
    cout << "Please input <filename> <directory path> <feature>";
    return -1;
  }

  char dirname[256];
  char feature[256];
  char buffer[256];
  FILE *fp;
  DIR *dirp;
  struct dirent *dp;
  int i;

  // get the directory path
  strcpy(dirname, argv[1]);
  cout << "Directory name: " << dirname << endl;

  // get the feature name
  strcpy(feature, argv[2]);
  cout << "Feature name: " << feature << endl;

  // open the directory
  dirp = opendir(dirname);
  if (dirp == NULL) {
    cout << "Cannot open directory " << dirname << endl;
    return -1;
  }

  // loop over all the files in the image file listing
  while ((dp = readdir(dirp)) != NULL) {
    // check if the file is an image
    if (strstr(dp->d_name, ".jpg") || strstr(dp->d_name, ".png") ||
        strstr(dp->d_name, ".ppm") || strstr(dp->d_name, ".tif")) {
      // printf("processing image file: %s\n", dp->d_name);

      // build the overall filename
      strcpy(buffer, dirname);
      strcat(buffer, "/");
      strcat(buffer, dp->d_name);

      // printf("full path name: %s\n", buffer);

      Mat img = imread(buffer, IMREAD_COLOR);

      if (!strcmp(feature, "baseline")) {
        vector<float> values;
        baseline(img, values);
        char filename[] = "data/baseline.csv";
        if (append_image_data_csv(filename, buffer, values, false) == 0) {
          cout << "Image written to file successfully!" << endl;
        }
      }
    }
  }

  cout << "Terminating...";

  return 0;
}