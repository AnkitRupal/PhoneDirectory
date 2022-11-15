#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Trie.h"
#include <stdlib.h> 

void greeting(void){
    cout<<"Welcome to the Phone Directory Program (made with love by Ankit Rupal :-) )\n";
    cout<<"Please enter the digits according to the functionality required : \n";
    cout<<"1) Add contact\n";
    cout<<"2) Delete contact\n";
    cout<<"3) Search contact\n";
    cout<<"0) Exit the program\n";
    return ;
}

int main(){
    string name;
    long long int type=1,mobile_number;
    Trie directory;
    while(type!=0){
        system("clear");
        greeting();
        cin>>type;
        if(type == 1){
            cout<<"Please enter the contact name : ";
            cin>>name;
            cout<<"Please enter the mobile number : ";
            cin>>mobile_number;
            directory.insert(name,mobile_number);

        }else if(type == 2){
            cout<<"Please enter the name of the contact to be deleted : ";
            cin>>name;
            directory.remove(name);
        }else if(type == 3){
            cout<<"Please enter the name of the contact to be searched : ";
            cin>>name;
            cout<<"Search Results :\n";
            directory.search(name);
            cout<<"Suggetsed Contacts : \n";
            directory.prefix_search(name);
            sleep(3);
        }else if(type!=0){
            cout<<"Sorry, can't understand your command :-( \n";
            sleep(3);
        }
    }
    return 0;
}