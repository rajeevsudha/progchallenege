#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;


void funhorz(int n,int s,int pos,int T[5][3])
{//cout<<n;
  
  for(int i=0;i<3;i++)
      if(T[pos][i])
	for(int j=0;j<s;j++)
	  cout<<"-";
      else
	if(i==1)
	  for(int j=0;j<s;j++)
	    cout<<" ";
	else
	  cout<<" ";
  
  
}

void funvert(int n,int s,int pos,int T[5][3])
{//cout<<n;
  
  for(int i=0;i<3;i++)
     if(!T[pos][i])
       if(i==1)
	 for(int j=0;j<s;j++)
	   cout<<" ";
       else
	 cout<<" ";
     else
       cout<<"|";
  
  
}


int main()
{
  ifstream infile;
  ofstream outfile;
  infile.open("110104.inp",ios::in);
  outfile.open("f110104.oup",ios::out);

  long double n;
  int s,num[8],digit=0;
 
  int A[5][3] = {0,0,0,
		 0,0,1,
		 0,0,0,
		 0,0,1,
		 0,0,0},
     B[5][3] =  {0,1,0,
		 0,0,1,
		 0,1,0,
		 1,0,0,
		 0,1,0},
     C[5][3] =  {0,1,0,
		 0,0,1,
		 0,1,0,
		 0,0,1,
		 0,1,0},
     D[5][3] =  {0,0,0,
		 1,0,1,
		 0,1,0,
		 0,0,1,
		 0,0,0},
     E[5][3] =  {0,1,0,
		 1,0,0,
		 0,1,0,
		 0,0,1,
		 0,1,0},
     F[5][3] =  {0,1,0,
		 1,0,0,
		 0,1,0,
		 1,0,1,
		 0,1,0},
     G[5][3] =  {0,1,0,
		 0,0,1,
		 0,0,0,
		 0,0,1,
		 0,0,0},
     H[5][3] =  {0,1,0,
		 1,0,1,
		 0,1,0,
		 1,0,1,
		 0,1,0},
     I[5][3] =  {0,1,0,
		 1,0,1,
		 0,1,0,
		 0,0,1,
		 0,1,0},
     J[5][3] =  {0,1,0,
		 1,0,1,
		 0,0,0,
		 1,0,1,
		 0,1,0};
     
  
  do{
    cin>>s;
    
    char ch[8];
    cin>>ch;
    if(s==0&&ch[0]=='0'&& ch[1]=='\0')break;
    for(int i=0;ch[i]!='\0';++i)
      {
	num[i]=ch[i]-48;
	++digit;
      }//cout<<digit<<num[1]<<"\n";
    for(int i=0;i<5;i++){
       if(i%2==0)
	 {
	   for(int j =0;j<digit;j++)
	     {//cout<<j;
	       
	       
	      switch(num[j])
		{
		
		case 1 : funhorz(1,s,i,A);break;
		case 2 : funhorz(2,s,i,B);break;
		case 3 : funhorz(3,s,i,C);break;
		case 4 : funhorz(4,s,i,D);break;
		case 5 : funhorz(5,s,i,E);break;
		case 6 : funhorz(6,s,i,F);break;
		case 7 : funhorz(7,s,i,G);break;
		case 8 : funhorz(8,s,i,H);break;
		case 9 : funhorz(9,s,i,I);break;
		case 0 : funhorz(0,s,i,J);break;
		}if(j!=digit-1)cout<<" ";
	     }cout<<"\n";
	     
	    }
	  else
	    {
	      for(int k=0;k<s;k++)
		{
		   for(int j =0;j<digit;j++)
		     {
		       switch(num[j])
			 {
			   
			 case 1 : funvert(1,s,i,A);break;
			 case 2 : funvert(2,s,i,B);break;
			 case 3 : funvert(3,s,i,C);break;
			 case 4 : funvert(4,s,i,D);break;
			 case 5 : funvert(5,s,i,E);break;
			 case 6 : funvert(6,s,i,F);break;
			 case 7 : funvert(7,s,i,G);break;
			 case 8 : funvert(8,s,i,H);break;
			 case 9 : funvert(9,s,i,I);break;
			 case 0 : funvert(0,s,i,J);break;
			 }if(j!=digit-1)cout<<" ";
		     }cout<<"\n";
		 
		}
	    }
	 
    }
      
    cout<<"\n";   
    digit=0;
  }while(1);
 
  infile.close();
  outfile.close();
  return(0);
}
