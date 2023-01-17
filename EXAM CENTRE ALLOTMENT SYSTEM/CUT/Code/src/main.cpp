#include"candidate.cpp"
#include"ExamCenter.cpp"
#include"functionality.cpp"



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
                //getline(fin,line);
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
        /*for(auto it=candidates.begin();it!=candidates.end();it++)
        {
                cout<<((it)->getId())<<"|";
                cout<<((it)->getName())<<"|";
                cout<<((it)->getExamId())<<"|";
                cout<<((it)->getExamCenterNo())<<"|";
                cout<<endl;
        }*/
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
         //getline(fin,line);
        getline(transporter, ECN, '|');
        getline(transporter, EXId, '|');
        getline(transporter, name, '|');
        getline(transporter, Address,'|');
        getline(transporter, Capacity,'|');
        getline(transporter,sD,'|');
        ExamCenter examCenter_obj(ECN,EXId,name,Address,sD,(stoi)(Capacity));
        Exams.emplace_back(examCenter_obj);
        }
        /*for(auto it=Exams.begin();it!=Exams.end();it++)
        {
                cout<<((it)->getExamCenterNo());
                cout<<((it)->getCapacity());
                cout<<((it)->getStartDate());


                cout<<endl;
        }*/
        return 0;
}
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





int main()
{
        vector<Candidate>candidates;
        vector<ExamCenter>Exams;
        readExamCenter(Exams);
        readCandidate(candidates);

        string name,exam_name;
        cout<<"\nEnter Candidate Name:: \n";
        cin>>name;
        cout<<"\nEnter Exam Name:: \n";
        cin>>exam_name;

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

        hallTicket_allotment(candidates,Exams);
        updateCandidate(candidates);
        updateExamCenter(Exams);
}