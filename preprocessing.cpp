
#include <opencv2/opencv.hpp>
#include <iostream>

 int main() {
        cv::Mat image = cv::imread("./image/input.jpg");
        if (image.empty()) {
            std::cout << "Error: Could not open or find the image." << std::endl;
            return -1;
        }
        cv::imshow("Image", image);
        cv::waitKey(0); // Wait indefinitely for a key press
        image.dump();
        std::cout << "Hello, world!" << std::endl;
        return 0;
    }