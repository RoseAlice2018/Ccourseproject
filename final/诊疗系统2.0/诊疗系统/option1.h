#ifndef OPTION1_H_INCLUDED
#define OPTION1_H_INCLUDED

void getpassword()
{
	print();
	printf("\n\n\t\t\t\t  请输入密码：");
	char pass[30];
	scanf("%s",pass);
	if(!strcmp(pass,password))
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
			return;
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
void patinquire(MedicalRecords* temp)
{
	print();
	printf("\t\t\t 您的信息：\n");
	printf("\t\t\t 姓名：%s；年龄：%d；\n",temp->paIn.name,temp->paIn.age);
	printf("\n\t\t\t 您的医生信息：\n");
	printf("\t\t\t 姓名：%s；级别：%s；科室：%s；工号：%s\n",temp->doIn.name,temp->doIn.level,temp->doIn.department,temp->doIn.ID);
	char a[10];
	printf("\n\t\t\t\t    ★请选择您要查询的信息★\n\n\t\t\t\t    ① 检查记录\n\n\t\t\t\t    ② 开药记录\n\n\t\t\t\t    ③ 住院记录\n\n\t\t\t\t    ④ 返回上一级\n");
    printf("\n\t\t\t\t    请选择：");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
        Sleep(1000);
        patinquire(temp);
    }
    else if(!strcmp(a,"1"))
    {
    	if(temp->mdIn.exam.examcount==0)
    	{
    		print();
    		printf("\n\t\t\t\t 您未有检查记录\n");
    		printf("\n\n\t\t\t\t ");
			system("pause");
    		patinquire(temp);
		}
    	else
    	{
			print();
    		printf("\n\t\t\t 您的检查次数：%d\n\n",temp->mdIn.exam.examcount);
    		int count=0;
    		while (count!=temp->mdIn.exam.examcount)
	        {
	        	printf("\t\t\t\t您的第%d次检查的费用：%d\n", count + 1,temp->mdIn.exam.examproj[count].examcost);
				printf("\t\t\t\t您的第%d次检查的时间：%d月%d日%d时%d分\n", count + 1,temp->mdIn.exam.examproj[count].examtime.month,
				temp->mdIn.exam.examproj[count].examtime.day,temp->mdIn.exam.examproj[count].examtime.hour,temp->mdIn.exam.examproj[count].examtime.minute);
				count++;
	        }
	        printf("\n\t\t\t\t您的总检查费用：%d\n",temp->mdIn.exam.SumCost); 
		}
	}
    else if(!strcmp(a,"2"))
    {
    	if(temp->mdIn.prmd.drugcount==0)
    	{
    		print();
    		printf("\n\t\t\t\t 您未有开药记录\n");
    		printf("\n\n\t\t\t\t ");
			system("pause");
    		patinquire(temp);
		}
    	else
    	{
    		print();
    		printf("\n\t\t\t 您的开药次数：%d\n\n",temp->mdIn.prmd.drugcount);
    		int count=0;
    		while (count!=temp->mdIn.prmd.drugcount)
	        {
	        	printf("\t\t\t\t药品名称：%s；单价：%d；数量：%d\n",temp->mdIn.prmd.drug[count].name,temp->mdIn.prmd.drug[count].Price,temp->mdIn.prmd.drug[count].Number);
				printf("\t\t\t\t开药时间：%d月%d日%d时%d分\n",temp->mdIn.prmd.drug[count].prescribetime.month,temp->mdIn.prmd.drug[count].prescribetime.day,
				temp->mdIn.prmd.drug[count].prescribetime.hour,temp->mdIn.prmd.drug[count].prescribetime.minute);
				count++;
	        }
	        printf("\n\t\t\t\t您的药品总价：%d\n",temp->mdIn.prmd.SumDrugCost); 
		}
	}
    else if(!strcmp(a,"3"))
    {
    	if(temp->mdIn.hosp.deposit==0)
    	{
    		print();
    		printf("\n\t\t\t\t 您未有住院记录\n");
    		printf("\n\n\t\t\t\t ");
			system("pause");
    		patinquire(temp);
		}
    	else
    	{
    		print();
    		printf("\n\n");
    		printf("\t\t\t\t住院开始时间：%d月%d日%d时%d分\n",temp->mdIn.hosp.beginDate.month,temp->mdIn.hosp.beginDate.day,
			temp->mdIn.hosp.beginDate.hour,temp->mdIn.hosp.beginDate.minute);
			printf("\t\t\t\t预计出院时间：%d月%d日%d时%d分\n",temp->mdIn.hosp.leaveDate.month,temp->mdIn.hosp.leaveDate.day,
			temp->mdIn.hosp.leaveDate.hour,temp->mdIn.hosp.leaveDate.minute);
			printf("\t\t\t\t您的剩余押金为：%d\n",temp->mdIn.hosp.deposit-showHospcost(temp));
		}
	}
	else if(!strcmp(a,"4"))
    {
    	option1_2(); 
	}
    else
    {
        printf("\n\t\t\t\t   × 输入错误，请重新输入!\n");
        Sleep(1000);
        patinquire(temp);
    }
}
void regiinqu()
{
	print();
	printf("\n");
	printf("\t\t\t\t     请输入您的挂号:\n\t\t\t\t     ");
	char tempID[30];
	scanf("%s",tempID);
	MedicalRecords* temp=records->next;
	while(temp!=NULL)
	{
		if(strcmp(temp->paIn.ID,tempID)==0)
		{
			patinquire(temp);
			printf("\n\n\t\t\t\t ");
			system("pause");
		}
		temp=temp->next;
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
    printf("\n\t\t\t\t    ★请选择您的身份★\n\n\t\t\t\t    ① 医生或工作人员\n\n\t\t\t\t    ② 病人\n\n\t\t\t\t    ③ 退出程序\n\n");
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
