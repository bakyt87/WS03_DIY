
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "MarksReport.h"
#include "ReportUtils.h"
#include "Mark.h"

using namespace std;
	namespace sdds {
		void MarksReport::initialize() {
			m_title = new char[1];
			strcpy(m_title, "");
			m_marks = new Mark[1];
			m_numOfMarks = -1;
			m_lowMark.set(0, 1);
			m_highMark.set(1, 1);
			m_average = 0;
		}
		float MarksReport::getMarks() {
			char name[71];
			int number;
			cout << "Enter the report Name: ";
            read(name, 70);
			m_title = new char[strlen(name) + 1];
			strcpy(m_title, name);
			cout << "Enter the number of marks: ";
			read(number, 1, 50);
			m_numOfMarks = number;
			m_marks = new Mark[m_numOfMarks];
			
			cout << "Please enter" << m_numOfMarks << " marks:";
			for (int i = 0; i < m_numOfMarks; i++) {
				cout << i + 1;
				m_marks[i].readName(": Subject Name:", 6);
				m_marks[i].read("Mark (mark / outof): ");
				if (m_highMark.percent() < m_marks[i].percent())
					m_highMark = m_marks[i];
				if (m_lowMark.percent > m_marks[i].percent())
					m_lowMark = m_marks[i];
				m_average += m_marks[i].letterBasedGPA();
			}
			m_average = m_average / m_numOfMarks;
			cout << "Entry Completed!" << endl;
			cout << endl;
			line(70, '-') << endl;
			return 0;
			}
		
		void MarksReport::print() {
		
			cout << m_title << endl;
			line(70, '-') << endl;
			cout << "Marks entered:" << endl;
			for (int i = 0; i < m_numOfMarks; i++) {
				m_marks[i].set(DSP_LETTER);
				m_marks[i].display(60);
				cout << endl;
			}
			line(70, '-') << endl;
			cout.precision(2);
			cout.setf(ios::fixed);

			line(30, ' ');
			m_lowMark.set("Lowest Mark");
			m_lowMark.set(DSP_PERCENT);
			m_lowMark.display(36);
			cout << endl;
			line(30, ' ');
			m_highMark.set("Highest Mark");
			m_highMark.set(DSP_PERCENT);
			m_highMark.display(36);
			cout << endl;

			cout.precision(1);
			line(30, ' ');
			cout.fill('.');
			cout.width(36);
			cout << left << "GPA";
			cout << m_average << endl;
		}
		void MarksReport::terminate() {
			delete[] m_marks;
			delete[] m_title;
		}
	
}