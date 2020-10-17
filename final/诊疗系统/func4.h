
int showHospcost(MedicalRecords* t = records)
{
	time_t T;
	struct tm* p;
	time(&T);
	p = localtime(&T);
	int hospcost = 0;
	//	if (p->tm_hour < 8)	//סԺ�� 
	//	{
	if (t->mdIn.hosp.leaveDate.month > (p->tm_mon + 1) ||//��δ��Ժ�����8��֮ǰ�ѳ�Ժ
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
	else//����֮ǰ��Ժ
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
void showProfit() // ͳ��ҽԺĿǰ��Ӫҵ��
{
	MedicalRecords* t = records;
	int Profit = 0;
	/*******ϵͳʱ��********/
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
	printf("ҽԺĿǰ��Ӫҵ��Ϊ��%d Ԫ\n", Profit);
	printf("���س�������");
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
	getchar();

}

void showPatientForm() // ����ĿǰסԺ���߱� 
{
	print();
	printf("\n");
	/*******ϵͳʱ��********/
	time_t T;
	struct tm* p;
	time(&T);
	p = localtime(&T);
	/**********************/
	MedicalRecords* t = records;

	while (t->next != NULL)
	{
		t = t->next;
		//��Ժʱ����ڵ�ǰʱ��
		if (t->mdIn.hosp.leaveDate.month > (p->tm_mon + 1) ||
			t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1) && t->mdIn.hosp.leaveDate.day > p->tm_mday ||
			t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1) && t->mdIn.hosp.leaveDate.day == p->tm_mday &&
			t->mdIn.hosp.leaveDate.hour > p->tm_hour ||
			t->mdIn.hosp.leaveDate.month == (p->tm_mon + 1) && t->mdIn.hosp.leaveDate.day == p->tm_mday &&
			t->mdIn.hosp.leaveDate.hour == p->tm_hour && t->mdIn.hosp.leaveDate.minute > p->tm_min)
		{
			printf("����������%s  �Һţ�%s\n", t->paIn.name, t->paIn.ID);
			printf("סԺ��ʼ���ڣ�%d/%d/%d/%d\n", t->mdIn.hosp.beginDate.month, t->mdIn.hosp.beginDate.day, t->mdIn.hosp.beginDate.hour, t->mdIn.hosp.beginDate.minute);
			printf("סԺԤ�ڽ�������: %d/%d/%d/%d\n", t->mdIn.hosp.leaveDate.month, t->mdIn.hosp.leaveDate.day, t->mdIn.hosp.leaveDate.hour, t->mdIn.hosp.leaveDate.minute);
		}
		int hospcost = 0;
		if (t->mdIn.hosp.leaveDate.month > (p->tm_mon + 1) ||//��δ��Ժ�����8��֮ǰ�ѳ�Ժ
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

		//if (p->tm_hour < 8)	//סԺ�� 
		//{
		//	hospcost = 200 * (p->tm_mday - 1 - t->mdIn.hosp.beginDate.day + 1);
		//}
		//else
		//{
		//	hospcost = 200 * (p->tm_mday - t->mdIn.hosp.beginDate.day + 1);
		//}
		printf("��ǰʣ��Ѻ��%d", t->mdIn.hosp.deposit - hospcost);
		if (t->mdIn.hosp.deposit - hospcost < 1000)
			printf("��Ѻ���㣬�û�����Ҫ����Ѻ��");
		printf("\n");
	}
	printf("���س�������");
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
		if (t->doIn.ID != 0)//ҽ����Ϣ��Ч
		{
			isnull = 1;
			print();
			printf("\n");
			docnum++;
			printf("%d.ҽ�����ţ�%s ������%s ����%s �������ţ�%s\n", docnum, t->doIn.ID, t->doIn.name, t->doIn.level, t->doIn.department);
			printf(" ҽ������ʱ�䣺");
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
			printf(" ҽ���Ƿ��������");
			if (onwork == 1)
				printf("��");
			else
				printf("��");
			printf("    ҽ������������%d\n\n", workdays);


		}
		//t = t->next;
	}
	if (isnull == 0)
		printf("��ǰ��ҽ��������Ϣ\n");
	fflush(stdin);
	getchar();
	printf("���س�������\n");
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
		printf("��������������������룡\n");
		Sleep(1000);
		getquerytime(querytime);
	}

}
void showMedicalInfoinPeriods()
{
	/*******ϵͳʱ��********/
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

	printf("�������ѯ��ʼʱ��---��ʽ���£���/��/ʱ/��\n");
	getquerytime(starttime);
	printf("�������ѯ����ʱ��---��ʽ���£���/��/ʱ/��\n");
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
			printf("%d.����������%s  ��ţ�%s  ���䣺%d\n", recordnum, t->paIn.name, t->paIn.ID, t->paIn.age);
			if (medinotnull == 1)
			{
				printf(" ��ҩ��Ϣ��\n");
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
						printf("  ��ҩʱ�䣺%d��%d��%dʱ%d��  ҩƷ���ƣ�%s  ��ҩ������%d  ҩƷ���ã�%d  \n",
							t->mdIn.prmd.drug[i].prescribetime.month, t->mdIn.prmd.drug[i].prescribetime.day,
							t->mdIn.prmd.drug[i].prescribetime.hour, t->mdIn.prmd.drug[i].prescribetime.minute,
							t->mdIn.prmd.drug[i].name, t->mdIn.prmd.drug[i].Number, t->mdIn.prmd.drug[i].Price);
					}
				}
			}
			if (examnotnull == 1)
			{
				printf(" �����Ϣ��\n");
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
						printf("  ���ʱ�䣺%d��%d��%dʱ%d��  �����ã�%d \n",
							t->mdIn.exam.examproj[i].examtime.month, t->mdIn.exam.examproj[i].examtime.day,
							t->mdIn.exam.examproj[i].examtime.hour, t->mdIn.exam.examproj[i].examtime.minute,
							t->mdIn.exam.examproj[i].examcost);
					}
				}
			}
			if (hospnotnull == 1)
			{
				printf(" סԺ��Ϣ��\n");
				if (beginhosp == 1)
				{
					printf("  ��Ժʱ�䣺%d��%d��%dʱ%d��\n",
						t->mdIn.hosp.beginDate.month, t->mdIn.hosp.beginDate.day,
						t->mdIn.hosp.beginDate.hour, t->mdIn.hosp.beginDate.minute);
				}
				if (leavehosp == 1)
				{
					printf("  ��Ժʱ�䣺%d��%d��%dʱ%d��\n",
						t->mdIn.hosp.leaveDate.month, t->mdIn.hosp.leaveDate.day,
						t->mdIn.hosp.leaveDate.hour, t->mdIn.hosp.leaveDate.minute);

				}
			}
			printf("\n");
		}

	}
	if (recordnum == 0)
		printf("��ʱ���������������Ϣ\n");
	printf("���س�������\n");
	getchar();

}

void func4()
{
	char a[10];
	while (1)
	{
		print();
		printf("\t\t\t\t     ����ѡ���ܡ�\n\n\t\t\t\t      �� ͳ��ҽԺĿǰӪҵ��\n\n\t\t\t\t      �� ����סԺ���߱���\n\n\t\t\t\t      �� ͳ��ҽ���ĳ������\n\n\t\t\t\t      �� ��ӡĳ��ʱ�䷶Χ�ڵ�����������Ϣ\n\n\t\t\t\t      �� ������һ��\n\n\t\t\t\t");
		printf("\n\t\t\t\t      ��ѡ��");
		scanf("%s", a);
		printf("\n");
		if (strlen(a) != 1)
		{
			printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
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
			printf("\n\t\t\t\t   �� �����������������!\n");
			Sleep(1000);
			func4();
		}
	}
}

