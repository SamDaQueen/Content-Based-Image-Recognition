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
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "csv_util.h"

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {
  if (argc < 6) {
    cout << "Please input <filename> <target image> <directory path>"
            " <method name> <feature name> <number of images to be found>";
    return -1;
  }

  char target[256];
  char dirname[256];
  char method[256];
  char feature[256];
  char buffer[256];
  FILE *fp;
  DIR *dirp;
  struct dirent *dp;
  int i;

  // get the target image name
  strcpy(target, argv[1]);
  cout << "Target image name: " << target << endl;

  // get the directory path
  strcpy(dirname, argv[2]);
  cout << "Directory name: " << dirname << endl;

  // get the method name
  strcpy(method, argv[3]);
  cout << "Method name: " << method << endl;

  // open the directory
  dirp = opendir(dirname);
  if (dirp == NULL) {
    cout << "Cannot open directory " << dirname << endl;
    return -1;
  }

  cout << "Terminating...";

  return 0;
}