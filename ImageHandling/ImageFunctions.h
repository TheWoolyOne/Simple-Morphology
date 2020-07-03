#pragma once


#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace ImageHandling
{
	class ImageFunctions
	{
	public:
		ImageFunctions() = default;

		static cv::Mat readImageToMat(const std::string& filename);

		static cv::Mat applyThreshold(const cv::Mat& grayscale_image, const int32_t threshold);
	};
}
