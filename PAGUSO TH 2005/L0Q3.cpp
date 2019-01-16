#include <iostream>
#define ASCII 256
using namespace std;


int main(){

    int cases =0;
    int letters[ASCII];
    int aux[ASCII];


    cin>>cases;

    for(int i =0; i<cases; i++){
        
        string word;
        int n=0;

        for(int j=0; j<=255; j++){
            letters[j]=0;
            aux[j] = 0;
        }
        cin>>word;
        cin>>n;

        int size = word.length();

        for(int j=0; j<size; j++){
            (letters[word.at(j)])++;
            (aux[word.at(j)])++;
        }

        cout<<"caso "<<(i+1)<<":"<<endl;

        for(int j=0; j<n; j++){

            cin>>word;

            int length = word.size();
            bool possible = true;
            bool removed = false;

            if(length>size){
                possible = false;
            }

            else{

                for(int k=0; k<length && possible ; k++){
                    if(letters[word.at(k)]==0){
                        possible = false;
                    }
                    else{
                        removed = true;
                        (letters[word.at(k)])--;
                    }
                }

                if(j<n-1 && removed){

                    for(int k=0;k<=255;k++){
                        letters[k] = aux[k];
                    }
                }
            }

            if(possible)
                cout<<"possivel"<<endl;
            else
                cout<<"impossivel"<<endl;

        }
    }
}