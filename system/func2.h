
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
        else if(!strcmp(a,"1"));
        
        else if(!strcmp(a,"2"));
        
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
