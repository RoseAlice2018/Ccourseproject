void getregi()
{
	char patID[30];
	/*******ϵͳʱ��*******/ 
	time_t T;
	struct tm*p;
	time(&T);
	p=localtime(&T);
    /**********************/
	print();
	/**���ҽ����Ϣ**/
	
	printf("\t\t\t\t      ��ѡ���ҽ������Ϊ��");
	char tempID[30];
	scanf("%s",tempID);
	/**У��**/ 
	
	int m=p->tm_mon+1;
	int d=p->tm_mday;
	patID[0]=m/10+'0';
	patID[1]=m%10+'0';
	patID[2]=d/10+'0';
	patID[3]=d%10+'0';
	patID[4]=regicount/100+'0';
	patID[5]=(regicount/10)%10+'0';
	patID[6]=regicount%10+'0';
	for(int i=0;i<strlen(tempID)-1;i++)
	{
		patID[6+i]=tempID[i];
	}
	printf("\n\t\t\t\t      ���ĹҺ�Ϊ %s",patID);
}
void regiinqu()
{
	print();
	printf("\n");
	printf("\t\t\t\t     ���������ĹҺ�\n");
	char tempID[30];
	scanf("%s",tempID);
	MedicalRecords* t=records->next;
	while(t!=NULL)
	{
		if(!strcmp(t->paIn.ID,tempID))
		{
			printf("\n\t\t\t\t     ������Ϣ��\n");
			printf("\t\t\t\t     �����������䣺��\n");
			printf("\n\t\t\t\t     ����ҽ����Ϣ��\n");
			printf("\t\t\t\t     �����������䣺��\n");
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
