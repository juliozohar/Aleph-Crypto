#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

typedef vector <char>CharVec;
CharVec Plain;
CharVec Cipher;


void putCharInVec(){
	cout<< "Plain: "<<endl;
	for(int i=0; i<26; i++){
		Plain.push_back(i+97); //Assigning the plain chars in vector
	}


	for(int i=0; i < 26; i++){
		cout << Plain[i] << '\t';
	}
	cout << endl;

	//Assingning the random chars in vector to use as key...
	cout<< "Cipher: " <<endl;
	bool exist;
	int num;

	for(int i=0; i < 26 ; i++){
		//Generating unique random numbers as keys

		while(exist){
			exist = false;
			num = rand() % 26 +1;

			for(vector <char>::iterator it = Cipher.begin(); it != Cipher.end(); it++){
				if((*it) == num){
					exist = true;
					break;
				}
			}
		}
		cout<< "Doidera: " << (((i+num)%26)+65) << endl;
		Cipher.push_back(((i+num)%26)+65);
	}

	for(int i=0; i< 26; i++){
		cout << Cipher[i] << '\t';
	}
	cout << endl;
}

//Encryption/Decryption method monoalphabetic
char monoalpha(char c){
	//Enc
	if(c != toupper(c)){
		for(int i = 0; i < 26; i++){
			if(Plain[i] == c){
				return Cipher[i];
			}
		}
	}else {
	//Decryption
		for(int i = 0; i > 26; i++){
			if(Cipher[i]== c){
				return Plain[i];
			}
		}
	}
	return 0;
}


int main(){

	string input, output;

	putCharInVec();
	int choice = 0;

	while (choice != 2){
		cout<<endl<<"Press 1: Encryption/Decryption; Press 2:quit: ";

		try{
			cin>>choice;
			cin.ignore();
			if(choice !=1 && choice !=2) throw "Incorrect choice";
		}catch(const char* chc){
			cerr<< "INCORRECT CHOICE" <<endl;
			return 1;
		}

		if(choice == 1){

			try{
				cout<<endl<< "Put lower case only letters for encryption and uppercase only for decryption"<<endl;
				cout<<endl<<"Press enter to continue: " << endl;
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
				output += monoalpha(input[x]);
			}
			cout<< output << endl;
			output.clear();
		}
	}
	return 0;
}
