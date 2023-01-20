#include"../inc/candidate.h"

Candidate::Candidate(int Id,string name,string ExamId,string ExamCenterNo="NULL")
{
        this->Id=Id;
        this->name=name;
        this->ExamId=ExamId;
	this->ExamCenterNo=ExamCenterNo;
}

int Candidate::getId()
{
        return Id;
}
string Candidate::getName()
{
        return name;
}
string Candidate::getExamId()
{
        return ExamId;
}
string Candidate::getExamCenterNo()
{
        return ExamCenterNo;
}
void Candidate::setExamCenterNo(string ExamCenterNo)
{
        this->ExamCenterNo=ExamCenterNo;
}
void Candidate::displayCandidateDetails(vector<Candidate>candidates)
{
	for(auto it=candidates.begin();it!=candidates.end();it++)
		{
		cout<<((it)->getId())<<"|";
                cout<<((it)->getName())<<"|";
                cout<<((it)->getExamId())<<"|";
                cout<<((it)->getExamCenterNo())<<"|";
                cout<<endl;
        
		}
}
