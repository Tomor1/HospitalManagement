#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<iomanip>
#include"Hospital.h"
using namespace std;

// Store the data of Hospital 
class Patient :public Hospital{
public:
	/*void PrintPatientData(vector<Patient>& patients,
		vector<Hospital>& hospitals);*/
	string P_name;//患者姓名
	int P_id;//患者编号
};

