#include <stdio.h>

#define N	(sizeof(int)*8)

void simple_convert(int n, unsigned char c[]);
void reverse(unsigned char c[]);
void first_exe(int n ,unsigned char c[]);
void second_exe(int n ,unsigned char c[]);
void third_exe(int n ,unsigned char c[]);
void fourth_exe(int n,int change ,unsigned char c[]);
void print(unsigned char c[]);


void first_exe(int n ,unsigned char c[]){
	simple_convert(n,c);
	reverse(c);
}

void second_exe(int n ,unsigned char c[]){
	n*=-1;
	simple_convert(n,c);
	for (int i=0; i < N;i++){		//inversion
		c[i]=!c[i];
	}
	c[0]++;					//add 1 to the number
	for (int i=0; i<N-1;i++){
		if(c[i]==2){
			c[i]=0;
			c[i+1]++;
		}
	}
	reverse(c);
	c[0]=1;
}

void third_exe(int n ,unsigned char c[]){
	if(n<0){
		second_exe(n,c);
	}else{
		first_exe(n,c);
	}

	int counter=0;
	for(int i=0;i<N;i++){
		counter+=c[i];
	}

	printf("%d x\"1\" \n",counter);
}

void fourth_exe(int n,int change ,unsigned char c[]){
	printf("from: %d\n", n);
	if(n<0){
		second_exe(n,c);
	}else{
		first_exe(n,c);
	}
	print(c);

	change=change<<(2*8);
	n = change | n;
	simple_convert(n,c);
	reverse(c);
	
	printf("we have: %d\n", n);
}

int main(){
	char var=0;
	int n;
	unsigned char c[sizeof(n)*8];
	while(var!=5){
	printf("Choose the exercise number:\n");
	printf("1 - positive number into binary\n");
	printf("2 - negative number into binary\n");
	printf("3 - how many zeros in bin form\n");
	printf("4 - change thid bit in number whatewer you want\n");
	printf("5 - quit the program\n\n");
	scanf("%d",&var);
		switch(var){
		case 1:
			printf("Input number to convert:\n");
			scanf("%d",&n);
			if(n>=0){
				first_exe(n,c);}
			else{
				printf("It's not positive number, but that's convertation: \n");
				second_exe(n,c);}
			print(c);
			break;
		case 2:
			printf("Input number to convert:\n");
			scanf("%d",&n);
			if(n<0)
				second_exe(n,c);
			else{
				printf("It's not negative number, but that's convertation: \n");
				first_exe(n,c);}
			print(c);
			break;
		case 3:
			printf("Input number to calculate zeros in bin form:\n");
			scanf("%d",&n);
			third_exe(n,c);
			break;
		case 4:
			printf("Input number where change the third byte:\n");
			scanf("%d",&n);
			printf("Type number in range from 0 to 255\n");
			int change;
			scanf("%d",&change);
			while(change>255||change<0){
				printf("It doesn't expected, number in range from 0 to 255\n");
				scanf("%d",&change);
			}
			fourth_exe(n,change,c);
			print(c);
			break;
		default:
			var=5;
			break;
		}
	}	
	
}

void simple_convert(int n, unsigned char c[]){
	for (int i=0; i < N;i++){
		c[i]=0;
	}
	int counter=0;
	while(n>0){
		c[counter]=n&0x1;
		n=n>>1;
		counter++;
	}
}

void reverse(unsigned char c[]){
	unsigned char bucket;
	for(int i=0;i<(N/2);i++){
		bucket=c[i];
		c[i]=c[N-i-1];
		c[N-i-1]=bucket;
	}
}

void print(unsigned char c[]){
	unsigned char counter = 0;
	for (int i=0; i<N;i++){
		counter++;
		printf("%d",c[i]);
		if(counter==8){
			printf(" ");
			counter=0;
		}
	}
	printf("\n");
}


