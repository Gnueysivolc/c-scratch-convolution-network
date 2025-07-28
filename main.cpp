#include <iostream>
#include <opencv2/opencv.hpp>
 int main() {
        cv::Mat image = cv::imread("input.jpg");
        if (image.empty()) {
            std::cout << "Error: Could not open or find the image." << std::endl;
            return -1;
        }
        cv::imshow("Image", image);
        cv::waitKey(0); // Wait indefinitely for a key press
        return 0;
    }