#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int useEncryptor(int text, int phrase)
{
  int key;
  int nextC = text;
  if(text == 32){
      return 32;
    }
  if(phrase > 91){
      key = phrase - 97;
    }
  else{
      if(phrase == 32){
	  key = 4;
	}
      else{
	  key = phrase - 65;
	}
    }
  if(nextC > 91)
    {
      nextC += key;
      if(nextC > 122)
	{
	  nextC = nextC%122 + 96;
	}
    }
  else
    {
      nextC += key;
      if(nextC > 90)
	{
	  nextC = nextC%90 + 64;
	}
    }
  return nextC;
}

int useDecryptor(int ctext, int phrase)
{
  int key;
  int nextPl = ctext;
  if(ctext == 32)
    {
      return 32;
    }
  if(phrase > 90)
    {
      key = phrase - 97;
    }
  else
    {
      if(phrase == 32)
	{
	  key = 4;
	}
      else
	{
	  key = phrase - 65;
	}
    }
  if(nextPl > 90)
    {
      nextPl -= key;
      if(nextPl < 97)
        {
          nextPl = nextPl + 26;
        }
    }
  else
    {
      nextPl -= key;
      if(nextPl < 65)
        {
          nextPl = nextPl + 26;
        }
    }
  return nextPl;
}


int main()
{
  string key, plaintext, ciphertext, decide;
  int path;
  bool encrypted = false;
  cout << "Enter 1 for encryption or 0 for decryption with Vigenere: \n";
  getline(cin, decide);
  path = atoi(decide.c_str());
  cout << "Enter Keyword: \n";
  getline(cin, key); 
  string::iterator keyIt = key.begin(), keyEnd = key.end();
  if(path == 1)
    {
      cout << "Enter Text to Encrypt with Phrase: \n";
      getline(cin, plaintext);
      cout << "\n\nPlaintext: " << plaintext << endl;
      //   string::iterator keyIt = key.begin(), keyEnd = key.end();
      string::iterator textIt = plaintext.begin(), textEnd = plaintext.end();
      while(textIt != textEnd)
	{
	  int asciiVal = useEncryptor(*textIt, *keyIt);
	  if(asciiVal == 32)
	    {
	      ciphertext += asciiVal;      
	      textIt++;
	    }
	  else
	    {
	      ciphertext += asciiVal;
	      keyIt++;
	      if(keyIt == keyEnd)
		{
		  keyIt = key.begin();
		}
	      textIt++;
	    }
	}
      cout << "CipherText: " << ciphertext << endl;
    }
  else
    {
      cout << "Enter Text to Decrypt with Phrase: \n";
      getline(cin, ciphertext);
      string::iterator cipherIt = ciphertext.begin(), cipherEnd = ciphertext.end();
      keyIt = key.begin();
      string decoded;  
      while(cipherIt != cipherEnd)
	{
	  int asciiVal_2 = useDecryptor(*cipherIt, *keyIt);
	  if(asciiVal_2 == 32)
	    {
	      decoded += asciiVal_2;
	      cipherIt++;
	    }
	  else
	    {
	      decoded += asciiVal_2;
	      keyIt++;
	      if(keyIt == keyEnd)
		{
		  keyIt = key.begin();
		}
	      cipherIt++;
	    }
	}
      cout << "\n\nDecodedText: " << decoded <<endl;
    }
  return 0;

}
