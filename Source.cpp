#include"iostream"
#include <fstream>
#include <iostream>
#include <sstream>
#include<vector>
#include <algorithm> 
#include <math.h> 

//#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include<cppunit/XmlOutputter.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;
double distanceCalculate(double valueArr[40][3]) {

	double minDis = 0;
	double currentDis = 0;
	double temp = 100;

	int index1;
	int index2;
	int n = 0;
	for (int i = 0; i < 40; i++)
	{

		currentDis = sqrt(pow(valueArr[i][0] - valueArr[i + 1][0], 2) + pow(valueArr[i][1] - valueArr[i + 1][1], 2) + pow(valueArr[i][2] - valueArr[i + 1][2], 2));


		if (currentDis < temp)
		{
			temp = currentDis;
			index1 = i;
			index2 = i + 1;
		}

	}
	
	double newArr[40][3];
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			newArr[index1][j] = NULL;
			newArr[index2][j] = NULL;

			if (i != index1&&i != index2)
			{
				newArr[i][j] = valueArr[i][j];
			}

		}
	
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

	//ifstream infile(argv[1]);

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

	double valueArr[40][3];

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 3; j++) {
			valueArr[i][j] = atof(num[i][j].c_str());

		}
	}

	distanceCalculate(valueArr);


	//CPPUNIT_ASSERT(distanceCalculate(valueArr)==5.5);

	//CPPUNIT_ASSERT(distanceCalculate(valueArr) == 7.8613);

	/*CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
	CppUnit::TextUi::TestRunner runner;

	std::ofstream fs("Result.txt");
	CppUnit::XmlOutputter*outputter = new CppUnit::XmlOutputter(&runner.result(), fs);
	runner.setOutputter(outputter);

	runner.addTest(suite);
	bool wasSucessful = runner.run();

	return wasSucessful ? 0 : 1;
	*/
}



