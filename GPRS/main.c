//
//  main.c
//  GPRS
//
//  Created by 20161104585 on 17/6/22.
//  Copyright © 2017年 20161104585. All rights reserved.
//

#include <stdio.h>
int main()
{
    FILE *fp=fopen("//Users//a20161104585//Desktop//GPRS//GPRS//GPS170510.log", "r");
    int i;
    char g1[63];
    char g2[70];
    char lat[8];
    if(fp==NULL)
    {
        printf("文件读取错误，请检查文件GPS170510.log是否存在!");
    }
    else
    {
        while(fscanf(fp,"%s%s",g1,g2)!=EOF)
        {
            printf("%s\n%s\n",g1,g2);
            for(i=0;i<8;i++)
            {
                lat[i]=g1[i+16];
                //lat[8]='0';
            }
            printf("%s\n",lat);
        }
    }
    fclose(fp);
    return 0;
}
