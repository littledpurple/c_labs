#include <stdio.h>
#include <math.h>

int main()
{
	float a[5],b[5],c[5],x1[5],x2[5],d[5];
	int i, numb;
	int symcount = 20;
	for(i=0; i<6; i++)
	{
		numb = i+1;
		printf("Enter a%d, b%d, c%d\n",numb,numb,numb);
		scanf("%f %f %f",&a[i],&b[i],&c[i]);
		printf("You have entered: a%d=%.2f, b%d=%.2f, c%d=%.2f\n",numb,a[i],numb,b[i],numb,c[i]);
	}
	
	printf("%c", 201);
	
	for(i=0; i < symcount; i++)
	{
		printf("%c",205);	
	}
	
	printf("%c \n", 187);
	printf("%c N %c\ta\t%c\tb\t%c\tc\t%c x1, x2\t\t%c",187,187,187,187,187,187);
	printf("%c \n", 220);
	
	for(i=0; i < symcount; i++)
	{
		printf("%c",205);	
	}
	
	printf("%c \n", 185);
	
	for(i=0; i<6; i++)
	{
		numb = i+1;
		if(a[i]==0)
		{
			if(b[i]==0)
			{
				if(c[i]==0){
					printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c x - any\t\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,186);
					}else{
					printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c x - empty set\t\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,186);
					}
			}else{
				if(c[i]==0){
				printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c x=0\t\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,186);
				}else{
					x1[i] = -c[i]/b[i];
					printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c x1=%.2f\t\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,x1[i],186);
					}}
		}else{
		if(b[i]==0){
			if(c[i]==0){
				printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c x=0\t\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,186);
				}else{
					if(-c[i]/a[i] > 0){
						x1[i]=sqrt(-c[i]/a[i]);
						x2[i]=x1[i];
						printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c x1=x2=%.2f\t\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,x1[i],186);
						}else{
							printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c complex number\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,186);
							}	
					}
			}else{
				if(c[i] == 0){
					x1[i] = 0;
					x2[i] = -b[i]/a[i];
					printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c x1=%.2f, x2=%.2f\t\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,x1[i],x2[i],186);
					}else{
						d[i]=(b[i]*b[i])-4*a[i]*c[i];
						if(d[i] > 0){
							x1[i] = (-b[i]+sqrt(d[i]))/(2*a[i]);
							x2[i] = (-b[i]-sqrt(d[i]))/(2*a[i]);
							printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c x1=%.2f, x2=%.2f\t\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,x1[i],x2[i],186);
							}else{
								if(d == 0){
									x1[i] = -b[i]/(2*a[i]);
									x2[i] = x1[i];
									printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c x1=x2=%.2f\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,x1[i],186);
									}else{
										printf("%c %d %c\t%.2f\t%c\t%.2f\t%c\t%.2f\t%c complex number\t%c\n",186,numb,186,a[i],186,b[i],186,c[i],186,186);
										}
								}
						}
				}
		}
	}
	
	printf("%c", 200);
	for(i=0; i < symcount; i++)
	{
		printf("%c",205);	
	}
	printf("%c \n", 188);
}                                                                            
