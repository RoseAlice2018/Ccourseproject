
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
    printf("��������׼��ʽ����������Ϣ\n");
    printf("�������뻼����Ϣ---��ʽ���£����� ���� �Һ�\n");
    scanf("%s %d %d",temp->paIn.name,&temp->paIn.age,&temp->paIn.ID);
    //ID���� 
    printf("��������ҽ����Ϣ---��ʽ���£����� ���� ���� ���� ����ʱ�䣨ʱ���ʽ��1 Mon 2 Tue 3 Wed Ĭ��������0\n");
    scanf("%s %d %s %d",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID);
    //�������ʱ��
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
    printf("�����������������\n");
    printf("�����������������δ�м��������0\n");
    int checkNumber=0;
    scanf("%d",&checkNumber);
    if(checkNumber==0)
    {
        printf("��δ�м���¼\n");
    }
    else
    {
        printf("����������ÿ�μ�����---��ʽ���£�100 ");
        while (checkNumber--)
        {
            int c;
            scanf("%d",&c);
            temp->mdIn.exam.cost[temp->mdIn.exam.costcount++]=c;
            temp->mdIn.exam.SumCost+=c;
        }  
    }
    //���뿪ҩ��¼
    printf("�������뿪ҩ��������δ����ҩ��������0\n");
    int medicount;
    scanf("%d",&medicount);
    if(medicount==0)
    {
        printf("��δ���п�ҩ��¼.\n");
    }
    else
    {
        while(medicount--)
        {
            printf("�������뿪ҩ��¼---��ʽ���£�ҩƷ���� ���� ����\n");
            scanf("%s %d %d",temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].name,&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].UnitPrice),&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number));
            temp->mdIn.prmd.SumDrugCost+=temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount++].cost;
        }
        
    }
    //����סԺ��¼
    
    printf("��������סԺ��¼---��ʽ���£���סԺ��ʼ��¼����/��/ʱ/�� ��Ԥ�ڳ�Ժ���ڣ���/��/ʱ/�� סԺѺ��\n");
    scanf("%d/%d/%d/%d %d/%d/%d/%d %d",&temp->mdIn.hosp.beginDate.month,&temp->mdIn.hosp.beginDate.day
    ,&temp->mdIn.hosp.beginDate.hour,&temp->mdIn.hosp.beginDate.minute,&temp->mdIn.hosp.leaveDate.month,
    &temp->mdIn.hosp.leaveDate.day,&temp->mdIn.hosp.leaveDate.hour,&temp->mdIn.hosp.leaveDate.minute,&temp->mdIn.hosp.deposit);
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
