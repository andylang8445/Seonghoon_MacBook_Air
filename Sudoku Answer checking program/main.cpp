//
//  main.cpp
//  Sudoku Answer checking program
//
//  Created by HongjunYun on 2019-03-02.
//  Copyright © 2019 HongjunYun. All rights reserved.
//

#include <stdio.h>
#define N 9

int cpy[N];
int map[N][N];
int line_test();

int main()
{
    int vertical_error=0;
    int horizontal_error=0;
    int box_error=0;
    int cpy_cnt=0;
    printf("Test\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&map[i][j]);
            cpy[j]=map[i][j];
        }
        vertical_error+=line_test();
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cpy[j]=map[j][i];
        }
        horizontal_error+=line_test();
    }
    for(int i=0;i<=6;i+=3)
    {
        for(int j=0;j<=6;j+=3)
        {
            for(int x=i;x<i+3;x++)
                for(int y=j;y<j+3;y++)
                    cpy[cpy_cnt++]=map[x][y];
            cpy_cnt=0;
            box_error+=line_test();
        }
    }
    
    printf("Vertical error: %d\nHorizontal error: %d\nBox error: %d\n----------------\nTotal error count: %d\n",vertical_error,horizontal_error,box_error,(vertical_error+horizontal_error+box_error));
}
int line_test()
{
    int tmp;
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(cpy[i]==cpy[j])
            {
                printf("p\n");
                return 1;
            }
            else if(cpy[i]>cpy[j])
            {
                tmp=cpy[i];
                cpy[i]=cpy[j];
                cpy[j]=tmp;
            }
        }
    }
    for(int i=0;i<N;i++)
        if(cpy[i]!=i+1)
            return 1;
    return 0;
}

/*
#include<stdio.h>
int organ[9];
int arrange()
{
    int tmp;
    for(int i=0;i<8;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(organ[i]>organ[j])
            {
                tmp=organ[i];
                organ[i]=organ[j];
                organ[j]=tmp;
            }
        }
    }
    for(int i=0;i<9;i++)
    {
        if(organ[i]!=i+1)
            return 1;
    }
    return 0;
}
int main()
{
    int error[9][2];
    int x,y;
    int map[9][9];
    int num=0;
    int cnt=0;
    int cntx=0,cnty=0,cnts=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            organ[j]=map[i][j];
        error[cntx][0]=i+1;
        cntx+=arrange();
        for(int j=0;j<9;j++)
            organ[j]=map[j][i];
        error[cnty][1]=i+1;
        cnty+=arrange();
    }
    for(int i=0;i<=6;i+=3)
    {
        for(int j=0;j<=6;j+=3)
        {
            for(x=i;x<i+3;x++)
                for(y=j;y<j+3;y++)
                    organ[num++]=map[x][y];
            num=0;
            cnts=arrange();
        }
    }
    cnt=cntx+cnty+cnts;
    printf("Vertical Line: %d error lines\nHorizontal line: %d error lines\nSection line: %d error sections\n",cnty,cntx,cnts);
    if(cntx>0)
        printf("Error locations: \n");
    for(int i=0;i<cntx;i++)
        printf("\t(%d,%d)\n",error[i][0],error[i][1]);
    printf("----------------------\nTotal error count: %d",cnt);
}
*/
