//break_the_bond
//jatt_james_bond
#include<bits/stdc++.h>
#include<unistd.h>
//#define endl '\n'
int32_t main(){
    int noProcesses, noResource, additionalReq, xvv{0};
    std ::vector<std ::vector<int>> allocated;
    std ::vector<std ::vector<int>> max;
    std ::vector<int> avail;

    std ::cout << std ::endl << "Enter the number of resources __";
    std ::cin >> noResource;
    
    //Enter the avilable resourses.
    std ::cout << std ::endl << "Enter "<<noResource << " space seprarted values for the avalible resourses"<< std ::endl;
    for (int i = 0; i < noResource;++i){
        int t;
        std ::cin >> t;
        avail.push_back(t);
    }

    std ::cout << std ::endl << "Enter the number of processes  __";
    std ::cin >> noProcesses;

    
    //Taking the input of all the occupied instances of all the processes.
    std ::cout << std ::endl << "Enter the occupied instances of " << noProcesses << "different processes." << std ::endl;
    
    for (int i = 0; i < noProcesses; ++i)
    {
        std ::vector<int> arr(noResource);
        std ::cout << std ::endl << "Enter " << noResource << " space seprated values for the P" << i << " process." << std ::endl;
        
        for (int j = 0; j < noResource; ++j)
        {
            std ::cin >> arr[j];
        }
        //Assigning the arr to Allocated vector. 
        allocated.push_back(arr);
    }

    // for (int i = 0; i < noProcesses; ++i){
    //     for (int j = 0; j < noResource; ++j){
    //         std ::cout << allocated[i][j] << " ";
    //     }
    //     std ::cout << std ::endl;
    // }

    //Taking the input for the max instances needed
    std ::cout << std ::endl << "Enter the maximum number of instances required for each " << noProcesses << " processes.";

    for (int i = 0; i < noProcesses; ++i)
    {
        std ::vector<int> arr(noResource);
        std ::cout << std ::endl << "Enter " << noResource << " space seprated values for the P" << i << " process." << std ::endl;

        for (int j = 0; j < noResource; ++j)
        {
            std ::cin >> arr[j];
        }
        //Assigning the arr to Max vector.
        max.push_back(arr);
    }

        std ::vector<std ::vector<int>> required;
        //Calculating the required resourses.

        for (int i = 0; i < noProcesses; ++i )
        {
            std ::vector<int> arr(noResource);
            for (int j = 0; j < noResource; ++j)
            {
                arr[j] = max[i][j] - allocated[i][j];
            }
            //Assigning the arr to required vector.
            required.push_back(arr);
        }
        system("clear");
        std ::cout << "Calculating required resourses..."<<std ::endl;
        usleep(2000000);

        std ::cout << std ::endl << "Enter the number of independent requests you want to enter __";
        std ::cin >> additionalReq;

        for (int i = 0; i < additionalReq;++i)
        {
            std ::vector<int> arr(noResource);
            std ::cout << std ::endl << "Enter " << noResource << " space seprated values for your " << additionalReq << " independent requests." << std ::endl;

            for (int j = 0; j < noResource; ++j)
            {
                std ::cin >> arr[i];
            }
            //Assigning the arr to required vector.
            required.push_back(arr);
        }

    std ::vector<bool> boo((noProcesses + additionalReq), false);
    std ::vector<int> answer(noProcesses + additionalReq);


        for (int vv = 0; vv < (noProcesses + additionalReq); ++vv){
            for (int i = 0; i < (noProcesses + additionalReq); ++i){
                if(!boo[i])
                {
                    bool quantum = false;
                    for (int j = 0; i < noResource; ++j)
                    {
                        if(required[i][j] > avail[j])
                        {
                            quantum = true;
                            break;
                        }
                    }

                    if(!quantum)
                    {
                        answer[xvv++] = i;
                        for (int k = 0; k < noResource; ++k)
                        {
                            avail[k] += allocated[i][k];
                        }
                        boo[i] = true;
                    }
                }
            }
        }

        std ::cout << std ::endl << "Following is the SAFE Sequence" << std ::endl;
        for (int i = 0; i < (noProcesses + additionalReq) - 1; i++)
            std ::cout << " P" << answer[i] << " ->";
        std ::cout << " P" << answer[(noProcesses + additionalReq) - 1] <<std ::endl;

        return 0;
}