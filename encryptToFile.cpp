// Ceasar Cipher.. basic shift cypher
#include <iostream>
#include <fstream>

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

int main(int argc, char *argv[])
{
  //variables
  string plaintext, encryption;
  int key;
  ofstream file ("hidden.txt", ios_base::app | ios_base::out);

  cout << "Welcome to Encrypt_To_File..\n";
  cout << "\nEnter Key:\n";
  cin >> key;
  cin.ignore();
  if(file.is_open())
    {
      cout << "\nEnter Plaintext: \n";
      getline(cin, plaintext);
      //Encrypting
      encryption = Encryption(key, plaintext);
      cout << "The text is now encrypted into file\n";
      file << key << endl;
      file << encryption << endl;
      file.close();
    }
  return 0;
}
