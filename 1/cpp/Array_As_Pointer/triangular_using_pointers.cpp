#include<bits/stdc++.h>
using namespace std;
auto main()->int
{
    int n = 5;
    int * ptr = new int[(n * (n+1))/2]; 
    cout<<"Enter Triangular 2D array"<<endl;
    for(int  k = 0; k< n;k++){
        for(int l = 0;l<=k;l++){
            cout<<"Enter value at ["<<k<<"]["<<l<<"]: ";
            int in;cin>>in;
            *(ptr+k+l) = in;
        }
    }
    cout<<"Triangular 2D array"<<endl;
    for(int  k = 0; k< n;k++){
        for(int l = 0;l<=k;l++){
            cout<<*(ptr+k+l)<<" ";
        }
        cout<<endl;
    }

    return EXIT_SUCCESS;   
}