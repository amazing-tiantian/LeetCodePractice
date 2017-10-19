/* 657. Judge Route Circle */
/* Oct. 19th, 2017 */
/* gets()与fgets()区别：gets()会将所有输入字符读取到数组，存在内存越界的可能；fgets()指定输入字符大小相对安全。 */
/* 访问结构体成员变量.与->区别：结构体变量的引用和赋值，有两种形式，一种是用符号”.”，一种是用符号”->”。结构体指针变量一般用”->”，非结构体指针变量，也就是一般结构体变量，一般用”.”。*/
typedef int bool; // C中没有布尔型，需要自行定义
#define true 1	// 同上
#define false 0	// 同上
#include <stdio.h>
#define N 50

bool judgeCircle(char* moves);
int getLength(char* str);

typedef struct coord{
	int x;
	int y;
}coord;

int main(int argc, char const *argv[])
{
	/* code */
	int j;
	char moves[N]; 
	printf("enter moves:");
	gets(moves);
	j = judgeCircle(moves);
	printf("answer is %d!\n", j);
	return 0;
}

bool judgeCircle(char* moves){
	coord c;
	c.x = 0;
	c.y = 0;
	for(int i = 0; moves[i] != '\0'; i++){
		switch(moves[i]){
			case 'R': c.x ++; break;  //""适用于字符串，''适用于单个字符
			case 'L': c.x --; break;
			case 'U': c.y ++; break;
			case 'D': c.y --; break;
			default: break;			  //此处开始忘记填写默认情况
		}
	}
	if(c.x == 0 && c.y == 0){
		return true;
	}else{
		return false;
	}
}

int getLength(char* str){
	int n = 0;
	for(int i = 0; str[i] != '\0'; i++){
		n ++;
	}
	return n;
} 
