
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <glob.h>


std::vector<cv::Mat> trial_image;


    void processing(){

        
    }



 void process() {
        cv::Mat image = cv::imread("./image/input.jpg");

    }






int read_and_process(std::vector<cv::Mat> images, int new_width, int new_height){ {
    std::cout<<"input folder to be processed, press enter to stop"<<std::endl;

    std::vector <std::string> folder_names;

    // for inputing required moddifying images folders' names
    while(true){
        std::string input;
        std::getline(std::cin,input);
        folder_names.push_back(input);
        if (input.empty()) {
            break;
        }
    }

    for(const auto& folder_name: folder_names){
        glob_t glob_result;
        std::string pattern = folder_name + "/*.jpg";
        glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);
        for (size_t i = 0; i < glob_result.gl_pathc; ++i) {
            cv::Mat image = cv::imread(glob_result.gl_pathv[i]);

    

        if(image.empty()){
            std::cout<<"Error: Could not open or find the"<<i<<"th image."<<std::endl;
            continue;
        }

         cv::Mat resized_image;
         cv::resize(image, resized_image, cv::Size(new_width, new_height));
        trial_image.push_back(resized_image);


        // Process the image
        std::cout << "Processing image: " << glob_result.gl_pathv[i] << std::endl;
        // ...
    }
    globfree(&glob_result);
    return 0;
}








/*
for (auto& image : images) {
    std::string outputFilename = outputFolder + "/image_" + std::to_string(&image - &images[0]) + ".jpg";
    cv::imwrite(outputFilename, image);
}
*/