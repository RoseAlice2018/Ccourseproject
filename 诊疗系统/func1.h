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
	
	printf("��������ҽ����Ϣ---��ʽ���£����� ���� ���� ���� \n");
    char doctorinformation[200];
    gets(doctorinformation);
    if(sscanf(doctorinformation,"%s %s %s %s",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID)==4)
    ;
    else
    {
        printf("��������������������룡\n");
        Sleep(1000);
        getdoc(temp);
    }
    
    //�������ʱ��
    printf("�����������ʱ�䣺ʱ���ʽ��1(��һ) 2(�ܶ�)... Ĭ��������0\n");
    char time[20];
    scanf("%s",time);
    if(time[0]=='0')
    {
    	int i;
        for(i=1;i<=7;i++)
            {
                temp->doIn.date[i]=1;//1 ��ʾ��ֵ��
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
    //����department
    insertDepartment(temp->doIn.department);
}
void getpat(MedicalRecords* temp)
{
	print();
	printf("\n");
	
    printf("�������뻼����Ϣ---��ʽ���£����� ���� �Һ�\n");
    char patientinformation[100];
    gets(patientinformation);
    if(sscanf(patientinformation,"%s %d %s",temp->paIn.name,&temp->paIn.age,temp->paIn.ID)==3)
    {
        //������ȷ����
    }
    else
    {
        printf("���������д��� ���������룡\n");
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
        printf("��������������������룡\n");
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
	
	printf("�����������������\n");
    printf("�����������������δ�м��������0\n");
    int checkNumber=0;
    char checknumber[10];
    gets(checknumber);
    if(sscanf(checknumber,"%d",&checkNumber)==1)
    {
    	if(checkNumber<0)
    	{
    		printf("��������������������룡\n");
        	Sleep(1000);
        	getexam(temp);
		}
	}
    else{
        printf("��������������������룡\n");
        Sleep(1000);
        getexam(temp);
    }
    if(checkNumber>0)
    {
        while (temp->mdIn.exam.examcount!=checkNumber)
        {
        	printf("����������ÿ�μ�����---��ʽ���£�100 \n");
           	getcost(temp);
			temp->mdIn.exam.examcount++;
        }  
    }
}
void getmedirec(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("�������뿪ҩ��¼---��ʽ���£�ҩƷ���� ���� ����\n");
    char medi[200];
    gets(medi);
    if(sscanf(medi,"%s %d %d",temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].name,&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Price),&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number))==3);
    else{
        printf("��������������������룡\n");
        Sleep(1000);
        getmedirec(temp);
    }
    temp->mdIn.prmd.SumDrugCost+=(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number*temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount++].Price);
}
void getmedi(MedicalRecords* temp)
{
	print();
	printf("\n");
	
	printf("�������뿪ҩ��������δ����ҩ��������0\n");
    int medicount;
    char medicount1[100];
    gets(medicount1);
    if(sscanf(medicount1,"%d",&medicount)==1)
    {
    	if(medicount<0)
    	{
    		printf("��������������������룡\n");
        	Sleep(1000);
        	getmedi(temp);
		}
	}
    else{
        printf("��������������������룡\n");
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
	
	printf("��������סԺ��¼---��ʽ���£���סԺ��ʼ��¼����/��/ʱ/�� ��Ԥ�ڳ�Ժ���ڣ���/��/ʱ/�� סԺѺ��\n");
    char hospitalr[200];
    gets(hospitalr);
    if(sscanf(hospitalr,"%d/%d/%d/%d %d/%d/%d/%d %d",&temp->mdIn.hosp.beginDate.month,&temp->mdIn.hosp.beginDate.day
    ,&temp->mdIn.hosp.beginDate.hour,&temp->mdIn.hosp.beginDate.minute,&temp->mdIn.hosp.leaveDate.month,
    &temp->mdIn.hosp.leaveDate.day,&temp->mdIn.hosp.leaveDate.hour,&temp->mdIn.hosp.leaveDate.minute,&temp->mdIn.hosp.deposit)==9);
    else{
        printf("��������������������룡\n");
        Sleep(1000);
        gethosp(temp);
    }
    /*if(temp->mdIn.hosp.deposit < temp->mdIn.hosp.leastdeposit)
    {
        printf("����Ѻ����");
        Sleep(2000);
    }
    else if(temp->mdIn.hosp.deposit<temp->mdIn.hosp.deposit)
    {
        printf("����Ѻ�������ͱ�׼");
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
    printf("\t\t\t\t     ����ѡ���ܡ�\n\n\t\t\t\t      �� ���ļ�¼�����Ƽ�¼\n\n\t\t\t\t      �� �ֶ�¼��һ�����Ƽ�¼\n\n\t\t\t\t      �� ������һ��\n\n\t\t\t\t");
    printf("\n\t\t\t\t      ��ѡ��");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
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
        printf("\n\t\t\t\t   �� �����������������!\n");
        Sleep(1000);
        func1();
    }
}
#endif
