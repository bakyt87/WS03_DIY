	#ifndef SDDS_MARK_H__
	#define SDDS_MARK_H__
	namespace sdds {
		int const DSP_RAW = 1;
		int const	DSP_PERCENT = 2;
		int const	DSP_ASIS = 3;
		int const	DSP_UNDEFINED = -1;
		int const DSP_GPA = 4;
		int const DSP_LETTER = 5;

		class Mark {
			int m_displayMode;
			double m_mark;
			int m_outOf;
			char m_name[71];
			void flushKeyboard()const;
			void prnLetter()const;
		public:
			void set(int diaplayMode);
			//This function sets m_displayMode member variable to value of the incoming argument(displayMode)
			void set(double mark, int outOf = 1);
			//This function sets “m_mark”and “m_outOf” member variables to the corresponding arguments.When this function is called, if the outOf argument is not provided, it will default its value to 1.
			void setEmpty();
			//Sets m_displayMode to DSP_UNDEFINED, m_mark  to - 1 and m_outf to 100.
			bool isEmpty()const;
			//returns true if the Mark object is Empty.
			int percent()const;
			//divides m_mark by m_outOf them multiplies it by 100 and ads 0.5 to it.Then it will cast the outcome to an integer and returns it.
			double rawValue()const;
			//returns the result of m_mark divided by m_outOf.
			bool read(const char* prompt);
			//This function reads the mark in following format :
			//mark / out of, for example : 30 / 50 or 20 / 20 and returns true if successful and If it cannot read the any part of the mark it will fail and return false.
				//To do this read first prints the prompt argument.Then it will read a double into m_mark, ignore one character and then read an integer into m_outOf.Afterwards it will check if the “cin” object has failed or not.If “cin” has failed, it will clear cin, set the Mark object to empty and return false.
				//In any case before returning anything read will flush the keyboard.
			std::ostream& display(int width = 55) const;
			//If the object is empty, it will print :
			//"Empty Mark object!"
				//if it is not empty, depending on the value of m_displayMode it will print the following :
			//if m_displayMode is DSP_RAW it will print the rawValue().
				//if m_displayMode is DSP_PERCENT it will print "%"and then the percent() value;
			void set(const char* name);
			bool readName(const char* prompt, int maxLen = 50);
			void changeOutOf(int value);
			double GPA()const;
			double letterBasedGPA()const;

		};
	}
#endif 
