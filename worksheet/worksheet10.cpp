/*
1. 
Write a program to write multiple lines to a file and then read the file 
using:
• For loop
• Using object of the ifstream class
• Using eof() with object of the ifstream class
[make use of constructor within this program]
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int main()
{

    cout<<"opening file to write to"<<endl;

    fstream fout("D:\\text files\\nxvtejj.txt");
    cout<<"enter multiple lines commented "<<endl;
    string line;
    getline(cin,line);
    fout<<line<<endl;
    fout.close();

    string line2;
    ifstream fin("D:\\text files\\nxvtejj.txt");
    
    while(fin.eof())
    {
        fin>>line2;
        cout<<line2;
    }
    fin.close();
    return 0;
}


/*
2
Write a program to take value of roll number and name from the user for 
multiple students and then write the contents to the file. Read the 
contents from the file entered for those multiple students. [make use of
open() within this program
*/
/*
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char** argv)
{
    float roll_number , roll_number2;
    char name[20] , name2[20] ;
    ofstream fout("\\D:\\text files\\nxvtejj.txt");

    for(int i = 0 ; i< 2 ; i++)
    {

    cout<<"enter the name and roll_number\n";
    cin>>name>>roll_number;

    fout<<name<<"\t"<<roll_number;
    fout<<"\n";

    }

    fout.close();

    ifstream fin("\\D:\\text files\\nxvtejj.txt");
    while(fin.eof())  // return 0 until it reaches end so while(!fin.eof()) can be written same thing 
    {

    fin>>name2;
    fin>>roll_number2;

    cout<<"\nthe name and roll_number are\n";
    cout<<name2<<"\t"<<roll_number2;

    }
    fin.close();
    return 0;
}

*/
/*
3. Write a program to write data members of faculty class namely uid, 
department and salary on to the file for n faculty members as mentioned by 
the user and then read back the contents from the file
*/
/*
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    float uid , uid2;
    char department , department2;
    float salary , salary2;
    char name[20] , name2[20] ;
    ofstream fout("\\D:\\text files\\nxvtejj.txt");

    if(!fout.is_open())
    {
        cerr << "Error in opening program" << endl;
    }
    for(int i = 0 ; i < 2 ; i++)
    {

    cout<<"enter the name , uid , department , salary \n";
    cin>>name>>uid>>department>>salary;

    fout<<name<<"\t"<<uid<<"\t"<<department<<"\t"<<salary;
    fout<<"\n";

    }

    fout.close();
    cout<<"file closed successfully\n";
    ifstream fin("\\D:\\text files\\nxvtejj.txt");
    while(fin.eof())  // return 0 until it reaches end so while(!fin.eof()) can be written same thing 
    {

    fin>>name2;
    fin>>uid2;
    fin>>department2;
    fin>>salary2;

    cout<<"\nthe name and roll_number are\n";
    cout<<name2<<"\t"<<uid2<<"\t"<<department2<<"\t"<<salary<<"\n";
    }
    fin.close();
    return 0;
}
*/
/*
W4. Write a program to demonstrate the use of seekg(),tellg(), seekp() and 
tellp()
*/
/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    fstream file;
    file.open("\\D:\text files\nxvtejj.txt" , ios :: out | ios :: ate);
    if(!file.is_open())
    {
        cerr<<"Failed to open"<<endl;
        exit(1);
    }
    file<<"nxvtejj.txt"<<endl;
    file<<"d drive"<<endl; // file content 

    cout<<"Starting position: "<<file.tellp()<<endl;

    file.seekp(-3,ios :: end); //
    file<<endl<<"this is being written at -3 position\n"; //
    // now seekg
    file.seekg(-1, ios :: end);
    cout<<file.tellg()<<endl;

    cout<<file.tellg()<<endl; // use of tellg
    return 0;
}
*/
/*
tell p = done;
tell g = done;

seek p = done;
seek g = done;
*/
/*
5. Write a program to copy the contents of one file to another file:
• Line by line
• Character by character
*/

/*
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string line;
    ifstream fin ("\\D:\\text files\\file1.txt");
    ofstream fout ("\\D:\\text files\\nxvtejj.txt");
        while(getline(fin,line)){
            fout << line << "\n";
            cout<<line << "\n";
        }
        cout <<"task successfully copied"<<endl;

    fin.close();
    fout.close();
    return 0;
}
*/

/*
5.20
character by character
*/
/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    char c[256];
    gets(c);

    ofstream fout ("\\D:\text files\nxvtejj.txt");
    if(!fout)
    {
        cerr<<"Error while opening a file"<<endl;
        exit(1);
    }

    for(int i = 0 ; i < c[i]!= '\0'; i++)
    fout.put(c[i]);
    fout.close();

    ifstream fin("\\D:\text files\nxvtejj.txt");
    if(!fin)
    {
        cerr<<"Error in opening program"<<endl;
        exit(1);
    }

    char ch;
    while (fin.eof() == 0)
    {
        fin.get(ch);
        cout<<ch;
    }
    fin.close();
    
}
*/
/*
6.Write a program to demonstrate the use of read() and write() used with 
binary files.
*/
/*
#include <iostream>
#include <fstream>
using namespace std;

struct Program
{
    int code_number;
}p[4];

struct worksheet10
{
    int code_number;
}c[4];

int main()
{
    ofstream fout;
    fout.open("\\D:\text files\file1.txt",ios::out | ios::binary);
    if(!fout.is_open())
    {
        cerr << "Error in opening program" << endl;
        exit(1);
    }
    // int code_number{};
    for(int i = 0; i < 4; i++)
    {
    cout<<"enter code_number of "<<i<<" :";
    cin>>p[i].code_number;
    }
    for(int i = 0 ; i < 4; i++)
    fout.write((char*)&p[i],sizeof(p[i]));
    fout.close();

    ifstream fin ;
    fin.open("\\D:\text files\nxvtejj.txt",ios::out | ios::binary);
    if(!fin.is_open())
    {
        cerr << "error in opening program"<<endl;
        exit(1);
    }

    for(int i = 0 ; i < 4; i++)
    fin.read((char*)&c[i],sizeof(c[i]));
    
    fin.close();

    return(0);
}
*/