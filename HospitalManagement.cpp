#include"Hospital.h"
#include"Patient.h"
#include"Case.h"

void PrintHospitalData(
	vector<Hospital>& hospitals)
{
	cout << "PRINT hospitals DATA:"
		<< endl;

	cout << "HospitalName	 "
		<< "Location	 "
		<< "Beds_Available	 "
		<< "Rating	 "
		<< "Hospital_Contact	 "
		<< "Doctor_Name	 "
		<< "Price_Per_Bed	 \n";

	for (int i = 0; i < 4; i++) {
		cout << setw(17) << setiosflags(ios::left)
			<< hospitals[i].H_name
			<< setw(16) << setiosflags(ios::left)
			<< hospitals[i].location
			<< setw(16) << setiosflags(ios::left)
			<< hospitals[i].available_beds
			<< setw(8) << setiosflags(ios::left)
			<< hospitals[i].rating
			<< setw(24) << setiosflags(ios::left)
			<< hospitals[i].contact
			<< setw(16) << setiosflags(ios::left)
			<< hospitals[i].doctor_name
			<< hospitals[i].price
			<< endl;
	}

	cout << endl
		<< endl;
}

void PrintPatientData(
	vector<Patient>& patients,
	vector<Hospital>& hospitals)
{
	cout << "PRINT patients DATA:"
		<< endl;
	cout << "Patient_Name	 "
		<< "Patient_Id	 "
		<< "Patient_Contact	 "
		/* << "Alloted_Hospital	 " */
		<< "Patient_Expenditure	 \n";

	for (int i = 0; i < 4; i++) {
		cout << setw(17) << setiosflags(ios::left)
			<< patients[i].P_name
			<< setw(16) << setiosflags(ios::left)
			<< patients[i].P_id
			<< setw(24) << setiosflags(ios::left)
			<< patients[i].contact
			/*<< setw(24) << setiosflags(ios::left)
			<< hospitals[i].H_name*/
			<< patients[i].price
			<< endl;
	}

	cout << endl
		<< endl;
}

void SortHospitalByName(
	vector<Hospital> hospitals)
{
	// Sort the date 
	sort(hospitals.begin(),
		hospitals.end(),
		[](Hospital& A, Hospital& B) {return A.H_name > B.H_name;});

	cout << "SORT BY NAME:"
		<< endl
		<< endl;
	PrintHospitalData(hospitals);
}

void SortHospitalByRating(vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		[](Hospital& A, Hospital& B) { return A.rating > B.rating;});

	cout << "SORT BY Rating:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

// Comparator function to sort the 
// hospital data by Bed Available 
bool beds(Hospital& A, Hospital& B)
{
	return A.available_beds > B.available_beds;
}

void SortByBedsAvailable(
	vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		beds);

	cout << "SORT BY Available Beds:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

// Comparator function to sort the 
// hospital data by Bed Price 
bool beds_price(Hospital& A, Hospital& B)
{
	return A.price < B.price;
}

void SortByBedsPrice(
	vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		beds_price);

	cout << "SORT BY Available Beds Price:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

void PrintHospitalBycity(
	string city, vector<Hospital> hospitals)
{
	cout << "PRINT hospitals by Name :"
		<< city << endl;

	cout << "HospitalName	 "
		<< "Location	 "
		<< "Beds_Available	 "
		<< "Rating	 "
		<< "Hospital_Contact	 "
		<< "Doctor_Name	 "
		<< "Price_Per_Bed	 \n";

	for (int i = 0; i < 4; i++) {

		if (hospitals[i].location != city)
			continue;
		cout << setw(17) << setiosflags(ios::left)
			<< hospitals[i].H_name
			<< setw(16) << setiosflags(ios::left)
			<< hospitals[i].location
			<< setw(16) << setiosflags(ios::left)
			<< hospitals[i].available_beds
			<< setw(8) << setiosflags(ios::left)
			<< hospitals[i].rating
			<< setw(24) << setiosflags(ios::left)
			<< hospitals[i].contact
			<< setw(16) << setiosflags(ios::left)
			<< hospitals[i].doctor_name
			<< hospitals[i].price
			<< endl;
	}
	cout << endl
		<< endl;
}

void HospitalManagement(
	string patient_Name[], int patient_Id[],
	string patient_Contact[], int bookingCost[],
	string hospital_Name[], string locations[], int beds[],
	double ratings[], string hospital_Contact[],
	string doctor_Name[], int prices[])
{
	// Stores the Hospital data 
	// and user data 
	vector<Hospital> hospitals;

	// Create Objects for hospital 
	// and the users 
	Hospital h;

	// Initialize the data 
	for (int i = 0; i < 4; i++) {
		h.H_name = hospital_Name[i];
		h.location = locations[i];
		h.available_beds = beds[i];
		h.rating = ratings[i];
		h.contact = hospital_Contact[i];
		h.doctor_name = doctor_Name[i];
		h.price = prices[i];
		hospitals.push_back(h);
	}

	ifstream fin("hospital.txt", ios::in);
	if (!fin.is_open()) {
		FILE* fp = fopen("hospital.txt", "at");
		char title[] = { "HospitalName,Location,Beds_Available,Rating,Hospital_Contact,Doctor_Name,Price_Per_Bed,IsFree" };
		fputs(title, fp);fputs("\n", fp);
		for (int i = 0;i < 4;i++) {
			fputs(hospitals[i].H_name.c_str(), fp);fputs(",", fp);
			fputs(hospitals[i].location.c_str(), fp);fputs(",", fp);
			fputs(to_string(hospitals[i].available_beds).c_str(), fp);fputs(", ", fp);
			fputs(to_string(hospitals[i].rating).c_str(), fp);fputs(",", fp);
			fputs(hospitals[i].contact.c_str(), fp);fputs(",", fp);
			fputs(hospitals[i].doctor_name.c_str(), fp);fputs(",", fp);
			fputs(to_string(hospitals[i].price).c_str(), fp);fputs(",", fp);
			fputs(hospitals[i].free.c_str(), fp);fputs("\n", fp);
		}
		fclose(fp);
	}fin.close();

	// Stores the patient data 
	vector<Patient> patients;
	Patient p;

	// Initialize the data 
	for (int i = 0; i < 4; i++) {
		p.P_name = patient_Name[i];
		p.P_id = patient_Id[i];
		p.contact = patient_Contact[i];
		p.price = bookingCost[i];
		patients.push_back(p);
	}

	ifstream fin1("patient.txt", ios::in);
	if (!fin1.is_open()) {
	FILE* fp1 = fopen("patient.txt", "at");
	char title1[] = { "Patient_Name,Patient_Id,Patient_Contact,Patient_Expenditure,located_H" };
	fputs(title1, fp1);fputs("\n", fp1);
	for (int i = 0;i < 4;i++) {
		fputs(patients[i].P_name.c_str(), fp1);fputs(",", fp1);
		fputs(to_string(patients[i].P_id).c_str(), fp1);fputs(", ", fp1);
		fputs(patients[i].contact.c_str(), fp1);fputs(",", fp1);		
		fputs(to_string(patients[i].price).c_str(), fp1);fputs(",", fp1);
		fputs("null", fp1);fputs("\n", fp1);
	}
	fclose(fp1);
	}fin1.close();

	/*PrintHospitalData(hospitals);
	PrintPatientData(patients,hospitals);
	SortHospitalByName(hospitals);
	SortHospitalByRating(hospitals);
	PrintHospitalBycity("Bangalore", hospitals);
	SortByBedsAvailable(hospitals);
	SortByBedsPrice(hospitals);*/

	cout << endl;


}

void finance(string price,string fee) {
	ifstream fin("finance.txt", ios::in);
	char time[22] = { 0 };
	Gettime(time);string time1 = time;
	int total = atoi(price.c_str()) + atoi(fee.c_str());
	FILE* fp = fopen("finance.txt", "at");
	fputs(time1.c_str(), fp);
    fputs(("收入"+to_string(total)).c_str(), fp);fputs("\n", fp);
		fclose(fp);
		fin.close();
	

	cout << "财务已更新" << endl;
}

void registration() {
	string p_id;
	cout << "请输入您的用户id：";
	cin >> p_id;
	cout << endl << "请输入您想要预约的医生名称：";
	string d_name;
	cin >> d_name;
	cout << endl;
	//查询该医生是否空闲
	ifstream infile("hospital.txt");
	char line[256] = { 0 };
	string h_name;//其所属医院名称
	string price;
	while (!infile.eof())
	{
		infile.getline(line, sizeof(line) - 1);
		/*修改医生状态free->busy*/
		int dijihang = 0;//该医生在第几行
		
		if (strstr(line, d_name.c_str()) != NULL)//找到该医生
		{
			if (strstr(line, "yes") != NULL) {
				infile.close();
				//找出该医生在文件中第几行
				char line[256] = { 0 };int x = 0;
				ifstream infile("hospital.txt");
				//假设文件一定存在
				while (!infile.eof())
				{
					infile.getline(line, sizeof(line) - 1);x++;
					if (strstr(line, d_name.c_str()) != NULL)
					{
						infile.close();
						break;
					}
				}dijihang = x;//找到第几行了
				/*修改状态*/
				ifstream infile1("hospital.txt");
				char line1[256] = { 0 };
				string temp[999];int t = dijihang;int u = 0;
				while (!infile1.eof())
				{
					infile1.getline(line1, sizeof(line1) - 1);
					temp[u] = line1;
					if (t == 1)
					{
						int p = 0;int q = 0;
						for (int c = 0;c < 7;p++) {
							if (temp[u][p] == ',')c++;
							if (temp[u][p] == ',' && c == 6)q = p;
						}

						string mof = temp[u];
						temp[u] = mof.substr(0, p);
						temp[u] += "busy";
						h_name = mof.substr(0, 2);
						price = mof.substr(q + 1, p - q-2);
					}u++;t--;
				} infile1.close();
				FILE* fp = fopen("hospital.txt", "w+");
				for (int j = 0;j < u - 1;j++) {
					fputs(temp[j].c_str(), fp);fputs("\n", fp);
				}fclose(fp);
			}
			else {
				cout << "该医生正忙！请重试。" << endl;
				return;
			}
		}
	} infile.close();

	string p_name;string fee;
	ifstream infile2("patient.txt");
	while (!infile2.eof())
	{
		infile2.getline(line, sizeof(line) - 1);
		int dijihang = 0;
		if (strstr(line, p_id.c_str()) != NULL)//找到该患者
		{
			infile.close();
			//找出该患者在文件中第几行
			char line[256] = { 0 };int x = 0;
			ifstream infile("patient.txt");
			//假设文件一定存在
			while (!infile.eof())
			{
				infile.getline(line, sizeof(line) - 1);x++;
				string str = line;
				if (strstr(str.substr(3,1).c_str(), p_id.c_str()) != NULL)
				{
					infile.close();
					break;
				}
			}dijihang = x;
			ifstream infile3("patient.txt");
			char line1[256] = { 0 };
			string temp[999];int t = dijihang;int u = 0;
			while (!infile3.eof())
			{
				infile3.getline(line1, sizeof(line1) - 1);
				temp[u] = line1;
				if (t == 1)
				{
					int p = 0;int q = 0;
					for (int c = 0;c < 4;p++) {
						if (temp[u][p] == ',')c++;
						if (temp[u][p] == ',' && c == 3)q = p;
					}
					string mof = temp[u];
					temp[u] = mof.substr(0, p);
					temp[u] += h_name;
					p_name = mof.substr(0, 2);
					fee = mof.substr(q + 1, p - q-2);
				}u++;t--;
			} infile3.close();
			FILE* fp = fopen("patient.txt", "w+");
			for (int j = 0;j < u - 1;j++) {
				fputs(temp[j].c_str(), fp);fputs("\n", fp);
			}fclose(fp);
		}
	}
	infile2.close();
	//Case c;
	//c.create(h_name, d_name, p_name);
	finance(price, fee);
	return;
}


// Driver Code 
int main()
{
	// Stores hospital data and 
	// the user data 
	string patient_Name[] = { "P1", "P2", "P3", "P4" };
	int patient_Id[] = { 2, 3, 4, 1 };
	string patient_Contact[]
		= { "234534XXX7", "234576XXX2", "857465XXX9",
			"567657XXX0" };
	int bookingCost[] = { 1000, 1200, 1100, 600 };

	string hospital_Name[] = { "H1", "H2", "H4", "H3" };
	string locations[] = { "Bangalore", "Bangalore",
						"Mumbai ", "Prayagraj" };
	int beds[] = { 4, 5, 6, 9 };
	double ratings[] = { 5.2, 4.1, 3.4, 5.9 };
	string hospital_Contact[]
		= { "657534XXX7", "298766XXX2", "324565XXX9",
			"343456XXX4" };
	string doctor_Name[] = { "D1", "D4", "D3", "D2" };
	int prices[] = { 100, 200, 100, 290 };

	// Function Call 
	HospitalManagement(
		patient_Name, patient_Id, patient_Contact,
		bookingCost, hospital_Name, locations, beds,
		ratings, hospital_Contact, doctor_Name, prices);
	registration();
	
	//Case c;
	//c.search();
	//c.modify();
	return 0;
}
