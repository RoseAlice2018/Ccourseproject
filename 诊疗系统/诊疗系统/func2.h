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
    printf("��������");
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
        printf("\t\t\t\t       ��ѡ���ܡ�\n\n\t\t\t\t      �� �޸����Ƽ�¼\n\n\t\t\t\t      �� ɾ�����Ƽ�¼\n\n\t\t\t\t      �� ������һ��\n\n\t\t\t\t      ");
        printf("\n\t\t\t\t      ��ѡ��");
        scanf("%s",a);
        printf("\n");
        if(strlen(a)!=1)
        {
            printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
            Sleep(1000);
            func2();
        }
        else if(!strcmp(a,"1"))
        {
            printf("��������Ҫɾ����¼�ĹҺ�ID\n");
            char ID[30];
            scanf("%s",&ID);
            MedicalRecords* t=records->next;
            while(t!=NULL&&!(strcmp(t->paIn.ID,ID)==0))
            {
                t=t->next;
            }
            if(t==NULL)
            {
                printf("δ�ҵ�ID��Ӧ�ļ�¼���������룺\n");
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
             printf("��������Ҫɾ����¼�ĹҺ�ID\n");
            char ID[30];
            scanf("%s",&ID);
            MedicalRecords* t=records->next;
            while(t!=NULL&&!(strcmp(t->paIn.ID,ID)==0))
            {
                t=t->next;
            }
            if(t==NULL)
            {
                printf("δ�ҵ�ID��Ӧ�ļ�¼���������룺\n");
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
                printf("\n\t\t\t\t   �� �����������������!\n");
                Sleep(1000);
                print();
                option();
        }
    }
}
#endif
