#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include <vector>
#include <algorithm>
#include <string>
#include<iomanip>
using namespace std;

// Store the data of Hospital 
class Hospital {
public:
	//void PrintHospitalData(vector<Hospital>& hospitals);
	//void SortHospitalByName(vector<Hospital> hospitals);
	//void SortHospitalByRating(vector<Hospital> hospitals);
	//void SortByBedsAvailable(vector<Hospital> hospitals);
	//void SortByBedsPrice(vector<Hospital> hospitals);
	//void PrintHospitalBycity(string city, vector<Hospital> hospitals);
	//void HospitalManagement(
	//	string hospital_Name[], string locations[], int beds[],
	//	double ratings[], string hospital_Contact[],
	//	string doctor_Name[], int prices[]);
	string H_name;
	string location;
	int available_beds;
	double rating;
	string contact;
	string doctor_name;
	int price;
	string free = "yes";
};
