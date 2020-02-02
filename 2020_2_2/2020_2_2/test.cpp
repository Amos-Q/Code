#define _CRT_SECURE_NO_WARNINGS 1
#include  <iostream>

using namespace std;

classStudent

{//**1**

intcomputer;

inttotal;

public:

voidgetinformation();

voidcomputesum();

intgetcode();

intgettotalscore();

~Student(); };

voidStudent::getinformation()

{//**2**

	cout << "英语成绩：";

	cin >> english;

	cout << "计算机成绩：";

	cin >> computer;
}

voidStudent::computesum()

{
	total = english + computer;

	cout << "编号" <

		intStudent::getcode()

	{
		returncode;
	}

	intStudent::gettotalscore()

	{
		returntotal;
	}

	voidfirstname(Student*A[], intnum)

	{

		//**3**

		tempsum = (*A[0]).gettotalscore();

		for (inti = 1; i

			{

			if (((*A[i]).gettotalscore()) > tempsum)

			{
		  tempcode = (*A[i]).getcode();

		 tempsum = (*A[i]).gettotalscore();
	   }

			}

			cout << "总分最高者--" <

	}

	voidmain()

	{
		Student*A[3];

		inti, n = 3;

		for (i = 0; i

			{ A[i] = newStudent;

			A[i]->getinformation(); }

		for (i = 0; i

			{ A[i]->computesum(); }

		firstname(A, 3);
	}
