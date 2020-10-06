
void showProfit() // 统计医院目前的营业额
{
	MedicalRecords* t=records;
	int Profit=0;
	/*******系统时间********/ 
	time_t T;
	struct tm*p;
	time(&T);
	p=localtime(&T);
    /**********************/ 
    while(t->next!=NULL)
    {
    	int hospcost=0;
    	if(p->tm_hour<8)	//住院费 
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
    printf("医院目前的营业额为：%d 元\n",Profit);
}

void showPatientForm() // 生成目前住院患者表 
{
	print();
	printf("\n");
	/*******系统时间********/ 
	time_t T;
	struct tm*p;
	time(&T);
	p=localtime(&T);
    /**********************/
	MedicalRecords* t=records;
	while(t->next!=NULL)
	{
		printf("患者姓名：%s  挂号：%d\n",t->paIn.name,t->paIn.ID);
		printf("住院开始日期：%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
        printf("住院预期结束日期: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);
        
		int hospcost=0;
    	if(p->tm_hour<8)	//住院费 
    	{
    		hospcost=200*(p->tm_mday-1-t->mdIn.hosp.beginDate.day+1);
		}else
		{
			hospcost=200*(p->tm_mday-t->mdIn.hosp.beginDate.day+1);
		}
		printf("当前剩余押金：%d\n",t->mdIn.hosp.deposit-hospcost); 
	}
}

void func4()
{
    char a[10];
    while(1)
    {
        print();
        printf("\t\t\t\t     ★请选择功能★\n\n\t\t\t\t      ① 统计医院目前营业额\n\n\t\t\t\t      ② 生成住院患者报表\n\n\t\t\t\t      ③ 统计医生的出诊情况\n\n\t\t\t\t      ④ 打印某段时间范围内的所有诊疗信息\n\n\t\t\t\t      ⑤ 返回上一级\n\n\t\t\t\t");
        printf("\n\t\t\t\t      请选择：");
        scanf("%s",a);
        printf("\n");
        if(strlen(a)!=1)
        {
            printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
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
                printf("\n\t\t\t\t   × 输入错误，请重新输入!\n");
                Sleep(1000);
                func4();
        }
    }
}
