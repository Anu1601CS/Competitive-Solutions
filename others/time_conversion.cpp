#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
  string s, da, o;
  char hh[20];
  int size;
  int fi;
  cin>>s;

  size =  s.size();

  da = s[size-2];

  size_t length = s.copy(hh,2,0);
  hh[length]='\0';

	// object from the class stringstream
	stringstream geek(hh);

	// The object has the value 12345 and stream
	// it to the integer x
	int x = 0;
	geek >> x;

  s.erase(size-2, size-1);

  if (da == "A")
  {
    if(x == 12)
    {
      s.erase(0, 2);
      cout<<"00"<<s<<endl;
    }
    else
    {
      cout<<s<<endl;
    }
  }
  else if (da == "P")
  {
    if (x == 12)
    {
      cout<<s<<endl;
    }
    else
    {
      fi = x+12;
      s.erase(0, 2);
      cout<<fi<<s<<endl;
    }
  }
  return 0;

}
