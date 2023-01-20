//#include"candidate.h"
//#include"ExamCenter.h"



int readCandidate(vector<Candidate>&candidates)
{
        char filename[ ] = "./Candidate.txt";
        fstream fin;
        try {
                fin.open(filename,ios::in);
                if(!fin.is_open())
                throw ;
            }
        catch(...) {
                cout<<"\n\tError in opening file to read...";
                return 0;
                }
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
                string name ;
                string ExamId;
                string ExamCenterNo;
                string line;
                getline(transporter, Id, '|');
                getline(transporter, name, '|');
                getline(transporter, ExamId, '|');
                getline(transporter,ExamCenterNo,'|');

                if((ExamCenterNo)!="NULL")
                {
                        Candidate candidate_obj((stoi)(Id),name,ExamId,ExamCenterNo);
                        candidates.emplace_back(candidate_obj);
                }
		else
                {
                        Candidate candidate_obj((stoi)(Id),name,ExamId);
                        candidates.emplace_back(candidate_obj);
                }
        }
	fin.close();
        return 0;
}

int readExamCenter(vector<ExamCenter>&Exams)
{
          char filename[ ] = "./ExamCenter.txt";
          fstream fin;
          try {
                  fin.open(filename,ios::in);
                  if(!fin.is_open())
                  throw ;
              }
        catch(...) {
                cout<<"\n\tError in opening file to read...";
		return 0;
		}
	while(true)
	{
	string segment;
        if (!getline(fin, segment))
        {
                  break;
        }
        stringstream transporter;
        transporter << segment;
        string ECN ;
        string EXId ;
        string name;
        string Address;
        string sD;
        string Capacity;
        string line;
        getline(transporter, ECN, '|');
        getline(transporter, EXId, '|');
        getline(transporter, name, '|');
        getline(transporter, Address,'|');
        getline(transporter, Capacity,'|');
        getline(transporter,sD,'|');
        ExamCenter examCenter_obj(ECN,EXId,name,Address,sD,(stoi)(Capacity));
        Exams.emplace_back(examCenter_obj);
        }
	fin.close();
	return 0;
}
/*int readHallTicket(vector<Ticket>&hallTickets)
{
	char filename[ ] = "./HallTicket.txt";
	fstream fin;
	try {
		fin.open(filename,ios::in);
		if(!fin.is_open())
		throw ;
	     }
	catch(...) {
		cout<<"\n\tError in opening file to read...";
		return 0;
		}
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
		string ExamStartDate;
		string line;
		getline(transporter, Id, '|');
		getline(transporter, ExamID, '|');
		getline(transporter, name, '|');
		getline(transporter,ExamCenterName,'|');
		getline(transporter,ExamCenterAddress,'|');
		getline(transporter,ExamStartDate,'|');
		Ticket ticket1_obj((stoi)(Id),ExamID,name,ExamCenterName,ExamCenterAddress,ExamStartDate);
		hallTickets.emplace_back(ticket1_obj);
	}
	return 0;
}*/


void updateCandidate(vector<Candidate>&candidates)
{
        char filename[ ] = "./Candidate.txt";
        ofstream file_out;
        file_out.open(filename, std::ios_base::trunc);
        for(auto it=candidates.begin();it!=candidates.end();it++)
        {
                file_out <<it->getId()<<"|"<<it->getName()<<"|"<<it->getExamId()<<"|"<<it->getExamCenterNo()<<endl;
        }
        file_out.close();
}

void updateExamCenter(vector<ExamCenter>&Exams)
{
        char filename[ ] = "./ExamCenter.txt";
        ofstream file_out;
        file_out.open(filename, std::ios_base::trunc);
        for(auto exe=Exams.begin();exe!=Exams.end();exe++)
        {
                file_out <<exe->getExamCenterNo()<<"|"<<exe->getExamId()<<"|"<<exe->getName()<<"|"<<exe->getAddress()<<"|"<<exe->getCapacity()<<"|"<<exe->getStartDate()<<endl;
        }
        file_out.close();
}

/*void hallTicket_allotment(vector<Candidate>&candidates,vector<ExamCenter>&Exams,vector<Ticket>&hallTickets)
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
}*/
