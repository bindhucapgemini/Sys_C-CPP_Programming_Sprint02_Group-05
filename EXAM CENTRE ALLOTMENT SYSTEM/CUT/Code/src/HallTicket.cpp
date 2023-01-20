//#include"HallTicket.h"


Ticket::Ticket(int ID,string name,string ExamId,string ECN,string ECname,string ECA,string startDate){
	this->ID=ID;
	this->name=name;
	this->ExamId=ExamId;
	ExamCenterNo=ECN;
	ExamCenterName=ECname;
	ExamCenterAddress=ECA;
	this->startDate=startDate;
}



int Ticket::getCandidateId()
{
	return ID;
}
string Ticket::getCandidateName()
{
	return name;
}
string Ticket::getExamCenterNo()
{
	return ExamCenterNo;
}
string Ticket::getExamId()
{
	return ExamID;
}
string Ticket::getExamCenterName()
{
	return ExamCenterName;
}
string Ticket::getExamCenterAddress()
{
	return ExamCenterAddress;
}
string Ticket::getExamStartDate()
{
	return startDate;
}
void Ticket::displayHallTicketDetails(vector<Ticket>&hallTickets)
{
	cout<<"\n..........................Candidate HallTickets.........................\n":
        for(auto it=hallTickets.begin();it!=hallTickets.end();it++)
        {
		cout<<"Candidate Id :"<<(it)->getCandidateId()<<endl;
		cout<<"ExamID :"<<(it)->getExamID()<<endl;
		cout<<"Candidate Name :"<<(it)->getCandidateName()<<endl;
		cout<<"ExamCenterNo : "<<(it)->getExamCenterNo()<<endl;
		cout<<"ExamCenterName : "<<(it)->getExamCenterName()<<endl;
		cout<<"ExamCenter Address : "<<(it)->getExamCenterAddress<<endl;
		cout<<"Exam StartDate : "<<(it)->getExamCenterStartDate()<<endl;

        }
}
