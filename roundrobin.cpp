#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <list>
#include <queue>

using namespace std;

struct roundRobin
{
    int processID;
    char processName;
    int duration;
    int arrivalTime;
    int turnAroundTime;
    int startTime;
    int completionTime;
};

bool compare(roundRobin a,roundRobin b)
{
    if (a.arrivalTime==b.arrivalTime) // For selecting the smallest duration
        return a.duration<b.duration; // if arrival time is same;
    return a.arrivalTime<b.arrivalTime;
}

int main()
{
    int n, t, x, r, i, processID, duration, arrivalTime;
    char processName;
    struct roundRobin rr;
    vector<roundRobin>v;
    list<roundRobin>l;
    queue<roundRobin>q;
    cout << "Input:" << endl;
    cout << "TQ = ";
    cin >> t;
    cout << "n = ";
    cin >> n;
    i=0;
    double sum=0.0;
    for (int j=0; j<n; ++j)
    {
        cin >> processID >> processName >> duration >> arrivalTime;
        l.push_back({processID, processName, duration, arrivalTime});
    }
    l.sort(compare);
    x=l.front().arrivalTime;
    while(l.front().arrivalTime==x)
    {
        q.push(l.front());
        l.pop_front();
    }

    while(!q.empty())
    {

        v.push_back(q.front());
        v[i].startTime=x;
        if (v[i].duration<=t)
        {
            r=0;
            v[i].completionTime=v[i].duration+x;
            v[i].turnAroundTime=v[i].completionTime-v[i].arrivalTime;
        }
        else
        {
            r=v[i].duration-t;
            v[i].completionTime=t+x;
            rr=v[i];
            rr.duration=r;
        }
        x=v[i].completionTime;

        while(!l.empty() && (l.front().arrivalTime<=v[i].completionTime))
        {
            q.push(l.front());
            l.pop_front();
        }
        if (r!=0)
            q.push(rr);
        q.pop();
        i++;
    }

    cout << "Output:" << endl;
    cout << "Seq.No. " << "ProcessName " << "Timeline " << endl;
    for (int i=0; i<v.size(); ++i)
    {
        cout << i+1 << "        " << v[i].processName << "          " << v[i].startTime << "-" << v[i].completionTime << endl;
        sum+=v[i].turnAroundTime;
    }
    cout << "A.T.T = " << fixed << setprecision(1) << sum/(double)n << endl;
    return 0;
}
