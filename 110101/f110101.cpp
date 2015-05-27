#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int findmax(int set[],int l)
{
  int max= set[0];
  int i=1;
   while(i<l)
    {
      if(set[i]>max)
	max=set[i];
      i++;
      
    }
  return(max);
}

int createset(int n)
{
  int count=1;
  while(n!=1)
    {
      if(n%2==0)
	{
	  n=n/2;
	  count++;
	}
      else
	{
	  n=3*n+1;
	  count++;
	}
    }
  return(count);
}

int startf(int i , int j)
{
  int x=i,y=j,len[100000],max=0;
      int count=0;
      //cout<<i<<" "<<j<<"\n";
      while(x<=y)
	{
	  len[count] = createset(x);
	  count++;x++;
	  
	  }
      max=findmax(len,j-i+1);
      return(max);
}

int main()
{
  int i,j,len[10000],count=0,max=0,x,y;
  ifstream infile;
  ofstream outfile;
  infile.open("110101.inp",ios::in);
  outfile.open("110101.oup",ios::out);
  while(infile>>i>>j)
    {
      if(i>j)
	max = startf(j,i);
      else
	max = startf(i,j);
     
      outfile<<i<<" "<<j<<" "<<max<<"\n";
    }
  infile.close();
  outfile.close();
  return(0);
}

