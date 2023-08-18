#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
using namespace std;

const vector<int>nums={1,2,3};

mutex a;
void myprint(int i )
{
    a.lock();
    cout<<"this is thread"<<i<<nums[0]<<"  "<<nums[1]<<"  "<<nums[2]<<endl;
    a.unlock();
}
int main()
{
    vector<thread> huhu;
    for (int  i = 0; i < 5; i++)
    {
        huhu.push_back(thread(myprint,i));
    }
    for(auto iter = huhu.begin(); iter!=huhu.end();iter++)
    {
       iter->join();
    }
    return 0;
}