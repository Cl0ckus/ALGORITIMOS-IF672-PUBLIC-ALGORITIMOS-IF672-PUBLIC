#include <iostream>

using namespace std;

int main(){

    int cases =0;

    cin>>cases;

    for(int i=0; i<cases; i++){
        int number=0;
        cin>>number;

        int cube = number*number*number;
        int odds[number];
        int result = 0;
        int first =1;
        
        while(result!=cube){
            result =0;
            int k=first;
            

            for(int j = 0; j<number; j++){
                
                odds[j] = k;
                result+=k;
                k+=2;
                
            }

            first+=2;
        }
            cout<<"caso "<<(i+1)<<": ";
        for(int j=0; j<number; j++){
            if(j==number-1){
                cout<<odds[j]<<endl;
            }
            else{
                cout<<odds[j]<<" ";
            }
        }
    }

}