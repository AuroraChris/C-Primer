#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const string func()
{
    string ret;
    //string ret = "world";
    if (!ret.empty())
    {
        return ret;
    } else {
        return "empty";
    }
}

int main()
{
    cout<<__func__<<endl;
    cout<<__FILE__<<endl;
    cout<<__LINE__<<endl;
    cout<<__TIME__<<endl;
    cout<<__DATE__<<endl;
}