#ifdef Local
#include "C:\Users\manee\OneDrive\Desktop\codeforces\debug1.h"
#else 
#define dbg(...)
#endif

#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define ld long double

// Assumption: There are five subjects for each student: english, maths, physics, chemistry and biology
//             and the total marks of a student is the sum of marks in each question. Also, when  the student 
//             class is initialised, the marks in each subject is zero and total marks is also zero

class Teacher; //Declaring Teacher class early so it can be used as a friend class

class Student{
    private:
    string name;
    vector<pair<string,int>> subject_marks_pair;
    int total_marks;

    friend class Teacher; // Declaring the teacher as a friend class because only teacher can access students' marks

    public:

    //Constructor
    Student(string name){

        this->name=name;
        
        subject_marks_pair.push_back(make_pair("english",0));
        subject_marks_pair.push_back(make_pair("maths",0));
        subject_marks_pair.push_back(make_pair("physics",0));
        subject_marks_pair.push_back(make_pair("chemistry",0));
        subject_marks_pair.push_back(make_pair("biology",0));
        total_marks=0;
    }

    int get_total_marks(){
        return total_marks;
    }
    int get_subject_marks(string subject){

        if(subject=="english")
        return subject_marks_pair[0].second;
        else if(subject=="maths")
        return subject_marks_pair[1].second;
        else if(subject=="physics")
        return subject_marks_pair[2].second;
        else if(subject=="chemistry")
        return subject_marks_pair[3].second;
        else if(subject=="biology")
        return subject_marks_pair[4].second;

        //Handling cases where subject does not exist
        return -1;


    }

    void display_name(){
        cout<<name<<endl;
    }


};

class Teacher{
    private:
        string name;

    public:

    Teacher(string name){

        this->name=name;

    }
        void change_student_marks(Student &student,string subject, int marks){


            // Updating the total marks and changing the appropriate marks
            if(subject=="english"){
                student.total_marks-=(student.subject_marks_pair[0].second-marks);
                student.subject_marks_pair[0].second=marks;
            }
            else if(subject=="maths"){
                student.total_marks-=(student.subject_marks_pair[1].second-marks);
                student.subject_marks_pair[1].second=marks;

            }
            else if(subject=="physics"){
                student.total_marks-=(student.subject_marks_pair[2].second-marks);
                student.subject_marks_pair[2].second=marks;
            }
            else if(subject=="chemistry"){
                student.total_marks-=(student.subject_marks_pair[3].second-marks);
                student.subject_marks_pair[3].second=marks;

            }
            else if(subject=="biology"){
                student.total_marks-=(student.subject_marks_pair[4].second-marks);
                student.subject_marks_pair[4].second=marks;

            }



    }

    void display_name(){
        cout<<name<<endl;
    }




};

int main() {

    //Testing code
    Student s1("Maneesh");
    Teacher t1("Luis");

    t1.display_name();
    s1.display_name();
    cout<<s1.get_subject_marks("chemistry")<<endl;
    cout<<s1.get_total_marks()<<endl;
    t1.change_student_marks(s1,"chemistry",85);
    cout<<s1.get_subject_marks("chemistry")<<endl;
    cout<<s1.get_total_marks()<<endl;
    t1.change_student_marks(s1,"english",90);
    cout<<s1.get_subject_marks("english")<<endl;
    
    t1.change_student_marks(s1,"maths",100);
    cout<<s1.get_subject_marks("maths")<<endl;

    t1.change_student_marks(s1,"physics",75);
    cout<<s1.get_subject_marks("physics")<<endl;

    t1.change_student_marks(s1,"biology",60);
    cout<<s1.get_subject_marks("biology")<<endl;

    cout<<s1.get_total_marks()<<endl;
    t1.change_student_marks(s1,"biology",0);
    cout<<s1.get_subject_marks("biology")<<endl;
    cout<<s1.get_total_marks()<<endl;

    
 
    return 0;
}
 
