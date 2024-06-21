/* Two sum problem : givena a array & a target
 return an array which has indices such that 
 their sum of value is target*/


#include<iostream>
using namespace std;
#include<unordered_map>
#include<array>
// Brute force approach 
/*
int* solbf(int arr[], int size,int target)
{
   static int arr2[2]; //static is imp  to pertain the arr2 value
   
  for (int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+arr[j] == target)
            {
                arr2[0]=i;
                arr2[1]=j;
                return arr2;
            }
        }
    }
    return nullptr;
}
*/
array<int,2> twoSum (int arr[] , int size,int target)
{
    unordered_map<int,int> mymap;
    array<int,2> indices ={-1,-1} ;
    for (int i=0; i<size;i++)
    {
        int complement = target - arr[i];
        if(mymap.find(complement) == mymap.end())
        {
            mymap[arr[i]]=i;
        }
        else
        {
            indices[0]=mymap[complement];
            indices[1]=i;
            return indices;
            
        }
    }
    return indices;
}

int main()
{
    int arr[4]={1,2,3,4}; 
    int size=4;  
    int target=7;
  
  
  array <int,2> arr2=twoSum(arr,size,target);
    if (arr2[0] == -1 && arr2[1] == -1) {
        cout << "No indices found that sum to " << target << endl;
    } else {
        cout << "Indices of the two numbers that sum to " << target << " are: ";
        for (int k = 0; k < 2; ++k) {
            cout << arr2[k] << " ";
        }
        cout << endl;
    }
    

    return 0;
}