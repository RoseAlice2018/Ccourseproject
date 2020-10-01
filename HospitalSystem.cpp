#include<stdio.h>
#include"Hospital.h"
int SumProfit=0;//医院的总营业额
int countDepart=0;// department数量
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
    printf("请问您选择从文件读入诊疗记录请输入1，选择手动输入诊疗记录请输入2：\n");
    int tag=0;
    scanf("%d",&tag);
    if(tag==1)
    {
        // 从文件读入诊疗记录



    }
    else if(tag==2)// 选择手动输入诊疗记录
    {
        MedicalRecords* temp=new MedicalRecords();
        printf("请您按标准格式输入如下信息\n");
        printf("请您输入患者信息---格式如下：姓名 年龄 挂号\n");
        scanf("%s %d %d",temp->paIn.name,&temp->paIn.age,&temp->paIn.ID);
        //ID计算

        printf("请您输入医生信息---格式如下：姓名 级别 科室 工号 出诊时间（时间格式：1 Mon 2 Tue 3 Wed 默认请输入0\n");
        scanf("%s %d %s %d",temp->doIn.name,&temp->doIn.level,temp->doIn.department,&temp->doIn.ID);
        //插入出诊时间
        char time[20];
        scanf("%s",time);
        if(time[0]=='0')
        {
            for(int i=1;i<=7;i++)
                {
                    temp->doIn.date[i]=1;//1 表示在值班
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
        //插入department
        insertDepartment(temp->doIn.department);
        //输入检查状况
        printf("请您输入诊疗情况：\n");
        printf("请您输入检查次数：如未有检查请输入0\n");
        int checkNumber=0;
        scanf("%d",&checkNumber);
        if(checkNumber==0)
        {
            printf("您未有检查记录\n");
        }
        else
        {
            printf("请依次输入每次检查费用---格式如下：100 ");
            while (checkNumber--)
            {
                int c;
                scanf("%d",&c);
                temp->mdIn.exam.cost[temp->mdIn.exam.costcount++]=c;
                temp->mdIn.exam.SumCost+=c;
            }  
        }
        //输入开药记录
        printf("请您输入开药次数：如未曾开药，请输入0\n");
        int medicount;
        scanf("%d",&medicount);
        if(medicount==0)
        {
            printf("您未曾有开药记录.\n");
        }
        else
        {
            while(medicount--)
            {
                printf("请您输入开药记录---格式如下：药品名称 单价 数量\n");
                scanf("%s %d %d",temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].name,&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].UnitPrice),&(temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount].Number));
                temp->mdIn.prmd.SumDrugCost+=temp->mdIn.prmd.drug[temp->mdIn.prmd.drugcount++].cost;
            }
            
        }
        //输入住院记录
        printf("请您输入住院记录---格式如下：（住院开始记录）月/日/时/分 （预期出院日期）月/日/时/分 住院押金\n");
        scanf("%d/%d/%d/%d %d/%d/%d/%d %d",&temp->mdIn.hosp.beginDate.month,&temp->mdIn.hosp.beginDate.day
        ,&temp->mdIn.hosp.beginDate.hour,&temp->mdIn.hosp.beginDate.minute,&temp->mdIn.hosp.leaveDate.month,
        &temp->mdIn.hosp.leaveDate.day,&temp->mdIn.hosp.leaveDate.hour,&temp->mdIn.hosp.leaveDate.minute,&temp->mdIn.hosp.deposit);
        if(temp->mdIn.hosp.deposit < temp->mdIn.hosp.leastdeposit)
        {
            printf("您的押金不足");
        }
        else if(temp->mdIn.hosp.deposit<temp->mdIn.hosp.deposit)
        {
            printf("您的押金低于最低标准");
        } 
        //将当前记录链入表中
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
        printf("请输入您需要打印的信息：\n");
        printf("1:医生信息\n2:患者信息\n3:诊疗情况\n4:全部信息\n");
        int tagofrecords=0;
        scanf("%d",&tagofrecords);
        int countCheck=1;//记录当前是第i条记录
        while (t->next!=NULL)
        {
            printf("当前是第%d条记录:\n",countCheck);
            if(t->doIn.department==name)
            {
                // 打印诊疗信息
                if(tagofrecords==1)
                {
                    printf("医生姓名：%s 医生级别：%d 医生所属部门：%s 医生工号：%d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                    //打印出诊时间
                    printf("医生出诊时间：");
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
                    printf("患者姓名：%s 患者年龄：%d 患者ID：%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                }
                else if(tagofrecords==3)
                {
                    // 输出诊疗情况
                    printf("检查总花费：%d\n",t->mdIn.exam.SumCost);
                    printf("药物总花费: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("住院开始日期：%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("住院预期结束日期: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
                else if(tagofrecords==4)
                {
                    //1
                    printf("医生姓名：%s 医生级别：%d 医生所属部门：%s 医生工号：%d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                    //打印出诊时间
                    printf("医生出诊时间：");
                    for(int i=1;i<=7;i++)
                    {
                        if(t->doIn.date[i]==1)
                        {
                            printf("%d ",i);
                        }
                    }
                    printf("\n");
                    //2
                    printf("患者姓名：%s 患者年龄：%d 患者ID：%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                    //3
                    // 输出诊疗情况
                    printf("检查总花费：%d\n",t->mdIn.exam.SumCost);
                    printf("药物总花费: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("住院开始日期：%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("住院预期结束日期: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
            }
        }
}
void checkDepartment() // 按科室检索诊疗信息
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
    printf("请输入您需要打印的信息：\n");
    printf("1:医生信息\n2:患者信息\n3:诊疗情况\n4:全部信息\n");
    int tagofrecords=0;
    scanf("%d",&tagofrecords);
    while(t->next!=NULL)
    {
        if(t->doIn.ID==inID)
        {
            // 打印诊疗信息
                if(tagofrecords==1)
                {
                    printf("医生姓名：%s 医生级别：%d 医生所属部门：%s 医生工号：%d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                    //打印出诊时间
                    printf("医生出诊时间：");
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
                    printf("患者姓名：%s 患者年龄：%d 患者ID：%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                }
                else if(tagofrecords==3)
                {
                    // 输出诊疗情况
                    printf("检查总花费：%d\n",t->mdIn.exam.SumCost);
                    printf("药物总花费: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("住院开始日期：%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("住院预期结束日期: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
                else if(tagofrecords==4)
                {
                    //1
                    printf("医生姓名：%s 医生级别：%d 医生所属部门：%s 医生工号：%d\n",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
                    //打印出诊时间
                    printf("医生出诊时间：");
                    for(int i=1;i<=7;i++)
                    {
                        if(t->doIn.date[i]==1)
                        {
                            printf("%d ",i);
                        }
                    }
                    printf("\n");
                    //2
                    printf("患者姓名：%s 患者年龄：%d 患者ID：%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                    //3
                    // 输出诊疗情况
                    printf("检查总花费：%d\n",t->mdIn.exam.SumCost);
                    printf("药物总花费: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("住院开始日期：%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("住院预期结束日期: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
        }
    }
}
//打印某位患者的历史诊疗信息
void showPatientInformation(const int ID)//? 历史记录？
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

// 统计医院目前的营业额
void showProfit()
{
    printf("医院目前的营业额为：%d 元");
}
// 生成目前住院患者表 
void showPatient()
{

}
//根据输入的ID，返回第ID条诊疗记录
MedicalRecords* getMedicalReocrds(int ID)
{
    MedicalRecords* head=records;
    while(ID--)
    {
        head=head->next;
        if(head==NULL)
        {
            printf("您所需要的诊疗记录并不存在，请重新输入:\n");
            return NULL;
        }
    }
    return head;
}
int main()
{
    while(1)
    {    //0 System begin
        printf("欢迎使用吉林大学计算机医院诊疗管理系统\n\t");
        printf("1:读入记录\n\t");
        printf("2:修改诊疗记录\n\t");
        printf("3:删除诊疗记录\n\t");
        printf("4:按科室检索诊疗信息\n\t");
        printf("5:按医生的工号检索信息\n\t");
        printf("6:按患者信息检索信息\n\t");
        printf("7:统计营业额并生成住院患者报表\n\t");
        printf("8:统计每位医生的出诊情况和工作繁忙程度\n\t");
        printf("9:能够打印某段时间范围内的所有诊疗信息\n\t");
        printf("10:将当前系统中的所有信息保存到文件中\n\t");
        printf("0:退出系统\n\t");
        int code;
        scanf("%d",&code);
        if(code==0)//退出系统
        {
            printf("系统正在退出\n\t");
            break;
        }
        else if(code==1)
        {
             //1. 能够从文件中录入多条诊疗记录，也能够随时录入 1 条诊疗记录。
            //注意：需要考虑各种类型的不规范、不合理或错误数据，如：数据位数不对、格
            //式不对等。【重点考察】
            AddMedicalRecords();
        }
        else if(code==2)
        {
            //2 .能够随时修改 1 条诊疗记录。按照财务规范，如需修改错误的诊 疗记录，
            //应将当前错误的诊疗记录予以撤销后，再补充添加正确的诊疗记录。【重
            // 点考察】
            printf("请输入您所需要修改的诊疗记录的ID：\n");
            int ID;
            scanf("%d",&ID);
            MedicalRecords* t=getMedicalReocrds(ID);
            //如果用户输入的ID为错误的ID
            while(t==NULL)
            {
                int ID;
                scanf("%d",&ID);
                 MedicalRecords* t=getMedicalReocrds(ID);
            }
            //删除并添加诊疗记录
            deleteRecords(t);
        }
        else if(code==3)
        {
             //3.能够随时删除 1 条诊疗记录。
            printf("请输入您所需要修改的诊疗记录的ID：\n");
            int ID;
            scanf("%d",&ID);
            MedicalRecords* t=getMedicalReocrds(ID);
            //如果用户输入的ID为错误的ID
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
            //4. 能够按照合理顺序打印某个科室的诊疗信息（按照科室检索）
            checkDepartment();
        }
        else if(code==5)
        {
            //5 能够按照合理顺序打印某位医生的诊疗信息（按照医生的工号检索）
            printf("请输入您想要查询的医生的ID：\n");
            int ID=0;
            scanf("%d",&ID);
            showDoctor(ID);
        }
        else if(code==6)
        {
            //6 能够按照合理顺序打印某位患者的历史诊疗信息（按照患者的相关信息检索）
            printf("请输入患者ID：\n");
            int ID;
            scanf("%d",&ID);
            showPatientInformation(ID);
        }
        else if(code==7)
        {
            //7 能够统计医院目前的营业额（检查费用+药品费用+住院费用，不含住院押金）；能够生成目前的住院患者报表。【重点考察】
            showProfit();
             showPatient();
        }
        else if(code==8)
        {
            //8 能够统计每位医生的出诊情况和工作繁忙程度。
        }
        else if(code==9)
        {
            //9 【某段时间范围】能够打印某段时间范围内的所有诊疗信息。【重点考察】
        }
    }  
}