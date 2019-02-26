/*
 * Theater.c
 *
 *  Created on: Feb 23, 2019
 *      Author: hikar
 */

#include <stdio.h>

int main()
{
	char theater[15][30];
	int fee[15];
	int sales=0;
	int sold=0;
	int choice = 0;
	for(int i = 0; i<15; i++)
	{
		printf("What is the ticket price for row %d:",i+1);
		fflush(stdout);
		scanf("%d", &fee[i]);
		for(int j = 0; j<30; j++)
		{
			theater[i][j]='*';
		}
	}
	while(choice!=6)
	{
		printf("\n                    Seats\n         ");
		for(int i = 1; i<31; i++)
		{
			printf("%d",i%10);
		}
		for(int i = 0; i<15; i++)
		{
			if(i<9)
				printf("\nRow %d    ",i+1);
			else
				printf("\nRow %d   ",i+1);
			for(int j = 0; j<30; j++)
			{
				printf("%c", theater[i][j]);
			}
		}
		printf("\nMenu\n1. Purchase tickets\n2. View sales\n3. View seats sold\n4. Available seats"
				" per row\n5. Available seats in auditorium\n6. Exit\nOption: ");
		fflush(stdout);
		scanf("%d",&choice);
		if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6)
			printf("Invalid Input\n");
		if(choice==1)
		{
			int row;
			int col;
			int price=0;
			int cont=1;
			while(cont!=0)
			{
				printf("Enter row: ");
				fflush(stdout);
				scanf("%d",&row);
				printf("Enter column: ");
				fflush(stdout);
				scanf("%d",&col);
				if(row>14||row<0||col>29||col<0)
					printf("Seat does not exist");
				else if(theater[row][col]=='*')
				{
					theater[row][col]='#';
					price+=fee[row];
					printf("Continue? (0 to exit): ");
					fflush(stdout);
					scanf("%d",&cont);
					sold++;
				}
				else
					printf("Seat has already been sold\n");
			}
			printf("$%d spent\n",price);
			sales+=price;
		}
		else if(choice==2)
		{
			printf("$%d has been spent\n", sales);
		}
		else if(choice==3)
		{
			printf("%d seats have been sold\n",sold);
		}
		else if(choice==4)
		{
			for(int i = 0; i<15; i++)
			{
				int count=0;
				for(int j = 0; j<30; j++)
				{
					if(theater[i][j]=='*')
						count++;
				}
				printf("Row %d has %d seats remaining\n",i+1,count);
			}
		}
		else if(choice==5)
		{
			printf("There are %d seats remaining in the theater",450-sold);
		}
	}
	return 0;
}

