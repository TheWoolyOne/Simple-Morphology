// TestHarness.cpp : Defines the entry point for the console application.
//

#include <windows.h>

#include "stdafx.h"

#include "ImageFunctions.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

// opencv_imgcodecs345.lib;opencv_imgproc345.lib;opencv_highgui345.lib;opencv_core345.lib;%(AdditionalDependencies)
const std::string frigate_bird = "../Images/frigatebird.jpg";

int main()
{
	int num1 = 7;
	int num2 = 2;

	int ans = 7 / 2 + (7 % 2);

	std::cout << ans;

	cv::Mat image_matrix = ImageHandling::ImageFunctions::readImageToMat(frigate_bird);

	cv::Mat mask = ImageHandling::ImageFunctions::applyThreshold(image_matrix, 100);
	auto element = image_matrix;

	std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}

