#ifndef OPTION1_H_INCLUDED
#define OPTION1_H_INCLUDED

void getpassword()
{
	print();
	printf("\n\n\t\t\t\t  ���������룺");
	char pass[30];
	scanf("%s",pass);
	if(!strcmp(pass,password))
	{
		option();
	}
	else
	{
		printf("\n\t\t\t\t  �����������������");
		Sleep(1200);
		getpassword();
	}
}
void getregi()
{
	char patID[30];
	/*******ϵͳʱ��*******/ 
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
	/**���ҽ����Ϣ**/
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
	
	printf("\n\n\t\t\t\t ��ѡ���ҽ������Ϊ��");
	char tempID[50];
	scanf("%s",tempID);
	/**У��**/ 
	for(int i=0;i<index;i++)
	{
		if(!strcmp(tempID,chID[i]))
			break;
		if(i==index-1)
		{
			printf("\n\t\t\t\t ��ѡ���ҽ�������ڣ�����������");
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
	printf("\n\t\t\t\t ���ĹҺ�Ϊ��%s",patID);
	printf("\n\n\t\t\t\t ");
	system("pause");
	option1_2(); 
}
void patinquire(MedicalRecords* temp)
{
	print();
	printf("\t\t\t ������Ϣ��\n");
	printf("\t\t\t ������%s�����䣺%d��\n",temp->paIn.name,temp->paIn.age);
	printf("\n\t\t\t ����ҽ����Ϣ��\n");
	printf("\t\t\t ������%s������%s�����ң�%s�����ţ�%s\n",temp->doIn.name,temp->doIn.level,temp->doIn.department,temp->doIn.ID);
	char a[10];
	printf("\n\t\t\t\t    ����ѡ����Ҫ��ѯ����Ϣ��\n\n\t\t\t\t    �� ����¼\n\n\t\t\t\t    �� ��ҩ��¼\n\n\t\t\t\t    �� סԺ��¼\n\n\t\t\t\t    �� ������һ��\n");
    printf("\n\t\t\t\t    ��ѡ��");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
        Sleep(1000);
        patinquire(temp);
    }
    else if(!strcmp(a,"1"))
    {
    	if(temp->mdIn.exam.examcount==0)
    	{
    		print();
    		printf("\n\t\t\t\t ��δ�м���¼\n");
    		printf("\n\n\t\t\t\t ");
			system("pause");
    		patinquire(temp);
		}
    	else
    	{
			print();
    		printf("\n\t\t\t ���ļ�������%d\n\n",temp->mdIn.exam.examcount);
    		int count=0;
    		while (count!=temp->mdIn.exam.examcount)
	        {
	        	printf("\t\t\t\t���ĵ�%d�μ��ķ��ã�%d\n", count + 1,temp->mdIn.exam.examproj[count].examcost);
				printf("\t\t\t\t���ĵ�%d�μ���ʱ�䣺%d��%d��%dʱ%d��\n", count + 1,temp->mdIn.exam.examproj[count].examtime.month,
				temp->mdIn.exam.examproj[count].examtime.day,temp->mdIn.exam.examproj[count].examtime.hour,temp->mdIn.exam.examproj[count].examtime.minute);
				count++;
	        }
	        printf("\n\t\t\t\t�����ܼ����ã�%d\n",temp->mdIn.exam.SumCost); 
		}
	}
    else if(!strcmp(a,"2"))
    {
    	if(temp->mdIn.prmd.drugcount==0)
    	{
    		print();
    		printf("\n\t\t\t\t ��δ�п�ҩ��¼\n");
    		printf("\n\n\t\t\t\t ");
			system("pause");
    		patinquire(temp);
		}
    	else
    	{
    		print();
    		printf("\n\t\t\t ���Ŀ�ҩ������%d\n\n",temp->mdIn.prmd.drugcount);
    		int count=0;
    		while (count!=temp->mdIn.prmd.drugcount)
	        {
	        	printf("\t\t\t\tҩƷ���ƣ�%s�����ۣ�%d��������%d\n",temp->mdIn.prmd.drug[count].name,temp->mdIn.prmd.drug[count].Price,temp->mdIn.prmd.drug[count].Number);
				printf("\t\t\t\t��ҩʱ�䣺%d��%d��%dʱ%d��\n",temp->mdIn.prmd.drug[count].prescribetime.month,temp->mdIn.prmd.drug[count].prescribetime.day,
				temp->mdIn.prmd.drug[count].prescribetime.hour,temp->mdIn.prmd.drug[count].prescribetime.minute);
				count++;
	        }
	        printf("\n\t\t\t\t����ҩƷ�ܼۣ�%d\n",temp->mdIn.prmd.SumDrugCost); 
		}
	}
    else if(!strcmp(a,"3"))
    {
    	if(temp->mdIn.hosp.deposit==0)
    	{
    		print();
    		printf("\n\t\t\t\t ��δ��סԺ��¼\n");
    		printf("\n\n\t\t\t\t ");
			system("pause");
    		patinquire(temp);
		}
    	else
    	{
    		print();
    		printf("\n\n");
    		printf("\t\t\t\tסԺ��ʼʱ�䣺%d��%d��%dʱ%d��\n",temp->mdIn.hosp.beginDate.month,temp->mdIn.hosp.beginDate.day,
			temp->mdIn.hosp.beginDate.hour,temp->mdIn.hosp.beginDate.minute);
			printf("\t\t\t\tԤ�Ƴ�Ժʱ�䣺%d��%d��%dʱ%d��\n",temp->mdIn.hosp.leaveDate.month,temp->mdIn.hosp.leaveDate.day,
			temp->mdIn.hosp.leaveDate.hour,temp->mdIn.hosp.leaveDate.minute);
			printf("\t\t\t\t����ʣ��Ѻ��Ϊ��%d\n",temp->mdIn.hosp.deposit-showHospcost(temp));
		}
	}
	else if(!strcmp(a,"4"))
    {
    	option1_2(); 
	}
    else
    {
        printf("\n\t\t\t\t   �� �����������������!\n");
        Sleep(1000);
        patinquire(temp);
    }
}
void regiinqu()
{
	print();
	printf("\n");
	printf("\t\t\t\t     ���������ĹҺ�:\n\t\t\t\t     ");
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
	printf("\n\t\t\t\t     �Ҳ������ĹҺţ����������룡");
	Sleep(2000);
	regiinqu(); 
}
void option1_2()
{
    char a[10];
    print();
    printf("\n\t\t\t\t     ����ѡ���ܡ�\n\n\t\t\t\t      �� �Һ�\n\n\t\t\t\t      �� ��ѯ(�ѹҺ�)\n\n\t\t\t\t      �� ������һ��\n\n");
    printf("\n\t\t\t\t      ��ѡ��");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
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
        printf("\n\t\t\t\t   �� �����������������!\n");
        Sleep(1000);
        option1_2();
    }
}

void option1()
{
    char a[10];
    print();
    printf("\n\t\t\t\t    ����ѡ��������ݡ�\n\n\t\t\t\t    �� ҽ��������Ա\n\n\t\t\t\t    �� ����\n\n\t\t\t\t    �� �˳�����\n\n");
    printf("\n\t\t\t\t    ��ѡ��");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
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
        printf("\n\t\t\t\t   �� �����������������!\n");
        Sleep(1000);
        option1();
    }
}
#endif
