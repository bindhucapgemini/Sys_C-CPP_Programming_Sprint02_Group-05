//#include"candidate.h"
//#include"ExamCenter.h"


void hallTicket_allotment(vector<Candidate>&candidates,vector<ExamCenter>&Exams)
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
                                file_out <<it->getId()<<"|"<<exe->getExamId()<<"|"<<it->getName()<<"|"<<exe->getName()<<"|"<<exe->getAddress()<<"|"<<exe->getStartDate()<<endl;
                                        file_out.close();
                                        break;

                                }
                        }
                }
        }
}