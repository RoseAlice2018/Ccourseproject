
void func5()
{
    int a;
    //printf("did it");
    //scanf("%d ",&a);
	FILE* fpwirte=fopen("./data.txt","w");

    MedicalRecords* t=records->next;
    while(t!=NULL)
    {
        //input the data
        //1.input the patient information
        fprintf(fpwirte,"%s %d %s\n",t->paIn.name,t->paIn.age,t->paIn.ID);
        //2.input the doctor information
        fprintf(fpwirte,"%s %s %s %s ",t->doIn.name,t->doIn.level,t->doIn.department,t->doIn.ID);
            //input the onsite
        for(int i=0;i<8;i++)
        {
            if(t->doIn.date[i]=='1')
                fprintf(fpwirte,"%d working \n",i);
            else
            {
                fprintf(fpwirte,"%d free \n",i);
            } 
        }
        //input the medical information
        fprintf(fpwirte,"%d %d\n",t->mdIn.exam.SumCost,t->mdIn.exam.examcount);
        for(int i=0;i<t->mdIn.exam.examcount;i++)
        {
            fprintf(fpwirte,"%d/%d/%d/%d,%d\n",t->mdIn.exam.examproj->examtime.month,t->mdIn.exam.examproj->examtime.day,t->mdIn.exam.examproj->examtime.hour,t->mdIn.exam.examproj->examtime.minute,t->mdIn.exam.examproj->examcost);

        }
        //input the prescribe information
        fprintf(fpwirte,"%d %d\n",t->mdIn.prmd.SumDrugCost,t->mdIn.prmd.drugcount);
        for(int i=0;i<t->mdIn.prmd.drugcount;i++)
        {
            fprintf(fpwirte,"%s %d %d",t->mdIn.prmd.drug->name,t->mdIn.prmd.drug->Price,t->mdIn.prmd.drug->Number);
            fprintf(fpwirte,"%d/%d/%d/%d",t->mdIn.prmd.drug->prescribetime.month,t->mdIn.prmd.drug->prescribetime.day,t->mdIn.prmd.drug->prescribetime.hour,t->mdIn.prmd.drug->prescribetime.minute);

        }
        //input the hospital information
        fprintf(fpwirte,"%d %d\n",t->mdIn.hosp.Cost,t->mdIn.hosp.deposit);
        fprintf(fpwirte,"%d/%d/%d/%d\n",t->mdIn.hosp.beginDate.month,t->mdIn.hosp.beginDate.day,t->mdIn.hosp.beginDate.hour,t->mdIn.hosp.beginDate.minute);
        fprintf(fpwirte,"%d/%d/%d/%d\n",t->mdIn.hosp.leaveDate.month,t->mdIn.hosp.leaveDate.day,t->mdIn.hosp.leaveDate.hour,t->mdIn.hosp.leaveDate.minute);
        t=t->next;        
    }
    fclose(fpwirte);
    printf("Output Over");
    option();
}
