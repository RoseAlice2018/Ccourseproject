


void insertDepartment(char insertname[30])
{
    for(int i=0;i<countDepart;i++)
    {
        if(RealDepartment[i].name==insertname)
        {
            return;
        }
    }
   // RealDepartment[countDepart].name=insertname;
    countDepart++;
}
void AddMedicalRecords()
{
	print();
	printf("\n");
	 
    MedicalRecords* temp=new MedicalRecords();
    loop1: printf("��������׼��ʽ����������Ϣ\n");
    printf("�������뻼����Ϣ---��ʽ���£����� ���� �Һ�\n");
    char patientinformation[100];
    //scanf("%s",patientinformation);
    gets_s(patientinformation);
    if(sscanf(patientinformation,"%s %d %d",temp->paIn.name,&temp->paIn.age,&temp->paIn.ID)==3)
    {
        //������ȷ����
    }
    else
    {
        printf("���������д��� ���������룡\n");
        // int tag=0;
        // printf("�ӱ��п�ʼ��������������1�������ͷ��ʼ��������");
        // scanf("%d",&tag);
        // if(tag==0)
        // {
            
        // }
        goto loop1;
    }
    
    //scanf("%s %d %d",temp->paIn.name,&temp->paIn.age,&temp->paIn.ID);
    //ID���� 
    loop2: printf("��������ҽ����Ϣ---��ʽ���£����� ���� ���� ���� \n");
    //scanf("%s %d %s %d",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID);
    char doctorinformation[200];
    gets_s(doctorinformation);
    if(sscanf(doctorinformation,"%s %d %s %d",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID)==4)
    {
        //true;
        ;
    }
    else
    {
        printf("��������������������룡\n");
        goto loop2;
    }
    
    //�������ʱ��
    printf("�����������ʱ�䣺����ʱ�䣨ʱ���ʽ��1 Mon 2 Tue 3 Wed Ĭ��������0\n");
    char time[20];
    scanf("%s",time);
    if(time[0]=='0')
    {
        for(int i=1;i<=7;i++)
            {
                temp->doIn.date[i]=1;//1 ��ʾ��ֵ��
            }
    }
    else{
        for(int i=0;i<7;i++)
        {
            if(time[i]=='\0')
                break;
            int c=time[i]-'0';
            temp->doIn.date[c]=1;
        }
    }
    //����department
    insertDepartment(temp->doIn.department);
    //������״��
    loop3:printf("�����������������\n");
    printf("�����������������δ�м��������0\n");
    int checkNumber=0;
    char checknumber[10];
    gets_s(checknumber);
    if(sscanf(checknumber,"%d",&checkNumber)==1)
        ;
    else{
        printf("��������������������룡\n");
        goto loop3;
    }
    if(checkNumber==0)
    {
        printf("��δ�м���¼\n");
    }
    else
    {
        printf("����������ÿ�μ�����---��ʽ���£�100 ");
        while (checkNumber--)
        {
           loop4: int c;
            char cc[20];
            gets_s(cc);
            if(sscanf(cc,"%d",&c)==1);
            else{
                printf("��������������������룡\n");
                    goto loop4;
            }
            temp->mdIn.exam.cost[temp->mdIn.exam.costcount++]=c;
            temp->mdIn.exam.SumCost+=c;
        }  
    }
    //���뿪ҩ��¼
   loop5: printf("�������뿪ҩ��������δ����ҩ��������0\n");
    int medicount;
    char medicount1[100];
    gets_s(medicount1);
    if(sscanf(medicount1,"%d",&medicount)==1);
    else{
        printf("��������������������룡\n");
        goto loop5;
    }
    if(medicount==0)
    {
        printf("��δ���п�ҩ��¼.\n");
    }
    else
    {
        while(medicount--)
        {
            loop6:printf("�������뿪ҩ��¼---��ʽ���£�ҩƷ���� ���� ����\n");
            char medi[200];
            gets_s(medi);
            if(sscanf(medi,"%s %d %d",temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].name,&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].UnitPrice),&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number))==3);
            else{
                printf("��������������������룡\n");
                    goto loop6;
            }
            temp->mdIn.prmd.SumDrugCost+=temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount++].cost;
        }
        
    }
    //����סԺ��¼
    
    loop7:printf("��������סԺ��¼---��ʽ���£���סԺ��ʼ��¼����/��/ʱ/�� ��Ԥ�ڳ�Ժ���ڣ���/��/ʱ/�� סԺѺ��\n");
    char hospitalr[200];
    gets_s(hospitalr);
    if(sscanf(hospitalr,"%d/%d/%d/%d %d/%d/%d/%d %d",&temp->mdIn.hosp.beginDate.month,&temp->mdIn.hosp.beginDate.day
    ,&temp->mdIn.hosp.beginDate.hour,&temp->mdIn.hosp.beginDate.minute,&temp->mdIn.hosp.leaveDate.month,
    &temp->mdIn.hosp.leaveDate.day,&temp->mdIn.hosp.leaveDate.hour,&temp->mdIn.hosp.leaveDate.minute,&temp->mdIn.hosp.deposit)==9);
    else{
        printf("��������������������룡\n");
        goto loop7;
    }
    if(temp->mdIn.hosp.deposit < temp->mdIn.hosp.leastdeposit)
    {
        printf("����Ѻ����");
    }
    else if(temp->mdIn.hosp.deposit<temp->mdIn.hosp.deposit)
    {
        printf("����Ѻ�������ͱ�׼");
    } 
    //����ǰ��¼�������
    
    temp->before=pointer;
    pointer->next=temp;
    pointer=temp;
}
void func1()
{
    char a[10];
    while(1)
    {
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
}
void faultdeal()
{
    printf("���¿�ʼ���룡");
    AddMedicalRecords();
}