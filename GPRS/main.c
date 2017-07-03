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
    FILE *fp1=fopen("//Users//a20161104585//Desktop//GPRS/GPRS//output.csv", "r+");
    int i,a,b,c,d;
    int h1,h2,m1,m2,s1,s2,Y1,Y2,M1,M2,D1,D2;//定义时分秒，年月日
    char g1[63];
    char g2[70];
    char lat[9];//纬度
    char lat1[3];
    char lat2[6];
    char lng[10];//经度
    char lng1[4];
    char lng2[6];
    char day[7];//日期
    char time[7];//时间
    char alt[5];//海拔
    if(fp==NULL)
    {
        printf("文件读取错误，请检查文件GPS170510.log是否存在!");
    }
    else
    {
        while(fscanf(fp,"%s%s",g1,g2)!=EOF)
        {
            printf("%s\n%s\n",g1,g2);
            //输出纬度到屏幕和文件，
            for(i=0;i<8;i++)
            {
                lat[i]=g1[i+16];
                lat[8]='\0';
            }
            lat1[0]=lat[0];
            lat1[1]=lat[1];
            lat2[0]=lat[2];
            lat2[1]=lat[3];
            lat2[2]=lat[5];
            lat2[3]=lat[6];
            lat2[4]=lat[7];
            printf("纬度：%s‘%s\n",lat1,lat2);
            fprintf(fp1,"纬度：%s‘%s,",lat1,lat2);
            
            //输出经度到屏幕和文件，
            for(a=0;a<9;a++)
            {
                lng[a]=g1[a+27];
                lng[9]='\0';
            }
            lng1[0]=lng[0];
            lng1[1]=lng[1];
            lng1[2]=lng[2];
            lng2[0]=lng[3];
            lng2[1]=lng[4];
            lng2[2]=lng[6];
            lng2[3]=lng[7];
            lng2[4]=lng[8];
            printf("经度：%s‘%s\n",lng1,lng2);
            fprintf(fp1,"经度：%s’%s,",lng1,lng2);
            
            //输出日期到屏幕和文件，
            for(b=0;b<6;b++)
            {
                day[b]=g1[b+51];
                day[6]='\0';
            }
            Y1=day[4]-'0';
            Y2=day[5]-'0';
            M1=day[2]-'0';
            M2=day[3]-'0';
            D1=day[0]-'0';
            D2=day[1]-'0';
            printf("日期：%d%d年%d%d月%d%d日\n",Y1,Y2,M1,M2,D1,D2);
            fprintf(fp1,"日期：%d%d年%d%d月%d%d日,",Y1,Y2,M1,M2,D1,D2);
            
            //输出时间到屏幕和文件，
            for(d=0;d<2;d++)
            {
                time[d]=g1[d+7];
                time[2]='\0';
            }
            h1=(time[0]-'0')*10;
            h2=(time[1]-'0')*1+h1+8;
            for(d=0;d<4;d++)
            {
                time[d]=g1[d+9];
                time[4]='\0';
            }
            m1=time[0]-'0';
            m2=time[1]-'0';
            s1=time[2]-'0';
            s2=time[3]-'0';
            printf("时间：%d时%d%d分%d%d秒\n",h2,m1,m2,s1,s2);
            fprintf(fp1,"时间：%d时%d%d分%d%d秒,",h2,m1,m2,s1,s2);
            
            //输出海拔到屏幕和文件，
            for(c=0;c<4;c++)
            {
                alt[c]=g2[c+43];
                alt[4]='\0';
            }
            printf("海拔：%sm\n",alt);
            fprintf(fp1,"海拔：%sm\n",alt);
        }
    }
    fclose(fp);
    return 0;
}
