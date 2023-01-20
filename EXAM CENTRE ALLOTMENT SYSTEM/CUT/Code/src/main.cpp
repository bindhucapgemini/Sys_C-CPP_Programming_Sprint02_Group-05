#include"candidate.cpp"
#include"ExamCenter.cpp"
#include"functionality.cpp"


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
	
        fstream fin("./HallTicket.txt");
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

void hallTicket_allotment(vector<Candidate>&candidates,vector<ExamCenter>&Exams,vector<Ticket>&hallTickets)
{
	for(auto it=candidates.begin();it!=candidates.end();it++)
	{
		string str = it->getExamId();
		string temp = it->getExamCenterNo();
		if(temp=="NULL")
		{
			for(auto exe=Exams.begin();exe!=Exams.end();exe++)
			{
				if((str == exe->getExamId()) && (exe-> getCapacity()>=1))
				{
					it->setExamCenterNo(exe->getExamCenterNo());
					exe->setCapacity((exe->getCapacity())-1);
					char filename[ ] = "./HallTicket.txt";
					ofstream file_out;
					file_out.open(filename, std::ios_base::app);
			file_out <<it->getId()<<"|"<<exe->getExamId()<<"|"<<it->getName()<<"|"<<exe->getName()<<"|"<<exe->getAddress()<<"|"<<exe->getExamCenterNo()<<"|"<<exe->getStartDate()<<endl;
					file_out.close();
					int ID;
                string name,ExamId,ExamCenterNo,ExamCenterName,ExamCenterAddress,startDate;
		ID = it->getId();
		name = it->getName();
		ExamId = exe->getExamId();
		ExamCenterNo = exe->getExamCenterNo();
		ExamCenterName = exe->getName();
		ExamCenterAddress = exe->getAddress();
		startDate = exe->getStartDate();
		Ticket ticket3_obj(ID,ExamId,name,ExamCenterName,ExamCenterAddress,ExamCenterNo,startDate);
		hallTickets.emplace_back(ticket3_obj);
		
				break;
					
				}
			}
		}
	}
}



int main()
{
	vector<Candidate>candidates;
	vector<ExamCenter>Exams;
	vector<Ticket>hallTickets;
	


	Candidate cand_obj;
	ExamCenter exam_obj;
	Ticket tickets_obj;

	readCandidate(candidates);
	readExamCenter(Exams);
	tickets_obj.readHallTicket(hallTickets);
        

	cout<<"\n....................Welcome to ExamCenter Allotment.............................\n";
	int choice;
	
	string name,exam_name;
	int temp;
	do{
        cout<<"\nEnter Candidate Name:: \n";
        cin>>name;
        cout<<"\nEnter Exam Name:: \n";
        cin>>exam_name;

	cout<<"\nCandidate Details stored Successfull\n";

	
        fstream fin2;
        string segment;
        fin2.open("./static.txt",ios::in);
        getline(fin2,segment);
        int candidateId=(stoi)(segment);
        fin2.close();
        candidateId++;

        Candidate candidate_obj1(candidateId,name,exam_name);
        candidates.emplace_back(candidate_obj1);

        fstream file_out;
        file_out.open("./static.txt");
        file_out<<candidateId;
        file_out.close();

	cout<<"\nDo you Want add more Candidate Details?(1/0)\n";
	cin>>temp;
	}while(temp == 1);


	hallTicket_allotment(candidates,Exams,hallTickets);
	updateCandidate(candidates);
	updateExamCenter(Exams);

	while(1)
        {
                cout<<"\n1:Display Candidate details\n";
                cout<<"\n2:Display ExamCenter details\n";
                cout<<"\n3:Display HallTicket for the Candidate\n";
                cout<<"\n4:EXIT::\n";

                cout<<"\nPlease Enter Your Choice::\n";
                cin>>choice;


                switch(choice)
                {
                        case 1:cand_obj.displayCandidateDetails(candidates);
                               break;
                        case 2:exam_obj.displayExamCenterDetails(Exams);
                               break;
                        case 3:tickets_obj.displayHallTicketDetails(hallTickets);
                               break;
                        case 4: cout<<"\n..............Thank you for using this Applicaton........................\n";
				exit(0);

                        default: cout<<"\nEnter correct choice::\n";
                                 break;
                }
                
        }
	
}
