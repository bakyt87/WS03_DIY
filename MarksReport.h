#ifndef SDDS_REPORT_H__
#define SDDS_REPORT_H__
#include <iostream>
#include <cstring>
#include "Mark.h"
#include "MarksReport.h"
#include "ReportUtils.h"


	namespace sdds {
		class MarksReport {
			Mark* m_marks;
			char* m_title[71];
			int m_numOfMarks;
			Mark m_lowMark;
			Mark m_highMark;
			float m_average;
		public:
			void initialize();
			float getMarks();
			void print();
			void terminate();

	};
	}

#endif // !
