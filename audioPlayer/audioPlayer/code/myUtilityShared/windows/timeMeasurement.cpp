#include "timeMeasurement.h"

namespace MyUtility {
	TimeMeasurement::TimeMeasurement() :faultFlag(false) {}
	int TimeMeasurement::start() {
		//	std::cout << "QueryPerformanceCounter():\n";
		if (!QueryPerformanceFrequency(&freq))      // 単位習得
		{
			faultFlag = true;
			return 1;
		}
		if (!::QueryPerformanceCounter(&startTime))
		{
			faultFlag = true;
			return 1;
		}
		return 0;
	}

	int TimeMeasurement::end(double & durationSeconds) {
		if (faultFlag)
			return 1;
		if (!QueryPerformanceCounter(&endTime))
			return 1;    // 取得失敗
		//seconds
		durationSeconds = (double)(endTime.QuadPart - startTime.QuadPart) / freq.QuadPart;
		return 0;
	}
}