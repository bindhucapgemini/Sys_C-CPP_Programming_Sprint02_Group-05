#include"../inc/HallTicket.h"


Ticket::Ticket(int ID,string ExamId,string name,string ECname,string ECA,string ECN,string startDate){
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
string Ticket::getExamID()
{
        return ExamId;
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
        cout<<"\n...............................Candidate HallTickets.........................\n";
        for(auto it=hallTickets.begin();it!=hallTickets.end();it++)
        {
                cout<<"Candidate Id :"<<(it)->getCandidateId()<<endl;

                cout<<"ExamID :"<<(it)->getExamID()<<endl;
                cout<<"Candidate Name :"<<(it)->getCandidateName()<<endl;
                cout<<"ExamCenterNo : "<<(it)->getExamCenterNo()<<endl;
                cout<<"ExamCenterName : "<<(it)->getExamCenterName()<<endl;
                cout<<"ExamCenter Address : "<<(it)->getExamCenterAddress()<<endl;
                cout<<"Exam StartDate : "<<(it)->getExamStartDate()<<endl;
		cout<<"\n............................................................\n";
	}
        
}


int Ticket::readHallTicket(vector <Ticket> &hallTickets)
{
	
        //char filename[ ] = "./HallTicket.txt";
	
        fstream fin("../data/HallTicket.txt");
        try {

                if(!fin.is_open())
		{
			cout<<"\nFile not opened::\n";
		}
             }
        catch(...) {
                cout<<"\n\tError in opening file to read...";
                return 0;
                };
        while(true)
        {

                string segment;
                if (!getline(fin, segment))
                {
                        break;
                }

                stringstream transporter;
                transporter << segment;
                string Id ;
                string ExamID ;
                string name;
                string ExamCenterName;
                string ExamCenterAddress;
		string ExamCenterNo;
                string ExamStartDate;
                string line;
                getline(transporter, Id, '|');
                getline(transporter, ExamID, '|');
                getline(transporter, name, '|');
                getline(transporter,ExamCenterName,'|');
                getline(transporter,ExamCenterAddress,'|');
		getline(transporter,ExamCenterNo,'|');
                getline(transporter,ExamStartDate,'|');
                Ticket ticket1_obj((stoi)(Id),ExamID,name,ExamCenterName,ExamCenterAddress,ExamCenterNo,ExamStartDate);
		hallTickets.emplace_back(ticket1_obj);
        }
	fin.close();
        return 0;
}

