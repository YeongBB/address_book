#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;
using std::cout;

void newFile();
int callFile();
void see();
void delete_data();
void modify();
void filesave();

typedef struct {
	string name;
	string phone;
	string address;
	string email;
	string group;
}calls;

int i = 0;
vector<calls> pb(1);

void main()

{
	char st = NULL;
	char str = NULL;
	cout << "\n ----------전화번호부 프로그램----------\n\n" << endl;
	while (1)
	{
		cout.setf(ios::left);
		cout << setw(25) << "\n 새로만들기 : 1" << " 불러오기 : 2\n 입력 : ";
		cin >> st;

		if (st == '1')
		{
			newFile();
			break;
		}
		else if (st == '2')
		{
			if (callFile() == 1)
				break;
		}
		else
			cout << " 잘못 입력하였습니다" << endl;
	}

	while (1)
	{
		cout.setf(ios::left);
		cout << setw(15) << "\n 추가 : 1" << setw(15) << " 출력 : 2" << setw(15) << " 삭제 : 3" << setw(15) << " 수정 : 4" << setw(15) << "저장 : 5" << "종료 : 6\n 입력 : ";
		cin >> str;
		cout << endl;

		switch (str)
		{
		case '1':
			newFile();
			break;
		case '2':
			see();
			break;
		case '3':
			delete_data();
			break;
		case '4':
			modify();
			break;
		case '5':
			filesave();
		case '6':
			cout << " ---------------종 료---------------\n\n" << endl;
			exit(0);
		default:
			cout << "잘못된 입력" << endl;
		}

	}

}

void newFile()						// 새로만들기 / 추가
{
	if (0 < i)
		pb.resize(i + 1);

	cout << " 입력하세요" << endl;
	cout << "---------------------" << endl;
	cout << " 이름 : ";			cin >> pb[i].name;
	cout << " 전화번호 : ";		cin >> pb[i].phone;
	getchar();
	cout << " 주소 : ";			getline(cin, pb[i].address);
	cout << " 이메일 : ";			cin >> pb[i].email;
	cout << " 그룹 : ";			cin >> pb[i].group;

	i++;

	cout << "\n-----추가완료-----\n" << endl;
}

int callFile()						// 파일 불러오기
{
	ifstream fp;
	string filename;
	string cdrive = "C:\\Temp\\";
	string tx = ".txt";
	string line;
	cout << " 파일 이름을 입력하시오. : ";
	getchar();
	getline(cin, filename);

	string plu = cdrive + filename + tx;

	fp.open(plu);

	if (fp.is_open())
	{
		while (!fp.eof())
		{
			if (0 < i)
				pb.resize(i + 1);
			if (i == 0)
			{
				getline(fp, line);
				getline(fp, line);
				getline(fp, line);
			}
			getline(fp, line);
			line.erase(0, 7);
			pb[i].name = line;
			getline(fp, line);
			line.erase(0, 11);
			pb[i].phone = line;
			getline(fp, line);
			line.erase(0, 7);
			pb[i].address = line;
			getline(fp, line);
			line.erase(0, 9);
			pb[i].email = line;
			getline(fp, line);
			line.erase(0, 7);
			pb[i].group = line;
			getline(fp, line);

			i++;
		}
		cout << "\n\n ---완료---" << endl;
		fflush(stdin);

		return 1;
	}
	else
	{
		cout << "\n 일치하는 파일이 없습니다." << endl;
		return 0;
	}

	fp.close();
}

void see()								// 출력
{
	vector<calls> cop(i);
	string temp;
	char d;

	cout << " 보기 항목을 선택하세요 \n";
	cout.setf(ios::left);
	cout << setw(20) << " 선차 : 1" << setw(20) << "이름 : 2" << setw(20) << " 그룹보기 : 3" << " 이름검색 : 4" << endl << " 입력 : ";
	cin >> d;
	cout << endl;

	if (d == '1')
	{
		for (int j = 0; j < i; j++)
		{
			cout << " - " << j + 1 << "번 - " << endl;
			cout << " 이름 : " << pb[j].name << endl;
			cout << " 전화번호 : " << pb[j].phone << endl;
			cout << " 주소 : " << pb[j].address << endl;
			cout << " 이메일 : " << pb[j].email << endl;
			cout << " 그룹 : " << pb[j].group << endl;
			cout << endl;
		}
		cout << "---------------------" << endl;
	}
	else if (d == '2')
	{
		for (int h = 0; h < i; h++)
		{
			cop[h].name = pb[h].name;
			cop[h].phone = pb[h].phone;
			cop[h].address = pb[h].address;
			cop[h].email = pb[h].email;
			cop[h].group = pb[h].group;
		}

		for (int t = 0; t < i; t++)
		{
			for (int j = 0; j < i - 1 + 1; j++)
			{
				if (cop[t].name < cop[j].name)
				{
					temp = cop[j].name;
					cop[j].name = cop[t].name;
					cop[t].name = temp;

					temp = cop[j].phone;
					cop[j].phone = cop[t].phone;
					cop[t].phone = temp;

					temp = cop[j].address;
					cop[j].address = cop[t].address;
					cop[t].address = temp;

					temp = cop[j].email;
					cop[j].email = cop[t].email;
					cop[t].email = temp;

					temp = cop[j].group;
					cop[j].group = cop[t].group;
					cop[t].group = temp;
				}
			}
		}

		for (int j = 0; j < i; j++)
		{
			cout << "------------------" << endl;
			cout << "이름 : " << cop[j].name << endl;
			cout << "전화번호 : " << cop[j].phone << endl;
			cout << "주소 : " << cop[j].address << endl;
			cout << "이메일 : " << cop[j].email << endl;
			cout << "그룹 : " << cop[j].group << endl;
			cout << endl;
		}
	}
	else if (d == '3')
	{
		string gr;
		int q = 0;
		cout << "그룹명을 입력하세요\n 입력 :";
		cin >> gr;
		for (int a = 0; a < i; a++)
		{
			if (gr == pb[a].group)
			{
				cout << "------------------" << endl;
				cout << "이름 : " << pb[a].name << endl;
				cout << "전화번호 : " << pb[a].phone << endl;
				cout << "주소 : " << pb[a].address << endl;
				cout << "이메일 : " << pb[a].email << endl;
				cout << "그룹 : " << pb[a].group << endl;
				cout << endl;
			}
		}
		if (q == 0)
			cout << " ---\n없음---" << endl;
	}
	else if (d == '4')
	{
		string gr;
		int q = 0;
		cout << "이름을 입력하세요\n 입력 :";
		cin >> gr;
		for (int a = 0; a < i; a++)
		{
			if (gr == pb[a].name)
			{
				cout << "------------------" << endl;
				cout << "이름 : " << pb[a].name << endl;
				cout << "전화번호 : " << pb[a].phone << endl;
				cout << "주소 : " << pb[a].address << endl;
				cout << "이메일 : " << pb[a].email << endl;
				cout << "그룹 : " << pb[a].group << endl;
				cout << endl;
				q++;
			}
		}
		if (q == 0)
			cout << " ---\n없음---" << endl;
	}
	else
		cout << " 잘못 입력 하였습니다" << endl;
}

void delete_data()				// 삭제
{
	int num = 0;
	cout << "삭제할 번호를 입력하세요\n 입력 :";
	cin >> num;
	if (num <= 0 || num > i)
	{
		cout << " --잘못된 번호입니다--" << endl;
		return;
	}
	vector<calls>::iterator iter = pb.begin();
	iter += (num - 1);
	pb.erase(iter);
	i--;
	pb.resize(i);
	cout << "\n----삭제 완료----" << endl;
}

void modify()				// 수정
{
	int num = 0;
	cout << " 수정할 번호를 선택하세요\n 입력 : ";
	cin >> num;
	if (num <= 0 || num > i)
	{
		cout << " 잘못된 번호입니다" << endl;
		return;
	}

	cout << " 입력하세요" << endl;
	cout << "---------------------" << endl;
	cout << " 이름 : " << pb[num - 1].name << "\t -> \t";
	cout << " 이름 : ";	cin >> pb[num - 1].name;
	cout << " 전화번호 : " << pb[num - 1].phone << "\t -> \t";
	cout << " 전화번호 : ";	cin >> pb[num - 1].phone;
	getchar();
	cout << " 주소 : " << pb[num - 1].address << "\t -> \t";
	cout << " 주소 : "; getline(cin, pb[num - 1].address);
	cout << " 이메일 : " << pb[num - 1].email << "\t -> \t";
	cout << " 이메일 : ";		cin >> pb[num - 1].email;
	cout << " 그룹 : " << pb[num - 1].group << "\t -> \t";
	cout << " 그룹 : ";			cin >> pb[num - 1].group;

	cout << "\n ----수정완료----" << endl;
}

void filesave()			// 파일 저장
{
	string filename;
	string cdrive = "C:\\Temp\\";
	string tx = ".txt";

	cout << " 저장할 파일 이름을 입력하시오. : ";
	getchar();
	getline(cin, filename);

	string plu = cdrive + filename + tx;
	ofstream out(plu);
	if (out.is_open())
	{
		for (int a = 0; a < i; a++)
		{
			if (a == 0)
			{
				out << " --전화번호부-- " << endl;
				out << endl << endl;
			}
			out << "이름 : " << pb[a].name << endl;
			out << "전화번호 : " << pb[a].phone << endl;
			out << "주소 : " << pb[a].address << endl;
			out << "이메일 : " << pb[a].email << endl;
			if (a + 1 == i)
				out << "그룹 : " << pb[a].group;
			else
			{
				out << "그룹 : " << pb[a].group << endl;
				out << endl;
			}
		}
	}
	out.close();
	cout << "\n ---저장 완료---\n" << endl;
}