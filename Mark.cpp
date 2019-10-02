
	#define _CRT_SECURE_NO_WARNINGS
	#include <iostream>
	#include <cstring>
	#include "Mark.h"

	using namespace std;

	namespace sdds {

		void Mark::flushKeyboard()const {
			while (cin.get() != '\n');
		}
		void Mark::set(int displayMode) {
			m_displayMode = displayMode;

		}
		void Mark::set(double mark, int outOf) {
			m_mark = mark;
			m_outOf = outOf;
		}
		bool Mark::isEmpty()const {
			if (m_mark <= 0)
				return true;
			else
				return false;
		}
		void Mark::setEmpty() {
			m_displayMode = DSP_UNDEFINED;
			m_mark = -1;
			m_outOf = 100;
			strcpy(m_name, "");
		}
		int Mark::percent()const {

			return int((m_mark / m_outOf) * 100 + 0.5);

		}

		double Mark::rawValue()const {

			return(m_mark / m_outOf);

		}

		bool Mark::read(const char* prompt) {
			bool success = true;
			cout << prompt;
			cin >> m_mark;
			cin.ignore();
			cin >> m_outOf;
			if (cin.fail()) {
				cin.clear();
				setEmpty();
				success = false;

			}
			flushKeyboard();
			return success;

		}


		ostream& Mark::display(int width) const {
			if (strcmp(m_name, "")) {
				cout.fill('.');
				cout.width(width);

				cout << left << m_name;

			}
			if (isEmpty()) {
				cout << "Empty object";

			}
			else if (m_displayMode == DSP_RAW) {
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << rawValue();
			}
			else if (m_displayMode == DSP_PERCENT)
				cout << "%" << percent();


			else if (m_displayMode == DSP_ASIS) {
				cout.setf(ios::fixed);
				cout.precision(1);
				cout << m_mark << "/" << m_outOf;
			}
			else if (m_displayMode == DSP_UNDEFINED)
				cout << "Display mode not set!";

			else if (m_displayMode == DSP_LETTER)
				prnLetter();
			else if (m_displayMode == DSP_GPA) {
				cout.setf(ios::fixed);
				cout.precision(1);
				cout << Mark::GPA();
			}
			else
				cout << "Invalid Mark Display setting";
			return cout;
		}
		void Mark::prnLetter()const {

			if (percent() >= 0 && percent() <= 49)
			{
				cout << "F";
			}
			else if (percent() >= 50 && percent() <= 54)
			{
				cout << "D";
			}
			else if (percent() >= 55 && percent() <= 59)
			{
				cout << "D+";
			}

			else if (percent() >= 60 && percent() <= 64)
			{
				cout << "C";
			}
			else if (percent() >= 65 && percent() <= 69)
			{
				cout << "C+";
			}
			else if (percent() >= 70 && percent() <= 74)
			{
				cout << "B";
			}
			else if (percent() >= 75 && percent() <= 79)
			{
				cout << "B+";
			}
			else if (percent() >= 80 && percent() <= 89)
			{
				cout << "A";
			}
			else if (percent() >= 90 && percent() <= 100)
			{
				cout << "A+";
			}
			else
				cout << "?";


		}
		void Mark::set(const char* name) {
			strncpy(m_name, name, 50);
		}

		bool Mark::readName(const char* prompt, int maxLen) {
			int result = 1;
			cout << prompt;

			if (maxLen > 50) {
				maxLen = 50;
			}
			cin.getline(m_name, maxLen + 1, '\n');

			if (cin.fail()) {
				cin.clear();
				flushKeyboard();
				strcpy(m_name, "");
				result = 0;
			}return result;
		}
		void Mark::changeOutOf(int value) {
			m_mark = m_outOf / (double)value;
			m_outOf = value;
			if (value < 1) {
				setEmpty();
			}
		}


		double Mark::GPA()const {
			return (rawValue() * 4);

		}

		double Mark::letterBasedGPA()const {
			if (percent() >= 0 && percent() <= 49) {
				return 0.0;
			}
			else if (percent() >= 50 && percent() <= 54) {
				return 1;
			}
			else if (percent() >= 55 && percent() <= 59) {
				return 1.5;
			}
			else if (percent() >= 60 && percent() <= 64) {
				return 2;
			}
			else if (percent() >= 65 && percent() <= 69) {
				return 2.5;
			}
			else if (percent() >= 70 && percent() <= 74) {
				return 3;
			}
			else if (percent() >= 75 && percent() <= 79) {
				return 3.5;
			}
			else
				return 4;



		}


	}