
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
    printf("请您按标准格式输入如下信息\n");
    printf("请您输入患者信息---格式如下：姓名 年龄 挂号\n");
    scanf("%s %d %d",temp->paIn.name,&temp->paIn.age,&temp->paIn.ID);
    //ID计算 
    printf("请您输入医生信息---格式如下：姓名 级别 科室 工号 出诊时间（时间格式：1 Mon 2 Tue 3 Wed 默认请输入0\n");
    scanf("%s %d %s %d",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID);
    //插入出诊时间
    char time[20];
    scanf("%s",time);
    if(time[0]=='0')
    {
        for(int i=1;i<=7;i++)
            {
                temp->doIn.date[i]=1;//1 表示在值班
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
    //插入department
    insertDepartment(temp->doIn.department);
    //输入检查状况
    printf("请您输入诊疗情况：\n");
    printf("请您输入检查次数：如未有检查请输入0\n");
    int checkNumber=0;
    scanf("%d",&checkNumber);
    if(checkNumber==0)
    {
        printf("您未有检查记录\n");
    }
    else
    {
        printf("请依次输入每次检查费用---格式如下：100 ");
        while (checkNumber--)
        {
            int c;
            scanf("%d",&c);
            temp->mdIn.exam.cost[temp->mdIn.exam.costcount++]=c;
            temp->mdIn.exam.SumCost+=c;
        }  
    }
    //输入开药记录
    printf("请您输入开药次数：如未曾开药，请输入0\n");
    int medicount;
    scanf("%d",&medicount);
    if(medicount==0)
    {
        printf("您未曾有开药记录.\n");
    }
    else
    {
        while(medicount--)
        {
            printf("请您输入开药记录---格式如下：药品名称 单价 数量\n");
            scanf("%s %d %d",temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].name,&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].UnitPrice),&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number));
            temp->mdIn.prmd.SumDrugCost+=temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount++].cost;
        }
        
    }
    //输入住院记录
    
    printf("请您输入住院记录---格式如下：（住院开始记录）月/日/时/分 （预期出院日期）月/日/时/分 住院押金\n");
    scanf("%d/%d/%d/%d %d/%d/%d/%d %d",&temp->mdIn.hosp.beginDate.month,&temp->mdIn.hosp.beginDate.day
    ,&temp->mdIn.hosp.beginDate.hour,&temp->mdIn.hosp.beginDate.minute,&temp->mdIn.hosp.leaveDate.month,
    &temp->mdIn.hosp.leaveDate.day,&temp->mdIn.hosp.leaveDate.hour,&temp->mdIn.hosp.leaveDate.minute,&temp->mdIn.hosp.deposit);
    if(temp->mdIn.hosp.deposit < temp->mdIn.hosp.leastdeposit)
    {
        printf("您的押金不足");
    }
    else if(temp->mdIn.hosp.deposit<temp->mdIn.hosp.deposit)
    {
        printf("您的押金低于最低标准");
    } 
    //将当前记录链入表中
    
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
}
