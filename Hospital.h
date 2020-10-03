


struct PatientInformation
{
    char name[30];// name of the patient
    int age;    // age of the patient (1-140)
    int ID;     // ID of the patient (Uniqueness)
};

struct DoctorInformation
{
    char name[30];// name of the doctor
    int  level; //level of the doctor
    char department[30]; //department of the doctor
    int ID;     //ID of the doctor(Uniqueness)
    int date[8];   // doctor at work
};

struct Date
{
    int month;
    int day;
    int hour;
    int minute;
};
struct depart
{
    char name[40];// name of the department
};
struct Examination
{
    int SumCost=0; // sum cost of the examination
    int costcount=0;   // 检查数量
    int cost[1000]; //最多提供1000次检查
};
struct Drug
{
    char name[40]; // name of the drug
    int UnitPrice; // unit price 
    int Number;     // number of the drug
    int cost=Number*UnitPrice;// cost
};
struct Prescribemedicine
{
    int SumDrugCost; // sum cost of the drug Cost
    Drug  drug[40];  // category of drug
    int drugcount=0;
};
struct Hospitalized 
{
    Date beginDate;
    Date leaveDate;
    int   Cost=0;
    int  deposit;
    int  leastdeposit=200*(leaveDate.day-beginDate.day);
    int  min_=1000;   
};


struct MedicalInformation
{
    Examination exam;
    Prescribemedicine prmd;
    Hospitalized hosp;
};
struct MedicalRecords
{
    PatientInformation paIn;
    DoctorInformation  doIn;
    MedicalInformation mdIn;
    MedicalRecords* before;
    MedicalRecords* next;
};