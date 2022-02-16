CS5330 PRCV Project 2 README

#1. Links/URLs to any videos you created and want to submit as part of your report:
N/A

#2. The URL for your wiki report for this project:
https://wiki.khoury.northeastern.edu/x/5It5Bg


#3. What operating system and IDE you used to run and compile your code:
This was a collaboration between Samreen Reyaz Ansari and Anish Satalkar. 
Both Windows 11 and macOS Monterey were used to run and compile multiple parts of the code.
On Windows, Visual Studio Code was used and on macOS, Xcode was used.
The final version of the project was compiled and run on the Windows machine.

#4. Instructions for running your executables.
0. Create the following directories in your working directory ({working-directory}):
    a. build
    b. data
        i. olympus
        ii. test
    c. include
    d. src
1. Create the following empty files in {working-directory}/data
    a. baseline.csv
    b. texture.csv
    c. color.csv
    d. multi.csv
    e. center.csv

There are 2 executables that you'll need to run.
1. The 'extract' executable is responsible for extracting features from the database of images into a csv.
To execute it, do the following: ./bin/extract <directory path> <feature>
Where,
    <directory path>: The path where your database of images resides. Example: /data/olympus
    <feature>: Specifies the feature to be used for extraction. This can be one of these:
        baseline: Uses 9x9 center pixels to compute features.
        texture: Uses sobel gradient magnitude histogram features.
        histogram: Uses the entire image to get an RG-Chromaticity histogram as a feature.
        multi: Divides the image into 2 parts and uses 2 RG-Chromaticity histograms for features.
        center: Chops off the image and uses the center part and then calculates texcol features.

2. The 'matching' executable is responsible for matching a given image with the images in database.
To execute it, do the following: 
./bin/matching <target image path> <distance method> <feature> <number of images to be found>
Where,
    <target image name>: The path of the target image (the one you would like to match with others)
    <distance method>: This specifies the distance metric to be used. This can one of these:
        sad: Sum of Absolute Sifferences
        ssd: Sum of Squared Sifferences
        intersection: Histogram Intersection
    <feature>: Specifies the feature to be used for matching
        baseline: Uses 9x9 center pixels to compute features
	texture: Uses sobel gradient magnitude histogram for features
        texcol: Uses sobel gradient magnitude histogram and RG-Chromaticity histogram for features
        histogram: Uses the entire image to get an RG-Chromaticity histogram as a feature
        multi: Divides the image into 2 parts and uses 2 RG-Chromaticity histograms for features
        center: Chops off the image and uses the center part and then calculates texcol features
    <number of images to be found>: Specifies the number of matching images to return. Returns the top matched images and shows them. Also prints them in output console.


#5. Instructions for testing any extensions you completed.
For the first extension run the following executables:
1. ./bin/extract /data/olympus center
2. ./bin/matching pic.0287.jpg sad center /data/center.csv 3

The second extension was an experiment and its findings have been added in the Wiki.
No execution of code necessary.


#6. Whether you are using any time travel days and how many.
None.