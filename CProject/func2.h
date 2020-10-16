#ifndef FUNC2_H_INCLUDED
#define FUNC2_H_INCLUDED

void quickdelete(MedicalRecords* temp)
{
  //  printf("is deleting");
     //delete the record
    MedicalRecords* t=temp->before;
    t->next=temp->next;
    if(temp->next!=NULL)
    temp->next->before=t;
// printf("deleted");
}
void deleteRecords(MedicalRecords* temp)
{
    //delete the record
    quickdelete(temp);
    //add new record
    AddMedicalRecords();
}

void func2()
{
    char a[10];
    while(1)
    {
        print();
        printf("\t\t\t\t       请选择功能★\n\n\t\t\t\t      ① 修改诊疗记录\n\n\t\t\t\t      ② 删除诊疗记录\n\n\t\t\t\t      ③ 返回上一级\n\n\t\t\t\t      ");
        printf("\n\t\t\t\t      请选择：");
        scanf("%s",a);
        printf("\n");
        if(strlen(a)!=1)
        {
            printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
            Sleep(1000);
            func2();
        }
        else if(!strcmp(a,"1"));
        
        else if(!strcmp(a,"2"));
        
        else if(!strcmp(a,"3"))
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
