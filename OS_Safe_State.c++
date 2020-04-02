//break_the_bond
//jatt_james_bond
#include<bits/stdc++.h>
#include<unistd.h>
//#define endl '\n'
int32_t main(){
    int noProcesses, noResource;
    std ::vector<std ::vector<int>> allocated;
    std ::vector<std ::vector<int>> max;

    std ::cout << std ::endl << "Enter the number of resources __";
    std ::cin >> noResource;

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
                arr[i][j] = max[i][j] - allocated[i][j];
            }
            //Assigning the arr to required vector.
            required.push_back(arr);
        }
    //Amrit
        return 0;
}