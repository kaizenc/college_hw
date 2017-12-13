#include<iostream>
#include<string>
#include"Dictionary.h"

using namespace std;

int main()
{
    string str="abcedbee";

    Dictionary<char,unsigned short> dict;

    if(dict.IsEmpty()) cout<<"Empty\n"; // The message should appear on the screen

    for(int i=0; i<str.size(); i++)
    {
        if(dict.Count(str[i])==0) dict[str[i]]=1;
        else dict[str[i]]+=1;
    }

    cout<<"The number of unique letters is "<<dict.Size()<<endl; // Should show 5
    cout<<"The height of the tree is "<<dict.Height()<<endl;     // Should show 4
    cout<<"The letter a happened "<<dict['a']<<" times\n";        //Should show 1
    cout<<"The letter e happened "<<dict['e']<<" times\n\n";      //Should show 3

    dict.Remove('c');
    cout<<"The number of unique letters is "<<dict.Size()<<endl; // Should show 4
    cout<<"The height of the tree is "<<dict.Height()<<endl;     // Should show 4
    cout<<"The letter a happened "<<dict['a']<<" times\n";        //Should show 1
    if(dict.Count('c')==0) cout<<"Now the letter c is absent\n\n"; //This message should appear on the screen

    dict.Balance();
    cout<<"The height of the tree is "<<dict.Height()<<endl;     // Should show 3

    dict.Clear();
    cout<<"The number of unique letters is "<<dict.Size()<<endl; // Should show 0
    cout<<"The height of the tree is "<<dict.Height()<<endl;     // Should show 0

    return 0;
}