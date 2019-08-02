#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct fcfs
{
    int processID;
    char processName;
    int duration;
    int arrivalTime;
    int turnAroundTime;
    int startTime;
    int completionTime;
};

int c=1;

bool compare(fcfs a,fcfs b)
{
    if (a.arrivalTime==b.arrivalTime) // For selecting the smallest duration
        return a.duration<b.duration; // if arrival time is same;
    return a.arrivalTime<b.arrivalTime;
}

int main()
{
    int n, x, it=1, processID, duration, arrivalTime;
    char processName;
    vector<fcfs>v;
    while (1)
    {
        cout << "Iteration " << it++ << endl << endl;
        cout << "Input: n = ";
        cin >> n;
        x=0;
        double sum=0.0;
        while (n--)
        {
            cout << c++ << ". ";
            cin >> processID >> processName >> duration >> arrivalTime;
            v.push_back({processID, processName, duration, arrivalTime});
        }
        sort(v.begin(), v.end(), compare);
        for (int i=0; i<v.size(); ++i)
        {
            v[i].startTime=x;
            v[i].completionTime=v[i].duration+x;
            x=v[i].completionTime;
            v[i].turnAroundTime=v[i].completionTime-v[i].arrivalTime;
        }
        cout << "Output:" << endl;
        cout << "Seq.No. " << "ProcessName " << "Timeline " << "Turnaround" << endl;
        for (int i=0; i<v.size(); ++i)
        {
            cout << i+1 << "        " << v[i].processName << "          " << v[i].startTime << "-" << v[i].completionTime << "        " << v[i].turnAroundTime << endl;
            sum+=v[i].turnAroundTime;
        }
        cout << "A.T.T = " << fixed << setprecision(1) << sum/(double)v.size() << endl << endl;
    }
    return 0;
}
