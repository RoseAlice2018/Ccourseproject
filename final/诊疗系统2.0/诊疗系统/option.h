#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED

void changepassword()
{
	print();
	char oldpass[30];
	char newpass[30];
	printf("\n\n\t\t\t\t  ������ԭ���룺");
	scanf("%s",oldpass);
	if(strcmp(oldpass,password)!=0)
	{
		printf("\n\n\t\t\t\t  ��ԭ���������������������");
		Sleep(1200);
		changepassword();
		return;
	}
	printf("\n\n\t\t\t\t  �����������룺");
	scanf("%s",newpass);
	printf("\n\n\t\t\t\t  ���ٴ����������룺");
	scanf("%s",oldpass);
	if(strcmp(oldpass,newpass)!=0)
	{
		printf("\n\n\t\t\t\t  ���������벻һ�£�����������");
		Sleep(1200);
		changepassword();
		return;
	}
	printf("\n\n\t\t\t\t  �������޸ĳɹ���");
	strcpy(password,newpass);
	printf("\n\n\t\t\t\t  ");
	system("pause");
}
void option()//���˵�
{
    char a[10];
    
    print();
    printf("\t\t\t\t     ����ѡ���ܡ�\n\n\t\t\t\t      �� ����\n\n\t\t\t\t      �� �޸���ɾ��\n\n\t\t\t\t      �� ��Ϣ��ѯ\n\n\t\t\t\t      �� ����ͳ��\n\n\t\t\t\t      �� ������Ϣ\n\n\t\t\t\t      �� ������һ��\n\n\t\t\t\t      �� �޸�����\n\n\t\t\t\t      �� �˳�����\n\n\t\t\t\t      ");
    printf("\n\t\t\t\t      ��ѡ��");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   �� �������ʽ�������������룡\n");
        Sleep(1000);
        print();
        option();//��ӡѡ��
    }
    else if(!strcmp(a,"1"))
        func1();
    else if(!strcmp(a,"2"))
        func2();
    else if(!strcmp(a,"3"))
        func3();
    else if(!strcmp(a,"4"))
        func4();
    else if(!strcmp(a,"5"))
    	func5();
    else if(!strcmp(a,"6"))
    {
        option1();
	}
	else if(!strcmp(a,"7"))
	{
		changepassword();
		option();
	}
    else if(!strcmp(a,"8"))
    	func6();
    else
    {
        printf("\n\t\t\t\t   �� �����������������!\n");
        Sleep(1000);
        print();
        option();
    }
}
#endif
