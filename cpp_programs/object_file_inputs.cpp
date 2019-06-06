#include <iostream>
#include <string>
#include <fstream>
/**************************************************************
Desription: Object oriented fundamentals using classes to manupulate data from a text file.
   
*****************************************************************/
using namespace std;

class student_record
{
public:
	string firstname;
	string lastname;
	int age;
	double hours;
	double hourly_rate;
	double gross_pay;
};

class Student_Class
{
public:
	Student_Class();
	~Student_Class(); //de-allocates all memory allocate to call_DB by operator new.
	bool Is_empty() const { return count == 0; }; //inline implementation
	bool Is_full()const { return count == size; };//inline implementation
	int Search(const string key)const;//returns location if student record in database; -1 otherwise
	//																				//key is first_lastname
	void Add(); //adds item inorder to the list
	void Remove_Inorder(const string key); //removes student record with matching firstname + lastname
	void Double_size();
	void Process();
	void Print()const; //prints all the elements in the database to the screen
    void Remove(student_record *student_DB, int & count, const string & key);

private:
	int count;
	int size;
	student_record * student_DB;

};
////void Remove_ALL(student_record *student *DB, int count, const string & key);
///************************************************************************************/
////Name: Student_Class    --- Default Constructor
////Precondition:   The object has not been initialized
//					student_DB,count and size have not been initialized.
////               
////Postconditions: All student data has been entered into student_DB; count and size
////                contain the appropriate values
////                  
////Description: Read data into dynamic array.  If array becomes full Double_size is called.
////             Also, an ifstream is open and closed in the function
////***********************************************************************************

Student_Class::Student_Class()
{
	cout << "Copy Constructor Called\n";
	ifstream in;
	in.open("student_data.txt");
	size = 1;
	count = 0;
	student_DB = new student_record[size];

	while (!in.eof())
	{
		if (count == size)
		{
			Double_size();
		}

		in >> student_DB[count].firstname
			>> student_DB[count].lastname
			>> student_DB[count].age
			>> student_DB[count].hours
			>> student_DB[count].hourly_rate;
		count++;
	}
	Process();
	in.close();
}
///************************************************************************************/
////Name: Double_size    
////Precondition:   There is no free memory in Student_DB.  count == size ---
//                  Student_DB is full
/////
////Postconditions: The capacity of memory of Student_DB has been doubled
////                  
////Description: Doubles the memory and capacity of Student_DB.
////             
////***********************************************************************************
void Student_Class::Double_size()
{
	cout << "Double_size has been called\n\n";
	size *= 2;
	student_record *temp = new student_record[size];

	for (int i = 0; i < count; i++)
	{
		temp[i] = student_DB[i];
	}
	delete[] student_DB;
	student_DB = temp;
}

///************************************************************************************/
////Name: Process
////Precondition:   gross pay has not been calculated
/////
////Postconditions: gross pay has been calculated for all student records in Student_DB
////                  
////Description: Calculates the gross pay for all student employees
////             
////***********************************************************************************
void Student_Class::Process() 
{
	for (int i = 0; i < count; i++)
	{
		student_DB[i].gross_pay = student_DB[i].hours * student_DB[i].hourly_rate;
	}
	
}
///************************************************************************************/
////Name: Search
////Precondition:   Student_DB has been initialize and there is a valid value for key
/////
////Postconditions: Location of key in Student_DB is returned; otherwise -l is returned.
////                  
////Description: Location key in Student_DB
////             
////***********************************************************************************
int Student_Class::Search(const string key) const
{
	for (int i = 0; i < count; i++)
	{
		if ((student_DB[i].firstname + student_DB[i].lastname) == key)
		{
			return i;
		}	
	}
	return -1;
}

///************************************************************************************/
////Name: Add
////Precondition:   Add a student record toStudent_DB if it is not full.  Is it is full,
////                Double_size is called and the the record is add
/////
////Postconditions: Student records has been added to Student_DB
////                  
////Description: Add student records to Student_Db
////             
////***********************************************************************************
void Student_Class::Add()
{

	if (count == size)
	{
		Double_size();
	}

	cout << "Enter student firstname: ";
	cin >> student_DB[count].firstname;
	cout << "Enter student lastname: ";
	cin >> student_DB[count].lastname;
	cout<<"Enter student age: ";
	cin >> student_DB[count].age;
	cout <<"Enter student hours: ";
	cin >> student_DB[count].hours;
	cout<<"Enter student hourly rate: ";
	cin >> student_DB[count].hourly_rate;
	student_DB[count].gross_pay = student_DB[count].hours * student_DB[count].hourly_rate;
	cout << endl << endl;
	
	count++;
}

///************************************************************************************/
////Name: Remove_Inorder
////Precondition:   Student_DB, and key have been initialized
////Postconditions: The student record the matches key has been removed
////                  
////Description: Removes the student record with first and last names that match key, if
///                 Student_DB is not empty
////             
////***********************************************************************************
void Student_Class:: Remove_Inorder(const string key)
{
	int location = Search(key);

	if (location != -1)
	{
		for (int j = location; j < count - 1; j++)
		{
			student_DB[j] = student_DB[j + 1];
		}
		count--;
	}
}

///************************************************************************************/
////Name: Print
////Precondition:   Student_DB, size and count have been initialized
////Postconditions: Records in Student_DB printed to screen
////                  
////Description: Prints every field of every student records stored in Student_DB
////             
////***********************************************************************************
void Student_Class::Print( ) const
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	for (int i = 0; i < count; i++)
	{
		cout << student_DB[i].firstname << "\t"
			<< student_DB[i].lastname << "\t"
			<< student_DB[i].hourly_rate << "\t"
			<< student_DB[i].hours << "\t"
			<< student_DB[i].gross_pay << endl;
	}

	
}
///************************************************************************************/
////Name: ~Student_Class   --- Destructor
////Precondition:   Student_DB, size and count have been initialized
////Postconditions: Memory allocated to Student_DB using new has been de-allocated using delete
////                  
////Description: De-allocates dynamic memory allocated to the dynamic array, Student_DB
////             
////***********************************************************************************

Student_Class::~Student_Class()
{
	cout << "Destructor has been called\n";
	delete[] student_DB;

}


int main()
{
	Student_Class myClass;

	myClass.Print();

	return 0;
}


