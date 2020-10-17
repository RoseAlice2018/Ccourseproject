#ifndef OPTION1_H_INCLUDED
#define OPTION1_H_INCLUDED

void getpassword()
{
	print();
	printf("\n\n\t\t\t\t  请输入密码：");
	char password[30];
	scanf("%s",password);
	if(!strcmp(password,"123456"))
	{
		option();
	}
	else
	{
		printf("\n\t\t\t\t  密码错误，请重新输入");
		Sleep(1200);
		getpassword();
	}
}
void getregi()
{
	char patID[30];
	/*******系统时间*******/ 
	time_t T;
	struct tm*p;
	time(&T);
	p=localtime(&T);
    /**********************/
    if(p->tm_hour==0&&p->tm_min==0)
    {
    	regicount=0;
	}
	print();
	printf("\n");
	/**输出医生信息**/
	char ch[50];
	char chID[20][50];
	int index=0; 
	FILE *fp=fopen("docterregi.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			fscanf(fp,"%s",ch);
			printf("\t%-16s",ch);
			
			fscanf(fp,"%s",ch);
			printf("%-16s",ch);
			
			fscanf(fp,"%s",ch);
			printf("%-16s",ch);
			
			fscanf(fp,"%s",chID[index]);
			printf("%-16s",chID[index++]);
			
			fscanf(fp,"%s",ch);
			printf("%-16s\n\n",ch);
			
		}
	}
	fclose(fp);
	
	printf("\n\n\t\t\t\t 您选择的医生工号为：");
	char tempID[50];
	scanf("%s",tempID);
	/**校验**/ 
	for(int i=0;i<index;i++)
	{
		if(!strcmp(tempID,chID[i]))
			break;
		if(i==index-1)
		{
			printf("\n\t\t\t\t 您选择的医生不存在，请重新输入");
			Sleep(1200);
			getregi();
		}
	}
	regicount++;
	int m=p->tm_mon+1;
	int d=p->tm_mday;
	patID[0]=m/10+'0';
	patID[1]=m%10+'0';
	patID[2]=d/10+'0';
	patID[3]=d%10+'0';
	patID[4]=regicount/100+'0';
	patID[5]=(regicount/10)%10+'0';
	patID[6]=regicount%10+'0';
	for(int i=0;i<strlen(tempID);i++)
	{
		patID[7+i]=tempID[i];
	}
	printf("\n\t\t\t\t 您的挂号为：%s",patID);
	printf("\n\n\t\t\t\t ");
	system("pause");
	option1_2(); 
}
void regiinqu()
{
	print();
	printf("\n");
	printf("\t\t\t\t     请输入您的挂号\n");
	char tempID[30];
	scanf("%s",tempID);
	MedicalRecords* temp=records->next;
	while(temp!=NULL)
	{
		if(!strcmp(temp->paIn.ID,tempID))
		{
			printf("\n\t\t\t\t     您的信息：\n");
			printf("\t\t\t\t     姓名：%s；年龄：%d；\n",temp->paIn.name,temp->paIn.age);
			printf("\n\t\t\t\t     您的医生信息：\n");
			printf("\t\t\t\t     姓名：%s；级别：%s；科室：%s；工号：%s\n",temp->doIn.name,temp->doIn.level,temp->doIn.department,temp->doIn.ID);
			return;
		}
	}
	printf("\n\t\t\t\t     找不到您的挂号，请重新输入！");
	Sleep(2000);
	regiinqu(); 
}
void option1_2()
{
    char a[10];
    print();
    printf("\n\t\t\t\t     ★请选择功能★\n\n\t\t\t\t      ① 挂号\n\n\t\t\t\t      ② 查询(已挂号)\n\n\t\t\t\t      ③ 返回上一级\n\n");
    printf("\n\t\t\t\t      请选择：");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
        Sleep(1000);
        option1_2();
    }
    else if(!strcmp(a,"1"))
    	getregi(); 
    else if(!strcmp(a,"2"))
        regiinqu();
    else if(!strcmp(a,"3"))
    {
    	print();
        option1();
	}
    else
    {
        printf("\n\t\t\t\t   × 输入错误，请重新输入!\n");
        Sleep(1000);
        option1_2();
    }
}

void option1()
{
    char a[10];
    print();
    printf("\n\t\t\t\t    ★请选择您的身份★\n\n\t\t\t\t    ① 医生或工作人员\n\n\t\t\t\t    ② 病人\n\n\t\t\t\t    ③ 退出程序\n\n\t\t\t\t");
    printf("\n\t\t\t\t    请选择：");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
        Sleep(1000);
        option1();
    }
    else if(!strcmp(a,"1"))
    	getpassword();
    else if(!strcmp(a,"2"))
        option1_2();
    else if(!strcmp(a,"3"))
    	func6();
    else
    {
        printf("\n\t\t\t\t   × 输入错误，请重新输入!\n");
        Sleep(1000);
        option1();
    }
}
#endif
