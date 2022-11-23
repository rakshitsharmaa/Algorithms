#include<iostream>
using namespace std;

string encrypt(string txt,int key){

	string encrytext = "";
	int i;

	for(i=0;i<txt.length();i++){
		if(isupper(txt[i]))
			encrytext += char((int(txt[i] + key - 65) % 26) + 65);

		else
			encrytext += char((int(txt[i] + key - 97) % 26) + 97);

	}
	return encrytext;
	//cout << encrytext << endl;
}


int main(){
	string txt,encry;
	cin >> txt;

	int key;
	cin >> key;

	encry = encrypt(txt,key);
	cout << encry << endl;

}
