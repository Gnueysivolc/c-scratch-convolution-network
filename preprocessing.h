#pragma once
#include <vector>
#include <opencv2/opencv.hpp>

const int new_width = 300;
const int new_height = 300;


cv::Mat processing(cv::Mat images, int new_width, int new_height);

void read_and_process(int new_width, int new_height);






