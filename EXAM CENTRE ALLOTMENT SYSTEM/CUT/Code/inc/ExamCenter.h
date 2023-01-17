#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;



class ExamCenter{
        public:
                ExamCenter(){};
                ExamCenter(string,string,string,string,string,int);
                string getExamCenterNo();
                string getExamId();
                string getName();
                string getAddress();
                string getStartDate();
                int getCapacity();
                void setCapacity(int);
        private:
                string ExamCenterNo,ExamId,name,Address,startDate;
                int Capacity;
};