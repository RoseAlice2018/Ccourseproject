
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
        while (t->doIn.ID != 0)//ҽ����Ϣ��Ч
        {
            isnull = 1;
            printf("ҽ�����ţ�%d ҽ��������%s ҽ������%d ҽ���������ţ�%s\n", t->doIn.ID, t->doIn.name, t->doIn.level, t->doIn.department);
            printf("ҽ������ʱ�䣺");
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
            printf("ҽ���Ƿ��������");
            if (onwork == 1)
                printf("��");
            else
                printf("��");
            printf("    ҽ������������%d\n\n", workdays);


        }

    }
    if (isnull == 0)
        printf("��ǰ��ҽ��������Ϣ\n");
    fflush(stdin);
    getchar();
    printf("���س���������һ��\n");
    fflush(stdin);
    int w=getchar();
    fflush(stdin);
}

void showMedicalInfoinPeriods()
{
    printf("�������ѯ��ʼʱ�䣨�� �� ʱ �֣���\n");
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
    printf("�������ѯ����ʱ�䣨�� �� ʱ �֣���\n");
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
            printf("����������%s ���߱�ţ�%d �������䣺%d\n", t->paIn.name, t->paIn.ID, t->paIn.age);
            printf("����������Ϣ��\n");
            if (f_medi == 1)
            {
                printf("��ҩ��¼:\n");
                while (t->mdIn.detailedprmd.next != NULL)
                {
                    if (t->mdIn.detailedprmd.prescribetime.month > startmonth)
                        printf("ʱ�䣺%d��%d��%dʱ%d�֣�ҩƷ���ƣ�%s����ҩ������%d�� ��ҩҽ��������%s����ҩҽ�����ţ�%d\n", 
                            t->mdIn.detailedprmd.prescribetime.month, t->mdIn.detailedprmd.prescribetime.day, t->mdIn.detailedprmd.prescribetime.hour, t->mdIn.detailedprmd.prescribetime.minute, 
                            t->mdIn.detailedprmd.medicinename, t->mdIn.detailedprmd.medicinecount, t->mdIn.detailedprmd.Doctorname, t->mdIn.detailedprmd.DoctorID);
                    else if (t->mdIn.detailedprmd.prescribetime.month == startmonth && t->mdIn.detailedprmd.prescribetime.day > startday)
                        printf("ʱ�䣺%d��%d��%dʱ%d�֣�ҩƷ���ƣ�%s����ҩ������%d�� ��ҩҽ��������%s����ҩҽ�����ţ�%d\n", 
                            t->mdIn.detailedprmd.prescribetime.month, t->mdIn.detailedprmd.prescribetime.day, t->mdIn.detailedprmd.prescribetime.hour, t->mdIn.detailedprmd.prescribetime.minute, 
                            t->mdIn.detailedprmd.medicinename, t->mdIn.detailedprmd.medicinecount, t->mdIn.detailedprmd.Doctorname, t->mdIn.detailedprmd.DoctorID);
                    else if (t->mdIn.detailedprmd.prescribetime.month == startmonth && t->mdIn.detailedprmd.prescribetime.day == startday && t->mdIn.detailedprmd.prescribetime.hour > starthour)
                        printf("ʱ�䣺%d��%d��%dʱ%d�֣�ҩƷ���ƣ�%s����ҩ������%d�� ��ҩҽ��������%s����ҩҽ�����ţ�%d\n", 
                            t->mdIn.detailedprmd.prescribetime.month, t->mdIn.detailedprmd.prescribetime.day, t->mdIn.detailedprmd.prescribetime.hour, t->mdIn.detailedprmd.prescribetime.minute, 
                            t->mdIn.detailedprmd.medicinename, t->mdIn.detailedprmd.medicinecount, t->mdIn.detailedprmd.Doctorname, t->mdIn.detailedprmd.DoctorID);
                    else if (t->mdIn.detailedprmd.prescribetime.month == startmonth && t->mdIn.detailedprmd.prescribetime.day == startday && t->mdIn.detailedprmd.prescribetime.hour == starthour && t->mdIn.detailedprmd.prescribetime.minute > startminute)
                        printf("ʱ�䣺%d��%d��%dʱ%d�֣�ҩƷ���ƣ�%s����ҩ������%d�� ��ҩҽ��������%s����ҩҽ�����ţ�%d\n", 
                            t->mdIn.detailedprmd.prescribetime.month, t->mdIn.detailedprmd.prescribetime.day, t->mdIn.detailedprmd.prescribetime.hour, t->mdIn.detailedprmd.prescribetime.minute, 
                            t->mdIn.detailedprmd.medicinename, t->mdIn.detailedprmd.medicinecount, t->mdIn.detailedprmd.Doctorname, t->mdIn.detailedprmd.DoctorID);
                }
            }
            if (f_exam == 1)
            {
                printf("����¼:\n");
                while (t->mdIn.detailedexam.next != NULL)
                {
                    if (t->mdIn.detailedexam.examtime.month > startmonth)
                        printf("ʱ�䣺%d��%d��%dʱ%d�֣������Ŀ��%s��  ���ҽ��������%s�����ҽ�����ţ�%d\n",
                            t->mdIn.detailedexam.examtime.month, t->mdIn.detailedexam.examtime.day, t->mdIn.detailedexam.examtime.hour, t->mdIn.detailedexam.examtime.minute,
                            t->mdIn.detailedexam.project, t->mdIn.detailedexam.Doctorname, t->mdIn.detailedexam.DoctorID);
                    else if (t->mdIn.detailedexam.examtime.month == startmonth && t->mdIn.detailedexam.examtime.day > startday)
                        printf("ʱ�䣺%d��%d��%dʱ%d�֣������Ŀ��%s��  ���ҽ��������%s�����ҽ�����ţ�%d\n",
                            t->mdIn.detailedexam.examtime.month, t->mdIn.detailedexam.examtime.day, t->mdIn.detailedexam.examtime.hour, t->mdIn.detailedexam.examtime.minute,
                            t->mdIn.detailedexam.project, t->mdIn.detailedexam.Doctorname, t->mdIn.detailedexam.DoctorID);
                    else if (t->mdIn.detailedexam.examtime.month == startmonth && t->mdIn.detailedexam.examtime.day == startday && t->mdIn.detailedexam.examtime.hour > starthour)
                        printf("ʱ�䣺%d��%d��%dʱ%d�֣������Ŀ��%s��  ���ҽ��������%s�����ҽ�����ţ�%d\n",
                            t->mdIn.detailedexam.examtime.month, t->mdIn.detailedexam.examtime.day, t->mdIn.detailedexam.examtime.hour, t->mdIn.detailedexam.examtime.minute,
                            t->mdIn.detailedexam.project, t->mdIn.detailedexam.Doctorname, t->mdIn.detailedexam.DoctorID);
                    else if (t->mdIn.detailedexam.examtime.month == startmonth && t->mdIn.detailedexam.examtime.day == startday && t->mdIn.detailedexam.examtime.hour == starthour && t->mdIn.detailedexam.examtime.minute > startminute)
                        printf("ʱ�䣺%d��%d��%dʱ%d�֣������Ŀ��%s��  ���ҽ��������%s����ҩҽ�����ţ�%d\n",
                            t->mdIn.detailedexam.examtime.month, t->mdIn.detailedexam.examtime.day, t->mdIn.detailedexam.examtime.hour, t->mdIn.detailedexam.examtime.minute,
                            t->mdIn.detailedexam.project, t->mdIn.detailedexam.Doctorname, t->mdIn.detailedexam.DoctorID);
                }
            }
            if (f_hosp == 1)
            {
                printf("סԺ��Ϣ��\n");
                printf("��Ժʱ�䣺");
                printf("%d��%d��%dʱ%d��", t->mdIn.hosp.beginDate.month, t->mdIn.hosp.beginDate.day, t->mdIn.hosp.beginDate.hour, t->mdIn.hosp.beginDate.minute);
            }
            printf("\n");
        }
        if (flag == 1)
            isnull = 1;

    }
    if (isnull == 0)
        printf("��ʱ����������Ƽ�¼\n");
    printf("���س���������һ��");
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
