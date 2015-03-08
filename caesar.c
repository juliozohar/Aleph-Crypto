#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std; 

char caesar(char c, int k){
	if(isalpha(c) && c != toupper(c)){
		c = toupper(c); 
		c = (((c-65)+k)%26) + 65; 
	}else{
		c = ((((c-65)-k)+26) %26) + 65;
		c = tolower(c); 
	}
	return c; 
}

int main(){
	string input, output; 
	int choice = 0; 

	while (choice != 2){
		cout<<endl<<"Press 1: Encryption/Decryption; Press 2:quit: "; 

		try{
			cin>>choice; 
			if(choice !=1 && choice !=2) throw "Incorrect choice"; 
		}catch(const char* chc){
			cerr<< "INCORRECT CHOICE" <<endl;
			return 1; 
		}

		if(choice == 1){
			int key; 
			try{
				cout<<endl<<"Choose key value (between 1 and 26, inclusive: "; 
				cin>>key; 
				cin.ignore(); 
				if(key < 1 || key > 26) throw "Incorrect key"; 
			}catch(const char* k ){
				cerr<< "INCORRECT KEY VALUE CHOSEN" <<endl; 
				return 1; 
			}

			try{
				cout<<endl<< "Put lower case only letters for encryption and uppercase only for decryption"<<endl; 
				cout<<endl<<"Press enter to continue: "; 
				getline(cin, input); 

				for (int i=0; i < input.size(); i++){
					if((!(input[i] >= 'A' && input[i] <= 'Z')) &&
					(!(input[i] >= 'a' && input[i] <= 'z')))
						throw "Incorrect input string"; 
				}
			}catch(const char* str){
				cerr << "Alpha only"<<endl;
				return 1;  
			}

			//call for the caesar function
			for(unsigned int x = 0; x < input.length(); x++){
				output += caesar(input[x],key); 
			}
			cout<< output << endl; 
			output.clear(); 
		}
	}
}