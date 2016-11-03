// Ceasar Cipher.. basic shift cypher
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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
  string ciphertext, decryption, keyS;
  int key;
  ifstream file("hidden.txt");

  if(file.is_open())
    {
      cout << "Welcome to Decrypt_LIFE..\n";
      while(getline(file, keyS))
	{
	  istringstream(keyS) >> key;
	  getline(file, ciphertext);
	  //Decrypting
	  decryption = Decryption(key, ciphertext);
	  cout << "The secret message is : " << decryption << endl;
	}
    }
  return 0;
}
