#include<stdio.h>
struct MedicalRecords
{
    PatientInformation paIn;
    DoctorInformation  doIn;
    MedicalInformation mdIn;
    MedicalRecords* before;
    MedicalRecords* next;
};
MedicalRecords* records;
MedicalRecords* pointer=records;
struct depart
{
    char name[30];// name of the department
};
int countDepart=0;
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
    RealDepartment[countDepart].name=insertname;
    countDepart++;
}
struct PatientInformation
{
    char name[30];// name of the patient
    int age;    // age of the patient (1-140)
    int ID;     // ID of the patient (Uniqueness)
};

struct DoctorInformation
{
    char name[30];// name of the doctor
    int  level; //level of the doctor
    char department[30]; //department of the doctor
    int ID;     //ID of the doctor(Uniqueness)
    int date[8];   // doctor at work
};

struct MedicalInformation
{
    Examination exam;
    Prescribemedicine prmd;
    Hospitalized hosp;
};

struct Examination
{
    int SumCost; // sum cost of the examination
    int cost;   // 
};

struct Prescribemedicine
{
    int SumDrugCost; // sum cost of the drug Cost
    Drug  drug[40];  // category of drug
};

struct Drug
{
    char name[40]; // name of the drug
    int UnitPrice; // unit price 
    int Number;     // number of the drug
};

struct Hospitalized 
{
    Date beginDate;
    Date leaveDate;
    int  deposit;   
};

struct Date
{
    int month;
    int day;
    int hour;
    int minute;
};
void AddMedicalRecords()
{
    printf("请问，选择从文件读入诊疗记录请输入1，选择手动输入诊疗记录请输入2：\n");
    int tag=0;
    scanf("%d",&tag);
    if(tag==1)
    {

    }
    else if(tag==2)
    {
        MedicalRecords* temp=new MedicalRecords();
        printf("请您按标准格式输入如下信息\n");
        printf("请您输入患者信息---格式如下：姓名 年龄 挂号\n");
        scanf("%s %d %d",temp->paIn.name,&temp->paIn.age,&temp->paIn.ID);
        printf("请您输入医生信息---格式如下：姓名 级别 科室 工号 出诊时间（时间格式：1 Mon 2 Tue 3 Wed\n");
        scanf("%s %d %s %d",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID);
        //插入department
        insertDepartment(temp->doIn.department);
        // 输入出诊时间
        printf("请您输入诊疗情况：\n");
        printf("请您输入检查状况---格式如下：100 200 依次输入每次检查费用 如未有检查请输入0");
        //输入检查状况
        printf("请您输入开药记录：\n");
        printf("请您输入开药记录---格式如下：药品名称 单价 数量\n");
        //输入开药记录
        printf("请您输入住院记录---格式如下：（住院开始记录）月/日/时/分 （预期出院日期）月/日/时/分 住院押金\n");
        scanf("%d/%d/%d/%d %d/%d/%d/%d %d",&temp->mdIn.hosp.beginDate.month,&temp->mdIn.hosp.beginDate.day
        ,&temp->mdIn.hosp.beginDate.hour,&temp->mdIn.hosp.beginDate.minute,&temp->mdIn.hosp.leaveDate.month,
        &temp->mdIn.hosp.leaveDate.day,&temp->mdIn.hosp.leaveDate.hour,&temp->mdIn.hosp.leaveDate.minute,&temp->mdIn.hosp.deposit);
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

void checkDepartment()
{
    printf("您是否清楚所要查询的科室名称？True（输入1） False（输入0）\n");
    int tag=0;
    scanf("%d",&tag);
    if(tag==0)
    {
        printf("已经为您准备好科室名称\n");
        for(int i=0;i<countDepart;i++)
            printf("%s\n",RealDepartment[i]);
        printf("请输入您要查询的科室名称:\n");
        char name[30];
        scanf("%s",name);
        MedicalRecords* t=records;
        printf("请输入您需要打印的信息：\n");
        printf("1:医生信息\n2:患者信息\n3:诊疗情况\n4:全部信息\n");
        int tagofrecords=0;
        scanf("%d",&tagofrecords);
        while (t->next!=NULL)
        {
            if(t->doIn.department==name)
            {
                // 打印诊疗信息
                if(tag==1)
                {
                    printf("%s %d %s %d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                }
                else if(tag==2)
                {
                    printf("%s %d %d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                }
                else if(tag==3)
                {
                    // 输出诊疗情况
                }
                else if(tag==4)
                {
                    printf("%s %d %s %d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                    printf("%s %d %d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                    // 输出诊疗情况
                }
            }
        }
        
    }
    else
    {
        
    }
    
}
int main()
{
    //0 System begin
    //1. 能够从文件中录入多条诊疗记录，也能够随时录入 1 条诊疗记录。
    //注意：需要考虑各种类型的不规范、不合理或错误数据，如：数据位数不对、格
    //式不对等。【重点考察】
    AddMedicalRecords();
    //2 .能够随时修改 1 条诊疗记录。按照财务规范，如需修改错误的诊 疗记录，
    //应将当前错误的诊疗记录予以撤销后，再补充添加正确的诊疗记录。【重
    // 点考察】
    MedicalRecords* t;
    deleteRecords(t);
    //3.能够随时删除 1 条诊疗记录。
    quickdelete(t);
    //4. 能够按照合理顺序打印某个科室的诊疗信息（按照科室检索）



}