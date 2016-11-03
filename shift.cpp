// Joel Zarley
//Ceasar Cipher.. basic shift cypher
#include <iostream>

using namespace std;

string Encryption(int key, string plaintext)
{
  string encrypted;
  string::iterator text = plaintext.begin(), end = plaintext.end();  

  for(; text != end; text++)
    {
      int next = *text;
      if(next == 32)
	{
	  next = 32;
	}
      else
	{
	  if(next > 90)
	    {
	      next += key;
	      if(next > 122)
		{
		  next = next%122 + 96;
		}
	    }
	  else
	    {
	      next += key;
	      if(next > 90)
		{
		  next = next%90 + 64;
		}
	    }
	}
      encrypted += next;
    }

  return encrypted;
}
string Decryption(int key, string encryption)
{
  string decrypted;
  string::iterator text = encryption.begin(), end = encryption.end();      
  for(; text != end; text++)
    {     
      int next = *text;
      if(next == 32)
	{
	  next = 32;
	}                                                
      else
	{
	  if(next > 90)
	    {
	      next -= key;
	      if(next < 97)
		{
		  next = next + 26;
		}
	    }
	  else
	    {
	      next -= key;
	      if(next < 65)
		{
		  next = next + 26;
		}
	    }
	}
      decrypted += next;
    }
  
  return decrypted;
}


int main(int argc, char *argv[])
{
  //variables
  string plaintext, ciphertext, encryption, decryption;
  int key, decide;

  cout << "Welcome to Ceasar's BRUTE FORCE.\n";
  cout << "Enter 1 to encrypt or 0 to decrypt with ceasar:\n";
  cin >> decide;
  cin.ignore();
  if(decide == 1)
    {
      cout << "\nEnter Plaintext: \n";
      getline(cin, plaintext);
      //Encrypting
      key = 1;
      for(; key<27; key++)
	{
	  encryption = Encryption(key, plaintext);
	  cout << "Encryption_Key "<<key<<" : \n" << encryption << endl;
	}
    }
  else
    {
      cout << "\nEnter CipherText: \n";
      getline(cin, ciphertext);
      
      //Decrypting
      key = 1;
      for(; key<27; key++)
	{
	  decryption = Decryption(key, ciphertext);
	  cout << "Decryption_Key "<<key<<" : \n" << decryption << endl;
	}   
    }
  return 0;
}
