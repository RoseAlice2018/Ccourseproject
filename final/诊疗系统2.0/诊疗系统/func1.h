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
		            temp->doIn.date[i]=1;//1 ��ʾ��ֵ��
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
    printf("\n\n\n\t\t�� ���Ƽ�¼����ɹ���\n\n\t\t");
    system("pause");
}
void getpat(MedicalRecords* temp)
{
	print();
	printf("\n");
	
    printf("\t\t�������뻼����Ϣ---��ʽ���£����� ���� �Һ�\n\t\t");
    char patientinformation[100];
    gets(patientinformation);
    if(sscanf(patientinformation,"%s %d %s",temp->paIn.name,&temp->paIn.age,temp->paIn.ID)==3)
    {
        MedicalRecords* t=records->next;
        while(t!=NULL)
        {
        	if(strcmp(t->paIn.ID,temp->paIn.ID)==0)
        	{
        		printf("\n\t\t�� ���������д��� ���������룡\n");
        		Sleep(1200);
				getpat(temp);
				return;
			}
			t=t->next;
		}
    }
    else
    {
        printf("\n\t\t�� ���������д��� ���������룡\n");
        Sleep(1200);
		getpat(temp);
		return;
    }
}
void getdoctime(MedicalRecords* temp)
{
	printf("\t\t�����������ʱ�䣺ʱ���ʽ��1(��һ)3(����)... Ĭ��������0\n\t\t");
    char time[20];
    scanf("%s",time);
    if(strlen(time)>7)
    {
        printf("\n\t\t�� ���������д��� ���������룡\n");
        Sleep(1200);
        getdoctime(temp);
        return;
    }
    if(time[0]=='0')
    {
        for(int i=1;i<=7;i++)
        {
            temp->doIn.date[i]=1;//1 ��ʾ��ֵ��
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
            	printf("\n\t\t�� ���������д��� ���������룡\n");
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
	
	printf("\t\t��������ҽ����Ϣ---��ʽ���£����� ���� ���� ���� \n\t\t");
    char doctorinformation[200];
    gets(doctorinformation);
    if(sscanf(doctorinformation,"%s %s %s %s",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID)==4)
    ;
    else
    {
        printf("\n\t\t�� ��������������������룡\n");
        Sleep(1200);
        getdoc(temp);
        return;
    }
    
    //�������ʱ��
    getdoctime(temp);
    //����department
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
        printf("\n\t\t�� ��������������������룡\n\t\t");
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
			printf("\n\t\t�� ��������������������룡\n\t\t");
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
				printf("\n\t\t�� ��������������������룡\n\t\t");
				Sleep(1200);
				getexamtime(temp);
				return;
			}
		}else if(m==2)
		{
			if(temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day>28||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n\t\t");
				Sleep(1200);
				getexamtime(temp);
				return;
			}
		}else
		{
			if(temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day>30||
			temp->mdIn.exam.examproj[temp->mdIn.exam.examcount].examtime.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n\t\t");
				Sleep(1200);
				getexamtime(temp);
				return;
			}
		}
	}
	else {
		printf("\n\t\t�� ��������������������룡\n\t\t");
		Sleep(1200);
		getexamtime(temp);
		return;
	}
}
void getexam(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("\t\t�����������������\n");
    printf("\t\t�������������(��δ�м��������0)��\n\t\t");
    int checkNumber=0;
    char checknumber[10];
    gets(checknumber);
    if(sscanf(checknumber,"%d",&checkNumber)==1)
    {
    	if(checkNumber<0)
    	{
    		printf("\n\t\t�� ��������������������룡\n");
        	Sleep(1200);
        	getexam(temp);
        	return;
		}
	}
    else{
        printf("\n\t\t�� ��������������������룡\n");
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
        	printf("\t\t�������%d�μ��ķ���---��ʽ���£�100 \n\t\t", temp->mdIn.exam.examcount + 1);
			getcost(temp);
			printf("\t\t�������%d�μ���ʱ��---��ʽ���£���/��/ʱ/��\n\t\t", temp->mdIn.exam.examcount + 1);
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
			printf("\n\t\t�� ��������������������룡\n\t\t");
			Sleep(1200);
			getdrugtime(temp);
		}
		int m=temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.month;
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day>31||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n\t\t");
				Sleep(1200);
				getdrugtime(temp);
				return;
			}
		}else if(m==2)
		{
			if(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day>28||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n\t\t");
				Sleep(1200);
				getdrugtime(temp);
				return;
			}
		}else
		{
			if(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day>30||
			temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].prescribetime.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n\t\t");
				Sleep(1200);
				getdrugtime(temp);
				return;
			}
		}
	}
	else {
		printf("\n\t\t�� ��������������������룡\n\t\t");
		Sleep(1200);
		getdrugtime(temp);
		return;
	}
}
void getmedirec(MedicalRecords* temp)
{
	printf("\t\t�������뿪ҩ��¼---��ʽ���£�ҩƷ���� ���� ����\n\t\t");
    char medi[200];
    gets(medi);
    if(sscanf(medi,"%s %d %d",temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].name,&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Price),&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number))==3)
    {
    	printf("\t\t�������뱾�ο�ҩ��ʱ��---��ʽ���£���/��/ʱ/��\n\t\t");
		getdrugtime(temp);
	}
    else
	{
        printf("\n\t\t�� ��������������������룡\n");
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
	
	printf("\t\t�������뿪ҩ����(��δ����ҩ��������0)��\n\t\t");
    int medicount;
    char medicount1[100];
    gets(medicount1);
    if(sscanf(medicount1,"%d",&medicount)==1)
    {
    	if(medicount<0)
    	{
    		printf("\n\t\t�� ��������������������룡\n");
        	Sleep(1200);
        	getmedi(temp);
        	return;
		}
	}
    else{
        printf("\n\t\t�� ��������������������룡\n");
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
	
	printf("\t\t��������סԺ��¼---��ʽ���£�����ʼסԺ����/��/ʱ/�� ��Ԥ�ڳ�Ժ����/��/ʱ/�� סԺѺ��(��С��1000)\n");
	printf("\t\t(��δ�м��������0)\n\t\t");
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
			printf("\n\t\t�� ��������������������룡\n");
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
				printf("\n\t\t�� ��������������������룡\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}else if(m1==2)
		{
			if(temp->mdIn.hosp.beginDate.day>28||temp->mdIn.hosp.beginDate.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}else
		{
			if(temp->mdIn.hosp.beginDate.day>30||temp->mdIn.hosp.beginDate.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}
		
		if(m2==1||m2==3||m2==5||m2==7||m2==8||m2==10||m2==12)
		{
			if(temp->mdIn.hosp.leaveDate.day>31||temp->mdIn.hosp.leaveDate.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}else if(m2==2)
		{
			if(temp->mdIn.hosp.leaveDate.day>28||temp->mdIn.hosp.leaveDate.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}else
		{
			if(temp->mdIn.hosp.leaveDate.day>30||temp->mdIn.hosp.leaveDate.day<=0)
			{
				printf("\n\t\t�� ��������������������룡\n");
        		Sleep(1200);
        		gethosp(temp);
        		return;
			}
		}
		
		if((temp->mdIn.hosp.deposit%100)!=0)
    	{
    		printf("\n\t\t�� ����Ѻ������������������룡\n");
        	Sleep(1200);
        	gethosp(temp);
        	return;
		}
	}
    else
	{
        printf("\n\t\t�� ��������������������룡\n");
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
        printf("\n\t\t�� Ѻ����,����������");
        Sleep(1200);
        gethosp(temp);
        return;
    }
    else if(temp->mdIn.hosp.deposit<1000)
    {
        printf("\n\t\t�� Ѻ�������ͱ�׼,����������");
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
    printf("\n\n\n\t\t�� ���Ƽ�¼¼��ɹ���");
    Sleep(1200);
}

void func1()
{
    char a[10];
    print();
    printf("\t\t\t\t     ����ѡ���ܡ�\n\n\t\t\t\t      �� ���ļ�¼�����Ƽ�¼\n\n\t\t\t\t      �� �ֶ�¼��һ�����Ƽ�¼\n\n\t\t\t\t      �� ������һ��\n\n\t\t\t\t");
    printf("\n\t\t\t\t      ��ѡ��");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
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
        printf("\n\t\t\t\t   �� �����������������!\n");
        Sleep(1200);
        func1();
    }
}
#endif
