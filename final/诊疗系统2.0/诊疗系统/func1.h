#ifndef FUNC1_H_INCLUDED
#define FUNC1_H_INCLUDED

void scanfromtxt()
{
	print();
	
	MedicalRecords* temp=new MedicalRecords();
	FILE* fpread=fopen("medicalRecords.txt","r");
	if(fpread!=NULL)
	{
		while(!feof(fpread))
		{
			fscanf(fpread,"%s %d %s",temp->paIn.name,&temp->paIn.age,temp->paIn.ID);//patient
			fscanf(fpread,"%s %s %s %s",temp->doIn.name,temp->doIn.level,temp->doIn.department,temp->doIn.ID);//docter
			
			char time[20];
			fscanf(fpread,"%s",time);
			if(time[0]=='0')
		        for(int i=1;i<=7;i++)
		        {
		            temp->doIn.date[i]=1;//1 表示在值班
		        }
		    else
			{
		        for(int i=0;i<7;i++)
		        {
		            if(time[i]=='\0')
		                break;
		            int c=time[i]-'0';
		            temp->doIn.date[c]=1;
		        }
		    }
		    //exam
		    fscanf(fpread,"%d",&temp->mdIn.exam.examcount);
		    temp->mdIn.exam.SumCost=0;
		    for(int i=0;i<temp->mdIn.exam.examcount;i++)
		    {
		    	fscanf(fpread,"%d ",&temp->mdIn.exam.examproj[i].examcost);
		    	temp->mdIn.exam.SumCost+=temp->mdIn.exam.examproj[i].examcost;
		    	fscanf(fpread,"%d/%d/%d/%d",&temp->mdIn.exam.examproj[i].examtime.month,&temp->mdIn.exam.examproj[i].examtime.day,
				&temp->mdIn.exam.examproj[i].examtime.hour,&temp->mdIn.exam.examproj[i].examtime.minute);
			}
			//drug
			fscanf(fpread,"%d",&temp->mdIn.prmd.drugcount);
		    temp->mdIn.prmd.SumDrugCost=0;
		    for(int i=0;i<temp->mdIn.prmd.drugcount;i++)
		    {
		    	fscanf(fpread,"%s %d %d",temp->mdIn.prmd.drug[i].name,&temp->mdIn.prmd.drug[i].Price,&temp->mdIn.prmd.drug[i].Number);
		    	temp->mdIn.prmd.SumDrugCost += (temp->mdIn.prmd.drug[i].Number * temp->mdIn.prmd.drug[i].Price);
		    	fscanf(fpread,"%d/%d/%d/%d",&temp->mdIn.prmd.drug[i].prescribetime.month,&temp->mdIn.prmd.drug[i].prescribetime.day,
				&temp->mdIn.prmd.drug[i].prescribetime.hour,&temp->mdIn.prmd.drug[i].prescribetime.minute);
			}
			
			int flag=-1;
			fscanf(fpread,"%d",&flag);
			if(flag==0)
			{
				temp->mdIn.hosp.Cost=0;
    			temp->mdIn.hosp.deposit=0;
			}else
			{
				temp->mdIn.hosp.beginDate.month=flag;
				fscanf(fpread,"/%d/%d/%d %d/%d/%d/%d %d",&temp->mdIn.hosp.beginDate.day,
				&temp->mdIn.hosp.beginDate.hour,&temp->mdIn.hosp.beginDate.minute,&temp->mdIn.hosp.leaveDate.month,
			&temp->mdIn.hosp.leaveDate.day,&temp->mdIn.hosp.leaveDate.hour,&temp->mdIn.hosp.leaveDate.minute,&temp->mdIn.hosp.deposit);
			}
		}
	}
	
	temp->before = pointer;
	temp->next = pointer->next;
	pointer->next = temp;
	pointer = temp;
    printf("\n\n\n\t\t★ 诊疗记录读入成功！\n\n\t\t");
    system("pause");
}
void getpat(MedicalRecords* temp)
{
	print();
	printf("\n");
	
    printf("\t\t请您输入患者信息---格式如下：姓名 年龄 挂号\n\t\t");
    char patientinformation[100];
    gets(patientinformation);
    if(sscanf(patientinformation,"%s %d %s",temp->paIn.name,&temp->paIn.age,temp->paIn.ID)==3)
    {
        MedicalRecords* t=records->next;
        while(t!=NULL)
        {
        	if(strcmp(t->paIn.ID,temp->paIn.ID)==0)
        	{
        		printf("\n\t\t× 您的输入有错误！ 请重新输入！\n");
        		Sleep(1200);
				getpat(temp);
				return;
			}
			t=t->next;
		}
    }
    else
    {
        printf("\n\t\t× 您的输入有错误！ 请重新输入！\n");
        Sleep(1200);
		getpat(temp);
		return;
    }
}
void getdoctime(MedicalRecords* temp)
{
	printf("\t\t请您输入出诊时间：时间格式：1(周一)3(周三)... 默认请输入0\n\t\t");
    char time[20];
    scanf("%s",time);
    if(strlen(time)>7)
    {
        printf("\n\t\t× 您的输入有错误！ 请重新输入！\n");
        Sleep(1200);
        getdoctime(temp);
        return;
    }
    if(time[0]=='0')
    {
        for(int i=1;i<=7;i++)
        {
            temp->doIn.date[i]=1;//1 表示在值班
        }
    }
    else
	{
        for(int i=0;i<7;i++)
        {
            if(time[i]=='\0')
                break;
            int c=time[i]-'0';
            if(c<0||c>7)
            {
            	printf("\n\t\t× 您的输入有错误！ 请重新输入！\n");
        		Sleep(1200);
        		getdoctime(temp);
        		return;
			}
            temp->doIn.date[c]=1;
        }
    }
}
void getdoc(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("\t\t请您输入医生信息---格式如下：姓名 级别 科室 工号 \n\t\t");
    char doctorinformation[200];
    gets(doctorinformation);
    if(sscanf(doctorinformation,"%s %s %s %s",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID)==4)
    ;
    else
    {
        printf("\n\t\t× 您的输入错误！请重新输入！\n");
        Sleep(1200);
        getdoc(temp);
        return;
    }
    
    //插入出诊时间
    getdoctime(temp);
    //插入department
    for(int i=0;i<countDepart;i++)
    {
        if(RealDepartment[i].name==temp->doIn.department)
        {
            return;
        }
    }
	strcpy(RealDepartment[countDepart].name,temp->doIn.department);
}

void getcost(MedicalRecords* temp)
{
	int c;
    char cc[20];
    gets(cc);
    if(sscanf(cc,"%d",&c)==1);
    else{
        printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
        Sleep(1200);
        getcost(temp);
        return;
    }
	temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examcost = c;
    temp->mdIn.exam.SumCost+=c;
}
void getexamtime(MedicalRecords* temp)
{
	char time[200];
	char ch;
	//	while ((ch = getchar()) != '\n' && ch != EOF);
	gets(time);
	if (sscanf(time, "%d/%d/%d/%d",
		&temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.month,
		&temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day,
		&temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.hour,
		&temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.minute) == 4)
	{
		if(temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.month>12||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.month<=0||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.hour>59||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.hour<0||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.minute>59||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.minute<0)
		{
			printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
			Sleep(1200);
			getexamtime(temp);
			return;
		}
		int m=temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.month;
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day>31||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
				Sleep(1200);
				getexamtime(temp);
				return;
			}
		}else if(m==2)
		{
			if(temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day>28||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
				Sleep(1200);
				getexamtime(temp);
				return;
			}
		}else
		{
			if(temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day>30||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
				Sleep(1200);
				getexamtime(temp);
				return;
			}
		}
	}
	else {
		printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
		Sleep(1200);
		getexamtime(temp);
		return;
	}
}
void getexam(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("\t\t请您输入诊疗情况：\n");
    printf("\t\t请您输入检查次数(如未有检查请输入0)：\n\t\t");
    int checkNumber=0;
    char checknumber[10];
    gets(checknumber);
    if(sscanf(checknumber,"%d",&checkNumber)==1)
    {
    	if(checkNumber<0)
    	{
    		printf("\n\t\t× 您的输入错误！请重新输入！\n");
        	Sleep(1200);
        	getexam(temp);
        	return;
		}
	}
    else{
        printf("\n\t\t× 您的输入错误！请重新输入！\n");
        Sleep(1200);
        getexam(temp);
        return;
    }
    temp->mdIn.exam.examcount=0;
	temp->mdIn.exam.SumCost=0;

    if(checkNumber>0)
    {
        while (temp->mdIn.exam.examcount!=checkNumber)
        {
        	printf("\t\t请输入第%d次检查的费用---格式如下：100 \n\t\t", temp->mdIn.exam.examcount + 1);
			getcost(temp);
			printf("\t\t请输入第%d次检查的时间---格式如下：月/日/时/分\n\t\t", temp->mdIn.exam.examcount + 1);
			getexamtime(temp);
			temp->mdIn.exam.examcount++;
        }  
    }
}

void getdrugtime(MedicalRecords* temp)
{
	char time[200];
	gets(time);
	if (sscanf(time, "%d/%d/%d/%d",
		&temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.month,
		&temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day,
		&temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.hour,
		&temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.minute) == 4)
	{
		if(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.month>12||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.month<=0||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.hour>59||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.hour<0||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.minute>59||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.minute<0)
		{
			printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
			Sleep(1200);
			getdrugtime(temp);
		}
		int m=temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.month;
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day>31||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
				Sleep(1200);
				getdrugtime(temp);
				return;
			}
		}else if(m==2)
		{
			if(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day>28||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
				Sleep(1200);
				getdrugtime(temp);
				return;
			}
		}else
		{
			if(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day>30||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
				Sleep(1200);
				getdrugtime(temp);
				return;
			}
		}
	}
	else {
		printf("\n\t\t× 您的输入错误！请重新输入！\n\t\t");
		Sleep(1200);
		getdrugtime(temp);
		return;
	}
}
void getmedirec(MedicalRecords* temp)
{
	printf("\t\t请您输入开药记录---格式如下：药品名称 单价 数量\n\t\t");
    char medi[200];
    gets(medi);
    if(sscanf(medi,"%s %d %d",temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].name,&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Price),&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number))==3)
    {
    	printf("\t\t请您输入本次开药的时间---格式如下：月/日/时/分\n\t\t");
		getdrugtime(temp);
	}
    else
	{
        printf("\n\t\t× 您的输入错误！请重新输入！\n");
        Sleep(1200);
        getmedirec(temp);
        return;
    }
    temp->mdIn.prmd.SumDrugCost+=(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number*temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Price);
}
void getmedi(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("\t\t请您输入开药次数(如未曾开药，请输入0)：\n\t\t");
    int medicount;
    char medicount1[100];
    gets(medicount1);
    if(sscanf(medicount1,"%d",&medicount)==1)
    {
    	if(medicount<0)
    	{
    		printf("\n\t\t× 您的输入错误！请重新输入！\n");
        	Sleep(1200);
        	getmedi(temp);
        	return;
		}
	}
    else{
        printf("\n\t\t× 您的输入错误！请重新输入！\n");
        Sleep(1200);
        getmedi(temp);
        return;
    }
    temp->mdIn.prmd.drugcount=0;
    temp->mdIn.prmd.SumDrugCost=0;
    if(medicount>0)
 	{
        while(temp->mdIn.prmd.drugcount!=medicount)
        {
            getmedirec(temp);
            temp->mdIn.prmd.drugcount++;
        }   
	}
}
void gethosp(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("\t\t请您输入住院记录---格式如下：（开始住院）月/日/时/分 （预期出院）月/日/时/分 住院押金(不小于1000)\n");
	printf("\t\t(如未有检查请输入0)\n\t\t");
    char hospitalr[200];
    gets(hospitalr);
    int flag=1;
    if(sscanf(hospitalr,"%d",&flag)==1)
    {
    	if(flag==0)
    	{
    		temp->mdIn.hosp.Cost=0;
    		temp->mdIn.hosp.deposit=0;
    		return;
    	}
	}
    if(sscanf(hospitalr,"%d/%d/%d/%d %d/%d/%d/%d %d",&temp->mdIn.hosp.beginDate.month,&temp->mdIn.hosp.beginDate.day
    ,&temp->mdIn.hosp.beginDate.hour,&temp->mdIn.hosp.beginDate.minute,&temp->mdIn.hosp.leaveDate.month,
    &temp->mdIn.hosp.leaveDate.day,&temp->mdIn.hosp.leaveDate.hour,&temp->mdIn.hosp.leaveDate.minute,&temp->mdIn.hosp.deposit)==9)
    {
		if(temp->mdIn.hosp.beginDate.month>12||temp->mdIn.hosp.beginDate.month<=0||
			
			temp->mdIn.hosp.beginDate.hour>59||temp->mdIn.hosp.beginDate.hour<0||
			temp->mdIn.hosp.beginDate.minute>59||temp->mdIn.hosp.beginDate.minute<0||
			temp->mdIn.hosp.leaveDate.month>12||temp->mdIn.hosp.leaveDate.month<=0||
			temp->mdIn.hosp.leaveDate.hour>59||temp->mdIn.hosp.leaveDate.hour<0||
			temp->mdIn.hosp.leaveDate.minute>59||temp->mdIn.hosp.leaveDate.minute<0)
		{
			printf("\n\t\t× 您的输入错误！请重新输入！\n");
        	Sleep(1200);
        	gethosp(temp);
        	return;
		}
		int m1=temp->mdIn.hosp.beginDate.month;
		int m2=temp->mdIn.hosp.leaveDate.month;
		if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)
		{
			if(temp->mdIn.hosp.beginDate.day>31||temp->mdIn.hosp.beginDate.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}else if(m1==2)
		{
			if(temp->mdIn.hosp.beginDate.day>28||temp->mdIn.hosp.beginDate.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}else
		{
			if(temp->mdIn.hosp.beginDate.day>30||temp->mdIn.hosp.beginDate.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}
		
		if(m2==1||m2==3||m2==5||m2==7||m2==8||m2==10||m2==12)
		{
			if(temp->mdIn.hosp.leaveDate.day>31||temp->mdIn.hosp.leaveDate.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}else if(m2==2)
		{
			if(temp->mdIn.hosp.leaveDate.day>28||temp->mdIn.hosp.leaveDate.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}else
		{
			if(temp->mdIn.hosp.leaveDate.day>30||temp->mdIn.hosp.leaveDate.day<=0)
			{
				printf("\n\t\t× 您的输入错误！请重新输入！\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}
		
		if((temp->mdIn.hosp.deposit%100)!=0)
    	{
    		printf("\n\t\t× 您的押金输入错误！请重新输入！\n");
        	Sleep(1200);
        	gethosp(temp);
        	return;
		}
	}
    else
	{
        printf("\n\t\t× 您的输入错误！请重新输入！\n");
        Sleep(1200);
        gethosp(temp);
        return;
    }
    int period=0;
    for(int i=temp->mdIn.hosp.beginDate.month;i<temp->mdIn.hosp.leaveDate.month;i++)
    {
    	if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
    		period+=31;
    	else if(i==2)
    		period+=28;
    	else
    		period+=30;
	}
	period+=(temp->mdIn.hosp.leaveDate.day-temp->mdIn.hosp.beginDate.day);
    if(temp->mdIn.hosp.deposit < 200*period)
    {
        printf("\n\t\t× 押金不足,请重新输入");
        Sleep(1200);
        gethosp(temp);
        return;
    }
    else if(temp->mdIn.hosp.deposit<1000)
    {
        printf("\n\t\t× 押金低于最低标准,请重新输入");
        Sleep(1200);
        gethosp(temp);
        return;
    } 
}
void AddMedicalRecords()
{
	//print();
	//printf("\n");
	MedicalRecords* temp=new MedicalRecords();

	char trash[100];
	gets(trash);
	getpat(temp);
	getdoc(temp);
	gets(trash);
	getexam(temp);
	getmedi(temp);
	gethosp(temp);
	
	temp->before = pointer;
	temp->next = pointer->next;
	pointer->next = temp;
	pointer = temp;
    printf("\n\n\n\t\t★ 诊疗记录录入成功！");
    Sleep(1200);
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
        Sleep(1200);
        func1();
    }
    else if(!strcmp(a,"1"))
    {
    	scanfromtxt();
    	func1();
	}
    else if(!strcmp(a,"2"))
    {
		AddMedicalRecords();
		func1(); 
	} 
    else if(!strcmp(a,"3"))
    {
    	print();
        option();
	}
    else
    {
        printf("\n\t\t\t\t   × 输入错误，请重新输入!\n");
        Sleep(1200);
        func1();
    }
}
#endif
