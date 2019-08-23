//熄灯问题,问题要求：对矩阵中每盏灯设置一个初始状态，写一个程序确定需要按下哪些按钮，恰好是的所有的灯都熄灭
//详情：https://www.bilibili.com/video/av10046345/?p=4
//用一个矩阵puzzle[5][6]表示灯的初始状态
//puzzle[i][j]等于0或者1，表示灯熄灭或者点亮
//用一个矩阵press[5][6]表示要计算的结果
//press[i][j]=0或者1，表示需要按下或者不按下（i,j）
#include<stdio.h>
#include <stdlib.h>
int puzzle[6][8],press[6][8];
bool guess(){
    int c,r;
    for(r=1;r<5;r++)
        for(c=1; c<7; c++)
            press[r+1][c] = (puzzle[r][c]+press[r][c]+press[r-1][c]+press[r][c-1]+press[r][c+1]) % 2;
    for(c=1; c<7; c++)
        if ((press[5][c-1] + press[5][c] + press[5][c+1] + press[4][c]) %2 != press[5][c])//判断所计算的press数组能否熄灭地5行的所有灯
        return(false);
    return(true);
}
void enumerate(){
    int c;
    bool success;
    for (c=1;c<7;c++)
        press[1][c] = 0;
    while(guess() == false){  //while语句中的作用：对press第1行的元素
        press[1][1]++;        //press[1][1]~press[1][6]的各种取值情况
        c=1;                  //各种取值情况进行枚举；
        while (press[1][c]>1)
        {
            press[1][c] = 0;
            c++;
            press[1][c]++;     //进位操作
        }       
    }
    return;
}

int main(){
    int cases,i,r,c;
    scanf("%d",&cases);
    for (r=0;r<6;r++)
        press[r][0] = press[r][7] = 0;
    for (c=1;r<7;r++)
        press[0][c] = 0;
    for (i=0;i<cases;i++){
        for (r=1;r<6;r++)
            for(c=1;c<7;c++)
                scanf("%d",&puzzle[r][c]);
        enumerate();
        printf("PUZZLE#%d\n",i+1);
        for(r=1;r<6;r++){
            for(c=1;c<7;c++)
                printf("%d", press[r][c]);
            printf("\n");
        }   
    }
    system( "PAUSE "); 
    return 0;
    
}