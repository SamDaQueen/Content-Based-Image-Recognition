/**
 * @file matching.cpp
 * @author Samreen
 * @brief
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

#include "csv_util.h"
#include "distance.hpp"
#include "genFeatures.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
  if (argc < 6) {
    cout << "Please input <filename> <target image path> <distance method>"
            " <feature> <feature set file> <number of images to be found>";
    return -1;
  }

  char target[256];
  char method[256];
  char feature[256];
  char feature_file[256];
  unsigned int n;
  FILE *fp;
  DIR *dirp;
  struct dirent *dp;
  int i;

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

  // read the file and get the images and features
  vector<char *> image_names;
  vector<std::vector<float>> image_data;
  read_image_data_csv(feature_file, image_names, image_data, false);

  Mat target_image = imread(target, IMREAD_COLOR);

  typedef map<string, float> ErrorMap;
  ErrorMap errors;

  if (!strcmp(feature, "baseline")) {
    vector<float> target_data;
    baseline(target_image, target_data);
    for (unsigned int i = 0; i < image_names.size(); i++) {
      errors[image_names[i]] = SSD(target_data, image_data[i]);
    }
  }

  ErrorMap::iterator pos;
  for (pos = errors.begin(); pos != errors.end(); ++pos) {
    cout << "key: \"" << pos->first << "\" "
         << "value: " << pos->second << endl;
  }

  cout << "Terminating...";

  return 0;
}