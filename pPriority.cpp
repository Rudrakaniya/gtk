#include<bits/stdc++.h>
using namespace std;
//Data Sets Declaration
vector<int> processId;
vector<int> arivalTime;
vector<int> serviceTime;
//vector<int> priority(noProcesses,0);
vector<int> turnaroundTime;
vector<int> waitingTime;    

vector<int> boo(0,0);


int exicution(){

}

int turnAroundTimeCal(){
    //For calculating the Turn arund time.
}

int waitingTimeCal(){
    //For calculating the Waiting time.
}

int main()
{
    int noProcesses;
    cout << "Enter the number of processes = ";
    cin >> noProcesses;
    int totalService{0};

    //taking inputs
    cout << "Enter the Arival time and Servive time for each process: -" << endl;

    for (int i = 0; i < noProcesses; ++i){
        cout << endl << "Enter the Arival time for P" << i << "__";
        cin >> arivalTime[i];
        cout << "Enter the Burst time for P" << i << " __";
        cin >> serviceTime[i];
        cout << endl;
        totalService += serviceTime[i];
    }
    vector<pair <int,int>> sgService;

    for (int i = 0; i < noProcesses; ++i){
        sgService.push_back( make_pair(arivalTime[i],i) ); 
    }

    sort(sgService.begin(), sgService.end());

    vector<pair<int, int>> sgPriority;

    for (int i = 0; i < noProcesses; ++i){
        sgPriority.push_back(make_pair(0, i));
    }

    for (int i = 0; i < noProcesses; ++i){
        
    }

        return 0;
}