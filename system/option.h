
void option()//主菜单
{
    char a[10];
    while(1)
    {
        print();
        printf("\t\t\t\t     ★请选择功能★\n\n\t\t\t\t      ① 增加\n\n\t\t\t\t      ② 修改与删除\n\n\t\t\t\t      ③ 信息查询\n\n\t\t\t\t      ④ 数据统计\n\n\t\t\t\t      ⑤ 保存信息\n\n\t\t\t\t      ⑥ 程序退出\n\n\t\t\t\t      ");
        printf("\n\t\t\t\t      请选择：");
        scanf("%s",a);
        printf("\n");
        if(strlen(a)!=1)
        {
            printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
            Sleep(1000);
            print();
            option();//打印选项
        }
        else if(!strcmp(a,"1"))
            func1();
        else if(!strcmp(a,"2"));
            //func2();
        else if(!strcmp(a,"3"));
            //func3();
        else if(!strcmp(a,"4"))
            func4();
        else if(!strcmp(a,"5"));
        	//func5();
        else if(!strcmp(a,"6"))
        	func6();
        else
        {
                printf("\n\t\t\t\t   × 输入错误，请重新输入!\n");
                Sleep(1000);
                print();
                option();
        }
    }
}
