#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;


int main()
{
  ifstream infile;
  ofstream outfile;
  infile.open("110103.inp",ios::in);
  outfile.open("f110103.oup",ios::out);
  int i,j;
  int s[1000],sum=0,avg=0,n;
  long double d[1000],exch=0,sumdouble;
  while(cin>>n)
    {
      if(n==0)
	break;
      for(i = 0;i<n;i++)
	{
	  cin>>d[i];
	  d[i]*=100;
	  s[i]=d[i];
	  sumdouble = sumdouble+d[i];
	}
      sum = sumdouble;//cout<<"double"<<sumdouble<<"int"<<sum<<"\n";
      if(sum%n==0)
	{
	  avg = sum/n;
	  for(i=0;i<n;i++)
	    {
	      if(s[i]>avg)
		exch = exch + d[i]-avg;
	    }
	  long double exchf = exch/100;
	 
	  cout<<setiosflags(ios::fixed | ios::showpoint)<<setprecision(2)<<"$"<<exch/100<<"\n";
	}
      else
	{
	  long double avgf,sum1=sum;
	  avgf = sum1/n;
	  int g = avgf;
	  long double exch1=0,exch2=0;
	  //cout<<setiosflags(ios::fixed | ios::showpoint)<<setprecision(3)<<avgf<<"avg"<<h<<"\n";
	  int h = g+1;
	  for(i=0;i<n;i++)
	    {
	      if(d[i]>h)
		exch1 = exch1 + d[i]-h;
	      if(d[i]<g)
		exch2 = exch2 + g-d[i];
	      
	    }
	  if(exch1>exch2)
		 cout<<setiosflags(ios::fixed | ios::showpoint)<<setprecision(2)<<"$"<<exch1/100<<"\n";
	  else
	  	 cout<<setiosflags(ios::fixed | ios::showpoint)<<setprecision(2)<<"$"<<exch2/100<<"\n";

	}
      
      sum = 0;exch=0;n=0;sumdouble=0;
    }
  infile.close();
  outfile.close();
  return(0);
}
