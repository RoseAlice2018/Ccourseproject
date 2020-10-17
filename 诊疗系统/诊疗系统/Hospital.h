
typedef struct PatientInformation
{
    char name[40];// name of the patient
    int age;    // age of the patient (1-140)
    char ID[40];     // ID of the patient (Uniqueness)
}PatientInformation;

typedef struct DoctorInformation
{
    char name[40];// name of the doctor
    char  level[40]; //level of the doctor
    char department[40]; //department of the doctor
    char ID[40];     //ID of the doctor(Uniqueness)
    int date[8];   // doctor at work
}DoctorInformation;

typedef struct Date
{
    int month;
    int day;
    int hour;
    int minute;
}Date;
typedef struct depart
{
    char name[40];// name of the department
}depart;

typedef struct ExamProject
{
	Date examtime;	//���ʱ��
	int examcost; //������
}ExamProject;
typedef struct Examination
{
    int SumCost; // sum cost of the examination
    int examcount;   //������
	ExamProject examproj[40]; //
}Examination;

typedef struct Drug
{
    char name[40]; // name of the drug
    int Price;
    int Number;     // number of the drug
	Date prescribetime;	//��ҩʱ��
}Drug;
typedef struct Prescribemedicine
{
    int SumDrugCost; // sum cost of the drug Cost
    Drug drug[40];  // category of drug
    int drugcount;
}Prescribemedicine;
typedef struct Hospitalized 
{
    Date beginDate;
    Date leaveDate;
    int  Cost;
    int  deposit;  
}Hospitalized;

typedef struct MedicalInformation
{
    Examination exam;
    Prescribemedicine prmd;
    Hospitalized hosp;
}MedicalInformation;

typedef struct MedicalRecords
{
    PatientInformation paIn;
    DoctorInformation  doIn;
    MedicalInformation mdIn;
    struct MedicalRecords* before=NULL;
    struct MedicalRecords* next=NULL;
}MedicalRecords;
