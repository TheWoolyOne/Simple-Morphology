#pragma once

#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(condition) /*implementation defined*/
#endif

#include <cstdint>

namespace Morphology
{
	class CB_BoolGrid
	{
	public:
		CB_BoolGrid(int32_t x_width, int32_t y_height) : _width(x_width), _height(y_height)
		{
			_array = new bool[x_width * y_height];
		}

		~CB_BoolGrid()
		{
			delete _array;
		}

		bool getElement(int32_t x, int32_t y)
		{
			int64_t element_index = index(x, y);

			assert(_array.size() >= element_index);

			return _array[element_index];
		}

		void width(int32_t w) { _width = w; }
		int32_t width() { return _width; }

		void height(int32_t h) { _height = h; }
		int32_t height() { return _height; }

	private:
		int64_t index(int32_t x, int32_t y)
		{
			int64_t index = x + _width * y;

			return index;
		}

		bool * _array = nullptr;

		int32_t _width = 0;
		int32_t _height = 0;
	};
}