#ifndef FUNC1_H_INCLUDED
#define FUNC1_H_INCLUDED

void insertDepartment(char insertname[30])
{
	int i;
    for(i=0;i<countDepart;i++)
    {
        if(RealDepartment[i].name==insertname)
        {
            return;
        }
    }
	//RealDepartment[countDepart].name=insertname;
    countDepart++;
}
void getdoc(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("请您输入医生信息---格式如下：姓名 级别 科室 工号 \n");
    char doctorinformation[200];
    gets(doctorinformation);
    if(sscanf(doctorinformation,"%s %s %s %s",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID)==4)
    ;
    else
    {
        printf("您的输入错误！请重新输入！\n");
        Sleep(1000);
        getdoc(temp);
    }
    
    //插入出诊时间
    printf("请您输入出诊时间：时间格式：1(周一) 2(周二)... 默认请输入0\n");
    char time[20];
    scanf("%s",time);
    if(time[0]=='0')
    {
    	int i;
        for(i=1;i<=7;i++)
            {
                temp->doIn.date[i]=1;//1 表示在值班
            }
    }
    else{
    	int i;
        for(i=0;i<7;i++)
        {
            if(time[i]=='\0')
                break;
            int c=time[i]-'0';
            temp->doIn.date[c]=1;
        }
    }
    //插入department
    insertDepartment(temp->doIn.department);
}
void getpat(MedicalRecords* temp)
{
	print();
	printf("\n");
	
    printf("请您输入患者信息---格式如下：姓名 年龄 挂号\n");
    char patientinformation[100];
    gets(patientinformation);
    if(sscanf(patientinformation,"%s %d %s",temp->paIn.name,&temp->paIn.age,temp->paIn.ID)==3)
    {
        //输入正确无误
    }
    else
    {
        printf("您的输入有错误！ 请重新输入！\n");
        Sleep(1000);
		getpat(temp);
    }
}
void getcost(MedicalRecords* temp)
{
	int c;
    char cc[20];
    gets(cc);
    if(sscanf(cc,"%d",&c)==1);
    else{
        printf("您的输入错误！请重新输入！\n");
        Sleep(1000);
        getcost(temp);
    }
	temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examcost = c;
    temp->mdIn.exam.SumCost+=c;
}
void getexam(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("请您输入诊疗情况：\n");
    printf("请您输入检查次数：如未有检查请输入0\n");
    int checkNumber=0;
    char checknumber[10];
    gets(checknumber);
    if(sscanf(checknumber,"%d",&checkNumber)==1)
    {
    	if(checkNumber<0)
    	{
    		printf("您的输入错误！请重新输入！\n");
        	Sleep(1000);
        	getexam(temp);
		}
	}
    else{
        printf("您的输入错误！请重新输入！\n");
        Sleep(1000);
        getexam(temp);
    }
    if(checkNumber>0)
    {
        while (temp->mdIn.exam.examcount!=checkNumber)
        {
        	printf("请依次输入每次检查费用---格式如下：100 \n");
           	getcost(temp);
			temp->mdIn.exam.examcount++;
        }  
    }
}
void getmedirec(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("请您输入开药记录---格式如下：药品名称 单价 数量\n");
    char medi[200];
    gets(medi);
    if(sscanf(medi,"%s %d %d",temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].name,&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Price),&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number))==3);
    else{
        printf("您的输入错误！请重新输入！\n");
        Sleep(1000);
        getmedirec(temp);
    }
    temp->mdIn.prmd.SumDrugCost+=(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number*temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount++].Price);
}
void getmedi(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("请您输入开药次数：如未曾开药，请输入0\n");
    int medicount;
    char medicount1[100];
    gets(medicount1);
    if(sscanf(medicount1,"%d",&medicount)==1)
    {
    	if(medicount<0)
    	{
    		printf("您的输入错误！请重新输入！\n");
        	Sleep(1000);
        	getmedi(temp);
		}
	}
    else{
        printf("您的输入错误！请重新输入！\n");
        Sleep(1000);
        getmedi(temp);
    }
    if(medicount>0)
 	{
        while(medicount--)
        {
            getmedirec(temp);
        }   
	}
}
void gethosp(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("请您输入住院记录---格式如下：（住院开始记录）月/日/时/分 （预期出院日期）月/日/时/分 住院押金\n");
    char hospitalr[200];
    gets(hospitalr);
    if(sscanf(hospitalr,"%d/%d/%d/%d %d/%d/%d/%d %d",&temp->mdIn.hosp.beginDate.month,&temp->mdIn.hosp.beginDate.day
    ,&temp->mdIn.hosp.beginDate.hour,&temp->mdIn.hosp.beginDate.minute,&temp->mdIn.hosp.leaveDate.month,
    &temp->mdIn.hosp.leaveDate.day,&temp->mdIn.hosp.leaveDate.hour,&temp->mdIn.hosp.leaveDate.minute,&temp->mdIn.hosp.deposit)==9);
    else{
        printf("您的输入错误！请重新输入！\n");
        Sleep(1000);
        gethosp(temp);
    }
    /*if(temp->mdIn.hosp.deposit < temp->mdIn.hosp.leastdeposit)
    {
        printf("您的押金不足");
        Sleep(2000);
    }
    else if(temp->mdIn.hosp.deposit<temp->mdIn.hosp.deposit)
    {
        printf("您的押金低于最低标准");
        Sleep(2000);
    } */
}
void AddMedicalRecords()
{
	//print();
	//printf("\n");
	MedicalRecords* temp=(MedicalRecords*)malloc(sizeof(MedicalRecords));

	char trash[100];
	gets(trash);
	getpat(temp);
	getdoc(temp);
	getexam(temp);
	getmedi(temp);
	gethosp(temp);
	
	temp->before=pointer;
    pointer->next=temp;
    pointer=temp;
}

void func1()
{
    char a[10];
    print();
    printf("\t\t\t\t     ★请选择功能★\n\n\t\t\t\t      ① 从文件录入诊疗记录\n\n\t\t\t\t      ② 手动录入一条诊疗记录\n\n\t\t\t\t      ③ 返回上一级\n\n\t\t\t\t");
    printf("\n\t\t\t\t      请选择：");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
        Sleep(1000);
        func1();
    }
    else if(!strcmp(a,"1"));
    
    else if(!strcmp(a,"2"))
        AddMedicalRecords();
    else if(!strcmp(a,"3"))
    {
    	print();
        option();
	}
    else
    {
        printf("\n\t\t\t\t   × 输入错误，请重新输入!\n");
        Sleep(1000);
        func1();
    }
}
#endif
