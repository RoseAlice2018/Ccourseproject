
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

void showDoctorWorkingStatus()
{
    time_t rawtime; 
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    MedicalRecords* t = records;
    int isnull = 0;
    while (t->next != NULL)
    {
        while (t->doIn.ID != 0)//医生信息有效
        {
            isnull = 1;
            printf("医生工号：%d 医生姓名：%s 医生级别：%d 医生所属部门：%s\n", t->doIn.ID, t->doIn.name, t->doIn.level, t->doIn.department);
            printf("医生出诊时间：");
            int workdays = 0;
            int onwork = 0;
            for (int i = 1; i <= 7; i++)
            {
                if (t->doIn.date[i] == 1)
                {
                    workdays++;
                    if (i == 1)
                        printf("Mon ");
                    else if (i == 2)
                        printf("Tue ");
                    else if (i == 3)
                        printf("wed ");
                    else if (i == 4)
                        printf("Thur ");
                    else if (i == 5)
                        printf("Fri ");
                    else if (i == 6)
                        printf("Sat ");
                    else
                        printf("Sun ");
                    if (i == timeinfo->tm_wday)
                        onwork = 1;
                    else if (i == 7 && timeinfo->tm_wday == 0)
                        onwork = 1;
                }

            }
            printf("医生是否正在坐诊：");
            if (onwork == 1)
                printf("是");
            else
                printf("否");
            printf("    医生工作天数：%d\n\n", workdays);


        }

    }
    if (isnull == 0)
        printf("当前无医生出诊信息\n");
    fflush(stdin);
    getchar();
    printf("按回车键返回上一级\n");
    fflush(stdin);
    int w=getchar();
    fflush(stdin);
}

void showMedicalInfoinPeriods()
{
    printf("请输入查询起始时间（月 日 时 分）：\n");
 //   char starttime[20];
 //   char c;
    int startmonth=0;
    int startday = 0;
    int starthour = 0;
    int startminute=0;
  //  int pricision = 0;
    //c = getchar();
    //while (c != '\n')
    //{
    //    if (c != ' ')
    //    {
    //        if (pricision == 0)
    //            startmonth = startmonth * 10 + c - 48;
    //        if (pricision == 1)
    //            startday = startday * 10 + c - 48;
    //        if (pricision == 2)
    //            starthour = starthour * 10 + c - 48;
    //        if (pricision == 3)
    //            startminute = startminute * 10 + c - 48;
    //    }
    //    if (c == ' ')
    //        pricision++;
    //    c = getchar();
    //}
    fflush(stdin);
    scanf("%d %d %d %d",&startmonth,&startday,&starthour,&startminute);
    printf("请输入查询截至时间（月 日 时 分）：\n");
 //   char endtime[20];
 //   char cc;
    int endmonth=0;
    int endday = 0;
    int endhour = 0;
    int endminute=0;
 //   int pricision2 = 0;
    //cc = getchar();
    //while (cc != '\n')
    //{
    //    if (cc != ' ')
    //    {
    //        if (pricision2 == 0)
    //            endmonth = endmonth * 10 + c - 48;
    //        if (pricision2 == 1)
    //            endday = endday * 10 + c - 48;
    //        if (pricision2 == 2)
    //            endhour = endhour * 10 + c - 48;
    //        if (pricision2 == 3)
    //            endminute = endminute * 10 + c - 48;
    //    }
    //    if (cc == ' ')
    //        pricision2++;
    //    cc = getchar();
    //}
    fflush(stdin);
    scanf("%d %d %d %d", &endmonth, &endday, &endhour, &endminute);
    fflush(stdin);
    MedicalRecords* t = records;
    int isnull = 0;
    while (t->next != NULL)
    {
        int flag = 0;
        int f_hosp = 0;
        int f_exam = 0;
        int f_medi = 0;
        if (t->mdIn.hosp.beginDate.month > startmonth)
            flag = f_hosp=1;
        else if (t->mdIn.hosp.beginDate.month == startmonth && t->mdIn.hosp.beginDate.day > startday)
            flag = f_hosp = 1;
        else if (t->mdIn.hosp.beginDate.month == startmonth && t->mdIn.hosp.beginDate.day == startday && t->mdIn.hosp.beginDate.hour > starthour)
            flag = f_hosp = 1;
        else if (t->mdIn.hosp.beginDate.month == startmonth && t->mdIn.hosp.beginDate.day == startday && t->mdIn.hosp.beginDate.hour == starthour && t->mdIn.hosp.beginDate.minute > startminute)
            flag = f_hosp = 1;

        if (flag == 0)
        {
            while (t->mdIn.detailedexam.next != NULL)
            {
                if (t->mdIn.detailedexam.examtime.month > startmonth)
                    flag = f_exam = 1;
                else if (t->mdIn.detailedexam.examtime.month == startmonth && t->mdIn.detailedexam.examtime.day > startday)
                    flag = f_exam = 1;
                else if (t->mdIn.detailedexam.examtime.month == startmonth && t->mdIn.detailedexam.examtime.day == startday && t->mdIn.detailedexam.examtime.hour > starthour)
                    flag = f_exam = 1;
                else if (t->mdIn.detailedexam.examtime.month == startmonth && t->mdIn.detailedexam.examtime.day == startday && t->mdIn.detailedexam.examtime.hour == starthour && t->mdIn.detailedexam.examtime.minute > startminute)
                    flag = f_exam = 1;
            }
        }
        if (flag == 0)
        {
            while (t->mdIn.detailedprmd.next != NULL)
            {
                if (t->mdIn.detailedprmd.prescribetime.month > startmonth)
                    flag = f_medi = 1;
                else if (t->mdIn.detailedprmd.prescribetime.month == startmonth && t->mdIn.detailedprmd.prescribetime.day > startday)
                    flag = f_medi = 1;
                else if (t->mdIn.detailedprmd.prescribetime.month == startmonth && t->mdIn.detailedprmd.prescribetime.day == startday && t->mdIn.detailedprmd.prescribetime.hour > starthour)
                    flag = f_medi = 1;
                else if (t->mdIn.detailedprmd.prescribetime.month == startmonth && t->mdIn.detailedprmd.prescribetime.day == startday && t->mdIn.detailedprmd.prescribetime.hour == starthour && t->mdIn.detailedprmd.prescribetime.minute > startminute)
                    flag = f_medi = 1;
            }
        }
        if (flag == 1)
        {
            printf("患者姓名：%s 患者编号：%d 患者年龄：%d\n", t->paIn.name, t->paIn.ID, t->paIn.age);
            printf("患者诊疗信息：\n");
            if (f_medi == 1)
            {
                printf("开药记录:\n");
                while (t->mdIn.detailedprmd.next != NULL)
                {
                    if (t->mdIn.detailedprmd.prescribetime.month > startmonth)
                        printf("时间：%d月%d日%d时%d分，药品名称：%s，开药数量：%d， 开药医生姓名：%s，开药医生工号：%d\n", 
                            t->mdIn.detailedprmd.prescribetime.month, t->mdIn.detailedprmd.prescribetime.day, t->mdIn.detailedprmd.prescribetime.hour, t->mdIn.detailedprmd.prescribetime.minute, 
                            t->mdIn.detailedprmd.medicinename, t->mdIn.detailedprmd.medicinecount, t->mdIn.detailedprmd.Doctorname, t->mdIn.detailedprmd.DoctorID);
                    else if (t->mdIn.detailedprmd.prescribetime.month == startmonth && t->mdIn.detailedprmd.prescribetime.day > startday)
                        printf("时间：%d月%d日%d时%d分，药品名称：%s，开药数量：%d， 开药医生姓名：%s，开药医生工号：%d\n", 
                            t->mdIn.detailedprmd.prescribetime.month, t->mdIn.detailedprmd.prescribetime.day, t->mdIn.detailedprmd.prescribetime.hour, t->mdIn.detailedprmd.prescribetime.minute, 
                            t->mdIn.detailedprmd.medicinename, t->mdIn.detailedprmd.medicinecount, t->mdIn.detailedprmd.Doctorname, t->mdIn.detailedprmd.DoctorID);
                    else if (t->mdIn.detailedprmd.prescribetime.month == startmonth && t->mdIn.detailedprmd.prescribetime.day == startday && t->mdIn.detailedprmd.prescribetime.hour > starthour)
                        printf("时间：%d月%d日%d时%d分，药品名称：%s，开药数量：%d， 开药医生姓名：%s，开药医生工号：%d\n", 
                            t->mdIn.detailedprmd.prescribetime.month, t->mdIn.detailedprmd.prescribetime.day, t->mdIn.detailedprmd.prescribetime.hour, t->mdIn.detailedprmd.prescribetime.minute, 
                            t->mdIn.detailedprmd.medicinename, t->mdIn.detailedprmd.medicinecount, t->mdIn.detailedprmd.Doctorname, t->mdIn.detailedprmd.DoctorID);
                    else if (t->mdIn.detailedprmd.prescribetime.month == startmonth && t->mdIn.detailedprmd.prescribetime.day == startday && t->mdIn.detailedprmd.prescribetime.hour == starthour && t->mdIn.detailedprmd.prescribetime.minute > startminute)
                        printf("时间：%d月%d日%d时%d分，药品名称：%s，开药数量：%d， 开药医生姓名：%s，开药医生工号：%d\n", 
                            t->mdIn.detailedprmd.prescribetime.month, t->mdIn.detailedprmd.prescribetime.day, t->mdIn.detailedprmd.prescribetime.hour, t->mdIn.detailedprmd.prescribetime.minute, 
                            t->mdIn.detailedprmd.medicinename, t->mdIn.detailedprmd.medicinecount, t->mdIn.detailedprmd.Doctorname, t->mdIn.detailedprmd.DoctorID);
                }
            }
            if (f_exam == 1)
            {
                printf("检查记录:\n");
                while (t->mdIn.detailedexam.next != NULL)
                {
                    if (t->mdIn.detailedexam.examtime.month > startmonth)
                        printf("时间：%d月%d日%d时%d分，检查项目：%s，  检查医生姓名：%s，检查医生工号：%d\n",
                            t->mdIn.detailedexam.examtime.month, t->mdIn.detailedexam.examtime.day, t->mdIn.detailedexam.examtime.hour, t->mdIn.detailedexam.examtime.minute,
                            t->mdIn.detailedexam.project, t->mdIn.detailedexam.Doctorname, t->mdIn.detailedexam.DoctorID);
                    else if (t->mdIn.detailedexam.examtime.month == startmonth && t->mdIn.detailedexam.examtime.day > startday)
                        printf("时间：%d月%d日%d时%d分，检查项目：%s，  检查医生姓名：%s，检查医生工号：%d\n",
                            t->mdIn.detailedexam.examtime.month, t->mdIn.detailedexam.examtime.day, t->mdIn.detailedexam.examtime.hour, t->mdIn.detailedexam.examtime.minute,
                            t->mdIn.detailedexam.project, t->mdIn.detailedexam.Doctorname, t->mdIn.detailedexam.DoctorID);
                    else if (t->mdIn.detailedexam.examtime.month == startmonth && t->mdIn.detailedexam.examtime.day == startday && t->mdIn.detailedexam.examtime.hour > starthour)
                        printf("时间：%d月%d日%d时%d分，检查项目：%s，  检查医生姓名：%s，检查医生工号：%d\n",
                            t->mdIn.detailedexam.examtime.month, t->mdIn.detailedexam.examtime.day, t->mdIn.detailedexam.examtime.hour, t->mdIn.detailedexam.examtime.minute,
                            t->mdIn.detailedexam.project, t->mdIn.detailedexam.Doctorname, t->mdIn.detailedexam.DoctorID);
                    else if (t->mdIn.detailedexam.examtime.month == startmonth && t->mdIn.detailedexam.examtime.day == startday && t->mdIn.detailedexam.examtime.hour == starthour && t->mdIn.detailedexam.examtime.minute > startminute)
                        printf("时间：%d月%d日%d时%d分，检查项目：%s，  检查医生姓名：%s，开药医生工号：%d\n",
                            t->mdIn.detailedexam.examtime.month, t->mdIn.detailedexam.examtime.day, t->mdIn.detailedexam.examtime.hour, t->mdIn.detailedexam.examtime.minute,
                            t->mdIn.detailedexam.project, t->mdIn.detailedexam.Doctorname, t->mdIn.detailedexam.DoctorID);
                }
            }
            if (f_hosp == 1)
            {
                printf("住院信息：\n");
                printf("入院时间：");
                printf("%d月%d日%d时%d分", t->mdIn.hosp.beginDate.month, t->mdIn.hosp.beginDate.day, t->mdIn.hosp.beginDate.hour, t->mdIn.hosp.beginDate.minute);
            }
            printf("\n");
        }
        if (flag == 1)
            isnull = 1;

    }
    if (isnull == 0)
        printf("该时间段内无诊疗记录\n");
    printf("按回车键返回上一级");
    fflush(stdin);
    getchar();
    char w = getchar();
}

void func4()
{
    char a[10];
    while (1)
    {
        print();
        printf("\t\t\t\t     ★请选择功能★\n\n\t\t\t\t      ① 统计医院目前营业额\n\n\t\t\t\t      ② 生成住院患者报表\n\n\t\t\t\t      ③ 统计医生的出诊情况\n\n\t\t\t\t      ④ 打印某段时间范围内的所有诊疗信息\n\n\t\t\t\t      ⑤ 返回上一级\n\n\t\t\t\t");
        printf("\n\t\t\t\t      请选择：");
        scanf("%s", a);
        printf("\n");
        if (strlen(a) != 1)
        {
            printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
            Sleep(1000);
            func4();
        }
        else if (!strcmp(a, "1"))
            showProfit();
        else if (!strcmp(a, "2"))
            showPatientForm();
        else if (!strcmp(a, "3"))
            showDoctorWorkingStatus();
        else if (!strcmp(a, "4"))
            showMedicalInfoinPeriods();
        else if (!strcmp(a, "5"))
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
