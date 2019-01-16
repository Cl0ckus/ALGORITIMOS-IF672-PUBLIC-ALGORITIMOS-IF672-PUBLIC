#include <iostream>

using namespace std;

int main(){
    int cases =0;

    cin>>cases;

    for(int i=0; i<cases; i++){
        int num =0, numbers =0;
            int k =0;
        cin >> num>>numbers;

        for(int j=0; j<numbers; j++){
            
            int n=0;
            cin >> n;

            if(num%n==0){
                k++;
            }
            
        }

        cout<<"caso "<<(i+1)<<": "<<k<<endl;
    }
}