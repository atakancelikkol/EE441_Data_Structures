#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;
// Implementation of Student Class--
class Student
{   //Get and Set methods and OverallScore cal. method.
    public:
        Student(int newid=0,string newname="Atakan", string newsurname="Celikkol",int newmt1=0,int newmt2=0,int newfinal=0);
        int getID(void) const;
        void setID(int newID);
        string getName(void) ;
        void setName(string newname);
        string getSurname(void) ;
        void setSurname(string newsurname);
        int getmt1score(void) const;
        void setmt1score(int newmt1);
        int getmt2score(void) const;
        void setmt2score(int newmt2);
        int getfinalscore(void) const;
        void setfinalscore(int newfinal);
        float OverallScore (void) const;

    private:

    int ID;
    string name  ;
    string surname  ;
    int mt1_score;
    int mt2_score;
    int final_score;
};
// Constructor of the class

Student::Student(int newid,string newname,string newsurname,int newmt1,int newmt2,int newfinal) : ID(newid),name(newname),surname(newsurname),mt1_score(newmt1),mt2_score(newmt2),final_score(newfinal)
    {}
// Methods of the Class - Basic get and set methods and calculating overall score.

int Student::getID(void) const
{
    return ID;
}

void Student::setID(int newid)
{
    ID=newid;
}

string Student::getName(void)
{
    return name;
}

void Student::setName(string newname)
{
    name=newname;
}

string Student::getSurname(void)
{
    return surname;
}

void Student::setSurname(string newsurname)
{
    surname=newsurname;
}

int Student::getmt1score(void) const
{
    return mt1_score;
}

void Student::setmt1score(int newmt1)
{
    mt1_score=newmt1;
}

int Student::getmt2score(void) const
{
    return mt2_score;
}

void Student::setmt2score(int newmt2)
{
    mt2_score=newmt2;
}

int Student::getfinalscore(void) const
{
    return final_score;
}

void Student::setfinalscore(int newfinal)
{
    final_score=newfinal;
}

float Student::OverallScore(void) const
{

    return (mt1_score*0.25)+(mt2_score*0.25)+(final_score*0.5);

}

// Implementation of Course Class
class Course
{   // getnum, addstudent, changeweights,calcaverage,getstudent and -extra- getweights methods.
    public:

    Course();
    int getNum(void);
    void addStudent(int newid,string newname,string newsurname,int newmt1,int newmt2, int newfinal );
    void changeWeights(float w1,float w2,float wf);
    void calcAverage(int studnum4);
    Student* getStudent(int index);
    float getWeight1();
    float getWeight2();
    float getWeight3();
    private:

        Student entries[10];
        int num;
        float weight_mt1 ;
        float weight_mt2 ;
        float weight_final ;
};
// Constructor of the class

Course::Course() /*,weight_mt1(newweightmt1),weight_mt1(newweightmt2),weight_final(newweightfinal)*/
    {num=0;weight_mt1=0.25; weight_mt2=0.25; weight_final=0.5;} // Initial variables of the course.
    // in case of if you dont change the weights or add a student to the course

// Methods of the Class
int Course::getNum(void)
{
    return num;
}

void Course::addStudent(int newid,string newname,string newsurname,int newmt1,int newmt2, int newfinal)
// If you add a student entries array are set and numb of student in the course is incremented
{
entries[num].setID(newid);
entries[num].setName(newname);
entries[num].setSurname(newsurname);
entries[num].setmt1score(newmt1);
entries[num].setmt2score(newmt2);
entries[num].setfinalscore(newfinal);
num++;
}

void Course::changeWeights(float w1,float w2,float wf)
{
    weight_mt1=w1;
    weight_mt2=w2;
    weight_final=wf;
}

// I need to add extra GetWeight methods for the calling the weights.

float Course::getWeight1()
{
    return weight_mt1;
}

float Course::getWeight2()
{
    return weight_mt2;
}

float Course::getWeight3()
{
    return weight_final;
}

Student* Course::getStudent(int index)
{
    return (entries+index);
}

void Course::calcAverage(int studnum4)
{

    float mt1avg=0;float mt1sum;
    float mt2avg=0;float mt2sum;
    float finalavg=0;float finalsum;
    float overallavg=0;float overallsum;
    for(int i=0;i<studnum4;i++)
    {
        float mt1sum=mt1sum+entries[i].getmt1score();
        mt1avg=mt1sum/studnum4;
        float mt2sum=mt2sum+entries[i].getmt2score();
        mt2avg=mt2sum/studnum4;
        float finalsum=finalsum+entries[i].getfinalscore();
        finalavg=finalsum/studnum4;

    }


    overallavg=(mt1avg*weight_mt1)+(mt2avg*weight_mt2)+(finalavg*weight_final);

        cout<<"MT1 Average: "<<mt1avg<<endl;
        cout<<"MT2 Average: "<<mt2avg<<endl;
        cout<<"Final Average: "<<finalavg<<endl;
        cout<<"Overall Average: "<<overallavg<<endl;
return;
}

// 2nd option searchBy ID Function
void searchByID(int searchid, Course &atu)
{

    Student *x,*a,*b,*c,*d,*e,*f,*g,*h,*j;
    int studnum=atu.getNum();
    float w1,w2,w3;
        w1=atu.getWeight1();
        w2=atu.getWeight2();
        w3=atu.getWeight3();
     a=atu.getStudent(1);  b=atu.getStudent(2);c=atu.getStudent(3);d=atu.getStudent(4);e=atu.getStudent(5);f=atu.getStudent(6);
    if((searchid!=(*a).getID())&&(searchid!=(*b).getID())&&(searchid!=(*c).getID())&&(searchid!=(*d).getID())&&(searchid!=(*e).getID())&&(searchid!=(*f).getID())&&(searchid!=(*g).getID())&&(searchid!=(*h).getID())&&(searchid!=(*j).getID()))
    {
        cout<<"Invalid ID"<<endl;
        cout<<" "<<endl;
    }

    for(int i =0; i<studnum;i++)
    {

        x=atu.getStudent(i);


        if (searchid==(*x).getID())
        {
            int xid=(*x).getID();
            string xname=(*x).getName();
            string xsurname=(*x).getSurname();
            int xmt1=(*x).getmt1score();
            int xmt2=(*x).getmt2score();
            int xfinal=(*x).getfinalscore();
            float xoverall=(xmt1*w1)+(xmt2*w2)+(xfinal*w3);
            cout<<xid<<"       "<<xname<<"       "<<xsurname<<"       "<<xmt1<<"       "<<xmt2<<"       "<<xfinal<<"       "<<xoverall<<endl;

        }

    }

    return;
}

// 3rd option showAbove function
void showAbove(int m,Course &atu)
{
       float w1,w2,w3;
        w1=atu.getWeight1();
        w2=atu.getWeight2();
        w3=atu.getWeight3();

    int studnum2=atu.getNum();
    Student *y;
    for(int k=0;k<studnum2;k++)
        {
        y=atu.getStudent(k);

            if((((*y).getmt1score()*w1)+((*y).getmt2score()*w2)+((*y).getfinalscore()*w3))>m)
            {
              cout<<(*y).getID()<<"       "<<(*y).getName()<<"       "<<(*y).getSurname()<<"       "<<(*y).getmt1score()<<"       "<<(*y).getmt2score()<<"       "<<(*y).getfinalscore()<<"       "<< (((*y).getmt1score()*w1)+((*y).getmt2score()*w2)+((*y).getfinalscore()*w3)) <<endl;
            }
        }
        /*for(l=0;l<studnum2;l++)
           if (y[l].OverallScore()<m && y[1].OverallScore()<m && y[2].OverallScore()<m && y[3].OverallScore()<m && y[4].OverallScore()<m &&) */
        return;

}

// 4th option showBelow function
void showBelow(int n,Course &atu)
{
    float w1,w2,w3;
        w1=atu.getWeight1();
        w2=atu.getWeight2();
        w3=atu.getWeight3();

    int studnum3=atu.getNum();
    Student *z;
    for(int l=0;l<studnum3;l++)
    {
      z=atu.getStudent(l);


          if((((*z).getmt1score()*w1)+((*z).getmt2score()*w2)+((*z).getfinalscore()*w3))<n)
          {
              cout<<(*z).getID()<<"       "<<(*z).getName()<<"       "<<(*z).getSurname()<<"       "<<(*z).getmt1score()<<"       "<<(*z).getmt2score()<<"       "<<(*z).getfinalscore()<<"       "<< (((*z).getmt1score()*w1)+((*z).getmt2score()*w2)+((*z).getfinalscore()*w3)) <<endl;
          }
    }
      return;
}

//5th option showAverage function
int showAverage(Course &atu)
{
    int studnum4=atu.getNum();
    atu.calcAverage(studnum4);

    return 0;
}

//6th option updateStudentScore function
void updateStudentScore(Course &atu ) // mainde oluşturduğum Course class'ında değişiklik yapıyorum
{
int studnum5=atu.getNum(); // course ta kaç kişi var diye bakıyorum kimse yoksa entry yoktur
    if(studnum5==0)
        {
            cout << "No student data entries!"<<endl;
            cout<<" "<<endl;

        }
     else
        {
    cout<<"Enter ID,exam type and updated score: "<<endl;
            int search2id;
            string searchsinav;
            int updatedscore;
            cin>>search2id>>searchsinav>>updatedscore; // girilenleri aldım

        if ( updatedscore<0) // girilen sınav neg. numbar olaamaz
            {
                    cout<<"Updated score could not be negative number!"<<endl;
                    cout<<" "<<endl;
            }

                                //mt1 mt2 veya finalden başka sınav girilemez
        else if((searchsinav!="mt1")&& (searchsinav!="mt2")&& (searchsinav!="final"))
            {
                cout<<"Enter appropriate exam!"<<endl;
                cout<<" "<<endl;

            }
            else
            {
                    for(int i=0;i<studnum5;i++)
                    {
                    Student *y = atu.getStudent(i); // burası önemli kanka
                    // arbitrary bir student oluşturdum ve enries arrayinden sırayla baktım

                    if(search2id==(*y).getID())//oluşturduğum ve entries arrayınden aldığım studenların idleri
                                            //   girilen id ye eşit mi diye baktım
                        {
                        if(searchsinav=="mt1")  // girilen eğer mt1 ise
                            {
                            (*y).setmt1score(updatedscore); // y nin point ettiği entries arrayındeki studentin score
                                                            // unu değiştirdim. Pointer ile olmasaydı başka yol olurdu belki
                                                            //ama illa private dataya ulaşmak lazım.

                            }
                        if(searchsinav=="mt2")
                            {
                                (*y).setmt2score(updatedscore);

                            }
                        if(searchsinav=="final")
                            {
                                (*y).setfinalscore(updatedscore);
                            }


                        }
                    }
            }
        }
    return;
}

// And the main part of the code
int main (void)
{

Course atu;
atu.changeWeights(0.25,0.25,0.5);// You can change the weights from there. If any entry not given to the changeWeights method,
// it will use the default weights - 0.25 , 0.25 , 0.5 . These values just give the instruction for the weights.

int option;
int usta=1;  // dummy variable for not to exit the console

cout<<"Classroom information interface"<<endl;
cout<<" "<<endl;
cout<<"Choose your option: "<<endl;
cout<<"1) Add a student "<<endl;
cout<<"2) Search a student by ID "<<endl;
cout<<"3) Show students with overall score above a threshold "<<endl;
cout<<"4) Show students with overall score below a threshold "<<endl;
cout<<"5) Show classroom average "<<endl;
cout<<"6) Change a student's score "<<endl;
cout<<"7) Exit "<<endl;

while(usta)

{  cout <<" "<< endl;
    cout<<"Enter your option: ";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int id;
            string n,s;
            int mt1,mt2,fin;
            cout<<"Enter ID, name, surname and exam scores (MT1, MT2, final)"<<endl;
            cin>>id>>n>>s>>mt1>>mt2>>fin;
            if(id<=0)
            {
                cout<<"Written ID number is negative!"<<endl;

            }
            else if(mt1<0 || mt2<0 || fin<0 )
            {
                cout<<"Written exam score could not be a negative result!"<<endl;
            }
            else
            atu.addStudent(id,n,s,mt1,mt2,fin);

            break;
        }
        case 2:
        {
            cout<<"Enter ID: ";
            int id;
            cin>>id;
            while(cin.fail()) {
            cout << "Error: Enter an integer number!"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Enter ID: ";
            cin >> id;
            }

            searchByID(id,atu);

            break;
        }
        case 3:
        {
            cout<<"Enter minimum score: "<<endl;
            int minscore;
            cin>>minscore;

            while(cin.fail()) {
            cout << "Error: Enter an integer number!"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Enter minimum score: ";
            cin >> minscore;
            }

            showAbove(minscore,atu);

            break;
        }
        case 4:
        {
            cout<<"Enter maximum score: "<<endl;

            int maxscore;
            cin>>maxscore;

            while(cin.fail()) {
            cout << "Error: Enter an integer number!"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Enter maximum score: ";
            cin >> maxscore;
            }

            showBelow(maxscore,atu);

            break;
        }
        case 5:
        {
            showAverage(atu);

            break;
        }
        case 6:
        {
            updateStudentScore(atu); // Simple fonksiyonu çağırıyorum

            break;
        }
        case 7:
        {

            usta=0;
            cout<<" "<<endl;
            cout<<"Thanks for the Good Grades =)))"<<endl;
            cout<<" "<<endl;
            cout<<"Program is closing in"<<endl;
            cout<<" "<<endl;
            cout<<"3"<<endl;
            cout<<" "<<endl;
            Sleep(1000);
            cout<<"2"<<endl;
            cout<<" "<<endl;
            Sleep(1000);
            cout<<"1"<<endl;
            cout<<" "<<endl;
            Sleep(1000);
            cout<<" "<< endl;
            break;
        }
        case 8:
        {
            cout<<"Invalid Option"<<endl;
            cout<<" "<< endl;
            break;
        }
    }
}
return 0;
}    ;
