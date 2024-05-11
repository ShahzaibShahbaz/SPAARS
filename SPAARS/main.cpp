/*           Ikram - Ul - Haq (21L - 1764)
			 Murtaza Ahmad (21L - 5173)
			 Shahzaib Shahbaz (21L - 5378)


			 PROGRAM NAME: SPAAR*/


#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<cmath>

struct personal
{
	char batch[5];
	char roll_no[8];
	char gender[2];
	char name[30];
	char cnic[16];
	char father_name[30];
	int dob[3];
	char address[100];
	char city[11];
	char cell_phone[13];
	char father_status[2];
	char education[10];
};

struct course
{
	char course_code[8];
	char course_title[40];
	int credit_hours;
};

struct result
{
	char roll_num[8];
	char coursecode[8];
	int semester;
	int numbers;
};

struct report1c
{
	char roll[8] = { '\0' };
	char s_name[31] = { '\0' };
	char batch[5] = { '\0' };
	char city[11] = { '\0' };
	char education[10] = { '\0' };
};

struct report3
{
	char roll_no[8] = { '\0' };
	int semester;
	int numbers;
	char name[30];
	char grade[3];
	float gpa;
};

struct report1b
{
	char roll_no[8] = { '\0' };
	char name[30] = { '\0' };
};

struct report4
{
	char crs_code[7][8];
	int semester;
	int numbers[7];
	char course_title[7][40];
	int credit_hours[7];
	char grade[7][3];
	float gpa[7];
};

using namespace std;

char display();
int reading_personal(personal[]);
void reading_course(course[]);
void reading_result(result[]);
void r1a(personal[]);
void r1b(personal[], int);
void r1c(personal[]);
void r1d(personal[]);
void r2(course[], result[], personal[]);
void r3(course[], result[], personal[]);
void r4(course[], result[], personal[]);
void grde(report3[], int);
void GPA(report3[], int);
int min_marks(int, int);
int max_marks(int, int);
double avgm(report3[], int);
double avgg(report3[], int);
float grd(int, char[]);

int main()
{
	char report, again = 'Y';
	int l;

	personal student[100];
	course data[50];
	result marks[500];

	l = reading_personal(student);
	reading_course(data);
	reading_result(marks);

	//     Start Menu

	while (again == 'Y' || again == 'y')
	{
		report = display();

		//     Report - 1a

		if (report == '1')
		{
			r1a(student);
		}

		//     Report - 1b

		else if (report == '2')
		{
			r1b(student, l);
		}

		//     Report - 1c

		else if (report == '3')
		{
			r1c(student);
		}

		//     Report - 1d

		else if (report == '4')
		{
			r1d(student);
		}

		//     Report - 2

		else if (report == '5')
		{
			r2(data, marks, student);
		}

		//     Report - 3

		else if (report == '6')
		{
			r3(data, marks, student);
		}

		//     Report - 4

		else if (report == '7')
		{
			r4(data, marks, student);
		}

		else if (report == '8')
		{
			break;
		}

		cout << "Do You Want To Enter Again ( Y / N ) :   ";
		cin >> again;
	}

	return 0;
}

char display()
{
	char report = '0';

	while (!(report == '1' || report == '2' || report == '3' || report == '4' || report == '5' || report == '6' || report == '7' || report == '8'))
	{
		cout << "\n\n\n\n";
		cout << "\n\t\t\t\t\t\t\t------------------------------------------------------------------\n";
		cout << "\n\t\t\t\t\t\t\t|   WELCOME TO SPAAR (STUDENTS' PERSONAL AND ACADEMIC RECORDS)   |\n";
		cout << "\n\t\t\t\t\t\t\t------------------------------------------------------------------\n" << endl;
		cout << "\n\n\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "||-------||-----|----------|-----|-------------------------------------------------------------------|------------------|--------------------------------------------------------------|" << endl;
		cout << "|  Sr No. |      REPORT NO.      |                                                                       REPORT TITLE                                                                  |" << endl;
		cout << "||-------||-----|----------|-----|-------------------------------------------------------------------|------------------|--------------------------------------------------------------|" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "|_________|______________________|_____________________________________________________________________________________________________________________________________________________|" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "|    1    |          1A          |                                                               PERSONAL RECORD OF A STUDENT                                                          |" << "\n";
		cout << "|---------|----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "|    2    |          1B          |                                              PERSONAL INFORMATION OF ALL THE STUDENTS IN A SORTED ORDER                                             |" << "\n";
		cout << "|---------|----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "|    3    |          1C          |                                                     PERSONAL INFORMATION OF GROUP OF STUDENTS                                                       |" << "\n";
		cout << "|---------|----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "|    4    |          1D          |                                                                       STUDENT'S AGE                                                                 |" << "\n";
		cout << "|---------|----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "|    5    |          2           |                                                                   COURSE RESULTS ( A )                                                              |" << "\n";
		cout << "|---------|----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "|    6    |          3           |                                                                   COURSE RESULTS ( B )                                                              |" << "\n";
		cout << "|---------|----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|         |                      |                                                                                                                                                     |" << endl;
		cout << "|    7    |          4           |                                                                   STUDENT'S TRANSCRIPT                                                              |" << "\n";
		cout << "|---------|----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|         |                                                                                                                                                                            |" << endl;
		cout << "|    8    |                                                                                                  EXIT                                                                      |" << endl;
		cout << "|_________|____________________________________________________________________________________________________________________________________________________________________________|" << endl;

		cout << "\n\n\n\n\n\n\n";

		cout << "PLEASE SELECT AN OPTION:  " << endl;

		cout << "\n\n-->  ";

		cin >> report;

		if (!(report == '1' || report == '2' || report == '3' || report == '4' || report == '5' || report == '6' || report == '7' || report == '8'))
			cout << "You Have Entered Wrong Option. Please Input Again" << endl << endl;
	}

	return report;
}

int reading_personal(personal student[])
{
	ifstream fin;

	fin.open("Personal.txt");

	int i = 0, l = 0;

	while (!fin.eof())
	{
		fin.getline(student[i].batch, 5, ',');

		fin.ignore();

		fin.getline(student[i].roll_no, 8, ',');

		fin.ignore();

		fin.getline(student[i].gender, 2, ',');

		fin.ignore();

		fin.getline(student[i].name, 30, ',');

		fin.ignore();

		fin.getline(student[i].cnic, 16, ',');

		fin.ignore();

		fin.getline(student[i].father_name, 30, ',');

		fin.ignore();

		fin >> student[i].dob[0];

		fin.ignore();

		fin >> student[i].dob[1];

		fin.ignore();

		fin >> student[i].dob[2];

		fin.ignore();

		fin.getline(student[i].address, 100, ',');

		fin.ignore();

		fin.getline(student[i].city, 11, ',');

		fin.ignore();

		fin.getline(student[i].cell_phone, 13, ',');

		fin.ignore();

		fin.getline(student[i].father_status, 2, ',');

		fin.ignore();

		fin.getline(student[i].education, 10, '\n');

		i++;
		l++;
	}

	fin.close();

	return l;
}

void reading_course(course data[])
{
	ifstream fin;

	fin.open("Course.txt");

	int i = 0;

	while (!fin.eof())
	{
		fin.getline(data[i].course_code, 8, ',');

		fin.ignore();

		fin.getline(data[i].course_title, 40, ',');

		fin.ignore();

		fin >> data[i].credit_hours;

		fin.ignore();

		i++;
	}

	fin.close();
}

void reading_result(result marks[])
{
	ifstream fin;

	fin.open("Results.txt");

	int i = 0;

	while (!fin.eof())
	{
		fin.getline(marks[i].roll_num, 8, ',');

		fin.ignore();

		fin.getline(marks[i].coursecode, 8, ',');

		fin.ignore();

		fin >> marks[i].semester;

		fin.ignore();

		fin >> marks[i].numbers;

		fin.ignore();

		i++;
	}

	fin.close();
}

void r1a(personal student[100])
{
	char r_n[8];
	int r = 5, p = 1;

	cout << "\n\n\n\n";
	cin.ignore();

	while (p != 0)
	{
		cout << "\n\n\n\n";
		cout << "Enter Roll Number Of Student ( xxLxxxx ) :  ";
		cin.getline(r_n, 8, '\n');

		for (int i = 0; i < 100; i++)
		{
			p = strcmp(r_n, student[i].roll_no);

			if (p == 0)
			{
				break;
			}
		}

		if (p != 0)
		{
			cout << "Invalid Input" << endl;
			continue;
		}
	}

	cout << "\n\n\n\n";

	for (int i = 0; i < 100; i++)
	{
		int q = strcmp(r_n, student[i].roll_no);

		if (q == 0)
		{
			r = i;
			break;
		}
	}


	cout << "\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t------------------------------------------\n";
	cout << "\n\t\t\t\t\t\t\t\t\t|   REPORT - STUDENT'S PERSONAL RECORD   |\n";
	cout << "\n\t\t\t\t\t\t\t\t\t------------------------------------------\n" << endl;

	cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|                         |                                                                |                         |                                                                 |" << endl;
	cout << "| ROLL NUMBER             | " << setw(63) << left << student[r].roll_no;
	cout << "| STUDENT NAME            | " << setw(64) << left << student[r].name << "|" << endl;
	cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
	cout << "| BATCH                   | " << setw(63) << left << student[r].batch;
	cout << "| CNIC                    | " << setw(64) << left << student[r].cnic << "|" << endl;
	cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
	cout << "| FATHER NAME             | " << setw(63) << left << student[r].father_name;
	cout << "| CELL PHONE              | " << setw(64) << left << student[r].cell_phone << "|" << endl;
	cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
	cout << "| DATE OF BIRTH           | " << student[r].dob[0] << " - " << student[r].dob[1] << " - " << setw(54) << left << student[r].dob[2];
	cout << "| GENDER                  | " << setw(64) << left << student[r].gender << "|" << endl;
	cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
	cout << "| ADDRESS                 |" << setw(64) << left << student[r].address;
	cout << "| CITY                    | " << setw(64) << left << student[r].city << "|" << endl;
	cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
	cout << "| FATHER STATUS           | " << setw(63) << left << student[r].father_status;
	cout << "| EDUCATION               | " << setw(64) << left << student[r].education << "|" << endl;
	cout << "|_________________________|________________________________________________________________|_________________________|_________________________________________________________________|" << endl;

	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t  ||==================================================||" << "\n";
	cout << "\t\t\t\t\t\t\t\t  || HERE:-                                           ||"
		<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
		<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" M \"    IS FOR MALE                  ||"
		<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
		<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" F \"    IS FOR FEMALE                ||"
		<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
		<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" A \"    IS FOR ALIVE                 ||"
		<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
		<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" D \"    IS FOR DECEASED              ||"
		<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||";
	cout << "\n\t\t\t\t\t\t\t\t  ||==================================================||" << endl;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

}

void r1b(personal student[100], int l)
{
	report1b sort[100];
	char arr[8], arr1[30];
	char op1 = '3', op2 = '3';
	int s;


	while (!(op1 == '1' || op1 == '2'))
	{
		cout << "\n\n\n\n";

		cout << "On Which Basis You Want To Sort Data: \n\n";
		cout << "\t\t\t____________________________________________________________________________________\n";
		cout << "\t\t\t|           |                              |           |                           |\n";
		cout << "\t\t\t|   ( 1 )   |         STUDENT NAME         |   ( 2 )   |    STUDENT ROLL NUMBER    |\n";
		cout << "\t\t\t|___________|______________________________|___________|___________________________|\n";

		cout << "\n\n\n\n";

		cout << "\n\n\n\tENTER OPTION NUMBER";
		cout << "\n\n--->   ";
		cin >> op1;

		if (!(op1 == '1' || op1 == '2'))
			cout << "You Have Entered Wrong Option. Please Input Again" << endl << endl;
	}

	while (!(op2 == '1' || op2 == '2'))
	{
		cout << "\t\t\t____________________________________________________________________________________\n";
		cout << "\t\t\t|           |                              |           |                           |\n";
		cout << "\t\t\t|   ( 1 )   |        ASSCENDING ORDER      |   ( 2 )   |     DESCENDING ORDER      |\n";
		cout << "\t\t\t|___________|______________________________|___________|___________________________|\n";

		cout << "\n\n\n\tENTER OPTION NUMBER";
		cout << "\n\n--->   ";
		cin >> op2;

		if (!(op2 == '1' || op2 == '2'))
			cout << "You Have Entered Wrong Option. Please Input Again" << endl << endl;
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			sort[i].roll_no[j] = student[i].roll_no[j];
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			sort[i].name[j] = student[i].name[j];
		}
	}

	if (op1 == '1')
	{
		if (op2 == '1')
		{
			for (int i = 0; i < 100; i++)
			{
				for (int j = i + 1; j < 100; j++)
				{
					int q = strcmp(sort[i].name, sort[j].name);

					if (q == 1)
					{
						for (int k = 0; k < 30; k++)
						{
							arr1[k] = sort[i].name[k];
						}

						for (int k = 0; k < 30; k++)
						{
							sort[i].name[k] = sort[j].name[k];
						}

						for (int k = 0; k < 30; k++)
						{
							sort[j].name[k] = arr1[k];
						}
					}
				}
			}

			cout << endl;

			cout << "\n\n\n\n";
			cout << "\n\t\t\t\t\t\t\t\t  -----------------------------------------------\n";
			cout << "\n\t\t\t\t\t\t\t\t  |   REPORT - STUDENT'S PERSONAL INFORMATION   |\n";
			cout << "\n\t\t\t\t\t\t\t\t  -----------------------------------------------\n" << endl;

			cout << "\t\t\t\t\t\t____________________________________________________________________________________\n";
			cout << "\t\t\t\t\t\t|          |                                                                       |\n";
			cout << "\t\t\t\t\t\t|  SR NO.  |                          NAME OF STUDENTS                             |\n";
			cout << "\t\t\t\t\t\t|__________|_______________________________________________________________________|\n";

			for (int i = 0; i < l; i++)
			{
				cout << "\t\t\t\t\t\t|          |                                                                       |\n";
				cout << "\t\t\t\t\t\t|    " << i + 1 << "     |  " << setw(69) << left << sort[i].name << "|\n";

				if (i + 1 != l)
				{
					cout << "\t\t\t\t\t\t|----------|-----------------------------------------------------------------------|\n";
				}
			}

			cout << "\t\t\t\t\t\t|__________|_______________________________________________________________________|\n";
			cout << "\n\n\n\n\n\n\n";

			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					int q = strcmp(sort[i].name, student[j].name);

					if (q == 0)
					{
						s = j;
					}
				}


				cout << "                                                                                   " << i + 1 << "\n\n";
				cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
				cout << "|                         |                                                                |                         |                                                                 |" << endl;
				cout << "| STUDENT NAME            | " << setw(63) << left << student[s].name;
				cout << "| ROLL NUMBER             | " << setw(64) << left << student[s].roll_no << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| BATCH                   | " << setw(63) << left << student[s].batch;
				cout << "| CNIC                    | " << setw(64) << left << student[s].cnic << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| FATHER NAME             | " << setw(63) << left << student[s].father_name;
				cout << "| CELL PHONE              | " << setw(64) << left << student[s].cell_phone << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| DATE OF BIRTH           | " << student[s].dob[0] << " - " << student[s].dob[1] << " - " << setw(54) << left << student[s].dob[2];
				cout << "| GENDER                  | " << setw(64) << left << student[s].gender << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| ADDRESS                 |" << setw(64) << left << student[s].address;
				cout << "| CITY                    | " << setw(64) << left << student[s].city << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| FATHER STATUS           | " << setw(63) << left << student[s].father_status;
				cout << "| EDUCATION               | " << setw(64) << left << student[s].education << "|" << endl;
				cout << "|_________________________|________________________________________________________________|_________________________|_________________________________________________________________|" << endl;
				cout << "\n\n\n\n\n\n\n";
			}
			cout << "\n\n\n\n";
			cout << "\t\t\t\t\t\t\t\t  ||==================================================||" << "\n";
			cout << "\t\t\t\t\t\t\t\t  || HERE:-                                           ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" M \"    IS FOR MALE                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" F \"    IS FOR FEMALE                ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" A \"    IS FOR ALIVE                 ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" D \"    IS FOR DECEASED              ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||";
			cout << "\n\t\t\t\t\t\t\t\t  ||==================================================||" << endl;

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}


		if (op2 == '2')
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 4; j++)
				{
					int q = strcmp(sort[i].name, sort[j].name);

					if (q == -1)
					{
						for (int k = 0; k < 30; k++)
						{
							arr1[k] = sort[i].name[k];
						}

						for (int k = 0; k < 30; k++)
						{
							sort[i].name[k] = sort[j].name[k];
						}

						for (int k = 0; k < 30; k++)
						{
							sort[j].name[k] = arr1[k];
						}
					}
				}
			}

			cout << endl;

			cout << "\n\n\n\n";
			cout << "\n\t\t\t\t\t\t\t\t  -----------------------------------------------\n";
			cout << "\n\t\t\t\t\t\t\t\t  |   REPORT - STUDENT'S PERSONAL INFORMATION   |\n";
			cout << "\n\t\t\t\t\t\t\t\t  -----------------------------------------------\n" << endl;

			cout << "\t\t\t\t\t\t____________________________________________________________________________________\n";
			cout << "\t\t\t\t\t\t|          |                                                                       |\n";
			cout << "\t\t\t\t\t\t|  SR NO.  |                          NAME OF STUDENTS                             |\n";
			cout << "\t\t\t\t\t\t|__________|_______________________________________________________________________|\n";

			for (int i = 0; i < l; i++)
			{
				cout << "\t\t\t\t\t\t|          |                                                                       |\n";
				cout << "\t\t\t\t\t\t|    " << i + 1 << "     |  " << setw(69) << left << sort[i].name << "|\n";

				if (i + 1 != l)
				{
					cout << "\t\t\t\t\t\t|----------|-----------------------------------------------------------------------|\n";
				}
			}

			cout << "\t\t\t\t\t\t|__________|_______________________________________________________________________|\n";
			cout << "\n\n\n\n\n\n\n";


			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					int q = strcmp(sort[i].name, student[j].name);

					if (q == 0)
					{
						s = j;
					}
				}


				cout << "                                                                                   " << i + 1 << "\n\n";
				cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
				cout << "|                         |                                                                |                         |                                                                 |" << endl;
				cout << "| STUDENT NAME            | " << setw(63) << left << student[s].name;
				cout << "| ROLL NUMBER             | " << setw(64) << left << student[s].roll_no << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| BATCH                   | " << setw(63) << left << student[s].batch;
				cout << "| CNIC                    | " << setw(64) << left << student[s].cnic << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| FATHER NAME             | " << setw(63) << left << student[s].father_name;
				cout << "| CELL PHONE              | " << setw(64) << left << student[s].cell_phone << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| DATE OF BIRTH           | " << student[s].dob[0] << " - " << student[s].dob[1] << " - " << setw(54) << left << student[s].dob[2];
				cout << "| GENDER                  | " << setw(64) << left << student[s].gender << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| ADDRESS                 |" << setw(64) << left << student[s].address;
				cout << "| CITY                    | " << setw(64) << left << student[s].city << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| FATHER STATUS           | " << setw(63) << left << student[s].father_status;
				cout << "| EDUCATION               | " << setw(64) << left << student[s].education << "|" << endl;
				cout << "|_________________________|________________________________________________________________|_________________________|_________________________________________________________________|" << endl;
				cout << "\n\n\n\n\n\n\n";
			}
			cout << "\n\n\n\n";
			cout << "\t\t\t\t\t\t\t\t  ||==================================================||" << "\n";
			cout << "\t\t\t\t\t\t\t\t  || HERE:-                                           ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" M \"    IS FOR MALE                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" F \"    IS FOR FEMALE                ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" A \"    IS FOR ALIVE                 ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" D \"    IS FOR DECEASED              ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||";
			cout << "\n\t\t\t\t\t\t\t\t  ||==================================================||" << endl;

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
	}

	if (op1 == '2')
	{
		if (op2 == '1')
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 4; j++)
				{
					int q = strcmp(sort[i].roll_no, sort[j].roll_no);

					if (q == 1)
					{
						for (int k = 0; k < 8; k++)
						{
							arr[k] = sort[i].roll_no[k];
						}

						for (int k = 0; k < 8; k++)
						{
							sort[i].roll_no[k] = sort[j].roll_no[k];
						}

						for (int k = 0; k < 8; k++)
						{
							sort[j].roll_no[k] = arr[k];
						}
					}
				}
			}


			cout << endl;

			cout << "\n\n\n\n";
			cout << "\n\t\t\t\t\t\t\t\t  -----------------------------------------------\n";
			cout << "\n\t\t\t\t\t\t\t\t  |   REPORT - STUDENT'S PERSONAL INFORMATION   |\n";
			cout << "\n\t\t\t\t\t\t\t\t  -----------------------------------------------\n" << endl;

			cout << "\t\t\t\t\t\t____________________________________________________________________________________\n";
			cout << "\t\t\t\t\t\t|          |                                                                       |\n";
			cout << "\t\t\t\t\t\t|  SR NO.  |                          NAME OF STUDENTS                             |\n";
			cout << "\t\t\t\t\t\t|__________|_______________________________________________________________________|\n";

			for (int i = 0; i < l; i++)
			{
				cout << "\t\t\t\t\t\t|          |                                                                       |\n";
				cout << "\t\t\t\t\t\t|    " << i + 1 << "     |  " << setw(69) << left << sort[i].name << "|\n";

				if (i + 1 != l)
				{
					cout << "\t\t\t\t\t\t|----------|-----------------------------------------------------------------------|\n";
				}
			}

			cout << "\t\t\t\t\t\t|__________|_______________________________________________________________________|\n";
			cout << "\n\n\n\n\n\n\n";

			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					int q = strcmp(sort[i].roll_no, student[j].roll_no);

					if (q == 0)
					{
						s = j;
					}
				}


				cout << "                                                                                   " << i + 1 << "\n\n";
				cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
				cout << "|                         |                                                                |                         |                                                                 |" << endl;
				cout << "| ROLL NUMBER             | " << setw(63) << left << student[s].roll_no;
				cout << "| STUDENT NAME            | " << setw(64) << left << student[s].name << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| BATCH                   | " << setw(63) << left << student[s].batch;
				cout << "| CNIC                    | " << setw(64) << left << student[s].cnic << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| FATHER NAME             | " << setw(63) << left << student[s].father_name;
				cout << "| CELL PHONE              | " << setw(64) << left << student[s].cell_phone << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| DATE OF BIRTH           | " << student[s].dob[0] << " - " << student[s].dob[1] << " - " << setw(54) << left << student[s].dob[2];
				cout << "| GENDER                  | " << setw(64) << left << student[s].gender << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| ADDRESS                 |" << setw(64) << left << student[s].address;
				cout << "| CITY                    | " << setw(64) << left << student[s].city << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| FATHER STATUS           | " << setw(63) << left << student[s].father_status;
				cout << "| EDUCATION               | " << setw(64) << left << student[s].education << "|" << endl;
				cout << "|_________________________|________________________________________________________________|_________________________|_________________________________________________________________|" << endl;
				cout << "\n\n\n\n\n\n\n";
			}
			cout << "\n\n\n\n";
			cout << "\t\t\t\t\t\t\t\t  ||==================================================||" << "\n";
			cout << "\t\t\t\t\t\t\t\t  || HERE:-                                           ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" M \"    IS FOR MALE                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" F \"    IS FOR FEMALE                ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" A \"    IS FOR ALIVE                 ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" D \"    IS FOR DECEASED              ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||";
			cout << "\n\t\t\t\t\t\t\t\t  ||==================================================||" << endl;

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}


		if (op2 == '2')
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 4; j++)
				{
					int q = strcmp(sort[i].roll_no, sort[j].roll_no);

					if (q == -1)
					{
						for (int k = 0; k < 8; k++)
						{
							arr[k] = sort[i].roll_no[k];
						}

						for (int k = 0; k < 8; k++)
						{
							sort[i].roll_no[k] = sort[j].roll_no[k];
						}

						for (int k = 0; k < 8; k++)
						{
							sort[j].roll_no[k] = arr[k];
						}
					}
				}
			}


			cout << endl;

			cout << "\n\n\n\n";
			cout << "\n\t\t\t\t\t\t\t\t  -----------------------------------------------\n";
			cout << "\n\t\t\t\t\t\t\t\t  |   REPORT - STUDENT'S PERSONAL INFORMATION   |\n";
			cout << "\n\t\t\t\t\t\t\t\t  -----------------------------------------------\n" << endl;

			cout << "\t\t\t\t\t\t____________________________________________________________________________________\n";
			cout << "\t\t\t\t\t\t|          |                                                                       |\n";
			cout << "\t\t\t\t\t\t|  SR NO.  |                          NAME OF STUDENTS                             |\n";
			cout << "\t\t\t\t\t\t|__________|_______________________________________________________________________|\n";

			for (int i = 0; i < l; i++)
			{
				cout << "\t\t\t\t\t\t|          |                                                                       |\n";
				cout << "\t\t\t\t\t\t|    " << i + 1 << "     |  " << setw(69) << left << sort[i].name << "|\n";

				if (i + 1 != l)
				{
					cout << "\t\t\t\t\t\t|----------|-----------------------------------------------------------------------|\n";
				}
			}

			cout << "\t\t\t\t\t\t|__________|_______________________________________________________________________|\n";
			cout << "\n\n\n\n\n\n\n";

			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					int q = strcmp(sort[i].roll_no, student[j].roll_no);

					if (q == 0)
					{
						s = j;
					}
				}


				cout << "                                                                                   " << i + 1 << "\n\n";
				cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
				cout << "|                         |                                                                |                         |                                                                 |" << endl;
				cout << "| ROLL NUMBER             | " << setw(63) << left << student[s].roll_no;
				cout << "| STUDENT NAME            | " << setw(64) << left << student[s].name << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| BATCH                   | " << setw(63) << left << student[s].batch;
				cout << "| CNIC                    | " << setw(64) << left << student[s].cnic << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| FATHER NAME             | " << setw(63) << left << student[s].father_name;
				cout << "| CELL PHONE              | " << setw(64) << left << student[s].cell_phone << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| DATE OF BIRTH           | " << student[s].dob[0] << " - " << student[s].dob[1] << " - " << setw(54) << left << student[s].dob[2];
				cout << "| GENDER                  | " << setw(64) << left << student[s].gender << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| ADDRESS                 |" << setw(64) << left << student[s].address;
				cout << "| CITY                    | " << setw(64) << left << student[s].city << "|" << endl;
				cout << "|-------------------------|----------------------------------------------------------------|-------------------------|-----------------------------------------------------------------|" << endl;
				cout << "| FATHER STATUS           | " << setw(63) << left << student[s].father_status;
				cout << "| EDUCATION               | " << setw(64) << left << student[s].education << "|" << endl;
				cout << "|_________________________|________________________________________________________________|_________________________|_________________________________________________________________|" << endl;
				cout << "\n\n\n\n\n\n\n";
			}
			cout << "\n\n\n\n";
			cout << "\t\t\t\t\t\t\t\t  ||==================================================||" << "\n";
			cout << "\t\t\t\t\t\t\t\t  || HERE:-                                           ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" M \"    IS FOR MALE                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" F \"    IS FOR FEMALE                ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" A \"    IS FOR ALIVE                 ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||"
				<< "\n\t\t\t\t\t\t\t\t  ||\t<>\t\" D \"    IS FOR DECEASED              ||"
				<< "\n\t\t\t\t\t\t\t\t  ||                                                  ||";
			cout << "\n\t\t\t\t\t\t\t\t  ||==================================================||" << endl;

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
	}

}

void r1c(personal student[100])
{
	report1c stud[1000];
	int p = 1;
	int s = 0, count = 1;
	char option1 = '6';

	char city_name[11] = { '\0' }, gender_name[2], batch_name[5], father_s_name[2], education_name[10];

	char sp1, sp2;

	while (!(option1 == '1' || option1 == '2' || option1 == '3' || option1 == '4'))
	{
		cout << "On Which Basis You Want To Sort Data: \n\n";
		cout << "\t\t\t____________________________________________________________________________________\n";
		cout << "\t\t\t|           |                              |           |                           |\n";
		cout << "\t\t\t|   ( 1 )   |           CITY NAME          |   ( 2 )   |           GENDER          |\n";
		cout << "\t\t\t|           |                              |           |                           |\n";
		cout << "\t\t\t|-----------|------------------------------|-----------|---------------------------|\n";
		cout << "\t\t\t|           |                              |           |                           |\n";
		cout << "\t\t\t|   ( 3 )   |             BATCH            |   ( 4 )   |       FATHER STATUS       |\n";
		cout << "\t\t\t|___________|______________________________|___________|___________________________|\n";


		cout << "\n\n\n\tENTER OPTION NUMBER";
		cout << "\n\n--->   ";
		cin >> option1;

		if (!(option1 == '1' || option1 == '2' || option1 == '3' || option1 == '4'))
			cout << "You Have Entered Wrong Option. Please Input Again" << endl << endl;
	}

	cout << endl;
	cout << "\n\n\n\n";
	cout << "\n\t\t\t\t\t\t----------------------------------------------------------\n";
	cout << "\n\t\t\t\t\t\t|   REPORT - PERSONAL INFORMATION OF GROUP OF STUDENTS   |\n";
	cout << "\n\t\t\t\t\t\t----------------------------------------------------------\n" << endl;


	if (option1 == '1')
	{
		//cout << "Enter City Name: ";

		cin.ignore();
		//cin.getline(city_name, 11, '\n');

		while (p != 0)
		{
			cout << "\n\n\n\n";
			cout << "Enter City Name: ";
			cin.getline(city_name, 11, '\n');

			for (int i = 0; i < 100; i++)
			{
				p = strcmp(city_name, student[i].city);

				if (p == 0)
				{
					break;
				}
			}

			if (p != 0)
			{
				cout << "Invalid Input" << endl;
				continue;
			}
		}

		cout << endl;

		s = 0, count = 0;

		for (int i = 0; i < 100; i++)
		{
			int q = strcmp(city_name, student[i].city);

			if (q == 0)
			{
				for (int j = 0; j < 8; j++)
				{
					stud[s].roll[j] = student[i].roll_no[j];
				}

				for (int j = 0; j < 31; j++)
				{
					stud[s].s_name[j] = student[i].name[j];
				}

				s++;
				count++;
			}
		}

		cout << "\t\t\t\t\t\t   _____________________________________________________________________________________________\n";
		cout << "\t\t\t\t\t\t   |                   |                                                                       |\n";
		cout << "\t\t\t\t\t\t   |      ROLL NO.     |                          NAME OF STUDENTS                             |\n";
		cout << "\t\t\t\t\t\t   |___________________|_______________________________________________________________________|\n";

		for (int i = 0; i < count; i++)
		{
			cout << "\t\t\t\t\t\t   |                   |                                                                       |\n";
			cout << "\t\t\t\t\t\t   |      " << setw(13) << left << stud[i].roll << "|  " << setw(69) << left << stud[i].s_name << "|" << endl;

			if (i + 1 != count)
			{
				cout << "\t\t\t\t\t\t   |-------------------|-----------------------------------------------------------------------|\n";
			}
		}


		cout << "\t\t\t\t\t\t   |___________________|_______________________________________________________________________|\n";
	}

	p = 1;

	if (option1 == '2')
	{
		cout << "Enter Gender: ";

		cin.ignore();
		cin.getline(gender_name, 2, '\n');

		cout << endl;

		cout << "Do You Want To Enter Batch ( Y / N ) :   ";
		cin >> sp2;

		s = 0, count = 0;

		for (int i = 0; i < 100; i++)
		{
			int q = strcmp(gender_name, student[i].gender);

			if (q == 0)
			{
				for (int j = 0; j < 8; j++)
				{
					stud[s].roll[j] = student[i].roll_no[j];
				}

				for (int j = 0; j < 31; j++)
				{
					stud[s].s_name[j] = student[i].name[j];
				}

				for (int j = 0; j < 5; j++)
				{
					stud[s].batch[j] = student[i].batch[j];
				}

				s++;
				count++;
			}
		}

		if (sp2 == 'Y')
		{
			s = 0, count = 0;

			cout << endl;
			cout << "Enter Batch Year: ";
			cin.ignore();
			cin.getline(batch_name, 5, '\n');

			for (int i = 0; i < 100; i++)
			{
				int q = strcmp(batch_name, stud[i].batch);

				if (q == 0)
				{
					for (int j = 0; j < 8; j++)
					{
						stud[s].roll[j] = stud[i].roll[j];
					}

					for (int j = 0; j < 31; j++)
					{
						stud[s].s_name[j] = stud[i].s_name[j];
					}

					for (int j = 0; j < 5; j++)
					{
						stud[s].batch[j] = stud[i].batch[j];
					}

					s++;
					count++;
				}
			}

			for (int i = count; i < 100; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					stud[s].roll[j] = { '\0' };
				}

				for (int j = 0; j < 31; j++)
				{
					stud[s].s_name[j] = { '\0' };
				}

				for (int j = 0; j < 5; j++)
				{
					stud[s].batch[j] = { '\0' };
				}

				s++;
			}
		}


		cout << "\t\t\t\t\t\t   _____________________________________________________________________________________________\n";
		cout << "\t\t\t\t\t\t   |                   |                                                                       |\n";
		cout << "\t\t\t\t\t\t   |      ROLL NO.     |                          NAME OF STUDENTS                             |\n";
		cout << "\t\t\t\t\t\t   |___________________|_______________________________________________________________________|\n";

		for (int i = 0; i < count; i++)
		{
			cout << "\t\t\t\t\t\t   |                   |                                                                       |\n";
			cout << "\t\t\t\t\t\t   |      " << setw(13) << left << stud[i].roll << "|  " << setw(69) << left << stud[i].s_name << "|" << endl;

			if (i + 1 != count)
			{
				cout << "\t\t\t\t\t\t   |-------------------|-----------------------------------------------------------------------|\n";
			}
		}


		cout << "\t\t\t\t\t\t   |___________________|_______________________________________________________________________|\n";
	}

	if (option1 == '3')
	{
		cout << "Enter Batch Year: ";

		cin.ignore();
		cin.getline(batch_name, 5, '\n');

		cout << endl;

		for (int i = 0; i < 100; i++)
		{
			int q = strcmp(batch_name, student[i].batch);

			if (q == 0)
			{
				for (int j = 0; j < 8; j++)
				{
					stud[s].roll[j] = student[i].roll_no[j];
				}

				for (int j = 0; j < 31; j++)
				{
					stud[s].s_name[j] = student[i].name[j];
				}

				for (int j = 0; j < 5; j++)
				{
					stud[s].batch[j] = student[i].batch[j];
				}

				for (int j = 0; j < 11; j++)
				{
					stud[s].city[j] = student[i].city[j];
				}

				for (int j = 0; j < 10; j++)
				{
					stud[s].education[j] = student[i].education[j];
				}

				s++;
				count++;
			}
		}

		cout << "Do You Want To Enter Education ( Y / N ) :   ";
		cin >> sp1;

		if (sp1 == 'Y')
		{
			s = 0, count = 0;

			cout << endl;
			cout << "Enter Education: ";
			cin.ignore();
			cin.getline(education_name, 10, '\n');

			for (int i = 0; i < 100; i++)
			{
				int q = strcmp(education_name, stud[i].education);

				if (q == 0)
				{
					for (int j = 0; j < 8; j++)
					{
						stud[s].roll[j] = stud[i].roll[j];
					}

					for (int j = 0; j < 31; j++)
					{
						stud[s].s_name[j] = stud[i].s_name[j];
					}

					for (int j = 0; j < 5; j++)
					{
						stud[s].batch[j] = stud[i].batch[j];
					}

					for (int j = 0; j < 11; j++)
					{
						stud[s].city[j] = stud[i].city[j];
					}

					s++;
					count++;
				}
			}

			for (int i = count; i < 100; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					stud[s].roll[j] = { '\0' };
				}

				for (int j = 0; j < 31; j++)
				{
					stud[s].s_name[j] = { '\0' };
				}

				for (int j = 0; j < 5; j++)
				{
					stud[s].batch[j] = { '\0' };
				}

				for (int j = 0; j < 11; j++)
				{
					stud[s].city[j] = { '\0' };
				}

				s++;
			}
		}

		cout << "Do You Want To Enter City ( Y / N ) :   ";
		cin >> sp2;

		if (sp2 == 'Y')
		{
			s = 0, count = 0;

			cout << endl;
			cin.ignore();
			cout << "Enter City Name: ";
			cin.getline(city_name, 11, '\n');

			for (int i = 0; i < 100; i++)
			{
				int q = strcmp(city_name, stud[i].city);

				if (q == 0)
				{
					for (int j = 0; j < 8; j++)
					{
						stud[s].roll[j] = stud[i].roll[j];
					}

					for (int j = 0; j < 31; j++)
					{
						stud[s].s_name[j] = stud[i].s_name[j];
					}

					for (int j = 0; j < 5; j++)
					{
						stud[s].batch[j] = stud[i].batch[j];
					}

					s++;
					count++;
				}
			}

			for (int i = count; i < 100; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					stud[s].roll[j] = { '\0' };
				}

				for (int j = 0; j < 31; j++)
				{
					stud[s].s_name[j] = { '\0' };
				}

				for (int j = 0; j < 5; j++)
				{
					stud[s].batch[j] = { '\0' };
				}

				s++;
			}
		}

		cout << "\t\t\t\t\t\t   _____________________________________________________________________________________________\n";
		cout << "\t\t\t\t\t\t   |                   |                                                                       |\n";
		cout << "\t\t\t\t\t\t   |      ROLL NO.     |                          NAME OF STUDENTS                             |\n";
		cout << "\t\t\t\t\t\t   |___________________|_______________________________________________________________________|\n";

		for (int i = 0; i < count; i++)
		{
			cout << "\t\t\t\t\t\t   |                   |                                                                       |\n";
			cout << "\t\t\t\t\t\t   |      " << setw(13) << left << stud[i].roll << "|  " << setw(69) << left << stud[i].s_name << "|" << endl;

			if (i + 1 != count)
			{
				cout << "\t\t\t\t\t\t   |-------------------|-----------------------------------------------------------------------|\n";
			}
		}


		cout << "\t\t\t\t\t\t   |___________________|_______________________________________________________________________|\n";
	}

	if (option1 == '4')
	{
		s = count = 0;

		cout << "Enter Father Status: ";
		cin.ignore();
		cin.getline(father_s_name, 2, '\n');
		cout << endl;

		for (int i = 0; i < 100; i++)
		{
			int q = strcmp(father_s_name, student[i].father_status);

			if (q == 0)
			{
				for (int j = 0; j < 8; j++)
				{
					stud[s].roll[j] = student[i].roll_no[j];
				}

				for (int j = 0; j < 31; j++)
				{
					stud[s].s_name[j] = student[i].name[j];
				}

				s++;
				count++;
			}
		}

		cout << "\t\t\t\t\t\t   _____________________________________________________________________________________________\n";
		cout << "\t\t\t\t\t\t   |                   |                                                                       |\n";
		cout << "\t\t\t\t\t\t   |      ROLL NO.     |                          NAME OF STUDENTS                             |\n";
		cout << "\t\t\t\t\t\t   |___________________|_______________________________________________________________________|\n";

		for (int i = 0; i < count; i++)
		{
			cout << "\t\t\t\t\t\t   |                   |                                                                       |\n";
			cout << "\t\t\t\t\t\t   |      " << setw(13) << left << stud[i].roll << "|  " << setw(69) << left << stud[i].s_name << "|" << endl;

			if (i + 1 != count)
			{
				cout << "\t\t\t\t\t\t   |-------------------|-----------------------------------------------------------------------|\n";
			}
		}


		cout << "\t\t\t\t\t\t   |___________________|_______________________________________________________________________|\n";
	}

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void r1d(personal student[100])
{
	int current_date[3], v = 1000, age[3], p = 1;
	char rol_no[8];

	cout << "\n";
	cout << "Enter Current Date :  ";
	cin >> current_date[0];
	cout << "Enter Current Month :  ";
	cin >> current_date[1];
	cout << "Enter Current Year :  ";
	cin >> current_date[2];

	//cout << current_date[0] << " " << current_date[1] << " " << current_date[2] << endl;

	cin.ignore();
	cout << endl;

	//cout << "Enter Roll Number Of Student ( xxLxxxx ) :  ";
	//cin.getline(rol_no, 8, '\n');

	while (p != 0)
	{
		cout << "\n\n\n\n";
		cout << "Enter Roll Number Of Student ( xxLxxxx ) :  ";
		cin.getline(rol_no, 8, '\n');

		for (int i = 0; i < 100; i++)
		{
			p = strcmp(rol_no, student[i].roll_no);

			if (p == 0)
			{
				break;
			}
		}

		if (p != 0)
		{
			cout << "Invalid Input" << endl;
			continue;
		}
	}

	cout << "\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t------------------------------\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t|   REPORT - STUDENT'S AGE   |\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t------------------------------\n" << endl;

	//cout << rol_no;

	for (int i = 0; i < 1000; i++)
	{
		int q = strcmp(rol_no, student[i].roll_no);

		if (q == 0)
		{
			v = i;
			break;
		}
	}

	//cout << student[v].dob[0] << " " << student[v].dob[1] << " " << student[v].dob[2] << endl;

	// Year
	age[2] = current_date[2] - student[v].dob[2];

	if (current_date[1] >= student[v].dob[1])
	{
		age[1] = current_date[1] - student[v].dob[1];
	}

	if (current_date[1] < student[v].dob[1])
	{
		age[1] = current_date[1] - student[v].dob[1] + 12;
		age[2] = age[2] - 1;
	}

	if (current_date[0] >= student[v].dob[0])
	{
		age[0] = current_date[0] - student[v].dob[0];
	}

	if (current_date[0] < student[v].dob[0])
	{
		age[0] = current_date[0] - student[v].dob[0] + 30;
		age[1] = age[1] - 1;
	}

	if (age[1] < 0)
	{
		age[1] = age[1] + 12;
		age[2] = age[2] - 1;
	}

	if (age[2] < 0)
	{
		age[2] = 0;
	}

	if (current_date[0] >= 1 && current_date[0] < student[v].dob[0])
	{
		age[0] = age[0] + 1;
	}

	cout << "CONSIDERING EVERY YEAR IS NOT A LEAP YEAR AND EVERY MONTH HAS 30 DAYS\n\n";

	cout << "___________________________________________________________________________________" << "\n";
	cout << "|                   |           |      |            |        |            |       |" << "\n";
	cout << "|        AGE        | " << setw(10) << left << age[0] << "| DAYS |  " << setw(10) << left << age[1] << "| MONTHS |  " << setw(10) << left << age[2] << "| YEARS |" << "\n";
	cout << "|___________________|___________|______|____________|________|____________|_______|" << "\n";


	for (int i = student[v].dob[2]; i <= current_date[2]; i++)
	{
		if (i == student[v].dob[2] || i == current_date[2])
		{
			if (i % 4 == 0)
			{
				for (int j = 1; j <= current_date[1]; j++)
				{
					if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
					{
						age[0] = age[0] + 1;
					}

					if (j == 4 || j == 6 || j == 9 || j == 11)
					{
						age[0] = age[0] + 0;
					}

					if (j == 2)
					{
						age[0] = age[0] - 1;
					}
				}

				for (int j = student[v].dob[1]; j <= 12; j++)
				{
					if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
					{
						age[0] = age[0] + 1;
					}

					if (j == 4 || j == 6 || j == 9 || j == 11)
					{
						age[0] = age[0] + 0;
					}

					if (j == 2)
					{
						age[0] = age[0] - 1;
					}
				}
			}

			if (i % 4 == 0)
			{
				for (int j = 1; j <= current_date[1]; j++)
				{
					if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
					{
						age[0] = age[0] + 1;
					}

					if (j == 4 || j == 6 || j == 9 || j == 11)
					{
						age[0] = age[0] + 0;
					}

					if (j == 2)
					{
						age[0] = age[0] - 2;
					}
				}

				for (int j = student[v].dob[1]; j <= 12; j++)
				{
					if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
					{
						age[0] = age[0] + 1;
					}

					if (j == 4 || j == 6 || j == 9 || j == 11)
					{
						age[0] = age[0] + 0;
					}

					if (j == 2)
					{
						age[0] = age[0] - 2;
					}
				}
			}

		}

		else
		{
			if (i % 4 == 0)
			{
				age[0] = age[0] + 6;
			}

			else
			{
				age[0] = age[0] + 5;
			}
		}
	}

	while (age[0] > 30)
	{
		age[0] = age[0] - 30;
		age[1] = age[1] + 1;
	}

	while (age[1] > 12)
	{
		age[1] = age[1] - 12;
		age[2] = age[2] + 1;
	}

	cout << "\n\n\n\nCONSIDERING LEAP YEAR AND TAKING 31 DAYS IN 7 MONTHS\n\n";

	cout << "___________________________________________________________________________________" << "\n";
	cout << "|                   |           |      |            |        |            |       |" << "\n";
	cout << "|        AGE        | " << setw(10) << left << age[0] << "| DAYS |  " << setw(10) << left << age[1] << "| MONTHS |  " << setw(10) << left << age[2] << "| YEARS |" << "\n";
	cout << "|___________________|___________|______|____________|________|____________|_______|" << "\n";

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void r2(course data[50], result marks[500], personal student[100])
{
	char course_c[8], course_t[40], h_name[30], h_roll_no[8];
	int sem, n = -1, s = 0, count = 0, credit_h, mx_marks, mn_marks, sum = 0;
	double avg_marks, avg_gpa, str_dev = 0, mean;
	report3 crs[200];


	cout << "\n\n\n";
	cin.ignore();
	cout << "Enter Course Code:  ";
	cin.getline(course_c, 8, '\n');

	//cout << course_c << endl;

	cout << "Enter Semester Number:  ";
	cin >> sem;

	//cout << sem << endl;

	for (int i = 0; i < 50; i++)
	{
		int q = strcmp(course_c, data[i].course_code);

		if (q == 0)
		{
			n = i;
			break;
		}
	}

	for (int i = 0; i < 40; i++)
	{
		course_t[i] = data[n].course_title[i];
	}

	credit_h = data[n].credit_hours;

	for (int i = 0; i < 500; i++)
	{
		int q = strcmp(course_c, marks[i].coursecode);

		if (q == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				crs[s].roll_no[j] = marks[i].roll_num[j];
			}

			crs[s].semester = marks[i].semester;

			crs[s].numbers = marks[i].numbers;

			s++;
			count++;
		}
	}

	//for (int i = 0; i < count; i++)
	//{
	//	cout << crs[i].roll_no << "   " << crs[i].semester << "   " << crs[i].numbers << endl;
	//}

	s = 0;

	for (int i = 0; i < count; i++)
	{
		if (crs[i].semester == sem)
		{
			for (int j = 0; j < 8; j++)
			{
				crs[s].roll_no[j] = crs[i].roll_no[j];
			}

			crs[s].numbers = crs[i].numbers;

			s++;
		}
	}

	for (int i = s; i < 100; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			crs[i].roll_no[j] = { '\0' };
		}

		crs[i].numbers = { '\0' };
	}

	for (int i = 0; i < s; i++)
	{
		sum = sum + crs[i].numbers;
	}

	grde(crs, s);
	GPA(crs, s);

	mx_marks = crs[0].numbers;

	for (int i = 0; i < s; i++)
	{
		int r2 = crs[i].numbers;
		mx_marks = max_marks(mx_marks, r2);
	}

	mn_marks = crs[0].numbers;

	for (int i = 0; i < s; i++)
	{
		int r2 = crs[i].numbers;
		mn_marks = min_marks(mn_marks, r2);
	}

	avg_marks = avgm(crs, s);
	avg_gpa = avgg(crs, s);

	mean = sum / s;

	for (int i = 0; i < s; i++)
	{
		str_dev = str_dev + pow(crs[i].numbers - mean, 2);
	}

	str_dev = sqrt(str_dev / s);

	for (int x = 0; x < s; x++)
	{
		for (int i = 0; i < 100; i++)
		{
			int q = strcmp(crs[x].roll_no, student[i].roll_no);

			if (q == 0)
			{
				for (int j = 0; j < 30; j++)
				{
					crs[x].name[j] = student[i].name[j];
				}
			}
		}
	}

	for (int i = 0; i < s; i++)
	{
		if (mx_marks == crs[i].numbers)
		{
			for (int j = 0; j < 8; j++)
			{
				h_roll_no[j] = crs[i].roll_no[j];
			}

			for (int j = 0; j < 30; j++)
			{
				h_name[j] = crs[i].name[j];
			}

			break;
		}
	}

	cout << showpoint << setprecision(3);

	cout << "\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n";
	cout << "\n\t\t\t\t\t\t\t\t\t|   REPORT - COURSE RESULTS ( A )   |\n";
	cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n" << endl;

	cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|                 |                                                                                   |                  |                                                             |" << endl;
	cout << "|   COURSE CODE   |    " << setw(78) << left << course_c << " |   CREDIT HOURS   |    " << setw(57) << left << credit_h << "|" << endl;
	cout << "|_________________|___________________________________________________________________________________|__________________|_____________________________________________________________|" << endl;
	cout << "|                 |                                                                                   |                  |                                                             |" << endl;
	cout << "|  COURSE TITLE   |    " << setw(78) << left << course_t << " |     SEMESTER     |    " << setw(57) << left << sem << "|" << endl;
	cout << "|_________________|___________________________________________________________________________________|__________________|_____________________________________________________________|" << endl;
	cout << "\n\n\n";
	cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|                 |                                                                  |                         |                        |                                              |" << endl;
	cout << "|   ROLL NUMBER   |                               NAME                               |          MARKS          |          GRADE         |                      GPA                     |" << endl;
	cout << "|_________________|__________________________________________________________________|_________________________|________________________|______________________________________________|" << endl;
	cout << "|                 |                                                                  |                         |                        |                                              |" << endl;

	for (int i = 0; i < s; i++)
	{
		cout << "|     " << setw(12) << left << crs[i].roll_no << "|   " << setw(63) << left << crs[i].name << "|            " << setw(13) << left << crs[i].numbers << "|           " << setw(13) << left << crs[i].grade << "|                      " << setw(24) << left << crs[i].gpa << "|" << endl;

		if (i + 1 != s)
		{
			cout << "|-----------------|------------------------------------------------------------------|-------------------------|------------------------|----------------------------------------------|" << endl;
		}
	}


	cout << "|_________________|__________________________________________________________________|_________________________|________________________|______________________________________________|" << endl;
	cout << "|                                                                                                                                       |                                              |" << endl;
	cout << "|                                                                      MAXIMUM MARKS                                                    |                       " << setw(23) << left << mx_marks << "|" << endl;
	cout << "|_______________________________________________________________________________________________________________________________________|______________________________________________|" << endl;
	cout << "|                                                                                                                                       |                                              |" << endl;
	cout << "|                                                                      MINIMUM MARKS                                                    |                       " << setw(23) << left << mn_marks << "|" << endl;
	cout << "|_______________________________________________________________________________________________________________________________________|______________________________________________|" << endl;
	cout << "|                                                                                                                                       |                                              |" << endl;
	cout << "|                                                                      AVERAGE MARKS                                                    |                      " << setw(24) << left << avg_marks << "|" << endl;
	cout << "|_______________________________________________________________________________________________________________________________________|______________________________________________|" << endl;
	cout << "|                                                                                                                                       |                                              |" << endl;
	cout << "|                                                                   STANDARD DEVIATION                                                  |                      " << setw(24) << left << str_dev << "|" << endl;
	cout << "|_______________________________________________________________________________________________________________________________________|______________________________________________|" << endl;
	cout << "|                                                                                                                                       |                                              |" << endl;
	cout << "|                                                                       AVERAGE GPA                                                     |                      " << setw(24) << left << avg_gpa << "|" << endl;
	cout << "|_______________________________________________________________________________________________________________________________________|______________________________________________|" << endl;
	cout << "|                                                                                                                                       |                                              |" << endl;
	cout << "|                                                               MAXIMUM MARKS OBTAINED BY                                               |     " << setw(25) << left << h_name << "  ( " << h_roll_no << " )" << "   |" << endl;
	cout << "|_______________________________________________________________________________________________________________________________________|______________________________________________|" << endl;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void r3(course data[50], result marks[500], personal student[100])
{
	//     Report - 3
	char course_t[40], grd[3];
	int sem, n = -1, s = 0, count = 0;
	report3 crs[200];

	cout << "\n\n\n\n";
	cin.ignore();
	cout << "Enter Course Title:  ";
	cin.getline(course_t, 40, '\n');

	//cout << course_t << endl;

	cout << "Enter Semester Number:  ";
	cin >> sem;

	//cout << sem << endl;

	cin.ignore();
	cout << "Enter Grade Point Limit:  ";
	cin.getline(grd, 3, '\n');


	for (int i = 0; i < 50; i++)
	{
		int q = strcmp(course_t, data[i].course_title);

		if (q == 0)
		{
			n = i;
			break;
		}
	}

	for (int i = 0; i < 500; i++)
	{
		int q = strcmp(data[n].course_code, marks[i].coursecode);

		if (q == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				crs[s].roll_no[j] = marks[i].roll_num[j];
			}

			crs[s].semester = marks[i].semester;

			crs[s].numbers = marks[i].numbers;

			s++;
			count++;
		}
	}

	//for (int i = 0; i < count; i++)
	//{
	//	cout << crs[i].roll_no << "   " << crs[i].semester << "   " << crs[i].numbers << endl;
	//}

	s = 0;

	for (int i = 0; i < count; i++)
	{
		if (crs[i].semester == sem)
		{
			for (int j = 0; j < 8; j++)
			{
				crs[s].roll_no[j] = crs[i].roll_no[j];
			}

			crs[s].numbers = crs[i].numbers;

			s++;
		}
	}

	for (int i = s; i < 100; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			crs[i].roll_no[j] = { '\0' };
		}

		crs[i].numbers = { '\0' };
	}

	grde(crs, s);

	count = 0;

	for (int i = 0; i < s; i++)
	{
		int q = strcmp(grd, crs[i].grade);

		if (q == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				crs[count].roll_no[j] = crs[i].roll_no[j];
			}

			crs[count].numbers = crs[i].numbers;

			for (int j = 0; j < 3; j++)
			{
				crs[count].grade[j] = crs[i].grade[j];
			}

			count++;
		}
	}

	for (int x = 0; x < count; x++)
	{
		for (int i = 0; i < 100; i++)
		{
			int q = strcmp(crs[x].roll_no, student[i].roll_no);

			if (q == 0)
			{
				for (int j = 0; j < 30; j++)
				{
					crs[x].name[j] = student[i].name[j];
				}
			}
		}
	}


	cout << "\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n";
	cout << "\n\t\t\t\t\t\t\t\t\t|   REPORT - COURSE RESULTS ( B )   |\n";
	cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n" << endl;


	cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|                        |                                                                                         |                                 |                                 |" << endl;
	cout << "|      ROLL NUMBER       |                                   STUDENT NAME                                          |              MARKS              |               GRADE             |" << endl;
	cout << "|________________________|_________________________________________________________________________________________|_________________________________|_________________________________|" << endl;
	cout << "|                        |                                                                                         |                                 |                                 |" << endl;


	for (int i = 0; i < count; i++)
	{
		cout << "|         " << setw(15) << left << crs[i].roll_no << "|   " << setw(86) << left << crs[i].name << "|               " << setw(18) << left << crs[i].numbers << "|                 " << setw(16) << left << crs[i].grade << "|" << endl;

		if (i + 1 != s)
		{
			cout << "|------------------------|-----------------------------------------------------------------------------------------|---------------------------------|---------------------------------|" << endl;
		}
	}

	cout << "|________________________|_________________________________________________________________________________________|_________________________________|_________________________________|" << endl;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void r4(course data[50], result marks[500], personal student[100])
{
	report4 trs[10];

	int current_date[3], v = 1000, age[3], p = 1;
	char rl_no[8], name[30], father_name[30], batch[5], a1[5] = "2018", a2[5] = "2019", a3[5] = "2020", a4[5] = "2021", g[3];
	int n, y, s1, s2, s3, s4, s5, s6, s7, s, mrks;
	int src[7] = { 0,0,0,0,0,0,0 };
	float sgp = 0.0, s_cr = 0, sgpa[7];
	double cgp = 0, cgpa[7];

	cout << "\n\n\n";

	cout << "Enter Current Date  :    ";
	cin >> current_date[0];
	cout << "Enter Current Month :    ";
	cin >> current_date[1];
	cout << "Enter Current Year  :    ";
	cin >> current_date[2];

	cout << "\n\n\n";

	cin.ignore();
	//cout << "Enter Roll No       :    ";
	//cin.getline(rl_no, 8, '\n');

	while (p != 0)
	{
		cout << "\n\n\n\n";
		cout << "Enter Roll Number Of Student ( xxLxxxx ) :  ";
		cin.getline(rl_no, 8, '\n');

		for (int i = 0; i < 100; i++)
		{
			p = strcmp(rl_no, student[i].roll_no);

			if (p == 0)
			{
				break;
			}
		}

		if (p != 0)
		{
			cout << "Invalid Input" << endl;
			continue;
		}
	}

	cout << "\n\n\n";

	for (int i = 0; i < 1000; i++)
	{
		int q = strcmp(rl_no, student[i].roll_no);

		if (q == 0)
		{
			v = i;
			break;
		}
	}

	// AGE
	age[2] = current_date[2] - student[v].dob[2];

	if (current_date[1] >= student[v].dob[1])
	{
		age[1] = current_date[1] - student[v].dob[1];
	}

	if (current_date[1] < student[v].dob[1])
	{
		age[1] = current_date[1] - student[v].dob[1] + 12;
		age[2] = age[2] - 1;
	}

	if (current_date[0] >= student[v].dob[0])
	{
		age[0] = current_date[0] - student[v].dob[0];
	}

	if (current_date[0] < student[v].dob[0])
	{
		age[0] = current_date[0] - student[v].dob[0] + 30;
		age[1] = age[1] - 1;
	}

	if (age[1] < 0)
	{
		age[1] = age[1] + 12;
		age[2] = age[2] - 1;
	}

	if (age[2] < 0)
	{
		age[2] = 0;
	}

	for (int i = 0; i < 100; i++)
	{
		int q = strcmp(rl_no, student[i].roll_no);

		if (q == 0)
		{
			n = i;
			break;
		}
	}

	for (int i = 0; i < 30; i++)
	{
		name[i] = student[n].name[i];
		father_name[i] = student[n].father_name[i];
	}

	for (int i = 0; i < 5; i++)
	{
		batch[i] = student[n].batch[i];
	}

	s = s1 = s2 = s3 = s4 = s5 = s6 = s7 = 0;

	if (strcmp(batch, "2018") == 0)
	{
		for (int i = 0; i < 500; i++)
		{
			int q = strcmp(rl_no, marks[i].roll_num);

			if (q == 0)
			{
				y = i;

				trs[s].semester = marks[i].semester;

				if (trs[s].semester == 1)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s1].crs_code[0][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s1].crs_code[0], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s1].course_title[0][k] = data[j].course_title[k];
							}

							trs[s1].credit_hours[0] = data[j].credit_hours;
						}
					}

					trs[s1].numbers[0] = marks[i].numbers;

					mrks = trs[s1].numbers[0];

					trs[s1].gpa[0] = grd(mrks, g);

					trs[s1].grade[0][0] = g[0];
					trs[s1].grade[0][1] = g[1];
					trs[s1].grade[0][2] = g[2];

					s1++;
				}

				sgp = s_cr = src[0] = 0;

				for (int j = 0; j < s1; j++)
				{
					sgp = sgp + (trs[j].gpa[0] * trs[j].credit_hours[0]);
					s_cr = s_cr + trs[j].credit_hours[0];
					src[0] = src[0] + trs[j].credit_hours[0];
				}

				sgpa[0] = sgp / s_cr;

				if (trs[s].semester == 2)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s2].crs_code[1][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s2].crs_code[1], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s2].course_title[1][k] = data[j].course_title[k];
							}

							trs[s2].credit_hours[1] = data[j].credit_hours;
						}
					}

					trs[s2].numbers[1] = marks[i].numbers;

					mrks = trs[s2].numbers[1];

					trs[s2].gpa[1] = grd(mrks, g);

					trs[s2].grade[1][0] = g[0];
					trs[s2].grade[1][1] = g[1];
					trs[s2].grade[1][2] = g[2];

					s2++;
				}

				sgp = s_cr = src[1] = 0;

				for (int j = 0; j < s2; j++)
				{
					sgp = sgp + (trs[j].gpa[1] * trs[j].credit_hours[1]);
					s_cr = s_cr + trs[j].credit_hours[1];
					src[1] = src[1] + trs[j].credit_hours[1];
				}

				sgpa[1] = sgp / s_cr;

				if (trs[s].semester == 3)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s3].crs_code[2][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s3].crs_code[2], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s3].course_title[2][k] = data[j].course_title[k];
							}

							trs[s3].credit_hours[2] = data[j].credit_hours;
						}
					}

					trs[s3].numbers[2] = marks[i].numbers;

					mrks = trs[s3].numbers[2];

					trs[s3].gpa[2] = grd(mrks, g);

					trs[s3].grade[2][0] = g[0];
					trs[s3].grade[2][1] = g[1];
					trs[s3].grade[2][2] = g[2];

					s3++;
				}

				sgp = s_cr = src[2] = 0;

				for (int j = 0; j < s3; j++)
				{
					sgp = sgp + (trs[j].gpa[2] * trs[j].credit_hours[2]);
					s_cr = s_cr + trs[j].credit_hours[2];
					src[2] = src[2] + trs[j].credit_hours[2];
				}

				sgpa[2] = sgp / s_cr;

				if (trs[s].semester == 4)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s4].crs_code[3][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s4].crs_code[3], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s4].course_title[3][k] = data[j].course_title[k];
							}

							trs[s4].credit_hours[3] = data[j].credit_hours;
						}
					}

					trs[s4].numbers[3] = marks[i].numbers;

					mrks = trs[s4].numbers[3];

					trs[s4].gpa[3] = grd(mrks, g);

					trs[s4].grade[3][0] = g[0];
					trs[s4].grade[3][1] = g[1];
					trs[s4].grade[3][2] = g[2];

					s4++;
				}

				sgp = s_cr = src[3] = 0;

				for (int j = 0; j < s4; j++)
				{
					sgp = sgp + (trs[j].gpa[3] * trs[j].credit_hours[3]);
					s_cr = s_cr + trs[j].credit_hours[3];
					src[3] = src[3] + trs[j].credit_hours[3];
				}

				sgpa[3] = sgp / s_cr;

				if (trs[s].semester == 5)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s5].crs_code[4][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s5].crs_code[4], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s5].course_title[4][k] = data[j].course_title[k];
							}

							trs[s5].credit_hours[4] = data[j].credit_hours;
						}
					}

					trs[s5].numbers[4] = marks[i].numbers;

					mrks = trs[s5].numbers[4];

					trs[s5].gpa[4] = grd(mrks, g);

					trs[s5].grade[4][0] = g[0];
					trs[s5].grade[4][1] = g[1];
					trs[s5].grade[4][2] = g[2];

					s5++;
				}

				sgp = s_cr = src[4] = 0;

				for (int j = 0; j < s5; j++)
				{
					sgp = sgp + (trs[j].gpa[4] * trs[j].credit_hours[4]);
					s_cr = s_cr + trs[j].credit_hours[4];
					src[4] = src[4] + trs[j].credit_hours[4];
				}

				sgpa[4] = sgp / s_cr;

				if (trs[s].semester == 6)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s6].crs_code[5][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s6].crs_code[5], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s6].course_title[5][k] = data[j].course_title[k];
							}

							trs[s6].credit_hours[5] = data[j].credit_hours;
						}
					}

					trs[s6].numbers[5] = marks[i].numbers;

					mrks = trs[s6].numbers[5];

					trs[s6].gpa[5] = grd(mrks, g);

					trs[s6].grade[5][0] = g[0];
					trs[s6].grade[5][1] = g[1];
					trs[s6].grade[5][2] = g[2];

					s6++;
				}

				sgp = s_cr = src[5] = 0;

				for (int j = 0; j < s6; j++)
				{
					sgp = sgp + (trs[j].gpa[5] * trs[j].credit_hours[5]);
					s_cr = s_cr + trs[j].credit_hours[5];
					src[5] = src[5] + trs[j].credit_hours[5];
				}

				sgpa[5] = sgp / s_cr;

				if (trs[s].semester == 7)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s7].crs_code[6][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s7].crs_code[6], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s7].course_title[6][k] = data[j].course_title[k];
							}

							trs[s7].credit_hours[6] = data[j].credit_hours;
						}
					}

					trs[s7].numbers[6] = marks[i].numbers;

					mrks = trs[s7].numbers[6];

					trs[s7].gpa[6] = grd(mrks, g);

					trs[s7].grade[6][0] = g[0];
					trs[s7].grade[6][1] = g[1];
					trs[s7].grade[6][2] = g[2];

					s7++;
				}

				sgp = s_cr = src[6] = 0;

				for (int j = 0; j < s7; j++)
				{
					sgp = sgp + (trs[j].gpa[6] * trs[j].credit_hours[6]);
					s_cr = s_cr + trs[j].credit_hours[6];
					src[6] = src[6] + trs[j].credit_hours[6];
				}

				sgpa[6] = sgp / s_cr;

				s++;
			}
		}

		for (int i = 0; i < 7; i++)
		{
			cgp = 0;

			for (int j = 0; j < i + 1; j++)
			{
				cgp = cgp + sgpa[j];
			}

			cgpa[i] = cgp / (i + 1);
		}

		cout << showpoint << setprecision(3);

		cout << "\n\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n";
		cout << "\n\t\t\t\t\t\t\t\t\t|   REPORT - STUDENT'S TRANSCRIPT   |\n";
		cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n" << endl;

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| ROLL NO.                :  " << setw(60) << left << rl_no << "             | " << "STUDENT NAME   :  " << setw(61) << left << name << "|\n";

		cout << "|-----------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| FATHER NAME             :  " << setw(60) << left << father_name << "             | " << "BATCH          :  " << setw(61) << left << batch << "|\n";

		cout << "|-----------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| TRANSCRIPT PRINTED ON   :  " << current_date[0] << " - " << current_date[1] << " - " << setw(50) << left << current_date[2] << "             | "
			<< "AGE            :  " << age[2] << " Years    " << age[1] << " Months    " << age[0] << setw(35) << left << " Days" << "|\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;

		cout << "\n\n\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2018   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s1; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[0] << "| " << setw(43) << left << trs[i].course_title[0] << "|                 " << setw(19) << left << trs[i].credit_hours[0] << "|            " << setw(15) << left << trs[i].numbers[0] << "|           " << setw(12) << left << trs[i].grade[0] << "|           " << setw(13) << left << trs[i].gpa[0] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[0] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[0] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[0] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t___________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                  |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   SPRING 2019   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|__________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s2; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[1] << "| " << setw(43) << left << trs[i].course_title[1] << "|                 " << setw(19) << left << trs[i].credit_hours[1] << "|            " << setw(15) << left << trs[i].numbers[1] << "|           " << setw(12) << left << trs[i].grade[1] << "|           " << setw(13) << left << trs[i].gpa[1] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[1] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[1] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[1] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2019   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s3; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[2] << "| " << setw(43) << left << trs[i].course_title[2] << "|                 " << setw(19) << left << trs[i].credit_hours[2] << "|            " << setw(15) << left << trs[i].numbers[2] << "|           " << setw(12) << left << trs[i].grade[2] << "|           " << setw(13) << left << trs[i].gpa[2] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[2] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[2] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[2] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t___________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                  |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   SPRING 2020   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|__________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s4; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[3] << "| " << setw(43) << left << trs[i].course_title[3] << "|                 " << setw(19) << left << trs[i].credit_hours[3] << "|            " << setw(15) << left << trs[i].numbers[3] << "|           " << setw(12) << left << trs[i].grade[3] << "|           " << setw(13) << left << trs[i].gpa[3] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[3] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[3] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[3] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2020   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s5; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[4] << "| " << setw(43) << left << trs[i].course_title[4] << "|                 " << setw(19) << left << trs[i].credit_hours[4] << "|            " << setw(15) << left << trs[i].numbers[4] << "|           " << setw(12) << left << trs[i].grade[4] << "|           " << setw(13) << left << trs[i].gpa[4] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[4] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[4] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[4] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t___________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                  |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   SPRING 2021   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|__________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s6; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[5] << "| " << setw(43) << left << trs[i].course_title[5] << "|                 " << setw(19) << left << trs[i].credit_hours[5] << "|            " << setw(15) << left << trs[i].numbers[5] << "|           " << setw(12) << left << trs[i].grade[5] << "|           " << setw(13) << left << trs[i].gpa[5] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[5] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[5] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[5] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2021   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s7; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[6] << "| " << setw(43) << left << trs[i].course_title[6] << "|                 " << setw(19) << left << trs[i].credit_hours[6] << "|            " << setw(15) << left << trs[i].numbers[6] << "|           " << setw(12) << left << trs[i].grade[6] << "|           " << setw(13) << left << trs[i].gpa[6] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[6] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[6] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[6] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}

	if (strcmp(batch, "2019") == 0)
	{
		for (int i = 0; i < 500; i++)
		{
			int q = strcmp(rl_no, marks[i].roll_num);

			if (q == 0)
			{
				y = i;

				trs[s].semester = marks[i].semester;

				if (trs[s].semester == 1)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s1].crs_code[0][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s1].crs_code[0], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s1].course_title[0][k] = data[j].course_title[k];
							}

							trs[s1].credit_hours[0] = data[j].credit_hours;
						}
					}

					trs[s1].numbers[0] = marks[i].numbers;

					mrks = trs[s1].numbers[0];

					trs[s1].gpa[0] = grd(mrks, g);

					trs[s1].grade[0][0] = g[0];
					trs[s1].grade[0][1] = g[1];
					trs[s1].grade[0][2] = g[2];

					s1++;
				}

				sgp = s_cr = src[0] = 0;

				for (int j = 0; j < s1; j++)
				{
					sgp = sgp + (trs[j].gpa[0] * trs[j].credit_hours[0]);
					s_cr = s_cr + trs[j].credit_hours[0];
					src[0] = src[0] + trs[j].credit_hours[0];
				}

				sgpa[0] = sgp / s_cr;

				if (trs[s].semester == 2)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s2].crs_code[1][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s2].crs_code[1], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s2].course_title[1][k] = data[j].course_title[k];
							}

							trs[s2].credit_hours[1] = data[j].credit_hours;
						}
					}

					trs[s2].numbers[1] = marks[i].numbers;

					mrks = trs[s2].numbers[1];

					trs[s2].gpa[1] = grd(mrks, g);

					trs[s2].grade[1][0] = g[0];
					trs[s2].grade[1][1] = g[1];
					trs[s2].grade[1][2] = g[2];

					s2++;
				}

				sgp = s_cr = src[1] = 0;

				for (int j = 0; j < s2; j++)
				{
					sgp = sgp + (trs[j].gpa[1] * trs[j].credit_hours[1]);
					s_cr = s_cr + trs[j].credit_hours[1];
					src[1] = src[1] + trs[j].credit_hours[1];
				}

				sgpa[1] = sgp / s_cr;

				if (trs[s].semester == 3)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s3].crs_code[2][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s3].crs_code[2], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s3].course_title[2][k] = data[j].course_title[k];
							}

							trs[s3].credit_hours[2] = data[j].credit_hours;
						}
					}

					trs[s3].numbers[2] = marks[i].numbers;

					mrks = trs[s3].numbers[2];

					trs[s3].gpa[2] = grd(mrks, g);

					trs[s3].grade[2][0] = g[0];
					trs[s3].grade[2][1] = g[1];
					trs[s3].grade[2][2] = g[2];

					s3++;
				}

				sgp = s_cr = src[2] = 0;

				for (int j = 0; j < s3; j++)
				{
					sgp = sgp + (trs[j].gpa[2] * trs[j].credit_hours[2]);
					s_cr = s_cr + trs[j].credit_hours[2];
					src[2] = src[2] + trs[j].credit_hours[2];
				}

				sgpa[2] = sgp / s_cr;

				if (trs[s].semester == 4)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s4].crs_code[3][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s4].crs_code[3], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s4].course_title[3][k] = data[j].course_title[k];
							}

							trs[s4].credit_hours[3] = data[j].credit_hours;
						}
					}

					trs[s4].numbers[3] = marks[i].numbers;

					mrks = trs[s4].numbers[3];

					trs[s4].gpa[3] = grd(mrks, g);

					trs[s4].grade[3][0] = g[0];
					trs[s4].grade[3][1] = g[1];
					trs[s4].grade[3][2] = g[2];

					s4++;
				}

				sgp = s_cr = src[3] = 0;

				for (int j = 0; j < s4; j++)
				{
					sgp = sgp + (trs[j].gpa[3] * trs[j].credit_hours[3]);
					s_cr = s_cr + trs[j].credit_hours[3];
					src[3] = src[3] + trs[j].credit_hours[3];
				}

				sgpa[3] = sgp / s_cr;

				if (trs[s].semester == 5)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s5].crs_code[4][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s5].crs_code[4], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s5].course_title[4][k] = data[j].course_title[k];
							}

							trs[s5].credit_hours[4] = data[j].credit_hours;
						}
					}

					trs[s5].numbers[4] = marks[i].numbers;

					mrks = trs[s5].numbers[4];

					trs[s5].gpa[4] = grd(mrks, g);

					trs[s5].grade[4][0] = g[0];
					trs[s5].grade[4][1] = g[1];
					trs[s5].grade[4][2] = g[2];

					s5++;
				}

				sgp = s_cr = src[4] = 0;

				for (int j = 0; j < s5; j++)
				{
					sgp = sgp + (trs[j].gpa[4] * trs[j].credit_hours[4]);
					s_cr = s_cr + trs[j].credit_hours[4];
					src[4] = src[4] + trs[j].credit_hours[4];
				}

				sgpa[4] = sgp / s_cr;

				s++;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			cgp = 0;

			for (int j = 0; j < i + 1; j++)
			{
				cgp = cgp + sgpa[j];
			}

			cgpa[i] = cgp / (i + 1);
		}

		cout << showpoint << setprecision(3);

		cout << "\n\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n";
		cout << "\n\t\t\t\t\t\t\t\t\t|   REPORT - STUDENT'S TRANSCRIPT   |\n";
		cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n" << endl;

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| ROLL NO.                :  " << setw(60) << left << rl_no << "             | " << "STUDENT NAME   :  " << setw(61) << left << name << "|\n";

		cout << "|-----------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| FATHER NAME             :  " << setw(60) << left << father_name << "             | " << "BATCH          :  " << setw(61) << left << batch << "|\n";

		cout << "|-----------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| TRANSCRIPT PRINTED ON   :  " << current_date[0] << " - " << current_date[1] << " - " << setw(50) << left << current_date[2] << "             | "
			<< "AGE            :  " << age[2] << " Years    " << age[1] << " Months    " << age[0] << setw(35) << left << " Days" << "|\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;

		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2019   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s1; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[0] << "| " << setw(43) << left << trs[i].course_title[0] << "|                 " << setw(19) << left << trs[i].credit_hours[0] << "|            " << setw(15) << left << trs[i].numbers[0] << "|           " << setw(12) << left << trs[i].grade[0] << "|           " << setw(13) << left << trs[i].gpa[0] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[0] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[0] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[0] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t___________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                  |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   SPRING 2020   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|__________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s2; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[1] << "| " << setw(43) << left << trs[i].course_title[1] << "|                 " << setw(19) << left << trs[i].credit_hours[1] << "|            " << setw(15) << left << trs[i].numbers[1] << "|           " << setw(12) << left << trs[i].grade[1] << "|           " << setw(13) << left << trs[i].gpa[1] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[1] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[1] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[1] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2020   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s3; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[2] << "| " << setw(43) << left << trs[i].course_title[2] << "|                 " << setw(19) << left << trs[i].credit_hours[2] << "|            " << setw(15) << left << trs[i].numbers[2] << "|           " << setw(12) << left << trs[i].grade[2] << "|           " << setw(13) << left << trs[i].gpa[2] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[2] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[2] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[2] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t___________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                  |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   SPRING 2021   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|__________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s4; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[3] << "| " << setw(43) << left << trs[i].course_title[3] << "|                 " << setw(19) << left << trs[i].credit_hours[3] << "|            " << setw(15) << left << trs[i].numbers[3] << "|           " << setw(12) << left << trs[i].grade[3] << "|           " << setw(13) << left << trs[i].gpa[3] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[3] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[3] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[3] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2021   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s5; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[4] << "| " << setw(43) << left << trs[i].course_title[4] << "|                 " << setw(19) << left << trs[i].credit_hours[4] << "|            " << setw(15) << left << trs[i].numbers[4] << "|           " << setw(12) << left << trs[i].grade[4] << "|           " << setw(13) << left << trs[i].gpa[4] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[4] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[4] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[4] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}

	if (strcmp(batch, "2020") == 0)
	{
		for (int i = 0; i < 500; i++)
		{
			int q = strcmp(rl_no, marks[i].roll_num);

			if (q == 0)
			{
				y = i;

				trs[s].semester = marks[i].semester;

				if (trs[s].semester == 1)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s1].crs_code[0][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s1].crs_code[0], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s1].course_title[0][k] = data[j].course_title[k];
							}

							trs[s1].credit_hours[0] = data[j].credit_hours;
						}
					}

					trs[s1].numbers[0] = marks[i].numbers;

					mrks = trs[s1].numbers[0];

					trs[s1].gpa[0] = grd(mrks, g);

					trs[s1].grade[0][0] = g[0];
					trs[s1].grade[0][1] = g[1];
					trs[s1].grade[0][2] = g[2];

					s1++;
				}

				sgp = s_cr = src[0] = 0;

				for (int j = 0; j < s1; j++)
				{
					sgp = sgp + (trs[j].gpa[0] * trs[j].credit_hours[0]);
					s_cr = s_cr + trs[j].credit_hours[0];
					src[0] = src[0] + trs[j].credit_hours[0];
				}

				sgpa[0] = sgp / s_cr;

				if (trs[s].semester == 2)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s2].crs_code[1][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s2].crs_code[1], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s2].course_title[1][k] = data[j].course_title[k];
							}

							trs[s2].credit_hours[1] = data[j].credit_hours;
						}
					}

					trs[s2].numbers[1] = marks[i].numbers;

					mrks = trs[s2].numbers[1];

					trs[s2].gpa[1] = grd(mrks, g);

					trs[s2].grade[1][0] = g[0];
					trs[s2].grade[1][1] = g[1];
					trs[s2].grade[1][2] = g[2];

					s2++;
				}

				sgp = s_cr = src[1] = 0;

				for (int j = 0; j < s2; j++)
				{
					sgp = sgp + (trs[j].gpa[1] * trs[j].credit_hours[1]);
					s_cr = s_cr + trs[j].credit_hours[1];
					src[1] = src[1] + trs[j].credit_hours[1];
				}

				sgpa[1] = sgp / s_cr;

				if (trs[s].semester == 3)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s3].crs_code[2][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s3].crs_code[2], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s3].course_title[2][k] = data[j].course_title[k];
							}

							trs[s3].credit_hours[2] = data[j].credit_hours;
						}
					}

					trs[s3].numbers[2] = marks[i].numbers;

					mrks = trs[s3].numbers[2];

					trs[s3].gpa[2] = grd(mrks, g);

					trs[s3].grade[2][0] = g[0];
					trs[s3].grade[2][1] = g[1];
					trs[s3].grade[2][2] = g[2];

					s3++;
				}

				sgp = s_cr = src[2] = 0;

				for (int j = 0; j < s3; j++)
				{
					sgp = sgp + (trs[j].gpa[2] * trs[j].credit_hours[2]);
					s_cr = s_cr + trs[j].credit_hours[2];
					src[2] = src[2] + trs[j].credit_hours[2];
				}

				sgpa[2] = sgp / s_cr;

				s++;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			cgp = 0;

			for (int j = 0; j < i + 1; j++)
			{
				cgp = cgp + sgpa[j];
			}

			cgpa[i] = cgp / (i + 1);
		}

		cout << showpoint << setprecision(3);

		cout << "\n\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n";
		cout << "\n\t\t\t\t\t\t\t\t\t|   REPORT - STUDENT'S TRANSCRIPT   |\n";
		cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n" << endl;

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| ROLL NO.                :  " << setw(60) << left << rl_no << "             | " << "STUDENT NAME   :  " << setw(61) << left << name << "|\n";

		cout << "|-----------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| FATHER NAME             :  " << setw(60) << left << father_name << "             | " << "BATCH          :  " << setw(61) << left << batch << "|\n";

		cout << "|-----------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| TRANSCRIPT PRINTED ON   :  " << current_date[0] << " - " << current_date[1] << " - " << setw(50) << left << current_date[2] << "             | "
			<< "AGE            :  " << age[2] << " Years    " << age[1] << " Months    " << age[0] << setw(35) << left << " Days" << "|\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;

		cout << "\n\n\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2020   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s1; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[0] << "| " << setw(43) << left << trs[i].course_title[0] << "|                 " << setw(19) << left << trs[i].credit_hours[0] << "|            " << setw(15) << left << trs[i].numbers[0] << "|           " << setw(12) << left << trs[i].grade[0] << "|           " << setw(13) << left << trs[i].gpa[0] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[0] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[0] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[0] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t___________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                  |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   SPRING 2021   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|__________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s2; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[1] << "| " << setw(43) << left << trs[i].course_title[1] << "|                 " << setw(19) << left << trs[i].credit_hours[1] << "|            " << setw(15) << left << trs[i].numbers[1] << "|           " << setw(12) << left << trs[i].grade[1] << "|           " << setw(13) << left << trs[i].gpa[1] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[1] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[1] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[1] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2021   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s3; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[2] << "| " << setw(43) << left << trs[i].course_title[2] << "|                 " << setw(19) << left << trs[i].credit_hours[2] << "|            " << setw(15) << left << trs[i].numbers[2] << "|           " << setw(12) << left << trs[i].grade[2] << "|           " << setw(13) << left << trs[i].gpa[2] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[2] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[2] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[2] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}

	if (strcmp(batch, "2021") == 0)
	{
		for (int i = 0; i < 500; i++)
		{
			int q = strcmp(rl_no, marks[i].roll_num);

			if (q == 0)
			{
				y = i;

				trs[s].semester = marks[i].semester;

				if (trs[s].semester == 1)
				{
					for (int j = 0; j < 8; j++)
					{
						trs[s1].crs_code[0][j] = marks[i].coursecode[j];
					}

					for (int j = 0; j < 50; j++)
					{
						int h = strcmp(trs[s1].crs_code[0], data[j].course_code);

						if (h == 0)
						{
							for (int k = 0; k < 40; k++)
							{
								trs[s1].course_title[0][k] = data[j].course_title[k];
							}

							trs[s1].credit_hours[0] = data[j].credit_hours;
						}
					}

					trs[s1].numbers[0] = marks[i].numbers;

					mrks = trs[s1].numbers[0];

					trs[s1].gpa[0] = grd(mrks, g);

					trs[s1].grade[0][0] = g[0];
					trs[s1].grade[0][1] = g[1];
					trs[s1].grade[0][2] = g[2];

					s1++;
				}

				sgp = s_cr = src[0] = 0;

				for (int j = 0; j < s1; j++)
				{
					sgp = sgp + (trs[j].gpa[0] * trs[j].credit_hours[0]);
					s_cr = s_cr + trs[j].credit_hours[0];
					src[0] = src[0] + trs[j].credit_hours[0];
				}

				sgpa[0] = sgp / s_cr;

				s++;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			cgp = 0;

			for (int j = 0; j < i + 1; j++)
			{
				cgp = cgp + sgpa[j];
			}

			cgpa[i] = cgp / (i + 1);
		}

		cout << showpoint << setprecision(3);

		cout << "\n\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n";
		cout << "\n\t\t\t\t\t\t\t\t\t|   REPORT - STUDENT'S TRANSCRIPT   |\n";
		cout << "\n\t\t\t\t\t\t\t\t\t-------------------------------------\n" << endl;

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| ROLL NO.                :  " << setw(60) << left << rl_no << "             | " << "STUDENT NAME   :  " << setw(61) << left << name << "|\n";

		cout << "|-----------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| FATHER NAME             :  " << setw(60) << left << father_name << "             | " << "BATCH          :  " << setw(61) << left << batch << "|\n";

		cout << "|-----------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------|" << endl;
		cout << "|                                                                                                     |                                                                                |" << endl;

		cout << "| TRANSCRIPT PRINTED ON   :  " << current_date[0] << " - " << current_date[1] << " - " << setw(50) << left << current_date[2] << "             | "
			<< "AGE            :  " << age[2] << " Years    " << age[1] << " Months    " << age[0] << setw(35) << left << " Days" << "|\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;

		cout << "\n\n\n\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t_________________  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t                |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|   FALL 2021   |  ";
		cout << "\n\t\t\t\t\t\t\t\t\t\t|________________\n" << endl;
		cout << "\n\n";

		cout << "________________________________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|                       |                                            |                                    |                           |                       |                        |" << endl;
		cout << "|      COURSE CODE      |                COURSE TITLE                |            CREDIT HOURS            |           MARKS           |         GRADE         |           GPA          |" << endl;
		cout << "|_______________________|____________________________________________|____________________________________|___________________________|_______________________|________________________|" << endl;

		for (int i = 0; i < s1; i++)
		{
			cout << "| " << setw(22) << left << trs[i].crs_code[0] << "| " << setw(43) << left << trs[i].course_title[0] << "|                 " << setw(19) << left << trs[i].credit_hours[0] << "|            " << setw(15) << left << trs[i].numbers[0] << "|           " << setw(12) << left << trs[i].grade[0] << "|           " << setw(13) << left << trs[i].gpa[0] << "|" << endl;
			cout << "|-----------------------|--------------------------------------------|------------------------------------|---------------------------|-----------------------|------------------------|" << endl;
		}

		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                              TOTAL CREDIT HOURS                                                     |                       " << setw(25) << left << src[0] << "|" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    SGPA                                                             |                      " << sgpa[0] << "                      |" << endl;
		cout << "|-------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|" << endl;
		cout << "|                                                                                                                                     |                                                |" << endl;
		cout << "|                                                                    CGPA                                                             |                      " << cgpa[0] << "                      |" << endl;
		cout << "|_____________________________________________________________________________________________________________________________________|________________________________________________|" << endl;

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
}

void grde(report3 crs[200], int s)
{

	for (int i = 0; i < s; i++)
	{
		if (crs[i].numbers >= 90)
		{
			crs[i].grade[0] = { 'A' };
			crs[i].grade[1] = { '+' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 86 && crs[i].numbers < 90)
		{
			crs[i].grade[0] = { 'A' };
			crs[i].grade[1] = { '\0' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 82 && crs[i].numbers < 86)
		{
			crs[i].grade[0] = { 'A' };
			crs[i].grade[1] = { '-' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 78 && crs[i].numbers < 82)
		{
			crs[i].grade[0] = { 'B' };
			crs[i].grade[1] = { '+' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 74 && crs[i].numbers < 78)
		{
			crs[i].grade[0] = { 'B' };
			crs[i].grade[1] = { '\0' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 70 && crs[i].numbers < 74)
		{
			crs[i].grade[0] = { 'B' };
			crs[i].grade[1] = { '-' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 66 && crs[i].numbers < 70)
		{
			crs[i].grade[0] = { 'C' };
			crs[i].grade[1] = { '+' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 62 && crs[i].numbers < 66)
		{
			crs[i].grade[0] = { 'C' };
			crs[i].grade[1] = { '\0' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 58 && crs[i].numbers < 62)
		{
			crs[i].grade[0] = { 'C' };
			crs[i].grade[1] = { '-' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 54 && crs[i].numbers < 58)
		{
			crs[i].grade[0] = { 'D' };
			crs[i].grade[1] = { '+' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers >= 50 && crs[i].numbers < 54)
		{
			crs[i].grade[0] = { 'D' };
			crs[i].grade[1] = { '\0' };
			crs[i].grade[2] = { '\0' };
		}

		if (crs[i].numbers < 50)
		{
			crs[i].grade[0] = { 'F' };
			crs[i].grade[1] = { '\0' };
			crs[i].grade[2] = { '\0' };
		}
	}
}

void GPA(report3 crs[200], int s)
{

	for (int i = 0; i < s; i++)
	{
		if (crs[i].numbers >= 90)
		{
			crs[i].gpa = 4.00;
		}

		if (crs[i].numbers >= 86 && crs[i].numbers < 90)
		{
			crs[i].gpa = 4.00;
		}

		if (crs[i].numbers >= 82 && crs[i].numbers < 86)
		{
			crs[i].gpa = 3.67;
		}

		if (crs[i].numbers >= 78 && crs[i].numbers < 82)
		{
			crs[i].gpa = 3.33;
		}

		if (crs[i].numbers >= 74 && crs[i].numbers < 78)
		{
			crs[i].gpa = 3.00;
		}

		if (crs[i].numbers >= 70 && crs[i].numbers < 74)
		{
			crs[i].gpa = 2.67;
		}

		if (crs[i].numbers >= 66 && crs[i].numbers < 70)
		{
			crs[i].gpa = 2.33;
		}

		if (crs[i].numbers >= 62 && crs[i].numbers < 66)
		{
			crs[i].gpa = 2.00;
		}

		if (crs[i].numbers >= 58 && crs[i].numbers < 62)
		{
			crs[i].gpa = 1.67;
		}

		if (crs[i].numbers >= 54 && crs[i].numbers < 58)
		{
			crs[i].gpa = 1.33;
		}

		if (crs[i].numbers >= 50 && crs[i].numbers < 54)
		{
			crs[i].gpa = 1.00;
		}

		if (crs[i].numbers < 50)
		{
			crs[i].gpa = 4.00;
		}
	}
}

float grd(int mrks, char g[3])
{
	float gp;

	if (mrks >= 90)
	{
		g[0] = { 'A' };
		g[1] = { '+' };
		g[2] = { '\0' };

		gp = 4.00;
	}

	if (mrks >= 86 && mrks < 90)
	{
		g[0] = { 'A' };
		g[1] = { '\0' };
		g[2] = { '\0' };

		gp = 4.00;
	}

	if (mrks >= 82 && mrks < 86)
	{
		g[0] = { 'A' };
		g[1] = { '-' };
		g[2] = { '\0' };

		gp = 3.67;
	}

	if (mrks >= 78 && mrks < 82)
	{
		g[0] = { 'B' };
		g[1] = { '+' };
		g[2] = { '\0' };

		gp = 3.33;
	}

	if (mrks >= 74 && mrks < 78)
	{
		g[0] = { 'B' };
		g[1] = { '\0' };
		g[2] = { '\0' };

		gp = 3.00;
	}

	if (mrks >= 70 && mrks < 74)
	{
		g[0] = { 'B' };
		g[1] = { '-' };
		g[2] = { '\0' };

		gp = 2.67;
	}

	if (mrks >= 66 && mrks < 70)
	{
		g[0] = { 'C' };
		g[1] = { '+' };
		g[2] = { '\0' };

		gp = 2.33;
	}

	if (mrks >= 62 && mrks < 66)
	{
		g[0] = { 'C' };
		g[1] = { '\0' };
		g[2] = { '\0' };

		gp = 2.00;
	}

	if (mrks >= 58 && mrks < 62)
	{
		g[0] = { 'C' };
		g[1] = { '-' };
		g[2] = { '\0' };

		gp = 1.67;
	}

	if (mrks >= 54 && mrks < 58)
	{
		g[0] = { 'D' };
		g[1] = { '+' };
		g[2] = { '\0' };

		gp = 1.33;
	}

	if (mrks >= 50 && mrks < 54)
	{
		g[0] = { 'D' };
		g[1] = { '\0' };
		g[2] = { '\0' };

		gp = 1.00;
	}

	if (mrks < 50)
	{
		g[0] = { 'F' };
		g[1] = { '\0' };
		g[2] = { '\0' };

		gp = 0.00;
	}

	return gp;
}

int max_marks(int r1, int r2)
{
	if (r2 < r1)
	{
		r2 = r1;
	}

	return r2;
}

int min_marks(int r1, int r2)
{
	if (r2 > r1)
	{
		r2 = r1;
	}

	return r2;
}

double avgm(report3 crs[200], int s)
{
	double a_marks = 0.0;

	for (int i = 0; i < s; i++)
	{
		a_marks = a_marks + crs[i].numbers;
	}

	a_marks = a_marks / s;

	return a_marks;
}

double avgg(report3 crs[200], int s)
{
	double a_gpa = 0.0;

	for (int i = 0; i < s; i++)
	{
		a_gpa = a_gpa + crs[i].gpa;
	}

	a_gpa = a_gpa / s;

	return a_gpa;
}