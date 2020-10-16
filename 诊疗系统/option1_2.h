void getregi()
{
	char patID[30];
	/*******系统时间*******/ 
	time_t T;
	struct tm*p;
	time(&T);
	p=localtime(&T);
    /**********************/
	print();
	/**输出医生信息**/
	
	printf("\t\t\t\t      您选择的医生工号为：");
	char tempID[30];
	scanf("%s",tempID);
	/**校验**/ 
	
	int m=p->tm_mon+1;
	int d=p->tm_mday;
	patID[0]=m/10+'0';
	patID[1]=m%10+'0';
	patID[2]=d/10+'0';
	patID[3]=d%10+'0';
	patID[4]=regicount/100+'0';
	patID[5]=(regicount/10)%10+'0';
	patID[6]=regicount%10+'0';
	for(int i=0;i<strlen(tempID)-1;i++)
	{
		patID[6+i]=tempID[i];
	}
	printf("\n\t\t\t\t      您的挂号为 %s",patID);
}
void regiinqu()
{
	print();
	printf("\n");
	printf("\t\t\t\t     请输入您的挂号\n");
	char tempID[30];
	scanf("%s",tempID);
	MedicalRecords* t=records->next;
	while(t!=NULL)
	{
		if(!strcmp(t->paIn.ID,tempID))
		{
			printf("\n\t\t\t\t     您的信息：\n");
			printf("\t\t\t\t     姓名：；年龄：；\n");
			printf("\n\t\t\t\t     您的医生信息：\n");
			printf("\t\t\t\t     姓名：；年龄：；\n");
			return;
		}
	}
	printf("\n\t\t\t\t     找不到您的挂号，请重新输入！");
	Sleep(2000);
	regiinqu(); 
}
void option1_2()
{
    char a[10];
    print();
    printf("\n\t\t\t\t     ★请选择功能★\n\n\t\t\t\t      ① 挂号\n\n\t\t\t\t      ② 查询(已挂号)\n\n\t\t\t\t      ③ 返回上一级\n\n");
    printf("\n\t\t\t\t      请选择：");
    scanf("%s",a);
    printf("\n");
    if(strlen(a)!=1)
    {
        printf("\n\t\t\t\t   × 您输入格式错误，请重新输入！\n");
        Sleep(1000);
        option1_2();
    }
    else if(!strcmp(a,"1"))
    	getregi(); 
    else if(!strcmp(a,"2"))
        regiinqu();
    else if(!strcmp(a,"3"))
    {
    	print();
        option1();
	}
    else
    {
        printf("\n\t\t\t\t   × 输入错误，请重新输入!\n");
        Sleep(1000);
        option1_2();
    }
}
