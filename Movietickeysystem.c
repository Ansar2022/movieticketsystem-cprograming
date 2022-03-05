#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//GlOBAL VARIABLES
char movies[5][25]={"The-Avengers","Tenet","ShangChi","No-Time-To-Die","1917"};
char timesmovie[5][5][25]={
{"1:00 PM","3:00 PM","5:00 PM","7:00 PM","9:00 PM"},{"2:00 PM","4:00 PM","6:00 PM","8:00 PM","10:00 PM"},
{"4:00 PM","6:00 PM","8:00 PM","10:00 PM","12:00 AM"},{"7:00 PM","9:00 PM","11:00 PM","1:00 AM","3:00 AM"},
{"1:00 PM","5:00 PM","9:00 PM","11:00 PM","2:00 AM"}};
char datemovies[5][5][25]={
{"25/11/2020","27/11/2020","29/11/2020","01/12/2020","03/12/2020"},{"26/11/2020","28/11/2020","30/11/2020","02/12/2020","04/12/2020"},
{"23/11/2020","25/11/2020","27/11/2020","29/11/2020","01/12/2020"},{"24/11/2020","26/11/2020","28/11/2020","30/11/2020","02/12/2020"},
{"24/11/2020","25/11/2020","26/11/2020","27/11/2020","28/11/2020"}};
int ticketcount,seatnumber,movie,seatnumber1,time,price,deal;
int nametest,movieseat[5][5][24],price;
char name[24],number[15],seatid[40];
//FUNCTION
void operation();
void center(char a[100]);
void addfilingseats();
void getfilingseats();
void seatsprinting(int a,int b);
void BookTicket();
void printing();
void tab();
void datafile();
void printdatafile();
void fileexistdata();
void AvailableSeats();
void seating();
void detailsprint();
void fileexistdetails();
void details(char number[11]);
void fileexistseats();
void top();
void align(char a[100]);
void loadingBar();
void deals();
void namechecker(char b[100]);
void seatadding(char a[10]);
void adminfunctions();
void printall();
void fileexistprinting();
void numbercheck(char b[15]);
void ticketview();

int main()
{
	top();
	loadingBar();
	top();
	fileexistseats();
	fileexistdata();
    fileexistdetails();
	seating();
    getfilingseats();
	operation();
    return 0;
}

void operation()
{
	top();
	int operate,blen;
	printf("\n\n");
	center("------------------------------------------------------------");
	center("Enter a number for choosing the Operation");
	align("Press \"1\" For Booking A Ticket.");
	align("Press \"2\" For Check The Seats Available.");
	align("Press \"3\" For ADMIN FUNCTIONS.");
	align("Press \"4\" For Viewing The Ticket.");
	align("Press \"5\" For Exiting.\n");
	center("------------------------------------------------------------");
	printf("\tEnter your option:\n");
	tab();
	scanf("%d",&operate); 
	while((operate>6) || (operate<1))
	{
	printf("\tInvalid Operation Please Try Again\n");	
	tab();	
	scanf("%d",&operate);
	}
	switch(operate)
	{
		case 1:
		{
			top();
			BookTicket();
			printf("\n\tPress Enter To Restart Operation\n");
            tab();
        	getch();		
			operation();
		    break;
		}
		case 2:
		{	
		    top();
			AvailableSeats();		
	        printf("\n\tPress Enter To Restart Operation\n");
	        tab();
	        getch();
	        operation();
		    break;
		}
		case 3:
		{	top();
//		[Pass lock] User name: ADMIN password: 1234
			adminfunctions();
			break;
		}
		case 4:
		{
			ticketview();
			printf("\n\tPress Enter To Restart Operation\n");
	        tab();
	        getch();
	        operation();
		    break;
			break;
			}	
		
		case 5:
		{
			top();
			center("Thank You For Visiting Us\n");
			center("*=================================*");
			center(" Code Designed By Ansar & Alishan");
			center("*=================================*");
		break;	
			}	
	}
}

void BookTicket()
{
	fileexistprinting();
	char a[20],k='A';
	int i,j,y,blen,notickets;
	char b[12];
//	Taking details from user
	printf("\tEnter Your Full Name: \n");
	scanf("%c");
	tab();
	gets(name);
	namechecker(name);
	while(nametest==1)
	{
	tab();	
	gets(name);	
	namechecker(name);
	}
	printf("\tNumber:\n");
	numbercheck(b);
//	Movies Printing
	printf("\tChoose a movies below\n");
	for(i=0;i<5;i++)
	{printf("\t%d.%s\n",i+1,movies[i]);}
	tab();
	scanf("%d",&movie);
	while(movie>5||movie<1)
	{
		printf("\tWrong Input Please Try Again\n");
		tab();
		scanf("%d",&movie);
	}
	printf("\tChoose a Date and Time below\n");
	for(i=0;i<5;i++)
	{printf("\t%d.%s  AT\r\t\t\t %s\n",i+1,datemovies[movie-1][i],timesmovie[movie-1][i]);}
	tab();
	scanf("%d",&time);
	while(time>5||time<1)
	{
		printf("\tWrong Input Please Try Again\n");
		tab();
		scanf("%d",&time);
	}
	
	printf("\tHow Many Tickets You Want To Buy\n");
	tab();
	scanf("%d",&notickets);
	printf("\tPlease Enter %d Seat Number From The List Below\n\n",notickets);
    seatsprinting(movie,time);
    for(i=1;i<=notickets;i++)
	{
	printf("\n\tPlease Enter %d Seat Number From The List Below\n",i);
	tab();
	scanf("%c");
    scanf("%c %d",&seatid[0],&seatnumber);
    while(seatid[0]<65||seatid[0]>68||seatnumber<1||seatnumber>6)
	{
		printf("\tInvalid Input Please Enter Again\n");
		tab();
		scanf("%c");
		scanf("%c %d",&seatid[0],&seatnumber);
	}
	seatnumber1=seatnumber;
	seatadding(seatid);
	while(movieseat[movie-1][time-1][seatnumber-1]==0)
	{
	printf("\tSEAT IS CONSUMED PLEASE BOOK ANOTHER SEAT\n");
	tab();
	scanf("%c");
	scanf("%c %d",&seatid,&seatnumber);
	seatnumber1=seatnumber;
	seatadding(seatid);
	}
	ticketcount++;
	seatnumber=seatnumber-1;
	printf("\n\tPlease Enter A Deal For Ticket %d\n",i);
	deals();
	movieseat[movie-1][time-1][seatnumber]=0;
	datafile();
	details(b);
	addfilingseats(movie,time,seatnumber,ticketcount);
	printing();
	}
	printall();
	remove("seatsbulk.tmp");
}
void deals()
{
	
	printf("\t1.Get Drink Only 200ML and Small Sized Popcorn Bag in 200.\n");
	printf("\t2.Get Soft Drink 300ML and Medium Sized Popcorn Bag in 300.\n");
	printf("\t3.Get Soft Drink 500ML and Large Sized Popcorn Bag in 500.\n");
	printf("\t4.Family Pack Get 4 Soft Drinks and 2 Large Sized Popcorn Bag in 1000.\n");
	printf("\t5.None Of The Above.\n");
	tab();
	scanf("%d",&deal);
	while(deal>5||deal<1)
	{
		printf("\tWrong Input Please Try Again\n");
		tab();
		scanf("%d",&deal);
	}
	switch(deal)
	{
	case 1:{
		price=price+200;
		break;
	}
	case 2:{
	    price=price+300;
		break;
	}
		
		
	case 3:{
		price=price+500;
		break;
	}
		
	case 4:{
	    price=price+1000;
		break;
	}
	case 5:{
	    price=price+0;
		break;
	}		
	}
}
void AvailableSeats(int a,int b)
{
	int i,j;
	if(a != 0)
	{
	printf("Enter the Movie ID from below list\n");
		for(i=0;i<5;i++)
	{printf("\t%d.%s\n",i+1,movies[i]);}
	tab();
	scanf("%d",&a);
	while(a>5||a<1)
	{
		printf("\tWrong Input Please Try Again\n");
		tab();
		scanf("%d",&a);
	}
	printf("Enter the Time ID from below list\n");
		for(i=0;i<5;i++)
	{printf("\t%d.%s  AT\r\t\t\t %s\n",i+1,datemovies[a-1][i],timesmovie[a-1][i]);}
	tab();
	scanf("%d",&b);
	while(b>5||b<1)
	{
		printf("\tWrong Input Please Try Again\n");
		tab();
		scanf("%d",&b);
	}
	center("All Seat Available For Your Time Slot\n\n");
	seatsprinting(a,b);
}}
void seatsprinting(int a,int b)
{
	int i,j,cb=100;
	char k='A';
	if(a!=0)
	{
	for(i=0 ;i<24;i=i+6)
	{
		printf(">> Price %d",cb);
			for(j=0 ;j<6;j++)
			{
			if(movieseat[a-1][b-1][i+j]==0)
			{
				printf("\t--\t");
			}
			else
			printf("\t%c%d\t",k, movieseat[a-1][b-1][i+j]-i);
		}
			k++;
			printf("\n\n");	
			cb=cb+50;	
	}	}}
void center(char a[100])
{
	int i,b,c;
	b=strlen(a);
	c=(120-b)/2;
	for(i=0;i<c;i++)
	{
	printf(" ");
	}
	printf("%s\n\n",a);
}
void tab()
{
	printf("ANSWER >> ");
}

void seating()
{
	int i,j,k;
	for(i=0;i<5;i++)
	{
	for(k=0;k<5;k++)
	{
	for(j=0;j<24;j++)	
	movieseat[i][k][j]=j+1;
}
}
}
void fileexistprinting()
{
	FILE *fptr;
	fptr = fopen("seatsbulk.tmp","w");
	fclose(fptr);
}
void printing()
{
	int ticketid=(1000*movie)+(100*time)+(ticketcount);
	FILE *fptr = fopen("seatsbulk.tmp","a");	
       fprintf(fptr,"\t\t  ----------------------------------E-Ticket---------------------------------\n");
        fprintf(fptr,"\t=================================================================================================\n");
        fprintf(fptr,"\t   Ticket ID : %13d \tMovie Name:\t%s \r\t\t\t\t\t\t\t\t\t| Ticket ID    : %10d\n",ticketid,movies[movie-1],ticketid);
        fprintf(fptr,"\t   Customer  : %13s\r\t\t\t\t\t\t\t\t\t| Movie Name   : %10s\n",name,movies[movie-1]);
        fprintf(fptr,"\t   HALL ID   : %13d \tSEAT No :\t%c%d \r\t\t\t\t\t\t\t\t\t| Starting Time: %10s\n",movie,seatid[0],seatnumber1,timesmovie[movie-1][time-1]);
        fprintf(fptr,"\t   PRICE     : %13d \tDeal No :\t0%d \r\t\t\t\t\t\t\t\t\t| SEAT No      :     \t%2c%d\n",price,deal,seatid[0],seatnumber1);
        fprintf(fptr,"\t   Date      : %13s \tStarting Time:\t%s \r\t\t\t\t\t\t\t\t\t| Date         : %10s\n",datemovies[movie-1][time-1],timesmovie[movie-1][time-1],datemovies[movie-1][time-1]);
        fprintf(fptr,"\t   Date and Time Of Prinitng: \t%s,%s \r\t\t\t\t\t\t\t\t\t| HALL ID      : %10d\n", __DATE__,__TIME__,movie);
        fprintf(fptr,"\t=================================================================================================\n");       
fclose(fptr);
}
void printall()
{
	FILE *fptr = fopen("seatsbulk.tmp","r");	
	char a[1000];
	printf("\n");
	while(fgetc(fptr) != EOF)
	{
	fgets(a,1000,fptr);
	printf("\t%s",a);
	}
	fclose(fptr);
}

void addfilingseats(int a, int b,int c,int d)
{
FILE *fptr = fopen("seatfiling.txt","a");
fprintf(fptr,"\n%d %d %d %d",a,b,c+1,d);
fclose(fptr);
}
void getfilingseats()
{
		FILE *fptr = fopen("seatfiling.txt","r");
		int c,time,seatnumber;
		while(fgetc(fptr) != EOF)
		{
		fscanf(fptr,"%d %d %d %d", &movie,&time,&seatnumber,&ticketcount);
		printf("%d %d %d %d",movie,time,seatnumber,ticketcount);
		movieseat[movie-1][time-1][seatnumber-1]=0;
		}
		fclose(fptr);
}
void fileexistseats()
{
	FILE *fptr;
	if ( (fptr = fopen("seatfiling.txt", "r")) == NULL)
	fptr = fopen("seatfiling.txt","w");
	fclose(fptr);
}
void fileexistdata()
{
	FILE *fptr;
	if ( (fptr = fopen("ticket.txt", "r")) == NULL)
	fptr = fopen("ticket.txt","w");
	fclose(fptr);
}
void datafile()
{
	int ticketid=(1000*movie)+(100*time)+(ticketcount);
	FILE *fptr = fopen("ticket.txt","a");	
      fprintf(fptr,"\t\t  ----------------------------------E-Ticket---------------------------------\n");
        fprintf(fptr,"\t=================================================================================================\n");
        fprintf(fptr,"\t   Ticket ID : %13d \tMovie Name:\t%s \r\t\t\t\t\t\t\t\t\t| Ticket ID    : %10d\n",ticketid,movies[movie-1],ticketid);
        fprintf(fptr,"\t   Customer  : %13s\r\t\t\t\t\t\t\t\t\t| Movie Name   : %10s\n",name,movies[movie-1]);
        fprintf(fptr,"\t   HALL ID   : %13d \tSEAT No :\t%c%d \r\t\t\t\t\t\t\t\t\t| Starting Time: %10s\n",movie,seatid[0],seatnumber1,timesmovie[movie-1][time-1]);
        fprintf(fptr,"\t   PRICE     : %13d \tDeal No :\t0%d \r\t\t\t\t\t\t\t\t\t| SEAT No      :     \t%2c%d\n",price,deal,seatid[0],seatnumber1);
        fprintf(fptr,"\t   Date      : %13s \tStarting Time:\t%s \r\t\t\t\t\t\t\t\t\t| Date         : %10s\n",datemovies[movie-1][time-1],timesmovie[movie-1][time-1],datemovies[movie-1][time-1]);
        fprintf(fptr,"\t   Date and Time Of Prinitng: \t%s,%s \r\t\t\t\t\t\t\t\t\t| HALL ID      : %10d\n", __DATE__,__TIME__,movie);
        fprintf(fptr,"\t=================================================================================================\n");     
        

fclose(fptr);
}
void printdatafile()
{
	FILE *fptr = fopen("ticket.txt","r");	
	char a[1000];
	printf("\n");
	while(fgetc(fptr) != EOF)
	{
	fgets(a,1000,fptr);
	printf("\t%s",a);
	}
	fclose(fptr);
}
void fileexistdetails()
{
	FILE *fptr;
	if ( (fptr = fopen("userdetails.txt", "r")) == NULL)
	fptr = fopen("userdetails.txt","w");
	fclose(fptr);
}
void details(char number[11])
{
	FILE *fptr = fopen("userdetails.txt","a");
	fprintf(fptr,"\n%24s | %s 	| %s 		| %s At %s 	| %c%d",name,number,movies[movie-1],datemovies[movie-1][time-1],timesmovie[movie-1][time-1],seatid[0],seatnumber1);
	fclose(fptr);
}
void detailsprint()
{
	FILE *fptr = fopen("userdetails.txt","r");	
	char a[1000],b[1000],c[1000],d[1000],e[1000];
	printf("\n");
	printf("\t\tName\t| Number\t| \tMovie ID\t| \t\tTime\t\t| Seat.No\n");
	center("----------------------------------------------------------------------------------------------");
	while(fgetc(fptr) != EOF)
	{
	fgets(a,1000,fptr);
	printf("");
	printf("%s\n",a);
	}
	fclose(fptr);
}
void loadingBar() 
{
    int j; 
    system("color 0A");
    printf("\n"); 
    center("Please Wait Program Loading..."); 
    
    for(j=0;j<30;j++)
    printf(" ");
    
    for ( j = 0; j < 60; j++) 
    printf("%c", 178);
	 
    printf("\r");  
    for(j=0;j<30;j++)
    printf(" ");
    
    for ( j = 0; j < 60; j++) { 
        printf("%c", 219); 
        Sleep(25); 
    } 
} 
void align(char a[100])
{
	int i;
	for (i=0;i<39;i++)
	printf(" ");
	printf("%s\n",a);
}
void top()
{

	system("cls");
	center("|------------------------------------------------------------|");
	center("WELCOME TO SZABIST CINEMA");
	center("Designers: Ansar (2012333) Ali Shan(2012330)");
	center("|------------------------------------------------------------|");
}
void namechecker(char namecheck[100])
{
    char x;
	int a,i;
for(i=0;i<strlen(namecheck);i++)
	{
	x=namecheck[i];
	if(x>= 97 && x <= 122)
	nametest=2;
	if(x >= 65 && x<= 90)
	nametest=2;
	if(x >= 48 && x<= 57)
	{
	nametest=1;
	break;
	}
	if(((x>=0)&&(x<=47))||(x >= 48 && x<= 57)||((x>=58)&&(x<=64))||((x>=91)&&(x<=96))||((x>=123)&&(x<=127)))
	{
	nametest=1;
	break;
	}
	}
	if(nametest==1)
	printf("\tInvaild Name\n");
}

void seatadding(char a[10])
{
	if(a[0]=='A')
	{
		seatnumber=seatnumber+0;
		price=100;	
	}
	else if(a[0]=='B')
	{
		seatnumber=seatnumber+6;
		price=150;	
	}
	else if(a[0]=='C')
	{
		seatnumber=seatnumber+12;
		price=200;	
	}
	else if(a[0]=='D')
	{
		seatnumber=seatnumber+18;
		price=250;	
	}
}
void adminfunctions()
{
	char a[100],b[100];
	int ad;
	printf("\tEnter Your User Name (Enter \"ADMIN\")\n");
	scanf("%c");
	tab();
	gets(a);
	printf("\tEnter Your Password (Enter \"1234\")\n");
	tab();
	gets(b);
	top();
	if(strcmp(a,"ADMIN")==0)
	{
		if(strcmp(b,"1234")==0){
	center("------------------------------------------------------------");
	center("[ADMIN PANEL]");
	align("Press \"1\" For Printing All Purchased Tickets\n");
	align("Press \"2\" For Viewing All Details\n");
	center("------------------------------------------------------------");
	scanf("%d",&ad);
	switch(ad)
	{
	case 1:
	{
		printdatafile();
		break;
	}
	case 2:
	{
		detailsprint();
		break;
	}
		
	}
            printf("\n\tPress Enter To Restart Operation\n");
	        tab();
	        getch();
	        operation();
}
    else
	operation();}
	else
	operation();
}
void numbercheck(char number[15])
{
	int i,numbertest;
	char k;
	while(numbertest!=1)
	{
	tab();	
	gets(number);	
	for(i=0;i<strlen(number);i++)
	k=number[i];
	{		
	if((k>=48&&k<=57)||(k>=0&&k<=47))
	{
		if(strlen(number)==11)
		{
		 numbertest=1;
	    }
		else
		printf("\tPlease Enter Only Numbers.\n");	
	}
    else
    	printf("\tPlease Enter Only Numbers.\n");
}}
}

void ticketview()
{
	FILE *fptr = fopen("ticket.txt","r");	
	char ticket[1000],ticketcheck[100];
	int ticketid,i,userticketid,itvc;
	printf("\tEnter Your Ticket ID\n");
	tab();
	scanf("%d",&userticketid);
	ticketid=userticketid%100;
	
	for(i=0;i<9*(ticketid-1);i++)
	fgets(ticket,1000,fptr);
	
	for(i=0;i<6;i++)
	{
		fscanf(fptr,"%s",&ticketcheck);
	}
	fclose(fptr);
	itvc=atoi(ticketcheck);
	
	if(itvc == userticketid)
	{
	fptr = fopen("ticket.txt","r");		
	printf("\n");
	
	for(i=0;i<9*ticketid;i++)
	{
	fgets(ticket,1000,fptr);
	if((ticketid-1)*9<=i)
	printf("%s",ticket);
	}
	fclose(fptr);
	}
	else
	printf("\tInvalid Input");
}
