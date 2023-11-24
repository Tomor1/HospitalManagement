#include"Case.h"
#include<Time.h>
using namespace std;


void Case::create(string h_name, string d_name, string p_name) {
	ifstream fin("case.txt", ios::in);
	char time[22] = { 0 };
	int id ;
	Gettime(time);string time1 = time;
	//第一条病例
	if (!fin.is_open()) {
		id = 1;
		FILE* fp = fopen("case.txt", "at");
		char title[] = { "CaseID,Hospital_name,Doctor_name,Patient_name,Advice" };
		fputs(title, fp);fputs("\n", fp);
		fputs(time1.c_str(), fp);fputs(":", fp);
		fputs(to_string(id).c_str(), fp);fputs(",        ", fp);
		fputs(h_name.c_str(), fp);fputs(",        ", fp);
		fputs(d_name.c_str(), fp);fputs(",        ", fp);
		fputs(p_name.c_str(), fp);fputs("        \n", fp);
		fclose(fp);
		fin.close();
	}
	else {
		fin.close();
		ifstream infile3("case.txt");
		char line1[256] = { 0 }; id = 0;
		while (!infile3.eof())
		{
			infile3.getline(line1, sizeof(line1) - 1);
			id++;
		} infile3.close();
		id--;
		ifstream fin("case.txt", ios::in);
		FILE* fp = fopen("case.txt", "at");
		fputs(time1.c_str(), fp);fputs(":", fp);
		fputs(to_string(id).c_str(), fp);fputs(",        ", fp);
		fputs(h_name.c_str(), fp);fputs(",        ", fp);
		fputs(d_name.c_str(), fp);fputs(",        ", fp);
		fputs(p_name.c_str(), fp);fputs("        \n", fp);
		fclose(fp);
		fin.close();
	}
	cout << "病例已添加"<<endl;
};

void Case::search() {
	string p_name;
	cout << "请输入要查询病例的患者姓名：" ;
	cin >> p_name;
	ifstream infile("case.txt");
	//假设文件一定存在
	char line[256] = { 0 };string str;int tag = 0;
	while (!infile.eof())
	{
		infile.getline(line, sizeof(line) - 1);
		if (strstr(line, p_name.c_str()) != NULL)
		{
			tag = 1;
			str = line;
			cout << p_name << "对应的病例为：" << line << endl;;
		}
	}
	infile.close();
	if (tag == 0)cout << "无相关病例信息。";
};

void Case::modify() {
	string num;
	cout << "请输入要修改医嘱的病例序号：";
	cin >> num;
	string modification;
	cout << "请输入医嘱：";
	cin >> modification;
	char line[256] = { 0 };
	ifstream infile2("case.txt");
	while (!infile2.eof())
	{
		infile2.getline(line, sizeof(line) - 1);
		int dijihang = 0;
		string str = line;
		if (str.length()>23 && strcmp(str.substr(22,1).c_str(), num.c_str())==0)//找到该患者
		{
			//找出该患者在文件中第几行
			char line[256] = { 0 };int x = 0;int tag = 0;
			ifstream infile("case.txt");
			//假设文件一定存在
			while (!infile.eof())
			{
				infile.getline(line, sizeof(line) - 1);x++;
				string str = line;
				if (x!=1&&strcmp(str.substr(22, 1).c_str(), num.c_str()) == 0)
				{
					infile.close();tag = 1;
					break;
				}
			}
			if (tag == 0) {
				cout << "该病例不存在！" << endl;
				return;
			}
			dijihang = x;
			ifstream infile3("case.txt");
			char line1[256] = { 0 };
			string temp[999];int t = dijihang;int u = 0;
			while (!infile3.eof())
			{
				infile3.getline(line1, sizeof(line1) - 1);
				temp[u] = line1;
				if (t == 1)
				{
					temp[u] = temp[u].substr(0, 64);
					temp[u] += ',';
					temp[u] += modification;
				}u++;t--;
			} infile3.close();
			FILE* fp = fopen("case.txt", "w+");
			for (int j = 0;j < u - 1;j++) {
				fputs(temp[j].c_str(), fp);fputs("\n", fp);
			}fclose(fp);
			cout << "修改成功！" << endl;
		}
	}
	infile2.close();
};