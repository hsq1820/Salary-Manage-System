#ifndef employees_h_INCLUDED
#define employees_h_INCLUDED
#include <string>
using namespace std;
class employees{
    protected:
    int id,age,rank;
    double salary,value=0;
    string name,gender,place;
    char job;
    public:
    employees(int id,string name,string gender,int age,char job,string place,double salary=0,int rank=0){
        this->id=id;
        this->name=name;
        this->gender=gender;
        this->age=age;
        this->job=job;
        this->place=place;
        this->salary=salary;
        this->rank=rank;
        if(job=='C'||job=='c'){
            value=salary/0.04;
        }
    }
    int getid() const {
        return id;
    }
    string getname() const {
        return name;
    }
    string getgender() const {
        return gender;
    }
    int getage() const {
        return age;
    }
    char getjob() const {
        return job;
    }
    string getplace() const {
        return place;
    }
    double getsalary() const {
        return salary;
    }
    int getrank() const {
        return rank;
    }
    double getvalue() const {
        return value;
    }
    void setrank(int rank) {
        this->rank = rank;
    }
    void setsalary(double salary) {
        this->salary = salary;
    }
    void setvalue(double value) {
        this->value = value;
    }
};
#endif