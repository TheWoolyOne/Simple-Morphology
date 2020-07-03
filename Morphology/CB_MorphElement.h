#pragma once

#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(condition) /*implementation defined*/
#endif

#include "CB_Grid.h"

#include <cstdint>
#include <vector>
namespace Morphology
{
	// The square structure element has a simple constructor, just make every 
	class CB_SquareElement : public CB_BoolGrid
	{
	public:
		CB_SquareElement(int32_t size) : CB_BoolGrid(size, size) 
		{
		}
	};

	// A "diamond" shaped structure element requires a bit more thought
	// ensure size is at least 3
	// example structure element with sizes 3 and 4
	// 0 1 0   0 1 1 0
	// 1 1 1   1 1 1 1
	// 0 1 0   1 1 1 1
	//         0 1 1 0
	class CB_DiamondElement : public CB_BoolGrid
	{
	public:
		CB_DiamondElement(const int32_t size) : CB_BoolGrid(size, size) {}

	private:
		// modify the row/column indexes for a matrix of the specified size, to a value indicating how far the index
		// is from the edge. 
		// This can be achieved by finding the threshold, taking the absolute difference between this and the index,
		// then take this value from the threshold
		// if the sum is greater than the threshold value, then that element of the matrix will be a 1, all others will be a 0
		void initialiseGrid(const int32_t size)
		{
			// get the modified indexes, i.e. the values we want to sum
			std::vector<int32_t> values_to_sum;

			int32_t threshold = calculateThresholdFromSize(size);

			for (int index = 1; index <= size; index++)
			{
				int abs_diff = std::abs(index - threshold);
				values_to_sum.push_back(threshold - abs_diff);
			}

			assert(values_to_sum.size() == size);
			// do the sums
			// the matrix is zero indexed
			for (int row_index = 0; row_index < size; row_index++)
			{
				for (int column_index = 0; column_index < size; column_index++)
				{
					int sum_for_matrix_element = values_to_sum[row_index] + values_to_sum[column_index];

				}
			}
		}

		int32_t calculateThresholdFromSize(const int32_t size)
		{
			// calculate whether an element should be a 1 or a 0, in the diamond case.
			// For each row/column index, assign a value which tells us how far from the edge we are
			// e.g. for a size 5 element, the indexes, 1-5, would have the values : [ 1, 2, 3 (midvalue), 2, 1]
			// e.g. for a size 6 element, the idnexes, 1-6, would have the values : [ 1, 2, 3 (midvalue), 3 (midvalue), 2, 1]
			// 
			int32_t threshold = size / 2 + (size % 2);
			return threshold;
		}
	};
}