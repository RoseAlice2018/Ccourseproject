/*******���еĺ���������ȫ�ֱ���****/ 

int SumProfit=0;//ҽԺ����Ӫҵ��
int countDepart=0;// department����
MedicalRecords* records=new MedicalRecords();
MedicalRecords* pointer=records;
depart RealDepartment[30];

void print_nowtime()//�����ǰʱ��
{
    time_t T;
	struct tm*p;
	time(&T);
	p=localtime(&T);
    printf("\n  ��%d��%d�� %d:",p->tm_mon+1,p->tm_mday,p->tm_hour);
    if(p->tm_min<10)
        printf("0%d��",p->tm_min);
    else
        printf("%d��",p->tm_min);
}
void print_title()//�����Ʒ����ϵͳͼ��
{
    printf("\n\n\n");
    for(int i=0;i<30;i++) printf(" ");
    printf("��");
    for(int i=0;i<26;i++) printf("��");
    printf("��\n");
    for(int i=0;i<30;i++) printf(" ");
    printf("��");
    printf("     �� �� �� �� ϵ ͳ    ");
    printf("��\n");
    for(int i=0;i<30;i++) printf(" ");
    printf("��");
    for(int i=0;i<26;i++) printf("��");
    printf("��\n");
}
void print()//���ҳ��
{
    system("cls");//����
    print_nowtime();//��ӡ��ǰʱ��
    print_title();//��ӡ��¼����ͼ��
}

void option(); //���� 
