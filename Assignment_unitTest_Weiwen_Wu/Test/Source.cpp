#include"iostream"
#include <fstream>
#include <iostream>
#include <sstream>
#include<vector>
#include <algorithm> 
#include <math.h> 

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include<cppunit/XmlOutputter.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;
double distanceCalculate(string arr[40][3]) {

	double valueArr[40][3];

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 3; j++) {
			valueArr[i][j] = atof(arr[i][j].c_str());
			cout << valueArr[i][j] << " ";

		}
		cout << endl;
	}


	double minDis = 0;
	double currentDis = 0;
	double temp = 100;

	int index1;
	int index2;
	int n = 0;
	for (int i = 0; i < 40; i++)
	{

		currentDis = sqrt(pow(valueArr[i][0] - valueArr[i + 1][0], 2) + pow(valueArr[i][1] - valueArr[i + 1][1], 2) + pow(valueArr[i][2] - valueArr[i + 1][2], 2));
		cout << "Distance: " << currentDis << endl;


		if (currentDis < temp)
		{
			temp = currentDis;
			index1 = i;
			index2 = i + 1;
		}

	}
	cout << endl << "Min Distance" << temp << endl;
	cout << endl << index1 << " " << index2 << endl;


	double newArr[40][3];
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			newArr[index1][j] = 0;
			newArr[index2][j] = 0;

			if (i != index1&&i != index2)
			{
				newArr[i][j] = valueArr[i][j];

				cout << newArr[i][j] << "  ";
			}

		}
		cout << endl;
	}

	
	ofstream myfile("cba.txt");
	myfile << "Min Distance: " << temp << endl;
	myfile << "Row:" << index1<<", ";
	myfile << "Row:" << index2<<endl;


	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 3; j++) {

				myfile << newArr[i][j] << " ";

		}
		myfile << endl;
	}

	return temp;

}
int main(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		cout << "Argument:" << i + 1 << "On the Command Line" << argv[i] << endl;
	}


	ifstream infile("abc.txt");
	string num[40][3];


	while (infile.good())
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 3; j++) {

				infile >> num[i][j];
			}

		}

	}

	distanceCalculate(num);


	CPPUNIT_ASSERT(distanceCalculate(num)==0);

	CPPUNIT_ASSERT(distanceCalculate(num) == 7.8613);

	CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
	CppUnit::TextUi::TestRunner runner;

	std::ofstream fs("Result.txt");
	CppUnit::XmlOutputter*outputter = new CppUnit::XmlOutputter(&runner.result(), fs);
	runner.setOutputter(outputter);

	runner.addTest(suite);
	bool wasSucessful = runner.run();

	return wasSucessful ? 0 : 1;


}



