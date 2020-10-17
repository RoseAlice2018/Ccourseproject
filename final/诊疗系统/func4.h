
int showHospcost(MedicalRecords* t = records)
{
	time_t T;
	struct tm* p;
	time(&T);
	p = localtime(&T);
	int hospcost = 0;
	//	if (p->tm_hour < 8)	//住院费 
	//	{
	if (t->mdIn.hosp.leaveDate.month > (p->tm_mon + 1) ||//尚未出院或今日8点之前已出院
		t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1) && t->mdIn.hosp.leaveDate.day >= p->tm_mday)
	{
		if (p->tm_hour < 8)
			hospcost = 200 * (p->tm_mday - t->mdIn.hosp.beginDate.day);
		else
		{
			if (t->mdIn.hosp.leaveDate.hour < 8)
				hospcost = 200 * (p->tm_mday - t->mdIn.hosp.beginDate.day);
			if (t->mdIn.hosp.leaveDate.hour > 8)
				hospcost = 200 * (p->tm_mday - t->mdIn.hosp.beginDate.day + 1);
		}
	}
	else//昨天之前出院
	{
		if (t->mdIn.hosp.beginDate.month == t->mdIn.hosp.leaveDate.month)
			hospcost = 200 * (t->mdIn.hosp.leaveDate.day - t->mdIn.hosp.beginDate.day);
		else
		{
			int days = 0;
			for (int i = t->mdIn.hosp.beginDate.month; i < t->mdIn.hosp.leaveDate.month; i++)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					days += 31;
				else if (i == 2)
					days += 28;
				else
					days += 30;
			}
			int i = t->mdIn.hosp.beginDate.month;
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				days -= (31 - t->mdIn.hosp.beginDate.day + 1);
			if (t->mdIn.hosp.leaveDate.hour < 7)
				days += (t->mdIn.hosp.leaveDate.day - 1);
			else
				days += t->mdIn.hosp.leaveDate.day;
			hospcost = 200 * days;
		}
	}
	return hospcost;
}
void showProfit() // 统计医院目前的营业额
{
	MedicalRecords* t = records;
	int Profit = 0;
	/*******系统时间********/
	time_t T;
	struct tm* p;
	time(&T);
	p = localtime(&T);
	/**********************/
	while (t->next != NULL)
	{
		t = t->next;
		int hospcost = showHospcost(t);
		
		if (t->mdIn.exam.SumCost > 0)
			Profit += t->mdIn.exam.SumCost;
		if (t->mdIn.prmd.SumDrugCost > 0)
			Profit += t->mdIn.prmd.SumDrugCost;
		Profit += hospcost;
	}

	print();
	printf("\n");
	printf("医院目前的营业额为：%d 元\n", Profit);
	printf("按回车键继续");
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
	getchar();

}

void showPatientForm() // 生成目前住院患者表 
{
	print();
	printf("\n");
	/*******系统时间********/
	time_t T;
	struct tm* p;
	time(&T);
	p = localtime(&T);
	/**********************/
	MedicalRecords* t = records;

	while (t->next != NULL)
	{
		t = t->next;
		//出院时间大于当前时间
		if (t->mdIn.hosp.leaveDate.month > (p->tm_mon + 1) ||
			t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1) && t->mdIn.hosp.leaveDate.day > p->tm_mday ||
			t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1) && t->mdIn.hosp.leaveDate.day == p->tm_mday &&
			t->mdIn.hosp.leaveDate.hour > p->tm_hour ||
			t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1) && t->mdIn.hosp.leaveDate.day == p->tm_mday &&
			t->mdIn.hosp.leaveDate.hour == p->tm_hour && t->mdIn.hosp.leaveDate.minute > p->tm_min)
		{
			printf("患者姓名：%s  挂号：%s\n", t->paIn.name, t->paIn.ID);
			printf("住院开始日期：%d/%d/%d/%d\n", t->mdIn.hosp.beginDate.month, t->mdIn.hosp.beginDate.day, t->mdIn.hosp.beginDate.hour, t->mdIn.hosp.beginDate.minute);
			printf("住院预期结束日期: %d/%d/%d/%d\n", t->mdIn.hosp.leaveDate.month, t->mdIn.hosp.leaveDate.day, t->mdIn.hosp.leaveDate.hour, t->mdIn.hosp.leaveDate.minute);
		}
		int hospcost = 0;
		if (t->mdIn.hosp.leaveDate.month > (p->tm_mon + 1) ||//尚未出院或今日8点之前已出院
			t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1) && t->mdIn.hosp.leaveDate.day >= p->tm_mday)
		{
			if (p->tm_hour < 8)
				hospcost = 200 * (p->tm_mday - t->mdIn.hosp.beginDate.day);
			else
			{
				if (t->mdIn.hosp.leaveDate.hour < 8)
					hospcost = 200 * (p->tm_mday - t->mdIn.hosp.beginDate.day);
				if (t->mdIn.hosp.leaveDate.hour > 8)
					hospcost = 200 * (p->tm_mday - t->mdIn.hosp.beginDate.day + 1);
			}

		}

		//if (p->tm_hour < 8)	//住院费 
		//{
		//	hospcost = 200 * (p->tm_mday - 1 - t->mdIn.hosp.beginDate.day + 1);
		//}
		//else
		//{
		//	hospcost = 200 * (p->tm_mday - t->mdIn.hosp.beginDate.day + 1);
		//}
		printf("当前剩余押金：%d", t->mdIn.hosp.deposit - hospcost);
		if (t->mdIn.hosp.deposit - hospcost < 1000)
			printf("（押金不足，该患者需要缴纳押金）");
		printf("\n");
	}
	printf("按回车键继续");
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
	getchar();
}

void showDoctorWorkingStatus()
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	MedicalRecords* t = records;
	int isnull = 0;
	int docnum = 0;
	while (t->next != NULL)
	{
		t = t->next;
		if (t->doIn.ID != 0)//医生信息有效
		{
			isnull = 1;
			print();
			printf("\n");
			docnum++;
			printf("%d.医生工号：%s 姓名：%s 级别：%s 所属部门：%s\n", docnum, t->doIn.ID, t->doIn.name, t->doIn.level, t->doIn.department);
			printf(" 医生出诊时间：");
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
			printf(" 医生是否正在坐诊：");
			if (onwork == 1)
				printf("是");
			else
				printf("否");
			printf("    医生工作天数：%d\n\n", workdays);


		}
		//t = t->next;
	}
	if (isnull == 0)
		printf("当前无医生出诊信息\n");
	fflush(stdin);
	getchar();
	printf("按回车键继续\n");
	fflush(stdin);
	int w = getchar();
	fflush(stdin);
}
void getquerytime(Date* querytime)
{
	char time[200];
	fflush(stdin);
	setbuf(stdin, NULL);
	gets(time);
	if (sscanf(time, "%d/%d/%d/%d",
		&querytime->month, &querytime->day, &querytime->hour, &querytime->minute) == 4);
	else {
		printf("您的输入错误！请重新输入！\n");
		Sleep(1000);
		getquerytime(querytime);
	}

}
void showMedicalInfoinPeriods()
{
	/*******系统时间********/
	time_t T;
	struct tm* p;
	time(&T);
	p = localtime(&T);
	/**********************/
	MedicalRecords* t = records;
	Date* starttime = new Date();
	Date* endtime = new Date();
	print();
	printf("\n");

	printf("请输入查询起始时间---格式如下：月/日/时/分\n");
	getquerytime(starttime);
	printf("请输入查询截至时间---格式如下：月/日/时/分\n");
	getquerytime(endtime);

	int recordnum = 0;
	while (t->next != NULL)
	{
		t = t->next;
		int medinotnull = 0;
		int examnotnull = 0;
		int hospnotnull = 0;
		int beginhosp = 0;
		int leavehosp = 0;
		for (int i = 0; i < t->mdIn.prmd.drugcount; i++)
		{
			if ((t->mdIn.prmd.drug[i].prescribetime.month > starttime->month ||
				t->mdIn.prmd.drug[i].prescribetime.month == starttime->month
				&& t->mdIn.prmd.drug[i].prescribetime.day > starttime->day ||
				t->mdIn.prmd.drug[i].prescribetime.month == starttime->month
				&& t->mdIn.prmd.drug[i].prescribetime.day == starttime->day
				&& t->mdIn.prmd.drug[i].prescribetime.hour > starttime->hour ||
				t->mdIn.prmd.drug[i].prescribetime.month == starttime->month
				&& t->mdIn.prmd.drug[i].prescribetime.day == starttime->day
				&& t->mdIn.prmd.drug[i].prescribetime.hour == starttime->hour
				&& t->mdIn.prmd.drug[i].prescribetime.minute > starttime->minute)
				&&
				(t->mdIn.prmd.drug[i].prescribetime.month < endtime->month ||
					t->mdIn.prmd.drug[i].prescribetime.month == endtime->month
					&& t->mdIn.prmd.drug[i].prescribetime.day < endtime->day ||
					t->mdIn.prmd.drug[i].prescribetime.month == endtime->month
					&& t->mdIn.prmd.drug[i].prescribetime.day == endtime->day
					&& t->mdIn.prmd.drug[i].prescribetime.hour < endtime->hour ||
					t->mdIn.prmd.drug[i].prescribetime.month == endtime->month
					&& t->mdIn.prmd.drug[i].prescribetime.day == endtime->day
					&& t->mdIn.prmd.drug[i].prescribetime.hour == endtime->hour
					&& t->mdIn.prmd.drug[i].prescribetime.minute < endtime->minute)
				)
			{
				medinotnull = 1;
				break;
			}
		}
		for (int i = 0; i < t->mdIn.exam.examcount; i++)
		{
			if ((t->mdIn.exam.examproj[i].examtime.month > starttime->month ||
				t->mdIn.exam.examproj[i].examtime.month == starttime->month
				&& t->mdIn.exam.examproj[i].examtime.day > starttime->day ||
				t->mdIn.exam.examproj[i].examtime.month == starttime->month
				&& t->mdIn.exam.examproj[i].examtime.day == starttime->day
				&& t->mdIn.exam.examproj[i].examtime.hour > starttime->hour ||
				t->mdIn.exam.examproj[i].examtime.month == starttime->month
				&& t->mdIn.exam.examproj[i].examtime.day == starttime->day
				&& t->mdIn.exam.examproj[i].examtime.hour == starttime->hour
				&& t->mdIn.exam.examproj[i].examtime.minute > starttime->minute)
				&&
				(t->mdIn.exam.examproj[i].examtime.month < endtime->month ||
					t->mdIn.exam.examproj[i].examtime.month == endtime->month
					&& t->mdIn.exam.examproj[i].examtime.day < endtime->day ||
					t->mdIn.exam.examproj[i].examtime.month == endtime->month
					&& t->mdIn.exam.examproj[i].examtime.day == endtime->day
					&& t->mdIn.exam.examproj[i].examtime.hour < endtime->hour ||
					t->mdIn.exam.examproj[i].examtime.month == endtime->month
					&& t->mdIn.exam.examproj[i].examtime.day == endtime->day
					&& t->mdIn.exam.examproj[i].examtime.hour == endtime->hour
					&& t->mdIn.exam.examproj[i].examtime.minute < endtime->minute))

			{
				examnotnull = 1;
				break;
			}
		}
		if ((t->mdIn.hosp.beginDate.month > starttime->month ||
			t->mdIn.hosp.beginDate.month == starttime->month
			&& t->mdIn.hosp.beginDate.day > starttime->day ||
			t->mdIn.hosp.beginDate.month == starttime->month
			&& t->mdIn.hosp.beginDate.day == starttime->day
			&& t->mdIn.hosp.beginDate.hour > starttime->hour ||
			t->mdIn.hosp.beginDate.month == starttime->month
			&& t->mdIn.hosp.beginDate.day == starttime->day
			&& t->mdIn.hosp.beginDate.hour == starttime->hour
			&& t->mdIn.hosp.beginDate.minute > starttime->minute)
			&&
			(t->mdIn.hosp.beginDate.month < endtime->month ||
				t->mdIn.hosp.beginDate.month == endtime->month
				&& t->mdIn.hosp.beginDate.day < endtime->day ||
				t->mdIn.hosp.beginDate.month == endtime->month
				&& t->mdIn.hosp.beginDate.day == endtime->day
				&& t->mdIn.hosp.beginDate.hour < endtime->hour ||
				t->mdIn.hosp.beginDate.month == endtime->month
				&& t->mdIn.hosp.beginDate.day == endtime->day
				&& t->mdIn.hosp.beginDate.hour == endtime->hour
				&& t->mdIn.hosp.beginDate.minute < endtime->minute))
		{
			hospnotnull = 1;
			beginhosp = 1;
		}
		if ((t->mdIn.hosp.leaveDate.month > starttime->month ||
			t->mdIn.hosp.leaveDate.month == starttime->month
			&& t->mdIn.hosp.leaveDate.day > starttime->day ||
			t->mdIn.hosp.leaveDate.month == starttime->month
			&& t->mdIn.hosp.leaveDate.day == starttime->day
			&& t->mdIn.hosp.leaveDate.hour > starttime->hour ||
			t->mdIn.hosp.leaveDate.month == starttime->month
			&& t->mdIn.hosp.leaveDate.day == starttime->day
			&& t->mdIn.hosp.leaveDate.hour == starttime->hour
			&& t->mdIn.hosp.leaveDate.minute > starttime->minute)
			&&
			(t->mdIn.hosp.leaveDate.month < endtime->month ||
				t->mdIn.hosp.leaveDate.month == endtime->month
				&& t->mdIn.hosp.leaveDate.day < endtime->day ||
				t->mdIn.hosp.leaveDate.month == endtime->month
				&& t->mdIn.hosp.leaveDate.day == endtime->day
				&& t->mdIn.hosp.leaveDate.hour < endtime->hour ||
				t->mdIn.hosp.leaveDate.month == endtime->month
				&& t->mdIn.hosp.leaveDate.day == endtime->day
				&& t->mdIn.hosp.leaveDate.hour == endtime->hour
				&& t->mdIn.hosp.leaveDate.minute < endtime->minute)
			&&
			(t->mdIn.hosp.leaveDate.month < (p->tm_mon + 1) ||
				t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1)
				&& t->mdIn.hosp.leaveDate.day < p->tm_mday ||
				t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1)
				&& t->mdIn.hosp.leaveDate.day == p->tm_mday
				&& t->mdIn.hosp.leaveDate.hour < p->tm_hour ||
				t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1)
				&& t->mdIn.hosp.leaveDate.day == p->tm_mday
				&& t->mdIn.hosp.leaveDate.hour == p->tm_hour
				&& t->mdIn.hosp.leaveDate.minute < p->tm_min))
		{
			hospnotnull = 1;
			leavehosp = 1;
		}
		if (medinotnull || examnotnull || hospnotnull == 1)
		{
			recordnum++;
			printf("%d.患者姓名：%s  编号：%s  年龄：%d\n", recordnum, t->paIn.name, t->paIn.ID, t->paIn.age);
			if (medinotnull == 1)
			{
				printf(" 开药信息：\n");
				for (int i = 0; i < t->mdIn.prmd.drugcount; i++)
				{
					if ((t->mdIn.prmd.drug[i].prescribetime.month > starttime->month ||
						t->mdIn.prmd.drug[i].prescribetime.month == starttime->month
						&& t->mdIn.prmd.drug[i].prescribetime.day > starttime->day ||
						t->mdIn.prmd.drug[i].prescribetime.month == starttime->month
						&& t->mdIn.prmd.drug[i].prescribetime.day == starttime->day
						&& t->mdIn.prmd.drug[i].prescribetime.hour > starttime->hour ||
						t->mdIn.prmd.drug[i].prescribetime.month == starttime->month
						&& t->mdIn.prmd.drug[i].prescribetime.day == starttime->day
						&& t->mdIn.prmd.drug[i].prescribetime.hour == starttime->hour
						&& t->mdIn.prmd.drug[i].prescribetime.minute > starttime->minute)
						&&
						(t->mdIn.prmd.drug[i].prescribetime.month < endtime->month ||
							t->mdIn.prmd.drug[i].prescribetime.month == endtime->month
							&& t->mdIn.prmd.drug[i].prescribetime.day < endtime->day ||
							t->mdIn.prmd.drug[i].prescribetime.month == endtime->month
							&& t->mdIn.prmd.drug[i].prescribetime.day == endtime->day
							&& t->mdIn.prmd.drug[i].prescribetime.hour < endtime->hour ||
							t->mdIn.prmd.drug[i].prescribetime.month == endtime->month
							&& t->mdIn.prmd.drug[i].prescribetime.day == endtime->day
							&& t->mdIn.prmd.drug[i].prescribetime.hour == endtime->hour
							&& t->mdIn.prmd.drug[i].prescribetime.minute < endtime->minute))
					{
						printf("  开药时间：%d月%d日%d时%d分  药品名称：%s  开药数量：%d  药品费用：%d  \n",
							t->mdIn.prmd.drug[i].prescribetime.month, t->mdIn.prmd.drug[i].prescribetime.day,
							t->mdIn.prmd.drug[i].prescribetime.hour, t->mdIn.prmd.drug[i].prescribetime.minute,
							t->mdIn.prmd.drug[i].name, t->mdIn.prmd.drug[i].Number, t->mdIn.prmd.drug[i].Price);
					}
				}
			}
			if (examnotnull == 1)
			{
				printf(" 检查信息：\n");
				for (int i = 0; i < t->mdIn.exam.examcount; i++)
				{
					if ((t->mdIn.exam.examproj[i].examtime.month > starttime->month ||
						t->mdIn.exam.examproj[i].examtime.month == starttime->month
						&& t->mdIn.exam.examproj[i].examtime.day > starttime->day ||
						t->mdIn.exam.examproj[i].examtime.month == starttime->month
						&& t->mdIn.exam.examproj[i].examtime.day == starttime->day
						&& t->mdIn.exam.examproj[i].examtime.hour > starttime->hour ||
						t->mdIn.exam.examproj[i].examtime.month == starttime->month
						&& t->mdIn.exam.examproj[i].examtime.day == starttime->day
						&& t->mdIn.exam.examproj[i].examtime.hour == starttime->hour
						&& t->mdIn.exam.examproj[i].examtime.minute > starttime->minute)
						&&
						(t->mdIn.exam.examproj[i].examtime.month < endtime->month ||
							t->mdIn.exam.examproj[i].examtime.month == endtime->month
							&& t->mdIn.exam.examproj[i].examtime.day < endtime->day ||
							t->mdIn.exam.examproj[i].examtime.month == endtime->month
							&& t->mdIn.exam.examproj[i].examtime.day == endtime->day
							&& t->mdIn.exam.examproj[i].examtime.hour < endtime->hour ||
							t->mdIn.exam.examproj[i].examtime.month == endtime->month
							&& t->mdIn.exam.examproj[i].examtime.day == endtime->day
							&& t->mdIn.exam.examproj[i].examtime.hour == endtime->hour
							&& t->mdIn.exam.examproj[i].examtime.minute < endtime->minute))
					{
						printf("  检查时间：%d月%d日%d时%d分  检查费用：%d \n",
							t->mdIn.exam.examproj[i].examtime.month, t->mdIn.exam.examproj[i].examtime.day,
							t->mdIn.exam.examproj[i].examtime.hour, t->mdIn.exam.examproj[i].examtime.minute,
							t->mdIn.exam.examproj[i].examcost);
					}
				}
			}
			if (hospnotnull == 1)
			{
				printf(" 住院信息：\n");
				if (beginhosp == 1)
				{
					printf("  入院时间：%d月%d日%d时%d分\n",
						t->mdIn.hosp.beginDate.month, t->mdIn.hosp.beginDate.day,
						t->mdIn.hosp.beginDate.hour, t->mdIn.hosp.beginDate.minute);
				}
				if (leavehosp == 1)
				{
					printf("  出院时间：%d月%d日%d时%d分\n",
						t->mdIn.hosp.leaveDate.month, t->mdIn.hosp.leaveDate.day,
						t->mdIn.hosp.leaveDate.hour, t->mdIn.hosp.leaveDate.minute);

				}
			}
			printf("\n");
		}

	}
	if (recordnum == 0)
		printf("该时间段内暂无诊疗信息\n");
	printf("按回车键继续\n");
	getchar();

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

