#include"./functionality.cpp"





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
					char filename[ ] = "../data/HallTicket.txt";
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
        fin2.open("../data/static.txt",ios::in);
        getline(fin2,segment);
        int candidateId=(stoi)(segment);
        fin2.close();
        candidateId++;

        Candidate candidate_obj1(candidateId,name,exam_name);
        candidates.emplace_back(candidate_obj1);

        fstream file_out;
        file_out.open("../data/static.txt");
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
