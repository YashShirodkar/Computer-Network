#include<iostream>
using namespace std;

class Hamming
{
	int data[11],rec[11],err[4],i;
	
	public:
	
	Hamming()
	{
		for(i=1;i<=11;i++)
			data[i]=8;
	}
	
	void input()
	{
		cout<<"\nEnter the 7 bit data :";
		for(i=1;i<=11;i++)
		{
			if(i==1 || i==2 || i==4 || i==8)
				continue;
			cin>>data[i];	
		}
	}
	
	void cal()
	{
		data[1]=data[3]^data[5]^data[7]^data[9]^data[11];
		data[2]=data[3]^data[6]^data[7];
		data[4]=data[5]^data[6]^data[7];
		data[8]=data[9]^data[10]^data[11];
		
		cout<<"\nData Transmiited :";
		for(i=1;i<=11;i++)
			cout<<data[i]<<"\t";
			
		cout<<"\nEnter the 11 bits data received :";
		for(i=1;i<=11;i++)	
			cin>>rec[i];
			
		err[1]=rec[1]^rec[3]^rec[5]^rec[7]^rec[9]^rec[11];
		err[2]=rec[2]^rec[3]^rec[6]^rec[7];
		err[3]=rec[4]^rec[5]^rec[6]^rec[7];
		err[4]=rec[8]^rec[9]^rec[10]^rec[11];
		
		int e=(err[1]*1)+(err[2]*2)+(err[3]*4)+(err[4]*8);
		
		if(e==0)
			cout<<"\nData Received without Errors !!!\n";
		else
			cout<<"\nError in bit "<<e<<endl;		

	}
};


int main()
{	Hamming s;
	s.input();
	s.cal();
	return 0;
}
