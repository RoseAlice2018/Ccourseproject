#ifndef FUNC3_H_INCLUDED
#define FUNC3_H_INCLUDED
bool comparee(char A[],char B[])
{
    for(int i=0;i<30;i++)
    {
        // if((A[i]=='\0'&&B[i]!='\0')||(A[i]!='\0'&&B[i]=='\0'))
        // {
        //     return false;
        // }
        if(A[i]!='\0')
        {
            if(A[i]!=B[i])
                return false;
        }
        // if(B[i]!='\0')
        // {
        //     if(B[i]!=A[i])
        //         return false;
        // }
    }
    return true;
}
void showRecordsAccordingtoDepartment()
{
        char name[30];
        scanf("%s",name);
        MedicalRecords* t=records->next;
        printf("����������Ҫ��ӡ����Ϣ��\n");
        printf("1:ҽ����Ϣ\n2:������Ϣ\n3:�������\n4:ȫ����Ϣ\n");
        int tagofrecords=0;
        scanf("%d",&tagofrecords);
        int countCheck=1;//��¼��ǰ�ǵ�i����¼
        while (t!=NULL)
        {
          
            if(strcmp(t->doIn.department,name)==0)
            {  
                printf("��ǰ�ǵ�%d����¼:\n",countCheck++);
                // ��ӡ������Ϣ
                if(tagofrecords==1)
                {
                    printf("ҽ��������%s ҽ������%d ҽ���������ţ�%s ҽ�����ţ�%d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                    //��ӡ����ʱ��
                    printf("ҽ������ʱ�䣺");
                    for(int i=1;i<=7;i++)
                    {
                        if(t->doIn.date[i]==1)
                        {
                            if(i==1)
                                printf("Mon ");
                            else if(i==2)
                                printf("Tue ");
                            else if(i==3)
                                printf("wed ");
                            else if(i==4)
                                printf("Thur ");
                            else if(i==5)
                                printf("Fri ");
                            else if(i==6)
                                printf("Sat ");
                            else 
                                printf("Sun");
                        }
                    }
                    printf("\n");
                }
                else if(tagofrecords==2)
                {
                    printf("����������%s �������䣺%d ����ID��%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                }
                else if(tagofrecords==3)
                {
                    // ����������
                    printf("����ܻ��ѣ�%d\n",t->mdIn.exam.SumCost);
                    printf("ҩ���ܻ���: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("סԺ��ʼ���ڣ�%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("סԺԤ�ڽ�������: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
                else if(tagofrecords==4)
                {
                    //1
                    printf("ҽ��������%s ҽ������%d ҽ���������ţ�%s ҽ�����ţ�%d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                    //��ӡ����ʱ��
                    printf("ҽ������ʱ�䣺");
                    for(int i=1;i<=7;i++)
                    {
                        if(t->doIn.date[i]==1)
                        {
                            if(i==1)
                                printf("Mon ");
                            else if(i==2)
                                printf("Tue ");
                            else if(i==3)
                                printf("wed ");
                            else if(i==4)
                                printf("Thur ");
                            else if(i==5)
                                printf("Fri ");
                            else if(i==6)
                                printf("Sat ");
                            else 
                                printf("Sun");
                        }
                    }
                    printf("\n");
                    //2
                    printf("����������%s �������䣺%d ����ID��%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                    //3
                    // ����������
                    printf("����ܻ��ѣ�%d\n",t->mdIn.exam.SumCost);
                    printf("ҩ���ܻ���: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("סԺ��ʼ���ڣ�%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("סԺԤ�ڽ�������: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
            }
            t=t->next;
        }
        int a;
    printf("������1������չʾ\n");
    scanf("%d",&a);
}
void checkDepartment() // �����Ҽ���������Ϣ
{
    printf("���Ƿ������Ҫ��ѯ�Ŀ������ƣ�True������1�� False������0��\n");
    int tag=0;
    scanf("%d",&tag);
    if(tag==0)
    {
        printf("�Ѿ�Ϊ��׼���ÿ�������\n");
        for(int i=0;i<countDepart;i++)
            printf("%s\n",RealDepartment[i]);
        printf("��������Ҫ��ѯ�Ŀ�������:\n"); 
        showRecordsAccordingtoDepartment();       
    }
    else
    {
        showRecordsAccordingtoDepartment();
    }
    
}

void showDoctor(char inID[])
{
    MedicalRecords* t=records->next;
    printf("����������Ҫ��ӡ����Ϣ��\n");
    printf("1:ҽ����Ϣ\n2:������Ϣ\n3:�������\n4:ȫ����Ϣ\n");
    int tagofrecords=0;
    scanf("%d",&tagofrecords);
    while(t!=NULL)
    {
        if(strcmp(t->doIn.ID,inID)==0)
        {
            // ��ӡ������Ϣ
                if(tagofrecords==1)
                {
                    printf("ҽ��������%s ҽ������%d ҽ���������ţ�%s ҽ�����ţ�%d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                    //��ӡ����ʱ��
                    printf("ҽ������ʱ�䣺");
                    for(int i=1;i<=7;i++)
                    {
                        if(t->doIn.date[i]==1)
                        {
                            if(i==1)
                                printf("Mon ");
                            else if(i==2)
                                printf("Tue ");
                            else if(i==3)
                                printf("wed ");
                            else if(i==4)
                                printf("Thur ");
                            else if(i==5)
                                printf("Fri ");
                            else if(i==6)
                                printf("Sat ");
                            else 
                                printf("Sun");
                        }
                    }
                    printf("\n");
                }
                else if(tagofrecords==2)
                {
                    printf("����������%s �������䣺%d ����ID��%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                }
                else if(tagofrecords==3)
                {
                    // ����������
                    printf("����ܻ��ѣ�%d\n",t->mdIn.exam.SumCost);
                    printf("ҩ���ܻ���: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("סԺ��ʼ���ڣ�%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("סԺԤ�ڽ�������: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
                else if(tagofrecords==4)
                {
                    //1
                    printf("ҽ��������%s ҽ������%d ҽ���������ţ�%s ҽ�����ţ�%d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                    //��ӡ����ʱ��
                    printf("ҽ������ʱ�䣺");
                    for(int i=1;i<=7;i++)
                    {
                        if(t->doIn.date[i]==1)
                        {
                            if(i==1)
                                printf("Mon ");
                            else if(i==2)
                                printf("Tue ");
                            else if(i==3)
                                printf("wed ");
                            else if(i==4)
                                printf("Thur ");
                            else if(i==5)
                                printf("Fri ");
                            else if(i==6)
                                printf("Sat ");
                            else 
                                printf("Sun");
                        }
                    }
                    printf("\n");
                    //2
                    printf("����������%s �������䣺%d ����ID��%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                    //3
                    // ����������
                    printf("����ܻ��ѣ�%d\n",t->mdIn.exam.SumCost);
                    printf("ҩ���ܻ���: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("סԺ��ʼ���ڣ�%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("סԺԤ�ڽ�������: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
        }
        t=t->next;
    }
    int a;
    printf("������1������չʾ\n");
    scanf("%d",&a);
}
//��ӡĳλ���ߵ���ʷ������Ϣ
void showPatientInformation(char ID[40])//? ��ʷ��¼��
{
    MedicalRecords* t=records->next;
    while(t!=NULL)
    {
        //printf("%d\n",atoi(t->paIn.ID));
        if(strcmp(t->paIn.ID,ID)==0)// IDfind
        {
            printf("����������%s ����ҩ���ܻ��ѣ�%d ����סԺѺ��%d\n",t->doIn.name,t->mdIn.prmd.SumDrugCost,t->mdIn.hosp.deposit);
        }
        t=t->next;
        //getchar();
    }
    int a;
    printf("������1������չʾ\n");
    scanf("%d",&a);
}

void func3()
{
    char a[10];
    while(1)
    {
        print();
        printf("\t\t\t\t     ����ѡ���ܡ�\n\n\t\t\t\t      �� ���տ��Ҽ���\n\n\t\t\t\t      �� ����ҽ�����ż���\n\n\t\t\t\t      �� ���ջ��������Ϣ����\n\n\t\t\t\t      �� ������һ��\n\n\t\t\t\t");
        printf("\n\t\t\t\t      ��ѡ��");
        scanf("%s",a);
        printf("\n");
        if(strlen(a)!=1)
        {
            printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
            Sleep(1000);
            func3();
        }
        else if(!strcmp(a,"1"))
        {
            printf("\n\t\t\t\t   ��������������ƣ�");
            showRecordsAccordingtoDepartment(); 
            func3();
        }
        else if(!strcmp(a,"2"))
        {
            printf("\n\t\t\t\t   ������ҽ�����ţ�");
            char ID[30];
            //int ID;
            scanf("%s",ID);
            showDoctor(ID);
            func3();
        }
        else if(!strcmp(a,"3"))
        {
            printf("\n\t\t\t\t   �����뻼��ID:");
            char ID[30];
            scanf("%s",ID);
            showPatientInformation(ID);
            func3();
        }
        else if(!strcmp(a,"4"))
        {
        	print();
            option();
		}
        else
        {
                printf("\n\t\t\t\t   �� �����������������!\n");
                Sleep(1000);
                print();
                option();
        }
    }
}
#endif
