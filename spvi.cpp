#include <stdio.h>
#include <iostream>
using namespace std;
string removeComments(string str)
{
  //what is this 
  string value = "";
    int length = str.length();
    bool multiComment = false;
    bool singleComment = false;
    int spaceCount = 0;

    for (int i=0;i<length;i++)
    {
        if (str[i] == '/' && str[i + 1] == '/')
        {
            singleComment = true, i++;
        }
        else if (singleComment && str[i] == '\n')
        {
            singleComment = false;
        }
        else if (str[i] == '/' && str[i + 1] == '*')
        {
            multiComment = true, i++;
        }
        else if (multiComment && (str[i] == '*' && str[i + 1] == '/'))
        {
            multiComment = false, i++;
        }
        else if (singleComment || multiComment)
        {
            continue;
        }
        else
        {
            value += str[i];
        }
    }
    return value;
}

int main()
{  cout<< " Date is: " << __DATE__<< endl;
   cout<< " & Time : " <<  __TIME__<< endl;
    printf(R"EOF(
||====================================================================||
||//$\\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//$\\||
||(99)==================| Compiler Design Lab |===================(99)||
||\\$//                 '-----=========--------'                 \\$//||
||<< /    Fall 2021           /       \     Only for sale          |<<||
||<<|                        || /O O\ ||                           |>>||
||>>|                        ||       ||     Welcome to            |<<||
||<<|     Our VIP Compiler  *\\  \_/  //*      Project             |>>||
||>>|                         *\ /_\ /*                            |<<||
||<<\                    _____/ CICADA \______                     />>||
||//$\                 ~|     IP address      |~                  /$\\||
||(99)=================== 0000.0393.0443.0628 ====================(99)||
||\\$//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\\$//||
||====================================================================||
)EOF");
    cout<<""<< endl;
    string str;
    getline(cin,str,'~');
    cout<< removeComments(str);


    return 0;
    }
