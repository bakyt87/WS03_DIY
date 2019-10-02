#ifndef SDDS_REPORTUTILS_H__
#define SDDS_REPORTUTILS_H__



#include <iostream>
#include <cstring>
#include <iomanip>
#include "MarksReport.h"
#include "Mark.h" 


		using namespace std;

		namespace sdds {
		
	
			ostream& line(int len, char ch) {
				for (int i = 0; i < len; i++, cout << ch);
				return cout;
			}
	
			}

#endif