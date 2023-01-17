#include"ExamCenter.h"




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