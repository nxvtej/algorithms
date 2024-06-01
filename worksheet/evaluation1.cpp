/*
count the number of characters , words and lines you have within file

*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
/*
int main()
{
    ofstream fout;
    fout.open("D:\\text files\\navdeep.txt");
    fout<<"Hello world this is first line"<<endl;
    // fout<<"\n";
    fout<<"This is second line"<<endl;
    if(fout.good())
    {
            cout<<"data saved\n";
    }
    fout.close();

    ifstream fin;
    // string line ;
    char ch ;
    int lines{} , charnum{} ,wordnum{} ;
    fin.open("D:\\text files\\navdeep.txt");
    if(!fin.is_open())
    {
        cerr<<"Error opening\n";
    }
    while(!fin.eof())
    {
        fin.get(ch);
        charnum++;

        if(ch == ' ' || ch == '\n')
        wordnum++;

        if(ch == '\n')
        lines++;
    }

    fin.close();

    cout<<"total number of lines: "<<lines<<endl;
    cout<<"total number of words: "<<wordnum<<endl;
    cout<<"total number of characters: "<<charnum<<endl;

    return 0;
}
*/
class student
{
    public :
    int roll_number ;
    char name[20] ;

    public :
    void get_data();
    void show_data();
};
void student :: get_data()
{
    cout<<"enter the name of the student"<<endl;
    cin>>name;
    cout<<"enter the roll number"<<endl;
    cin>>roll_number;
}

void student :: show_data()
{
    cout<<"entered name is :"<<name<<endl;
    cout<<"entered roll number is :"<<roll_number<<endl;
}

int main(int argc, char** argv)
{

    cout<<"enter number of students"<<endl;
    int number{};
    cin>>number;
    student *s = new student[number];
    for(int i = 0; i < number; i++)
    s[i].get_data();    
    cout<<"displaying data"<<endl;
    for(int i = 0; i < number; i++)
    s[i].show_data();


    ofstream fout("D:\\text files\\navdeep.txt",ios::out | ios::binary);
    if(!fout.is_open())
    {
        cerr << "Error in opening program" << endl;
        exit(1);
    }

    for(int i = 0 ; i < number; i++)
    fout.write((char*)&s[i],sizeof(s[i]));

    if(fout.good())
    {
        cout<<"data stored to file successfully"<<endl;
    }

    fout.close();

    ifstream fin ;
    fin.open("D:\\text files\\navdeep.txt",ios::out | ios::binary);
    if(!fin.is_open())
    {
        cerr << "error in opening program"<<endl;
        exit(1);
    }
    
    int data_num{};
    try
    {
        cout<<"enter which data want to read\n";
        cin>>data_num;
        if(data_num<0 || data_num>number)
        throw "wrongly entered\n";
        //fin.read((char*)&s[data_num],sizeof(s[data_num]));
        //s[data_num].show_data();
        void print(int);
    }
    catch(char const* msg)
    {
        std::cerr << msg<< '\n';
        exit(1);
    }

    fin.close();
}
    void print(int pos)
    {
        fstream fin;
        fin.open("D:\\text files\\navdeep.txt",ios::out | ios::binary);
        fin.seekp((pos-1) * sizeof(student));
        fin.seekg((pos-1)*sizeof(student));
        fin.read((char *)pos-1 , sizeof(student));
        fin.close();
    }