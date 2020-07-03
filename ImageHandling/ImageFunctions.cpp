

#include "ImageFunctions.h"



namespace ImageHandling
{
	cv::Mat ImageFunctions::readImageToMat(const std::string& filename)
	{
		// load the image as greyscale
		cv::Mat image;
		// 8 bit grayscale - 256 levels of luminance
		image = cv::imread(filename, CV_LOAD_IMAGE_GRAYSCALE);

		return image;
	}

	cv::Mat ImageFunctions::applyThreshold(const cv::Mat& grayscale_image, const int32_t threshold)
	{
		cv::Mat mask;

		int num_rows = grayscale_image.rows;
		int num_columns = grayscale_image.cols;

		uchar* grayscale_image_data = grayscale_image.data;
		for (int i = 0; i < num_rows; ++i)
		{
			for (int j = 0; j < num_columns; ++j)
			{
				//if(grayscale_image.data)
			}
		}

		return mask;
	}
}