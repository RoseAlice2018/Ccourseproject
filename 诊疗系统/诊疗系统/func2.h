#ifndef FUNC2_H_INCLUDED
#define FUNC2_H_INCLUDED

void quickdelete(MedicalRecords* temp)
{
    printf("is deleting");
     //delete the record
     Sleep(3000);
    MedicalRecords* t=temp->before;
    t->next=temp->next;
    if(temp->next!=NULL)
    temp->next->before=t;
    printf("deleted");
    Sleep(3000);
}
void deleteRecords(MedicalRecords* temp)
{
    //delete the record
    quickdelete(temp);
    //add new record
    printf("重新输入");
    AddMedicalRecords();
}
// bool compare(char A[],char B[])
// {
//     for(int i=0;i<30;i++)
//     {
//         if((A[i]=='\0'&&B[i]!='\0')||(A[i]!='\0'&&B[i]=='\0'))
//         {
//             return false;
//         }
//         if(A[i]!='\0')
//         {
//             if(A[i]!=B[i])
//                 return false;
//         }
//     }
//     return true;
// }
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
        else if(!strcmp(a,"1"))
        {
            printf("请输入想要删除记录的挂号ID\n");
            char ID[30];
            scanf("%s",&ID);
            MedicalRecords* t=records->next;
            while(t!=NULL&&!(strcmp(t->paIn.ID,ID)==0))
            {
                t=t->next;
            }
            if(t==NULL)
            {
                printf("未找到ID对应的记录！重新输入：\n");
                Sleep(3000);
                func2();
            }
            else
            {
                deleteRecords(t);
            }
            
        }
        else if(!strcmp(a,"2"))
        {
             printf("请输入想要删除记录的挂号ID\n");
            char ID[30];
            scanf("%s",&ID);
            MedicalRecords* t=records->next;
            while(t!=NULL&&!(strcmp(t->paIn.ID,ID)==0))
            {
                t=t->next;
            }
            if(t==NULL)
            {
                printf("未找到ID对应的记录！重新输入：\n");
                Sleep(3000);
                func2();
            }
            else
            {
                quickdelete(t);
            }
        }
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
