#include <iostream>
#include <string>


int Elegance(std::string password,int size){

    if(size==0){
        return 0;
    }
    else if(size==1){
        return (password.at(0)-96);
    }
    else if(size>1){

        int oddL =0;
        int evenL =0;
        int oddS =0;
        int evenS =0;

        if(size%2 == 0){
            evenS = (size/2)+1;
            oddS = evenS;
        }

        else if(size%2!=0){

            oddS = ((size/2)+1)+1;
            evenS= (size/2)+1;
        }

        char even_string[evenS];
        char odd_string[oddS];
        

        for(int j=0;j<size;j++){
                if((j+1)%2 == 0){
                    even_string[evenL] = password.at(j);
                    evenL++;
                }

                else if((j+1)%2 != 0){
                    odd_string[oddL] = password.at(j);
                    oddL++;
                }
        }

        even_string[evenL] = 0;
        odd_string[oddL] = 0;
        
        return (Elegance(odd_string,oddL)*oddL + Elegance(even_string,evenL))% 101009;
    }
    else if(size<1){
        return -1;
    }


}

int main(){

    int cases = 0;

    std::cin >> cases;

    for(int i=0; i<cases ; i++){
        std::string password;

        std::cin>>password;

        int length = password.length();
        int elegance = Elegance(password,length);

        std::cout<<elegance<<std::endl;
       

    }

    


}