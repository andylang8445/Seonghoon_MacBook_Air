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
int box_test();

int main()
{
    int vertical_error=0;
    int horizontal_error=0;
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
}

int line_test()
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(cpy[i]==cpy[j])
            {
                return 1;
            }
            else if(cpy[i]>cpy[j])
            {
                int tmp=cpy[i];
                cpy[i]=cpy[j];
                cpy[j]=tmp;
            }
        }
        for(int j=0;j<N;j++)
            if(cpy[j]!=j+1)
                return 1;
    }
    return 0;
}
