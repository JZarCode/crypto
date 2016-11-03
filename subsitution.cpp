///Joel Zarley
//frequency Fingerprint

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int freq[500];

int main(int argc, char *argv[])
{
  char cipher;
  if(argc != 2)
    {
      cout << "ERROR, please enter file to search!\n";
      return 1;
    }
  ifstream input (argv[1]);

  if(input)
    {
      int asciiVal;
      while(input.get(cipher))
	{
	  asciiVal = (int)cipher;
	  freq[asciiVal]++;
	}
	  for(int i= 30; i<123; i++)
	    {
	      char a = i;
	      if(i % 5 == 0)
		{
		  cout << endl;
		}
	      cout << a << " used: "<<freq[i]<<"   ";
	    }	
    }

  cout << endl;
  return 0;

}
