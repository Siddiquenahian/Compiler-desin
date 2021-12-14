#include <stdio.h>
#include <iostream>
using namespace std;

string removeComments(string str)//Nahian Siddique
{
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
//Razve Khan Tanmoy
string removeSpace(string str)
{
    int length = str.length();
    string value;
    int spaceCount = 0;
    for (int i=0;i<length;i++)
    {
        if (str[i] == ' ')
        {
            spaceCount++;
        }
        else
        {
            if (spaceCount >= 1)
                value+= ' ';
            value+= str[i];
            spaceCount = 0;
        }
    }
    return value;
}


//Mujahidul Islam
string resolveMacro(string str)
{
    int length = str.length();
    string value;
    string macro_name;
    bool macro_found = false;
    char macro_value;

    bool macro = false;
    for (int i=0;i<length;i++)
    {
        if(str[i] == '#' && str[i+1] == 'd')
        {
            macro = true;
        }
        if(macro && !macro_found  && str[i] == ' ')
        {
            int temp = i+1;
            while(str[temp]!= ' ')
            {
                macro_name+= str[temp++];
                macro_found = true;
            }
        }
        if(macro && str[i] == '\n')
        {
            macro_value = str[i-1];
            macro = false;
        }

        if(macro_found && str[i] == macro_name[0] && str[i+1] == macro_name[1] && str[i+2] == macro_name[2])
        {
            value+= macro_value;
            i+= 2;
            continue;
        }
        value+= str[i];
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
    string removed_comment = removeComments(str);
    string removed_space =  removeSpace(removed_comment);
    cout<<resolveMacro(removed_space);

    return 0;
}
