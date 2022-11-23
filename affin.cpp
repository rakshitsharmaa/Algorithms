#include<bits/stdc++.h>
using namespace std;
int modInverse(int k){
	for(int i=0; i<26; i++){
		int flag= (i*k)%26;
		if(flag==1){
			return i;
		}
	}
	return -1;
}
string encrypt(string plain_text, int key1, int key2){
	string cipher_text= "";
	for(int i=0; i<plain_text.size(); i++){
		if(isupper(plain_text[i])){
			cipher_text+= char((key1* int(plain_text[i]-65)+ key2)%26 +65);
		}else{
			cipher_text+= char((key1* int(plain_text[i]-97)+ key2)%26 +97);
		}
	}
	return cipher_text;
}
string decrypt(string cipher_text, int key1, int key2){
	string plain_text= "";
	int key_inverse= modInverse(key1);
	if(key_inverse==-1){
		return "Not exist";
	}
	cout<<"Key Inverse: "<<key_inverse<<endl;
	for(int i=0; i<cipher_text.size(); i++){
		if(isupper(cipher_text[i])){
			plain_text+= char(((((cipher_text[i]-65- key2)%26+26)%26)*key_inverse)%26+65);
		}else{
			plain_text+= char(((((cipher_text[i]-97- key2)%26+26)%26)*key_inverse)%26+97);
		}
	}
	return plain_text;
}
int main(){
	string plain_text;
	cout<<"Enter plain text: ";
	cin>>plain_text;
	int key1, key2;
	cout<<"Enter first key: ";
	cin>>key1;
	cout<<"Enter second key: ";
	cin>>key2;
	
	cout<<"\nEncryption:\n";
	string cipher_text= encrypt(plain_text, key1, key2);
	cout<<"Cipher: "<<cipher_text<<endl;
	
	cout<<"\nDecryption:\n";
	cout<<"Plain Text: "<<decrypt(cipher_text, key1, key2)<<endl;
}
