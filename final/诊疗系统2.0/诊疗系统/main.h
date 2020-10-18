/*******所有的函数声明与全局变量****/ 

int SumProfit=0;//医院的总营业额
int countDepart=0;// department数量
MedicalRecords* records=(MedicalRecords*)malloc(sizeof(MedicalRecords));

MedicalRecords* pointer;
depart RealDepartment[30];
char password[30]; 
int regicount=0; //当日挂号数 

void print_nowtime()//输出当前时间
{
    time_t T;
	struct tm*p;
	time(&T);
	p=localtime(&T);
    printf("\n  【%d月%d日 %d:",p->tm_mon+1,p->tm_mday,p->tm_hour);
    if(p->tm_min<10)
        printf("0%d】",p->tm_min);
    else
        printf("%d】",p->tm_min);
}
void print_title()//输出商品管理系统图形
{
	int i=0;
    printf("\n\n\n");
    for(i=0;i<30;i++) printf(" ");
    printf("┏");
    for(i=0;i<26;i++) printf("━");
    printf("┓\n");
    for(i=0;i<30;i++) printf(" ");
    printf("┃");
    printf("     诊 疗 管 理 系 统    ");
    printf("┃\n");
    for(i=0;i<30;i++) printf(" ");
    printf("┗");
    for(i=0;i<26;i++) printf("━");
    printf("┛\n");
}
void print()//组合页面
{
    system("cls");//清屏
    print_nowtime();//打印当前时间
    print_title();//打印登录界面图形
}

void option(); //声明 
void option1();
void option1_2();
