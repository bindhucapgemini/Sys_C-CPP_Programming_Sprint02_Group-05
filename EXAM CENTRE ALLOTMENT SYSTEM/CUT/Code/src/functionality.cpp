#include"./candidate.cpp"
#include"./ExamCenter.cpp"
#include"./HallTicket.cpp"

int readCandidate(vector<Candidate>&candidates)
{
        char filename[ ] = "../data/Candidate.txt";
        fstream fin;
        try {
                fin.open(filename,ios::in);
                if(!fin.is_open())
		{
			cout<<"\nFile not opened:\n";
		}
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
          char filename[ ] = "../data/ExamCenter.txt";
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



void updateCandidate(vector<Candidate>&candidates)
{
        char filename[ ] = "../data/Candidate.txt";
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
        char filename[ ] = "../data/ExamCenter.txt";
        ofstream file_out;
        file_out.open(filename, std::ios_base::trunc);
        for(auto exe=Exams.begin();exe!=Exams.end();exe++)
        {
                file_out <<exe->getExamCenterNo()<<"|"<<exe->getExamId()<<"|"<<exe->getName()<<"|"<<exe->getAddress()<<"|"<<exe->getCapacity()<<"|"<<exe->getStartDate()<<endl;
        }
        file_out.close();
}


