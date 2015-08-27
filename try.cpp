#include<stdio.h>
#include<string.h>
#include<math.h>

struct home
{
	char mon[10];
	char id[5];
	char acc_no [50];
	char meter_no [50];

	char name [50];

	double home_rent;
	double gas_bill;
	double water_bill;
	double electric_bill;
};

struct home bill[50];

void cal(char j[]);

void print_1();
void print_2(double s);

void electricity();


void file_print(double sum);

double first_unit(double bil);
double second_unit();
double third_unit(double bil);
double forth_unit(double bil);
double fifth_unit(double bil);


char i[20],d1[20],d2[20],month[20];
char ch='y';
int p,k,m,n;
double sum=0,unit=0,a,b,c,d,bil,charge,u,q;

int main()
{

	while (ch!='n')
	{
		printf ("\nWhich side do you want to calculate?\n\n");
		printf ("ID 		Name\n");
		printf ("----		--------\n\n");
		printf ("1.1		Sajarunl\n");
		printf ("1.2		Anisha\n");
		printf ("3.1		Jim\n");
		printf ("3.2		Sobuj\n");
		printf ("5.0		Anita\n\n");

		printf ("Your ans : ");
		scanf("%s", i);

		printf("\n Which month: ");
		scanf("%s",month);

		cal(i);

		printf ("\n Do you want to calculate?");
		printf ("\n\n Press 'Y' for yes and 'N' for no\n\n");
		printf ("Your ans : ");
		scanf("%s",&ch);


        return 0;
	}

}


void cal(char j[])
{
	FILE *fp;
		p=0;
		fp=fopen("File2.txt","r");
		while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %s %lf %lf %lf", bill[p].id,
												 bill[p].acc_no,
												 bill[p].meter_no,
												 bill[p].name,
												 &bill[p].home_rent,
												 &bill[p].gas_bill,
												 &bill[p].water_bill);

			p++;
		}

		fclose(fp);

		for(k=0;k<5;k++)
		{
			m=strcmp(bill[k].id,j);
			n=strcmp(bill[k].name,j);

			if(	m==0 || n==0)
			{
				if(k==0)
				{
					print_1();

					printf("\n\n For electric bill.........");
					printf("\n\n In main meter ------------");

					electricity();

					q=unit;

					printf("\n\n In su-meter -------------");

					printf("\n\n Current unit: ");
					scanf("%lf",&c);
					printf("\n Previous Unit: ");
					scanf("%lf",&d);

					u=fabs(c-d);
					printf("\n Uses unit in sub-meter: %.2lf",u);

					unit=unit-u;

					printf("\n\n Total uses unit: %.2lf",unit);

					printf("\n\n Total Electric bill: ");
					scanf("%lf",&bil);

					charge= bil/q;
					printf("\n Per unit charge: %.2lf",charge);

					bil=charge*unit;


					first_unit(bil);

				}

				if(k==1)
				{
					print_1();

					printf("\n\n For electric bill.........");
					printf("\n--------------------------------");
					printf("\n\n In submeter...");

					electricity();

					printf("\n\n Total Electric bill: ");
					scanf("%lf",&bil);

					printf("\n Total uses unit: ");
					scanf("%lf",&u);

					charge=(bil/u);

					printf("\n Per unit charge: %lf",charge);

					bil=charge*unit;

					second_unit();
				}

				if(k==2)
				{
					print_1();
					printf("\n\n For electric bill.........");
					printf("\n--------------------------------");

					electricity();

					printf("\n\n Electric bill: ");
					scanf("%lf",&bil);


					third_unit(bil);
				}

				if(k==3)
				{
					print_1();
					printf("\n\n For electric bill.........");
					printf("\n--------------------------------");

					electricity();

					printf("\n\n Electric bill: ");
					scanf("%lf",&bil);

					forth_unit(bil);
				}

				if(k==4)
				{
					print_1();
					printf("\n\n For electric bill.........");
					printf("\n--------------------------------");

					electricity();

					printf("\n\n Electric bill: ");
					scanf("%lf",&bil);

					fifth_unit(bil);
				}


			}
		}
}


void print_1()
{

	printf("\n\n");
	printf("\n Month : %s",month);
	printf("\n\n Id	 : %s",bill[k].id);


	printf("\n %s",bill[k].acc_no);
	printf("\n %s",bill[k].meter_no);
	printf("\n %s",bill[k].name);
}

void print_2(double s)
{

	printf("\n\n Home rent	=%.2lf",bill[k].home_rent);
	printf("\n Gas Bill	=%.2lf",bill[k].gas_bill);
	printf("\n Water Bill	=%.2lf",bill[k].water_bill);
	printf("\n Electric Bill=%.2lf",bill[k].electric_bill);
	printf("\n\n Total amount=%.2lf",s);

	printf("\n\n");
}

void electricity()
{
	printf("\n Current date : ");
	scanf("%s",&d1);

	printf("\n Previous date : ");
	scanf("%s",&d2);

	printf("\n Current unit : ");
	scanf("%lf",&a);

	printf("\n Previous unit : ");
	scanf("%lf",&b);


	unit=fabs(a-b);

	printf("\n\n Uses unit : %.2lf ",unit);

}


double first_unit(double bil)
{

	bill[k].electric_bill=bil;

	sum=0;

	sum= bill[k].home_rent + bill[k].gas_bill + bill[k].water_bill + bill[k].electric_bill;


	FILE *fp1;
	fp1=fopen("Sajarul.txt","w+");

	fprintf(fp1,"\n Month	 : %s",month);
	fprintf(fp1,"\n\n ID   : %s",bill[k].id);
	fprintf(fp1,"\n%s",bill[k].acc_no);
	fprintf(fp1,"\n%s",bill[k].meter_no);
	fprintf(fp1,"\n\n%s",bill[k].name);

	fprintf(fp1,"\n\n For Electric bill.........");
	fprintf(fp1,"\n--------------------------------");

	fprintf(fp1,"\n\n Current date :%s ",d1);
	fprintf(fp1,"\n Previous date  :%s ",d2);

	fprintf(fp1,"\n\n Current unit :%.2lf ",a);
	fprintf(fp1,"\n Previous unit  :%.2lf ",b);


	fprintf(fp1,"\n\n   Unit in main meter : %.2lf",q);
	fprintf(fp1,"\n(-) Unit in sub-meter   : %.2lf",u);
	fprintf(fp1,"\n--------------------------------------------");
	fprintf(fp1,"\n Your Uses unit         : %.2lf",unit);

	fprintf(fp1,"\n Per unit charge        : %.2lf",charge);

	fprintf(fp1,"\n Total Bill: ");
	fprintf(fp1,"\n ..........................");

	fprintf(fp1,"\n\n Home Rent	: %.2lf",bill[k].home_rent);
	fprintf(fp1,"\n Gas Bill		: %.2lf",bill[k].gas_bill);
	fprintf(fp1,"\n Water Bill		: %.2lf",bill[k].water_bill);
	fprintf(fp1,"\n Electric Bill	: %.2lf",bill[k].electric_bill);


	fprintf(fp1, "\n\n Total amount	: %.2lf",sum);

	fprintf(fp1,"\n\n\n\n\n\n-----------------------------------------------");
	fprintf(fp1,"\n   Signature of Home Owner");

	fclose(fp1);

	print_2(sum);

	return 0;


}


double second_unit()
{

	bill[k].electric_bill=bil;

	sum=0;

	sum= bill[k].home_rent + bill[k].gas_bill + bill[k].water_bill + bill[k].electric_bill;


	FILE *fp1;
	fp1=fopen("Anisha.txt","w+");


	fprintf(fp1,"\n Month	: %s",month);
	fprintf(fp1,"\n\n ID	: %s",bill[k].id);
	fprintf(fp1,"\n%s",bill[k].acc_no);
	fprintf(fp1,"\n%s",bill[k].meter_no);
	fprintf(fp1,"\n\n %s",bill[k].name);

	fprintf(fp1,"\n\n For Electric Bill.........");
	fprintf(fp1,"\n--------------------------------");

	fprintf(fp1,"\n\n Current date	: %s ",d1);
	fprintf(fp1,"\n Previous date	: %s ",d2);

	fprintf(fp1,"\n\n Current unit	: %lf ",a);
	fprintf(fp1,"\n Previous unit	: %lf ",b);
	fprintf(fp1,"\n Uses unit		: %.2lf",unit);
	fprintf(fp1,"\n Per unit charge	: %lf",charge);


	fprintf(fp1,"\n\n Total Bill: ");
	fprintf(fp1,"\n ..........................");

	fprintf(fp1,"\n\n Home Rent	: %.2lf",bill[k].home_rent);
	fprintf(fp1,"\n Gas Bill		: %.2lf",bill[k].gas_bill);
	fprintf(fp1,"\n Water Bill		: %.2lf",bill[k].water_bill);
	fprintf(fp1,"\n Electric Bill	: %.2lf",bill[k].electric_bill);


	fprintf(fp1, "\n\n Total amount	: %.2lf",sum);

	fprintf(fp1,"\n\n\n\n\n\n-----------------------------------------------");
	fprintf(fp1,"\n   Signature of Home Owner");

	fclose(fp1);

	print_2(sum);

	return 0;



}


double third_unit(double bil)
{

	bill[k].electric_bill=bil;

	sum=0;

	sum= bill[k].home_rent + bill[k].gas_bill + bill[k].water_bill + bill[k].electric_bill;


	FILE *fp1;
	fp1=fopen("Jim.txt","w+");


	fprintf(fp1,"\n Month	 : %s",month);
	fprintf(fp1,"\n\n ID	: %s",bill[k].id);
	fprintf(fp1,"\n %s",bill[k].acc_no);
	fprintf(fp1,"\n %s",bill[k].meter_no);
	fprintf(fp1,"\n\n %s",bill[k].name);

	fprintf(fp1,"\n\n For Electric Bill.........");
	fprintf(fp1,"\n--------------------------------");

	fprintf(fp1,"\n\n Current date	: %s",d1);
	fprintf(fp1,"\n Previous date	: %s",d2);

	fprintf(fp1,"\n\n Current unit	: %.2lf ",a);
	fprintf(fp1,"\n Previous unit	: %.2lf",b);
	fprintf(fp1,"\n Uses unit		: %.2lf",unit);


	fprintf(fp1,"\n\n Total Bill: ");
	fprintf(fp1,"\n ..........................");

	fprintf(fp1,"\n\n Home Rent	: %.2lf",bill[k].home_rent);
	fprintf(fp1,"\n Gas Bill		: %.2lf",bill[k].gas_bill);
	fprintf(fp1,"\n Water Bill		: %.2lf",bill[k].water_bill);
	fprintf(fp1,"\n Electric Bill	: %.2lf",bill[k].electric_bill);


	fprintf(fp1, "\n\n Total amount	: %.2lf",sum);

	fprintf(fp1,"\n\n\n\n\n\n-----------------------------------------------");
	fprintf(fp1,"\n   Signature of Home Owner");

	fclose(fp1);

	print_2(sum);

	return 0;


}


double forth_unit(double bil)
{


	bill[k].electric_bill=bil;

	sum=0;

	sum= bill[k].home_rent + bill[k].gas_bill + bill[k].water_bill + bill[k].electric_bill;


	FILE *fp1;
	fp1=fopen("Sobuj.txt","w+");


	fprintf(fp1,"\n Month	 : %s",month);
	fprintf(fp1,"\n\n ID	: %s",bill[k].id);
	fprintf(fp1,"\n %s",bill[k].acc_no);
	fprintf(fp1,"\n %s",bill[k].meter_no);
	fprintf(fp1,"\n\n %s",bill[k].name);

	fprintf(fp1,"\n\n For Electric Bill.........");
	fprintf(fp1,"\n--------------------------------");

	fprintf(fp1,"\n\n Current date	: %s",d1);
	fprintf(fp1,"\n Previous date	: %s",d2);

	fprintf(fp1,"\n\n Current unit	: %.2lf ",a);
	fprintf(fp1,"\n Previous unit	: %.2lf",b);
	fprintf(fp1,"\n Uses unit		: %.2lf",unit);


	fprintf(fp1,"\n\n Total Bill: ");
	fprintf(fp1,"\n ..........................");

	fprintf(fp1,"\n\n Home Rent	: %.2lf",bill[k].home_rent);
	fprintf(fp1,"\n Gas Bill		: %.2lf",bill[k].gas_bill);
	fprintf(fp1,"\n Water Bill		: %.2lf",bill[k].water_bill);
	fprintf(fp1,"\n Electric Bill	: %.2lf",bill[k].electric_bill);

	fprintf(fp1, "\n\n Total amount	: %.2lf",sum);

	fprintf(fp1,"\n\n\n\n\n\n-----------------------------------------------");
	fprintf(fp1,"\n   Signature of Home Owner");

	fclose(fp1);

	print_2(sum);

	return 0;

}


double fifth_unit(double bil)
{

	bill[k].electric_bill=bil;

	sum=0;

	sum= bill[k].home_rent + bill[k].gas_bill + bill[k].water_bill + bill[k].electric_bill;


	FILE *fp1;
	fp1=fopen("Anita.txt","w+");


	fprintf(fp1,"\n Month	 : %s",month);
	fprintf(fp1,"\n\n ID	: %s",bill[k].id);
	fprintf(fp1,"\n %s",bill[k].acc_no);
	fprintf(fp1,"\n %s",bill[k].meter_no);
	fprintf(fp1,"\n\n %s",bill[k].name);

	fprintf(fp1,"\n\n For Electric Bill.........");
	fprintf(fp1,"\n--------------------------------");

	fprintf(fp1,"\n\n Current date	: %s",d1);
	fprintf(fp1,"\n Previous date	: %s",d2);

	fprintf(fp1,"\n\n Current unit	: %.2lf ",a);
	fprintf(fp1,"\n Previous unit	: %.2lf",b);
	fprintf(fp1,"\n Uses unit		: %.2lf",unit);


	fprintf(fp1,"\n\n Total Bill: ");
	fprintf(fp1,"\n ..........................");

	fprintf(fp1,"\n\n Home Rent	: %.2lf",bill[k].home_rent);
	fprintf(fp1,"\n Gas Bill		: %.2lf",bill[k].gas_bill);
	fprintf(fp1,"\n Water Bill		: %.2lf",bill[k].water_bill);
	fprintf(fp1,"\n Electric Bill	: %.2lf",bill[k].electric_bill);


	fprintf(fp1, "\n\n Total amount	: %.2lf",sum);

	fprintf(fp1,"\n\n\n\n\n\n-----------------------------------------------");
	fprintf(fp1,"\n   Signature of Home Owner");

	fclose(fp1);

	print_2(sum);

	return 0;


}
