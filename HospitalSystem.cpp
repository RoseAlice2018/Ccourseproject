#include<stdio.h>
#include<string.h>
struct MedicalRecords
{

};

struct PatientInformation
{
    string name;// name of the patient
    int age;    // age of the patient (1-140)
    int ID;     // ID of the patient (Uniqueness)
};

struct DoctorInformation
{
    string name;// name of the doctor
    int  level; //level of the doctor
    string department; //department of the doctor
    int ID;     //ID of the doctor(Uniqueness)
    int date[8];   // doctor at work
};

struct MedicalInformation
{
    Examination exam;
    Prescribemedicine prmd;
    Hospitalized hosp;
};

struct Examination
{
    int SumCost; // sum cost of the examination
    int cost;   // 
};

struct Prescribemedicine
{
    int SumDrugCost; // sum cost of the drug Cost
    Drug  drug[40];  // category of drug
};

struct Drug
{
    string name; // name of the drug
    int UnitPrice; // unit price 
    int Number;     // number of the drug
};

struct Hospitalized 
{
    Date beginDate;
    Date leaveDate;
    int  deposit;   
};

struct Date
{
    int month;
    int day;
    int hour;
    int minute;
};

int main()
{
    //0 System begin
    
}