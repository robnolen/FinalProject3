//
//  main.cpp
//  FinalProject3
//
//  Created by Robert Nolen on 12/11/11.
//  Copyright 2011 Greencrayon.org. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;
class Course {
public:
    virtual void calcExamPercent() = 0;
    virtual void calcLabPercent() = 0;
    virtual void calcClassPercent() = 0;
    virtual void calcFinalGrade();
    virtual void print();
    Course(string, string);
    ~Course();
    
protected:
    float labPercent;
    float classPercent;
    float examPercent;
    float finalGrade;
    string finalLetterGrade;
    int points;
    int maxPoints;
    string courseName;
    string studentName;
    vector<int> examScores;
    vector<int> labScores;
    vector<int> classScores;
};

class BioCourse : public Course{
public:
    BioCourse(string, string);
    ~BioCourse();
    virtual void calcExamPercent();
    virtual void calcLabPercent();
    virtual void calcClassPercent();
    virtual void print();
};

class DraftingCourse : public Course{
public:
    DraftingCourse(string, string);
    ~DraftingCourse();
    virtual void calcExamPercent();
    virtual void calcLabPercent();
    virtual void calcClassPercent();
    virtual void print();
};

class ProgrammingCourse : public Course{
public:
    ProgrammingCourse(string, string);
    ~ProgrammingCourse();
    virtual void calcExamPercent();
    virtual void calcLabPercent();
    virtual void calcClassPercent();
    virtual void calcFinalGrade();
    virtual void print();
private:
    int finalExamScore;
};

class BasketWeavingCourse : public Course{
public:
    BasketWeavingCourse(string, string);
    ~BasketWeavingCourse();
    virtual void calcExamPercent();
    virtual void calcLabPercent();
    virtual void calcClassPercent();
    virtual void print();

};

Course::Course(string name, string student)
{
    courseName = name;
    studentName = student;
}
Course::~Course()
{
    
}

BioCourse::BioCourse(string name, string student) : Course(name, student)
{
    examScores.push_back(99);
    examScores.push_back(100);
    labScores.push_back(25);
    labScores.push_back(23);
    labScores.push_back(25);
    classScores.push_back(21);
    classScores.push_back(23);
    maxPoints = 325;
}

BioCourse::~BioCourse()
{
    
}

DraftingCourse::DraftingCourse(string name, string student) : Course(name, student)
{
    examScores.push_back(99);
    examScores.push_back(100);
    examScores.push_back(77);
    labScores.push_back(30);
    labScores.push_back(50);
    labScores.push_back(40);
    labScores.push_back(45);
    classScores.push_back(44);
    classScores.push_back(45);
    classScores.push_back(50);
    maxPoints = 450;
}

DraftingCourse::~DraftingCourse()
{
    
}

ProgrammingCourse::ProgrammingCourse(string name, string student) : Course(name, student)
{
    labScores.push_back(25);
    labScores.push_back(25);
    labScores.push_back(22);
    classScores.push_back(100);
    classScores.push_back(95);
    classScores.push_back(50);
    finalExamScore = 80;
    maxPoints = 475;
}

ProgrammingCourse::~ProgrammingCourse()
{
    
}

BasketWeavingCourse::BasketWeavingCourse(string name, string student) : Course(name, student)
{
    labScores.push_back(25); //three baskets each 25 points
    labScores.push_back(25);
    labScores.push_back(22);
    classScores.push_back(100); //final project baskets 100 pts each
    classScores.push_back(100 );
    maxPoints = 275;
}

BasketWeavingCourse::~BasketWeavingCourse()
{
    
}

void Course::print()
{
    cout << courseName << " " << studentName;
}

void Course::calcFinalGrade()
{
    finalGrade = (float) points / float(maxPoints)*100;
    if (finalGrade >= 85)
    {
        finalLetterGrade = "A";
    }
    else if (finalGrade <85 & finalGrade >=70)
    {
        finalLetterGrade = "B";
    }
    else if (finalGrade <70 & finalGrade >=55)
    {
        finalLetterGrade = "C";
    }
    else if (finalGrade <55 & finalGrade >=40)
    {
        finalLetterGrade = "D";
    }
    else 
    {
        finalLetterGrade = "F";
    }
    
}

void BioCourse::calcExamPercent()
{
    int temp = 0;
    int scoreMax = 200;
    for (int i=0; i<examScores.size(); i++) 
    {
        temp = temp + examScores[i];
    }
    points = points + temp;
    examPercent = ((float)temp / scoreMax) * 100;
}

void BioCourse::calcLabPercent()
{
    int temp = 0;
    int scoreMax = 75;
    for (int i=0; i<labScores.size(); i++) 
    {
        temp = temp + labScores[i];
    }
    points = points + temp;

    labPercent = ((float)temp / scoreMax) * 100;
}

void BioCourse::calcClassPercent()
{
    int temp = 0;
    int scoreMax = 50;
    for (int i=0; i<classScores.size(); i++) 
    {
        temp = temp + classScores[i];
    }
    points = points + temp;
    classPercent = ((float)temp / float(scoreMax)) * 100;
}

void BioCourse::print()
{
    Course::print();
   cout << setprecision(2) << fixed;
    cout << " Lab Score: " << labPercent << "%, Classroom Score: " << classPercent << "%, Exam Percent: " <<
        examPercent << "%, Final Grade: " << finalLetterGrade << endl;
}

void DraftingCourse::calcExamPercent()
{
   //needed for base class polymorphism but not used.
}

void DraftingCourse::calcLabPercent()
{
    int temp = 0;
    int scoreMax = 150;
    sort(labScores.begin(), labScores.end());
    for (int i=1; i<labScores.size(); i++) 
    {
        temp = temp + labScores[i];
    }
    points = points + temp;
    
    labPercent = ((float)temp / scoreMax) * 100;
}

void DraftingCourse::calcClassPercent()
{
    int temp = 0;
    int scoreMax = 300;
    sort(classScores.begin(), classScores.end());
    sort(examScores.begin(), examScores.end());
    for (int i=1; i<classScores.size(); i++) 
    {
        temp = temp + classScores[i];
    }
    for (int i=1; i<examScores.size(); i++) 
    {
        temp = temp + examScores[i];
    }
    points = points + temp;
    classPercent = ((float)temp / float(scoreMax)) * 100;
}

void DraftingCourse::print()
{
    Course::print();
    cout << setprecision(2) << fixed;
    cout << " Lab Score: " << labPercent << "%, Classroom Score: " << classPercent <<  "%, Final Grade: " << finalLetterGrade << endl;
    
}

void ProgrammingCourse::calcExamPercent()
{
    //needed for base class polymorphism but not used.
}

void ProgrammingCourse::calcLabPercent()
{
    int temp = 0;
    int scoreMax = 75;
    for (int i=0; i<labScores.size(); i++) 
    {
        temp = temp + labScores[i];
    }
    points = points + temp;
    
    labPercent = ((float)temp / scoreMax) * 100;
}

void ProgrammingCourse::calcClassPercent()
{
    int temp = 0;
    int scoreMax = 400;
    sort(classScores.begin(), classScores.end());
    
    if (classScores[0] < finalExamScore)
    {
        classScores[0] = finalExamScore;
    }
    
    for (int i=0; i<classScores.size(); i++) 
    {
        temp = temp + classScores[i];
    }
    
    temp += finalExamScore;
    points = points + temp;
    classPercent = ((float)temp / float(scoreMax)) * 100;
}

void ProgrammingCourse::print()
{
    Course::print();
    cout << setprecision(2) << fixed;
    cout << " Lab Score: " << labPercent << "%, Classroom Score: " << classPercent <<  "%, Final Grade: " << finalLetterGrade << endl;
    
}

void ProgrammingCourse::calcFinalGrade()
{
    Course::calcFinalGrade();
    if (finalExamScore < 40)
    {
        finalGrade = 0;
        finalLetterGrade = "F";
    }
    
}

void BasketWeavingCourse::calcExamPercent()
{
    //needed for base class polymorphism but not used.
}

void BasketWeavingCourse::calcLabPercent()
{
    int temp = 0;
    int scoreMax = 75;
    for (int i=0; i<labScores.size(); i++) 
    {
        temp = temp + labScores[i];
    }
    points = points + temp;
    
    labPercent = ((float)temp / scoreMax) * 100;
}

void BasketWeavingCourse::calcClassPercent()
{
    int temp = 0;
    int scoreMax = 200;

    
    for (int i=0; i<classScores.size(); i++) 
    {
        temp = temp + classScores[i];
    }
        points = points + temp;
    classPercent = ((float)temp / float(scoreMax)) * 100;
}

void BasketWeavingCourse::print()
{
    Course::print();
    cout << setprecision(2) << fixed;
    cout << " Lab Score: " << labPercent << "%, Classroom Score: " << classPercent <<  "%, Final Grade: " << finalLetterGrade << endl;
}

int main (int argc, const char * argv[])
{
    BioCourse biology("Bio 10", "Rob Nolen");
    biology.calcLabPercent();
    biology.calcExamPercent();
    biology.calcClassPercent();
    biology.calcFinalGrade();
    biology.print();
    
    DraftingCourse drafting ("Drafting 1", "Rob Nolen");
    drafting.calcLabPercent();
    drafting.calcClassPercent();
    drafting.calcFinalGrade();
    drafting.print();
    
    ProgrammingCourse prog ("Programming 11", "Rob Nolen");
    prog.calcLabPercent();
    prog.calcClassPercent();
    prog.calcFinalGrade();
    prog.print();
    
    Course *basket = new BasketWeavingCourse("Basket Weaving 111", "Rob Nolen");
    basket->calcLabPercent();
    basket->calcClassPercent();
    basket->calcFinalGrade();
    basket->print();

    return 0;
}

