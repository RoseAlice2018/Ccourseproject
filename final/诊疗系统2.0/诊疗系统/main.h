/*******���еĺ���������ȫ�ֱ���****/ 

int SumProfit=0;//ҽԺ����Ӫҵ��
int countDepart=0;// department����
MedicalRecords* records=(MedicalRecords*)malloc(sizeof(MedicalRecords));

MedicalRecords* pointer;
depart RealDepartment[30];
char password[30]; 
int regicount=0; //���չҺ��� 

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
	int i=0;
    printf("\n\n\n");
    for(i=0;i<30;i++) printf(" ");
    printf("��");
    for(i=0;i<26;i++) printf("��");
    printf("��\n");
    for(i=0;i<30;i++) printf(" ");
    printf("��");
    printf("     �� �� �� �� ϵ ͳ    ");
    printf("��\n");
    for(i=0;i<30;i++) printf(" ");
    printf("��");
    for(i=0;i<26;i++) printf("��");
    printf("��\n");
}
void print()//���ҳ��
{
    system("cls");//����
    print_nowtime();//��ӡ��ǰʱ��
    print_title();//��ӡ��¼����ͼ��
}

void option(); //���� 
void option1();
void option1_2();
