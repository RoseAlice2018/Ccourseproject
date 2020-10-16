#ifndef FUNC3_H_INCLUDED
#define FUNC3_H_INCLUDED

void showRecordsAccordingtoDepartment()
{
        char name[30];
        scanf("%s",name);
        MedicalRecords* t=records->next;
        printf("请输入您需要打印的信息：\n");
        printf("1:医生信息\n2:患者信息\n3:诊疗情况\n4:全部信息\n");
        int tagofrecords=0;
        scanf("%d",&tagofrecords);
        int countCheck=1;//记录当前是第i条记录
        while (t!=NULL)
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
                    printf("患者姓名：%s 患者年龄：%d 患者ID：%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                    //3
                    // 输出诊疗情况
                    printf("检查总花费：%d\n",t->mdIn.exam.SumCost);
                    printf("药物总花费: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("住院开始日期：%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("住院预期结束日期: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
            }
            t=t->next;
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
    MedicalRecords* t=records->next;
    printf("请输入您需要打印的信息：\n");
    printf("1:医生信息\n2:患者信息\n3:诊疗情况\n4:全部信息\n");
    int tagofrecords=0;
    scanf("%d",&tagofrecords);
    while(t!=NULL)
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
                    printf("患者姓名：%s 患者年龄：%d 患者ID：%d\n",t->paIn.name,t->paIn.age,t->paIn.ID);
                    //3
                    // 输出诊疗情况
                    printf("检查总花费：%d\n",t->mdIn.exam.SumCost);
                    printf("药物总花费: %d\n",t->mdIn.prmd.SumDrugCost);
                    printf("住院开始日期：%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
                    printf("住院预期结束日期: %d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);

                }
        }
        t=t->next;
    }
}
//打印某位患者的历史诊疗信息
void showPatientInformation(const int ID)//? 历史记录？
{
    MedicalRecords* t=records->next;
    while(t!=NULL)
    {
        if(t->paIn.ID==ID)// IDfind
        {
            printf("患者姓名：%s 患者药物总花费：%d 患者住院押金：%d\n",t->doIn.name,t->mdIn.prmd.SumDrugCost,t->mdIn.hosp.deposit);

        }
    }
}

void func3()
{
    char a[10];
    while(1)
    {
        print();
        printf("\t\t\t\t     ★请选择功能★\n\n\t\t\t\t      ① 按照科室检索\n\n\t\t\t\t      ② 按照医生工号检索\n\n\t\t\t\t      ③ 按照患者相关信息检索\n\n\t\t\t\t      ④ 返回上一级\n\n\t\t\t\t");
        printf("\n\t\t\t\t      请选择：");
        scanf("%s",a);
        printf("\n");
        if(strlen(a)!=1)
        {
            printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
            Sleep(1000);
            func3();
        }
        else if(!strcmp(a,"1"));
        
        else if(!strcmp(a,"2"));
        
        else if(!strcmp(a,"3"));
        
        else if(!strcmp(a,"4"))
        {
        	print();
            option();
		}
        else
        {
                printf("\n\t\t\t\t   × 输入错误，请重新输入!\n");
                Sleep(1000);
                print();
                option();
        }
    }
}
#endif
