
/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File report.cpp
// Version 1.0
// Date	2019/09/23
// Author	Fardad Soleimanloo
// Description
// tests Mark data entry
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/
	#define _CRT_SECURE_NO_WARNINGS
	#include "MarksReport.h"
	#include "Mark.h"
	#include "ReportUtils.h"
	#include <iostream>
	#include <cstring>
	#include <iomanip>



	int main() {
			sdds::MarksReport mr;
			mr.initialize();
			mr.getMarks();
			mr.print();
			mr.terminate();
			return 0;
		}
 