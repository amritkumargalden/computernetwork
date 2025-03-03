
//Write a program to calculate even and odd parity at sender and receiver sides

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

char sender(char a, char b[])
{	
	int i, n= 10, ones=0;
	
	for(i=0; i<n; i++)
	{
		if(b[i]=='1')
			ones++;

	}
	if(a=='0')
	{
		if(ones%2==0)
		{
			cout<<"Even parity = 0.\n";
			return '0';
		}
		else 
		{
			cout<<"Even parity = 1.\n";
			return '1';
		}
	}
	else
	{
		if(ones%2==0)
		{
			cout<<"Odd parity = 1.\n";
			return '1';
		}
		else 
		{
			cout<<"Odd parity = 0.\n";
			return '0';
		}
	}
	
}

int main()
{	
 	int n;
 	char parity,type, mx[n], tx[20];	//dynamic array size make 
 	
 	cout<<"Enter the no. of digits in the data:\n";
 	cin>>n;
	cout<<"Enter the data to be transmitted :M(x) = ";
	cin>>mx;
	label:
	cout<<"Choose the parity type:\nEven Parity\nOdd Parity\n";
	cout<<"Press 0 or 1 \n";
	type= getch();
	switch(type)
	{
		case '0':
			cout<<"Using Even Parity::";
			parity = sender(type,mx);
			break;
		case '1':
			cout<<"Using Odd Parity::";
			parity = sender(type,mx);
			break;
		default:
			cout<<"Invalid input. Try again";
			system("cls");
			goto label;
			exit(1);
	}
	tx=mx+parity;
	cout<<mx;
	cout<<endl<<mx<<endl;
	
	return 0;
	
}
