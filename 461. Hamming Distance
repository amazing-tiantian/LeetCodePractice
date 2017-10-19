/* 461. Hamming Distance */
/* Oct. 18th, 2017 */
/* 指针定义格式：1.对于函数应如"int * func()"，对于变量应如"int *p"*/
/* 本题解决过程中遇到toBinary()函数不能正常返回对应数组的问题，随即查阅相关文档发现在定义数组变量时若在自定义函数中按照常规方式定义（如int arr[N]）则会导致该函数生命周期结束时系统自动回收分配给该数组变量的内存。而后在定义变量时加入static关键字，发现输入不同参数会返回相同结果，原因或可能是此方式下为变量所分配的内存为同一块。进一步查阅相关资料，了解到可通过定义一个指针后手动分配空间，并将该指针指向所分配空间的首地址，开始使用的是malloc()函数，仍然会出现前面提到的问题，后来使用calloc()函数分配内存空间问题解决。具体原因尚不明*/
#include <stdio.h>
#include <stdlib.h>
#define N 32

int * toBinary(int n);
int hammingDistance(int x, int y);

int main() {
   	int x, y;
   	int n;
   	printf("enter x:\n");
   	scanf("%d", &x);
   	printf("enter y:\n");
   	scanf("%d", &y);
   	n = hammingDistance(x, y);
   	printf("the hammingDistance of %d and %d is %d!\n", x, y, n);
    return 0;
}

int * toBinary(int n){
	// static int n_bin[N]; 此处若不用static在该函数生命周期终止后便会被系统回收，导致返回值错乱
	int *n_bin;
	n_bin = calloc(N, sizeof(int));
   	int p = N - 1;
   	for(int i = 0; i < N; i++){
   		n_bin[i] = 0;
   	}
   	int quotient = -1, remainder;
   	while(quotient != 0){
   		quotient = n / 2;
   		// printf("quotient=%d\n", quotient);
   		remainder = n % 2;
   		n_bin[p] = remainder;
   		p--;
   		printf("remainder=%d\n", remainder);
   		n = quotient;
   	}
   	// for(int i = 0;i < N; i++){
   	// 	if(i == N - 1){
   	// 		printf("remainder=%d\n", n_bin[i]);
   	// 	}else{
   	// 		printf("remainder=%d, ", n_bin[i]);
   	// 	}
   	// }
   	return n_bin;
}

int hammingDistance(int x, int y){
	int *x_bin;
	int *y_bin;
	int hammingDistance = 0;
	x_bin = toBinary(x);
	y_bin = toBinary(y);
	for(int i = 0;i < N; i++){
		printf("x=%d, y=%d\n", x_bin[i], y_bin[i]);
		if(x_bin[i] != y_bin[i]){
			hammingDistance ++;
		}
	}
	return hammingDistance;
}
