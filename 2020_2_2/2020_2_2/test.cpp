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

	cout << "Ӣ��ɼ���";

	cin >> english;

	cout << "������ɼ���";

	cin >> computer;
}

voidStudent::computesum()

{
	total = english + computer;

	cout << "���" <

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

			cout << "�ܷ������--" <

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
