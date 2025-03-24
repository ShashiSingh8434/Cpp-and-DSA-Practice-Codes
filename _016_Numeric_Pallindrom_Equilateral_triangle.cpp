#include <iostream>
using namespace std;

int main(){
    int n = 5;

    for (int i = 0; i < n; i++){
        for(int a = n-i-1; a >= 0; a--){         // printing spaces
            cout<<"  ";
        }
        int num = 1;
        for (int j = 0; j < i+1 ; j++){       // printing first half number 
            cout<<j+1<<" ";
        }
        for (int k = i; k > 0 ; k--){       // printing second half number 
            cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//           1 
//         1 2 1
//       1 2 3 2 1
//     1 2 3 4 3 2 1
//   1 2 3 4 5 4 3 2 1