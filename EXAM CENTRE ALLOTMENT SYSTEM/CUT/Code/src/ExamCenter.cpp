#include"../inc/ExamCenter.h"

ExamCenter::ExamCenter(string ECN,string EXId,string name,string Address,string sD,int Capacity)
{
        ExamCenterNo = ECN;
        ExamId =EXId;
        startDate=sD;
        this->name = name;
        this->Address = Address;
        this->Capacity = Capacity;
}
string ExamCenter::getExamCenterNo()
{
        return ExamCenterNo;
}
string ExamCenter::getExamId()
{
        return ExamId;
}
string ExamCenter::getName()
{
        return name;
}
string ExamCenter::getAddress()
{
        return Address;
}
string ExamCenter::getStartDate()
{
        return startDate;
}

int ExamCenter::getCapacity()
{
        return Capacity;
}
void ExamCenter::setCapacity(int Capacity)
{
	this->Capacity = Capacity;
}
void ExamCenter::displayExamCenterDetails(vector<ExamCenter>Exams)
{
	for(auto it=Exams.begin();it!=Exams.end();it++)
        {
                cout<<((it)->getExamCenterNo())<<"|";
		cout<<((it)->getExamId())<<"|";
		cout<<((it)->getName())<<"|";
                cout<<((it)->getCapacity())<<"|";
                cout<<((it)->getStartDate())<<"|";
		


                cout<<endl;
        }
}

