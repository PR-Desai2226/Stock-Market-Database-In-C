#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
struct detail
{
	char name[40];
	char pan[10];
	double aad,amount;
	int id;
};
struct stock
{
	char name[30];
	int p1,p2,p3,p4,p5;
};
int main()
{
    system ("COLOR 3F");
	struct detail p[6];
	struct stock c[11];
	int i,n,x,j,q,flag,point,stock_number,v;
	char k,name[30],pan[11],cname[20],mn,garbage[50],z;
	float value;
	double aadhar;
	int u,d=0;

	flag=0;
	FILE *fp;
	fp=fopen("data.txt","r");
	if(fp!=NULL)
	{
	fseek(fp,0,0);
	for(i=0;i<6;i++)
	{
	fscanf(fp,"%lf",&p[i].amount);
	//printf("%lf ",p[i].amount);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%d",&p[i].id);
	//printf("%d ",p[i].id);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%s",p[i].pan);
	//printf("%s ",p[i].pan);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%lf",&p[i].aad);
	//printf("%.0lf ",p[i].aad);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%[^\n]s",p[i].name);
	//printf("%s",p[i].name);
	}

	}
	fclose(fp);
	FILE *fpr;
	fpr=fopen("stock data.txt","r");
	if(fpr!=NULL)
	{
    printf ("\t\t\t\t\t    *******The Available Companies Are ********\n");
	for(i=0;i<10;i++)
	{
		fscanf(fpr,"%s",c[i].name);
		fscanf(fpr,"%d",&c[i].p1);
		fscanf(fpr,"%d",&c[i].p2);
		fscanf(fpr,"%d",&c[i].p3);
		fscanf(fpr,"%d",&c[i].p4);
		fscanf(fpr,"%d",&c[i].p5);
		int z=0;
		while(c[i].name[z]!='\0')
		{
			if(c[i].name[z]=='_')
				putchar(' ');
			else
				putchar(c[i].name[z]);
			z++;
	 	}
		putchar('\n');

	}
	fclose(fpr);
	}

	bh:
    ret:
	printf("\n\nEnter your Name : ");
	fflush(stdin);
	gets(name);
	printf("\nEnter your PAN Number : ");
	gets(pan);
	printf("\nEnter your AADHAR Number : ");
	scanf("%lf",&aadhar);
	x=0;j=0;
	for(i=0;i<6;i++)
	{
		if(strcmp(p[i].pan,pan)==0 && p[i].aad==aadhar)
		{
			point=i;
			j=1;
			printf("\n\n\t\t     ------------------------You have successfully Logged In!!-----------------------------\n");
			printf("\nYour Balance : %.2lf\n",p[i].amount);
			j++;
		}

	}
	if(j==0)
		{
			printf("\nInvalid Data!!\a\nTry Again");
			x=1;
		}
	if(x==1)
	goto bh;
    back:
	printf("\n\n\t\t\t\t\t***** How may I Help You...?? *****\n\n");
	printf("1) Search by Company\n2) Stock Buy\n3) Stock Sell\n4) Graph Analysis\n");

	printf("\nEnter the number according to your choice : ");
	scanf("%d",&q);
switch(q)
	{
		case 1:
			printf("\n\t\t\t\t\t Enter the Company Name : ");
			fflush(stdin);
			gets(cname);
			for(i=0;i<10;i++)
			{int z=0;
			while(cname[z]!='\0')
			{	if(cname[z]==' ')
				{cname[z]='_';
				}
				z++;
			}
			if(strcmp(c[i].name,cname)==0)
				{
					printf("\n\t2018 H\t2017 H\t2016 H\t2015 H\t2014 H\n\n");
					printf("%s\t %d\t%d\t%d\t%d\t%d",c[i].name,c[i].p1,c[i].p2,c[i].p3,c[i].p4,c[i].p5);
					flag=1;
				}
			}
			if(flag==0)
			{
			printf("\nCompany not found in database\n");
			}
    printf("\n\nDo you want to continue?? Type Y for yes and N for no	");
	fflush(stdin);
    scanf("%c",&z);
    if(z=='Y' || z=='y')
    goto back;
    else
    {
            printf("\nDo you want to login again??");
            fflush(stdin);
            scanf("%c",&d);
                if(d=='Y' || d=='y')
                goto ret;
                else
                break;
    }
			break;

		case 2:
			printf("\n\n\t\t     *************************The List of Companies is given below*************************\n\n");
			for(i=0;i<10;i++)
			{
			printf("\t\t\t\t\t\t         -> %s\n",c[i].name);
			}
			printf("\nEnter the Company Name : ");
			fflush(stdin);
			gets(cname);

			for(i=0;i<10;i++)
			{
			if(strcmp(c[i].name,cname)==0)
				{
					printf("\n\t\t\t\t        Buying this will cost you Rs.%d per Stock\n",c[i].p1);
					printf("\n\t\t\t\t\t\t---Your Balance : %lf---\n",p[point].amount);
					printf("\nAre you sure you want to buy this Stock\?\?(type 'y' for yes and 'n' for no)\n");
					scanf("%c",&mn);
					if(mn=='y' || mn=='Y')
					{
					printf("\nHow many Stocks do you want to buy : ");
					scanf("%d",&stock_number);
					value=c[i].p1*stock_number;
					printf("\n\t\t\t\t\t\t*** Total Price : %.2f ***\n",value);
					printf("\n\nYou have successfully bought this Stock!!\n");
					FILE *fp;
					v=0;
					fp=fopen("data.txt","r+");
					if(fp!=NULL)
						{
							if(point==0)
							{
							p[point].amount=p[point].amount-value;
							fprintf(fp,"%.0lf ",p[point].amount);
							//printf("%.0lf",p[point].amount);
							}
							if(point!=0)
							{
							while(v<point)
								{
									fscanf(fp,"%[^\n]s",garbage);
									fseek(fp,2,1);
									v++;
								}
									p[point].amount=p[point].amount-value;
									fprintf(fp,"%.0lf ",p[point].amount);
									//printf("%.0lf",p[point].amount);
							}
						}

					}
					if(mn=='n' || 'N')
                    {
                        printf("\nThank you for visiting");
                        goto back;
                    }
				}
			}
	fseek(fp,0,0);
	for(i=0;i<5;i++)
	{
	fscanf(fp,"%lf",&p[i].amount);
	//printf("%lf ",p[i].amount);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%d",&p[i].id);
	//printf("%d ",p[i].id);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%s",p[i].pan);
	//printf("%s ",p[i].pan);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%lf",&p[i].aad);
	//printf("%.0lf ",p[i].aad);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%[^\n]s",p[i].name);
	//printf("%s",p[i].name);
	}
			fclose(fp);
				printf("Do you want to continue?? Type Y for yes and N for no	");
	fflush(stdin);
    scanf("%c",&z);
    if(z=='Y' || z=='y')
    goto back;
    else
    {
            printf("Do you want to login again??");
            fflush(stdin);
            scanf("%c",&d);
                if(d=='Y' || d=='y')
                goto ret;
                else
                break;
    }

			break;


case 3:
	printf("\n\n\t\t     *************************The List of Companies is given below*************************\n\n");
			for(i=0;i<10;i++)
			{
			printf("\t\t\t\t\t\t         -> %s\n",c[i].name);
			}
			printf("\nEnter the Company Name : ");
			fflush(stdin);
			gets(cname);

			for(i=0;i<10;i++)
			{
			if(strcmp(c[i].name,cname)==0)
				{
					printf("\n\t\t\t\t        You will get Rs.%d per Stock after selling it\n",c[i].p1);
					printf("\n\t\t\t\t\t\t---Your Balance : %lf---\n",p[point].amount);
					printf("\nAre you sure you want to buy this Stock\?\?(type 'y' for yes and 'n' for no)\n");
					scanf("%c",&mn);
					if(mn=='y' || mn=='Y')
					{
					printf("\nHow many Stocks do you want to sell : ");
					scanf("%d",&stock_number);
					value=c[i].p1*stock_number;
					printf("\n\t\t\t\t\t\t*** Total Price : %.2f ***\n",value);
					printf("\nYou have successfully sold this Stock!!\n");
					FILE *fp;
					v=0;
					fp=fopen("data.txt","r+");
					if(fp!=NULL)
						{
							if(point==0)
							{
							p[point].amount=p[point].amount+value;
							fprintf(fp,"%.0lf ",p[point].amount);
							//printf("%.0lf",p[point].amount);
							}
							if(point!=0)
							{
							while(v<point)
								{
									fscanf(fp,"%[^\n]s",garbage);
									fseek(fp,2,1);
									v++;
								}
									p[point].amount=p[point].amount+value;
									fprintf(fp,"%.0lf ",p[point].amount);
									//printf("%.0lf",p[point].amount);
							}
						}

					}
				}
			}
	fseek(fp,0,0);
	for(i=0;i<6;i++)
	{
	fscanf(fp,"%lf",&p[i].amount);
	//printf("%lf ",p[i].amount);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%d",&p[i].id);
	//printf("%d ",p[i].id);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%s",p[i].pan);
	//printf("%s ",p[i].pan);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%lf",&p[i].aad);
	//printf("%.0lf ",p[i].aad);
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%[^\n]s",p[i].name);
	//printf("%s",p[i].name);b
	}
	fclose(fp);
	printf("Do you want to continue?? Type Y for yes and N for no	");
	fflush(stdin);
    scanf("%c",&z);
    if(z=='Y')
    goto back;
    else
    {
            printf("Do you want to login again??");
            fflush(stdin);
            scanf("%c",&d);
                if(d=='Y' || d=='y')
                goto ret;
                else
                break;
    }

	break;

	case 4:
	    printf("\nEnter the Company Name : ");
			fflush(stdin);
			gets(cname);

			if(strcmp(c[0].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("Reliance.jpg",0,0,1000,450);
            getche();
            }

            if(strcmp(c[1].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("Tata.jpg",0,0,1000,450);
            getche();
            }

             if(strcmp(c[2].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("Airtel.jpg",0,0,1000,450);
            getche();
            }

             if(strcmp(c[3].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("ITC.jpg",0,0,1000,450);
            getche();
            }

             if(strcmp(c[4].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("Axis Bank.jpg",0,0,1000,450);
            getche();
            }

             if(strcmp(c[5].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("Maruti.jpg",0,0,1000,450);
            getche();
            }

             if(strcmp(c[6].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("ICICI Bank.jpg",0,0,1000,450);
            getche();
            }

             if(strcmp(c[7].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("Larsen.jpg",0,0,1000,450);
            getche();
            }

             if(strcmp(c[8].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("Bajaj Auto.jpg",0,0,1000,450);
            getche();
            }

             if(strcmp(c[9].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("Infosys.jpg",0,1000,450);
            getche();
            }

             if(strcmp(c[10].name,cname)==0)
            {
            initwindow (1000,450,"graph");
            readimagefile ("NTPC.jpg",0,0,1000,450);
            getche();
            }

            printf("Do you want to continue?? Type Y for yes and N for no	");
	fflush(stdin);
    scanf("%c",&z);
    if(z=='Y')
    goto back;
    else
    {
            printf("Do you want to login again??");
            fflush(stdin);
            scanf("%c",&d);
                if(d=='Y' || d=='y')
                goto ret;
                else
                break;
    }
            break;

            default:
                printf("Invalid Choice");
                goto back;
    }
}
