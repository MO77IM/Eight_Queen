#include <stdio.h>
#include <math.h>
#define SIZE 8
int amount=0;
int table[SIZE]={0};
bool check_row(int table[],int i);
bool check_across(int table[],int i);
void find(int table[],int i);
int main(void){
    find(table,0);
    return 0;
} 
bool check_row(int table[],int i){
	int count=0;
	for(int j=0;j<SIZE;++j)
	{
		if(table[j]==table[i])
		  count++;
	}
	return (count<2);
}
bool check_across(int table[],int i){
	int count=0;
	for(int j=0;j<SIZE;j++)
	{
		if(table[j]!=0&&((i-j)==(table[i]-table[j])||(i-j)==(table[j]-table[i])))
	      count++;
	}
	return (count<2);
}
void find(int table[],int i){
	if(i>=SIZE)
	{
		for(int k=0;k<SIZE;k++)
		  {
		  for(int j=1;j<=SIZE;j++)
          {
          	if(table[k]==j)
          	  printf("1 ");
          	else
          	  printf("0 ");
		  }
		  putchar('\n');
	      }
	      putchar('\n');
	    for(int j=0;j<SIZE;j++)
	      printf("%d ",table[j]);
	    putchar('\n');
	    putchar('\n');
		amount++;
		return;
	}
	for(int j=1;j<=SIZE;j++)
	{
		table[i]=j;
		if(check_row(table,i)&&check_across(table,i))
		  find(table,i+1);
	}
	table[i]=0;
	return;
}
