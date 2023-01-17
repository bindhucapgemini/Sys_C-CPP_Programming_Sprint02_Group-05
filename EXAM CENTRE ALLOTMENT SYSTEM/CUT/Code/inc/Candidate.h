#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;

class Candidate
{
        public:
                Candidate(){};
                Candidate(int ,string ,string,string);
                int getId();
                string getName();
                string getExamId();
                string getExamCenterNo();
                void setExamCenterNo(string);

        private:
                int Id;
                string name,ExamId,ExamCenterNo;
};