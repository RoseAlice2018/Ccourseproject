#include<stdio.h>
#include"Hospital.h"
int SumProfit=0;//ҽԺ����Ӫҵ��
int countDepart=0;// department����
MedicalRecords* records;
MedicalRecords* pointer=records;
depart RealDepartment[30];
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
    printf("������ѡ����ļ��������Ƽ�¼������1��ѡ���ֶ��������Ƽ�¼������2��\n");
    int tag=0;
    scanf("%d",&tag);
    if(tag==1)
    {
        // ���ļ��������Ƽ�¼



    }
    else if(tag==2)// ѡ���ֶ��������Ƽ�¼
    {
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
        
        pointer=temp;
        pointer=pointer->next;
    }
}

void deleteRecords(MedicalRecords* temp)
{
    //delete the record
    MedicalRecords* t=temp->before;
    t->next=temp->next;
    temp->next->before=t;
    //add new record
    AddMedicalRecords();
}

void quickdelete(MedicalRecords* temp)
{
     //delete the record
    MedicalRecords* t=temp->before;
    t->next=temp->next;
    temp->next->before=t;
}
void showRecordsAccordingtoDepartment()
{
        char name[30];
        scanf("%s",name);
        MedicalRecords* t=records;
        printf("����������Ҫ��ӡ����Ϣ��\n");
        printf("1:ҽ����Ϣ\n2:������Ϣ\n3:�������\n4:ȫ����Ϣ\n");
        int tagofrecords=0;
        scanf("%d",&tagofrecords);
        int countCheck=1;//��¼��ǰ�ǵ�i����¼
        while (t->next!=NULL)
        {
            printf("��ǰ�ǵ�%d����¼:\n",countCheck);
            if(t->doIn.department==name)
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
                            printf("%d ",i);
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
                            printf("%d ",i);
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
        }
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

void showDoctor(int inID)
{
    MedicalRecords* t=records;
    printf("����������Ҫ��ӡ����Ϣ��\n");
    printf("1:ҽ����Ϣ\n2:������Ϣ\n3:�������\n4:ȫ����Ϣ\n");
    int tagofrecords=0;
    scanf("%d",&tagofrecords);
    while(t->next!=NULL)
    {
        if(t->doIn.ID==inID)
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
                            printf("%d ",i);
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
                            printf("%d ",i);
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
    }
}
//��ӡĳλ���ߵ���ʷ������Ϣ
void showPatientInformation(const int ID)//? ��ʷ��¼��
{
    MedicalRecords* t=records;
    while(t->next!=NULL)
    {
        if(t->paIn.ID==ID)// IDfind
        {
            printf("%s %d %d\n",t->doIn.name,t->mdIn.prmd.SumDrugCost,t->mdIn.hosp.deposit);
        }
    }
}

// ͳ��ҽԺĿǰ��Ӫҵ��
void showProfit()
{
    printf("ҽԺĿǰ��Ӫҵ��Ϊ��%d Ԫ");
}
// ����ĿǰסԺ���߱� 
void showPatient()
{

}
//���������ID�����ص�ID�����Ƽ�¼
MedicalRecords* getMedicalReocrds(int ID)
{
    MedicalRecords* head=records;
    while(ID--)
    {
        head=head->next;
        if(head==NULL)
        {
            printf("������Ҫ�����Ƽ�¼�������ڣ�����������:\n");
            return NULL;
        }
    }
    return head;
}
int main()
{
    while(1)
    {    //0 System begin
        printf("��ӭʹ�ü��ִ�ѧ�����ҽԺ���ƹ���ϵͳ\n\t");
        printf("1:�����¼\n\t");
        printf("2:�޸����Ƽ�¼\n\t");
        printf("3:ɾ�����Ƽ�¼\n\t");
        printf("4:�����Ҽ���������Ϣ\n\t");
        printf("5:��ҽ���Ĺ��ż�����Ϣ\n\t");
        printf("6:��������Ϣ������Ϣ\n\t");
        printf("7:ͳ��Ӫҵ�����סԺ���߱���\n\t");
        printf("8:ͳ��ÿλҽ���ĳ�������͹�����æ�̶�\n\t");
        printf("9:�ܹ���ӡĳ��ʱ�䷶Χ�ڵ�����������Ϣ\n\t");
        printf("10:����ǰϵͳ�е�������Ϣ���浽�ļ���\n\t");
        printf("0:�˳�ϵͳ\n\t");
        int code;
        scanf("%d",&code);
        if(code==0)//�˳�ϵͳ
        {
            printf("ϵͳ�����˳�\n\t");
            break;
        }
        else if(code==1)
        {
             //1. �ܹ����ļ���¼��������Ƽ�¼��Ҳ�ܹ���ʱ¼�� 1 �����Ƽ�¼��
            //ע�⣺��Ҫ���Ǹ������͵Ĳ��淶���������������ݣ��磺����λ�����ԡ���
            //ʽ���Եȡ����ص㿼�졿
            AddMedicalRecords();
        }
        else if(code==2)
        {
            //2 .�ܹ���ʱ�޸� 1 �����Ƽ�¼�����ղ���淶�������޸Ĵ������ �Ƽ�¼��
            //Ӧ����ǰ��������Ƽ�¼���Գ������ٲ��������ȷ�����Ƽ�¼������
            // �㿼�졿
            printf("������������Ҫ�޸ĵ����Ƽ�¼��ID��\n");
            int ID;
            scanf("%d",&ID);
            MedicalRecords* t=getMedicalReocrds(ID);
            //����û������IDΪ�����ID
            while(t==NULL)
            {
                int ID;
                scanf("%d",&ID);
                 MedicalRecords* t=getMedicalReocrds(ID);
            }
            //ɾ����������Ƽ�¼
            deleteRecords(t);
        }
        else if(code==3)
        {
             //3.�ܹ���ʱɾ�� 1 �����Ƽ�¼��
            printf("������������Ҫ�޸ĵ����Ƽ�¼��ID��\n");
            int ID;
            scanf("%d",&ID);
            MedicalRecords* t=getMedicalReocrds(ID);
            //����û������IDΪ�����ID
            while(t==NULL)
            {
                int ID;
                scanf("%d",&ID);
                 MedicalRecords* t=getMedicalReocrds(ID);
            }
             quickdelete(t);
        }
        else if(code==4)
        {
            //4. �ܹ����պ���˳���ӡĳ�����ҵ�������Ϣ�����տ��Ҽ�����
            checkDepartment();
        }
        else if(code==5)
        {
            //5 �ܹ����պ���˳���ӡĳλҽ����������Ϣ������ҽ���Ĺ��ż�����
            printf("����������Ҫ��ѯ��ҽ����ID��\n");
            int ID=0;
            scanf("%d",&ID);
            showDoctor(ID);
        }
        else if(code==6)
        {
            //6 �ܹ����պ���˳���ӡĳλ���ߵ���ʷ������Ϣ�����ջ��ߵ������Ϣ������
            printf("�����뻼��ID��\n");
            int ID;
            scanf("%d",&ID);
            showPatientInformation(ID);
        }
        else if(code==7)
        {
            //7 �ܹ�ͳ��ҽԺĿǰ��Ӫҵ�������+ҩƷ����+סԺ���ã�����סԺѺ�𣩣��ܹ�����Ŀǰ��סԺ���߱������ص㿼�졿
            showProfit();
             showPatient();
        }
        else if(code==8)
        {
            //8 �ܹ�ͳ��ÿλҽ���ĳ�������͹�����æ�̶ȡ�
        }
        else if(code==9)
        {
            //9 ��ĳ��ʱ�䷶Χ���ܹ���ӡĳ��ʱ�䷶Χ�ڵ�����������Ϣ�����ص㿼�졿
        }
    }  
}