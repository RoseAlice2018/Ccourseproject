#ifndef OPTION1_H_INCLUDED
#define OPTION1_H_INCLUDED

void getpassword()
{
	print();
	printf("\n\n\t\t\t\t  ���������룺");
	char password[30];
	scanf("%s",password);
	if(!strcmp(password,"123456"))
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
void regiinqu()
{
	print();
	printf("\n");
	printf("\t\t\t\t     ���������ĹҺ�\n");
	char tempID[30];
	scanf("%s",tempID);
	MedicalRecords* temp=records->next;
	while(temp!=NULL)
	{
		if(!strcmp(temp->paIn.ID,tempID))
		{
			printf("\n\t\t\t\t     ������Ϣ��\n");
			printf("\t\t\t\t     ������%s�����䣺%d��\n",temp->paIn.name,temp->paIn.age);
			printf("\n\t\t\t\t     ����ҽ����Ϣ��\n");
			printf("\t\t\t\t     ������%s������%s�����ң�%s�����ţ�%s\n",temp->doIn.name,temp->doIn.level,temp->doIn.department,temp->doIn.ID);
			return;
		}
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
    printf("\n\t\t\t\t    ����ѡ��������ݡ�\n\n\t\t\t\t    �� ҽ��������Ա\n\n\t\t\t\t    �� ����\n\n\t\t\t\t    �� �˳�����\n\n\t\t\t\t");
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
