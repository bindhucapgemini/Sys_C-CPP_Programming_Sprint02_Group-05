#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;


class Ticket
{
	public:
		Ticket(){};
		Ticket(int,string,string,string,string,string,string);
		int getCandidateId();
		string getCandidateName();
		string getExamID();
		string getExamCenterNo();
		string getExamCenterName();
		string getExamCenterAddress();
		string getExamStartDate();
		string displayHallTicketDetails(vector<Ticket>&hallTickets);

	private:
		int ID;
		string name,ExamId,ExamCenterNo,ExamCenterName,ExamCenterAddress,startDate;
};

