#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED

void option()//���˵�
{
    char a[10];
    
    print();
    printf("\t\t\t\t     ����ѡ���ܡ�\n\n\t\t\t\t      �� ����\n\n\t\t\t\t      �� �޸���ɾ��\n\n\t\t\t\t      �� ��Ϣ��ѯ\n\n\t\t\t\t      �� ����ͳ��\n\n\t\t\t\t      �� ������Ϣ\n\n\t\t\t\t      �� ������һ��\n\n\t\t\t\t      �� �˳�����\n\n\t\t\t\t      ");
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
