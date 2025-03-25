#include <iostream>
#include <vector>
using namespace std;

int main(){
    int row = 5;
    int col = 6;

    int** arr = new int*[row];
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    // Initialize array with 0s
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            arr[i][j] = 0;
        }
    }
    

    // printing array
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<< endl;
        
    }

    // deallocating the heap memory since the program is finished
    for (int i = 0; i < row; i++){
        delete arr[i];
    }
    delete arr; 
    
    // --------------------------------------

    // using vector
    vector<vector<int>> arr2(5,vector<int>(6,0));
    for(auto val: arr2){
        for(auto a: val){
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
}