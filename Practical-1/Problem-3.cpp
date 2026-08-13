#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str,maxw,word="";

  
    cout<<"Enter the Highlight sentence of article:";
    getline(cin,str);
    
    for(int i=0;i<=str.length();i++)
    {
        if(i==str.length() || str[i]==' ')
        {
            if(word.length()>maxw.length())
            {
                maxw=word;
            }
            word="";
        }
        else{
            word+=str[i];
        }
    }
    cout<<"Longest word:"<<maxw;
    cout<<"\nLength of longest word:"<<maxw.length();

}