//Write a program to calculate even and odd parity at sender and receiver sides

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
#define MAXSIZE 20

char sender(char a, char b[], int n)
{	
	int i,ones=0;
	
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

void receiver(char a, char b[], int n)
{	
	int i,ones=0;
	
	for(i=0; i<n; i++)
	{
		if(b[i]=='1')
			ones++;

	}
	if(a=='0')
	{
		if(ones%2==0)
		{
			cout<<"There was no error.\n";
		}
		else 
		{
			cout<<"There was an error in the received data.\n";
		}
	}
	else
	{
		if(ones%2==0)
		{
			cout<<"There was an error in the received data.\n";
		}
		else 
		{
			cout<<"There was no error.\n";
		}
	}
	
}
int main()
{	
	int i=0, data_num=0;
 	char parity, type, mx[MAXSIZE], tx[MAXSIZE+1];	//dynamic array size make 
 	
	cout<<"Enter the data to be transmitted :M(x) = \n";
	cin>>mx;
	
	while(mx[i]!='\0')
	{
		data_num++;
		i++;
	}
	label:
	cout<<"\nChoose the parity type:\nEven Parity\nOdd Parity\n";
	cout<<"\t\tPress 0 or 1 \n";
	type= getch();
	switch(type)
	{
		case '0':
			cout<<"\nUsing Even Parity::";
			parity = sender(type,mx,data_num);
			break;
		case '1':
			cout<<"Using Odd Parity::";
			parity = sender(type,mx,data_num);
			break;
		default:
			cout<<"Invalid input. Try again";
			system("cls");
			goto label;
			exit(1);
	}
	
	strcpy(tx, mx);
	tx[data_num] = parity;
	tx[data_num+1] = '\0';

	cout<<endl<<mx<<" is transmitted as "<<tx<<endl;
	
	//checking the parity for the received data 
	cout<<"\nEnter the data received:";
	cin>>mx;

	i=0;
	while(mx[i]!='\0')
	{
		data_num++;
		i++;
	}
	cout<<"\n\nEnter 0: Even Parity \n 1:Odd Parity \nfor the parity received"<<endl;
	type= getch();
	switch(type)
	{
		case '0':
			receiver(type, mx, data_num);
			break;
		case '1':
			receiver(type, mx, data_num);
			break;
	}
	return 0;
	
}
