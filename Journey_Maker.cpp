#include<iostream>
#include<conio.h>
#define MAX 10
#include "display_map.txt"
#include "path_selector.txt"
#include "path_invader.txt"
#include "display_shortest_path.txt"

using namespace std;

void find_paths(int,int,int[][MAX],struct paths**,int);
struct paths* path_selector(struct paths*,int*,int);
void display_shortest_path(struct paths*,int,int,string,int,int,int);
void displaymap();

int main(){

	int mat[MAX][MAX]={{0,0,0,0,0,0,0,0,16,6},
				 	   {0,0,0,0,8,0,0,11,12,14},
				 	   {0,0,0,2,0,12,0,0,0,0},
				 	   {0,0,2,0,8,10,6,0,0,0},
				 	   {0,8,0,8,0,7,0,10,0,0},
				 	   {0,0,12,10,7,0,4,0,0,0},
				 	   {0,0,0,6,0,4,0,9,0,0},
				 	   {0,11,0,0,10,0,9,0,13,0},
				 	   {16,12,0,0,0,0,0,13,0,5},
				 	   {6,14,0,0,0,0,0,0,5,0}
					  };


jump:
displaymap();

cout<<"\nCHOOSE FROM HERE : \n\n"
<<"0) DARJEELING\n"
<<"1) BANKURA\n"
<<"2) KOLKATA\n"
<<"3) HOWRAH\n"
<<"4) KALYANI\n"
<<"5) BEHALA\n"
<<"6) BURDWAN\n"
<<"7) DURGAPUR\n"
<<"8) SILIGURI\n"
<<"9) MIDNAPUR\n";

int src,dest;

try{
cout<<"\nENTER SOURCE INDEX : ";
cin>>src;
if(src<0||src>MAX-1)
throw src;	
}
catch(int s){
	cout<<"\n*INVALID INPUT*\n";
	getch();
	system("cls");
	goto jump;
}

try{
cout<<"\nENTER DESTINATION INDEX : ";
cin>>dest;
if(dest<0||dest>MAX-1||src==dest)
throw dest;
}
catch(int d){
	cout<<"\n*INVALID INPUT*\n";
	getch();
	system("cls");
	goto jump;

}
int train,spd;
cout<<"\nCHOOSE FROM HERE :\n1) EXPRESS (Sp=90km/hr)\n2) LOCAL   (Sp=30km/hr)\n";
cout<<"\nWHICH TRAIN WOULD YOU PREFER ? ";
jump3:
cin>>train;
if(train>2||train<1){
	cout<<"*INVALID INPUT*\nPLEASE PROVIDE A STABLE INPUT : ";
	goto jump3;
}
if(train==1)
spd=90;
else spd=30;
string clock;
cout<<"\nPLEASE PROVIDE THE TIME OF DEPARTURE(hh:mm) : ";
jump2:
cin>>clock;
if((clock[0]-48)>2||clock[0]<48||clock[0]>57||clock[1]<48||clock[1]>57||clock[2]!=':'||clock[3]<48||clock[3]>57||clock[4]<48||clock[4]>57||(clock[3]-48)>5){
	cout<<"*INVALID INPUT*\nPLEASE PROVIDE A STABLE INPUT : ";
	goto jump2;
}
int time1;
time1=((((clock[0]-48)*10)+(clock[1]-48))*60)+(((clock[3]-48)*10)+(clock[4]-48));

struct paths *m;
m=new (struct paths);
m->next=NULL;

m->marr[0][0]=src;
m->marr[0][1]=0;

for(int j=1;j<MAX;j++){
	m->marr[j][0]=-1;
	m->marr[j][1]=0;		
}

for(int z=0;z<MAX;z++){
	mat[z][src]=0;
}
	
system("cls");

//cout<<src;//
struct paths *qq=m;

find_paths(src,dest,mat,&m,0);

int sum1=-1;

displaymap();

struct paths *store_p=path_selector(qq,&sum1,dest);
display_shortest_path(store_p,time1,sum1,clock,spd,train,dest);

getch();

return 0;

}
