#include <iostream>
#include <string>

#define MAPS  // Comment it to work in traditional approach to store in array, else it works with maps

#ifdef MAPS
#include <map>
#endif

using namespace std;

//  Function to count the number of character occurance in a string.


#ifndef MAPS
int main()
{
	string input = "hello";
	int letters[26] = {0};
	
	for(char c : input)
	{
		letters[c-'a']++;
	}
	
	for(int i=0; i<26; i++)
	{
		if(letters[i] > 0)
		{
			cout<<"Char:"<<char('a'+i)<<" Count:"<<letters[i]<<"\n";
		}
	}
#else
  int main()
{
	string input = "hello world";
	map<char, int>m;
	map<char, int>::iterator it;
	
	for(char c : input)
	{
	    it = m.find(c);
	    if(it==m.end())
	    {
	        m.insert({c,1});
	    }
	    else
	    {
	        it->second += 1;
	    }
		
	}
	
	for(it = m.begin(); it!=m.end(); it++)
	{
	    cout<<"Char:"<<it->first<<" count:"<<it->second<<"\n";
	}
#endif
	return 0;
}
