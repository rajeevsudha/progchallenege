#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
void field(int d[][1000] , int i ,int j)
{
  for(int x=0;x<i;x++)
	    {
	      for(int y=0;y<j;y++)
	      {
		if(d[x][y]==-1)
		  {
		    if(d[x][y-1]!=-1)//left
		      ++d[x][y-1];
		    
		    if(d[x][y+1]!=-1)//right
		      ++d[x][y+1];

		    if(d[x-1][y]!=-1)//top
		      ++d[x-1][y];

		    if(d[x+1][y]!=-1)//bot
		      ++d[x+1][y];

		    if(d[x-1][y-1]!=-1)//lefttop
		      ++d[x-1][y-1]; 

		     if(d[x-1][y+1]!=-1)//righttop
		      ++d[x-1][y+1]; 

		     if(d[x+1][y-1]!=-1)//leftbot
		      ++d[x+1][y-1]; 

		     if(d[x+1][y+1]!=-1)//rightbot
		      ++d[x+1][y+1]; 
		  }
		
		
	      }
	    
	    }
	   
	  
	    

}

void convert(char c[][1000], int d[][1000],int i, int j)
{
  for(int x=0;x<i;x++)
    for(int y=0;y<j;y++)
      if(c[x][y]=='*')
	d[x][y] = -1;
}

int main()
{
  ifstream infile;
  ofstream outfile;
  infile.open("110102.inp",ios::in);
  outfile.open("f110102.oup",ios::out);
  int i,j,n_field=1;
  char c[1000][1000];
  

  cin>>i>>j;
    

      if(i!=0 && j!=0)
	{
	  for(int x=0;x<i;x++)
	    for(int y=0;y<j;y++)
	      {
		cin>>c[x][y];
		
	      }
	  int e[1000][1000]={0};
	  convert(c,e,i,j);
	  field(e ,i ,j);
	  cout<<"Field #"<<n_field<<":\n";
	  for(int x=0;x<i;x++)
	    {
	      for(int y=0;y<j;y++)
	      {
		if(e[x][y]==-1)
		  cout<<'*';
		else
		  cout<<e[x][y];
		
	      }
	      cout<<"\n";
	    }
	    n_field++;
	   

	  }
    


 //after 1st field calculation
  while(cin>>i>>j)
    {int d[1000][1000]={0};

      if(i==0 || j==0)
	{break;}
      else
	{
	  for(int x=0;x<i;x++)
	    for(int y=0;y<j;y++)
	      {
		cin>>c[x][y];
		
	      }
	  
	  convert(c,d,i,j);
	  field(d ,i ,j);
	  cout<<"\nField #"<<n_field<<":\n";
	  for(int x=0;x<i;x++)
	    {
	      for(int y=0;y<j;y++)
	      {
		if(d[x][y]==-1)
		  cout<<'*';
		else
		  cout<<d[x][y];
		
	      }
	      cout<<"\n";
	    }
	    n_field++;
	    //outfile<<"3\n";

	  }
    }
  infile.close();
  outfile.close();
  return(0);
}

