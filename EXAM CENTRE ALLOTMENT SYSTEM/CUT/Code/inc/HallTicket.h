#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
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
                void displayHallTicketDetails(vector<Ticket>&hallTickets);
		int readHallTicket(vector<Ticket>&hallTickets);

        private:
                int ID;
                string name,ExamId,ExamCenterNo,ExamCenterName,ExamCenterAddress,startDate;
};

