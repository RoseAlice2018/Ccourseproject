
void showProfit() // ͳ��ҽԺĿǰ��Ӫҵ��
{
	MedicalRecords* t=records;
	int Profit=0;
	/*******ϵͳʱ��********/ 
	time_t T;
	struct tm*p;
	time(&T);
	p=localtime(&T);
    /**********************/ 
    while(t->next!=NULL)
    {
    	int hospcost=0;
    	if(p->tm_hour<8)	//סԺ�� 
    	{
    		hospcost=200*(p->tm_mday-1-t->mdIn.hosp.beginDate.day+1);
		}else
		{
			hospcost=200*(p->tm_mday-t->mdIn.hosp.beginDate.day+1);
		}
		
    	Profit=Profit+t->mdIn.exam.SumCost+t->mdIn.prmd.SumDrugCost+hospcost;
    	t=t->next;
	}
	
	print();
	printf("\n");
    printf("ҽԺĿǰ��Ӫҵ��Ϊ��%d Ԫ\n",Profit);
}

void showPatientForm() // ����ĿǰסԺ���߱� 
{
	print();
	printf("\n");
	/*******ϵͳʱ��********/ 
	time_t T;
	struct tm*p;
	time(&T);
	p=localtime(&T);
    /**********************/
	MedicalRecords* t=records;
	while(t->next!=NULL)
	{
		printf("����������%s  �Һţ�%d\n",t->paIn.name,t->paIn.ID);
		printf("סԺ��ʼ���ڣ�%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
        printf("סԺԤ�ڽ�������: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);
        
		int hospcost=0;
    	if(p->tm_hour<8)	//סԺ�� 
    	{
    		hospcost=200*(p->tm_mday-1-t->mdIn.hosp.beginDate.day+1);
		}else
		{
			hospcost=200*(p->tm_mday-t->mdIn.hosp.beginDate.day+1);
		}
		printf("��ǰʣ��Ѻ��%d\n",t->mdIn.hosp.deposit-hospcost); 
	}
}

void func4()
{
    char a[10];
    while(1)
    {
        print();
        printf("\t\t\t\t     ����ѡ���ܡ�\n\n\t\t\t\t      �� ͳ��ҽԺĿǰӪҵ��\n\n\t\t\t\t      �� ����סԺ���߱���\n\n\t\t\t\t      �� ͳ��ҽ���ĳ������\n\n\t\t\t\t      �� ��ӡĳ��ʱ�䷶Χ�ڵ�����������Ϣ\n\n\t\t\t\t      �� ������һ��\n\n\t\t\t\t");
        printf("\n\t\t\t\t      ��ѡ��");
        scanf("%s",a);
        printf("\n");
        if(strlen(a)!=1)
        {
            printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
            Sleep(1000);
            func4();
        }
        else if(!strcmp(a,"1"))
        	showProfit(); 
        else if(!strcmp(a,"2"))
        	showPatientForm();
        else if(!strcmp(a,"3"));
        
        else if(!strcmp(a,"4"));
        
        else if(!strcmp(a,"5"))
        {
        	print();
            option();
		}
        else
        {
                printf("\n\t\t\t\t   �� �����������������!\n");
                Sleep(1000);
                func4();
        }
    }
}
