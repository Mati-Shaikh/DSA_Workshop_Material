#include <iostream>
using namespace std;

class student_Node {
	public:
    string data;
    student_Node* next;
    student_Node(string data) {
	        this->data = data;
	        this->next = NULL;
    }
};
//The above portion cannot be changed

string* list_of_all_students(student_Node*& head1, student_Node*& head2, student_Node*& head3)
{
	string* result;
	//enter your code here
	
	/*
		FGC_List = {Ali, Usman, Haider, Maryam, Masooma, Urooj}
	FAS_List = {Ashiq, Manika, Ali, Masooma, Akbar, Urooj}
	FDS_List = {Masooma, Bilal, Amna, Madiha, Rohail, Urooj}
	The result will be : List_of_all_student  = {Ali, Umsan, Haider, Maryam, Masooma, Urooj, Ashiq, Manika, Akbar, Bilal, Amna, Madhiha, Rohail}

	*/
	
	return result;
}
string* list_common_student_society(student_Node* &head1, student_Node*& head2, student_Node*& head3)
{
	
	string* result;
	
	//enter your code here
	/*
	FGC_List = {Ali, Usman, Haider, Maryam, Masooma, Urooj}
	FAS_List = {Ashiq, Manika, Ali, Masooma, Akbar, Urooj}
	FDS_List = {Masooma, Bilal, Amna, Madiha, Rohail, Urooj}
	The result will be : List_of_all_student : {Masooma, Urooj}

	*/
	return result;
}

//you can make fuctions for input and output, Core logic will be in above two funcation. Main should only work as a runner.
main()
{
	student_Node* FGC_List;
    student_Node* FAS_List;
    student_Node* FDS_List ;
    string *result;
    
    //fill all llist
    //call both funcations
    //print results;
}
