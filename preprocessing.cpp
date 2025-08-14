
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <glob.h>
#include <sys/stat.h>
using namespace std::filesystem;


cv::Mat processing(cv::Mat image, int new_length) {
    // Calculate the maximum square size that can be cropped from the image
    int square_size = std::min(image.cols, image.rows);

    // Calculate the top-left corner of the square
    int x = (image.cols - square_size) / 2;
    int y = (image.rows - square_size) / 2;

    // Crop the square from the image
    cv::Rect roi(x, y, square_size, square_size);
    cv::Mat cropped_image = image(roi);

    // Resize the cropped image to 300x300
    cv::Mat resized_image;
    cv::resize(cropped_image, resized_image, cv::Size(new_length, new_length));

    std::cout << "processed image" << std::endl;
    return resized_image;
}








void read_and_process(int new_length){
    std::cout<<"input folder to be processed, press enter to stop"<<std::endl;

    std::vector <std::string> folder_names;

    // for inputing required moddifying images folders' names
    while(true){
        std::string input;
        std::getline(std::cin,input);
        if (input.empty()) {
            break;
        }
        folder_names.push_back(input);
    }


    // process images in a single file one by one
    for(const auto& folder_name: folder_names){
        std::cout<<"Processing folder: "<<folder_name<<std::endl;

        glob_t glob_result;
        std::string pattern = "image/" + folder_name + "/*.jpg";

        std::vector<cv::Mat> current_images; // create vector for storing modified images of current folders

        glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);
       
        int ret = glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);

    if (ret != 0) {
        std::cout << "⚠️ No JPG files found in '" << folder_name << "' (glob error: " << ret << ")" << std::endl;
          globfree(&glob_result);
         continue;
    }

    if (glob_result.gl_pathc == 0) {
        std::cout << "⚠️ No JPG files found in '" << folder_name << "'" << std::endl;
        globfree(&glob_result);
        continue;
    }

    for (size_t i = 0; i < glob_result.gl_pathc; ++i) {
        cv::Mat image = cv::imread(glob_result.gl_pathv[i]);

    

        if(image.empty()){
            std::cout<<"Error: Could not open or find the"<<i<<"th image."<<std::endl;
            continue;
        }



        // process the image
         cv::Mat resized_image;
         resized_image = processing(image, new_length );
        current_images.push_back(resized_image);
        std::cout<<"saved image"<<std::endl;
        cv::imshow("Resized Image", resized_image);
        cv::waitKey(0);


        std::cout << "Processing image: " << glob_result.gl_pathv[i] << std::endl;
        // ...
    }
    //make new directory and store the modified images inside
    std::string newFolderName = "modified_" + folder_name;

    // Create the new folder if it doesn't exist
    if (mkdir(newFolderName.c_str(), 0777) == 0) {
        std::cout <<newFolderName<< "Directory created!" << std::endl;
    } else {
        std::cout << "Directory creation failed!" << std::endl;
    }

    for (auto& image : current_images) {
        std::string outputFilename = newFolderName + "/image_" + std::to_string(&image - &current_images[0]) + ".jpg";
        cv::imwrite(outputFilename, image);
        std::cout << "Image saved: " << outputFilename << std::endl;
    }
    globfree(&glob_result);
}
}







/*
for (auto& image : images) {
    std::string outputFilename = outputFolder + "/image_" + std::to_string(&image - &images[0]) + ".jpg";
    cv::imwrite(outputFilename, image);
}
*/