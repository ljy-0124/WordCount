#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <io.h>
int cword = 0;
int cchar = 0;	
int aword=0;
int countw(char *file)//统计单词的个数
{   FILE *f;
	char ch;
	f=fopen(file,"r");
	if(NULL==(f=fopen(file,"r")))
    {
     printf("file is NULL");
    }
    else
	while(!feof(f))
	{
		ch=fgetc(f);
		if((ch >= 'a'&&ch <= 'z')||(ch>='A'&&ch<='Z')||ch=='_')
		aword=1;
	else if (aword)
	{
		cword++;
    	aword=0;
	}
	}
	fclose(f); 
	printf("单词个数:%d ",cword);
	return 0;
}
int countc(char *file) //统计字符的个数 
{ 
	FILE *f;
	char a;
	f = fopen(file, "r");
	if(NULL==(f=fopen(file,"r")))
    {
	    printf("file is NULL");
	}
    else
	while (!feof(f))
	{
		a=fgetc(f);
        if (a != ' '&&a != '\n'&&a != '\t')
		cchar++;

	}
	fclose(f);
	printf("字符个数:%d ",cchar);
		return 0;
}



int searchfile(void) //寻找文件夹中的txt文件
{
    struct _finddata_t filefind;
    long handle;
    int t=0;
       if( (handle=_findfirst( "H:\\wordcount\\test\\*txt", &filefind)) == -1L ) 
        {
        printf( "没找到txt文件\n");
        }
    else
	do{
		t++;
        printf("找到文件:%s\n", filefind.name); 
    }while (_findnext(handle,&filefind)==0);
	_findclose(handle);
	printf("txt文件数量：%d\n",t);
	 return 0;
}

int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("FileNull\n\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(!strcmp(argv[1],"-w")) 
		countw(argv[2]);                
        else if(!strcmp(argv[1],"-c"))  
		countc(argv[2]);                
		else
            printf("NullPoint\n");

        printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}
	return 0;
}
