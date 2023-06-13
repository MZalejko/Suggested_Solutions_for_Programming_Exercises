#include <iostream>

const int SLEN{30};

struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main(){

    int class_size;

    std::cout<<"Set a size of a group: ";
    std::cin>>class_size;
    while(std::cin.get() != '\n'){
        continue;
    }

    student *ptr_stu = new student[class_size];

    int entered = getinfo(ptr_stu, class_size);
    for(int i = 0; i < entered; i++){
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    std::cout<<"Done!\n";

    return 0;
}

int getinfo(student pa[], int n){
    int num_of_st{0};
    for(int i = 0; i < n; i++){
        std::cout<<"Enter student's fullname: \n";
        std::cin.getline(pa[i].fullname, SLEN);
        if(pa[i].fullname[0] == '\n' || pa[i].fullname[0] == '\0'){
            std::cout<<"Empty fullname entered. Entering the students aborted.\n";
            break;
        }
        std::cout<<"Student's hobby:\n";
        std::cin.getline(pa[i].hobby, SLEN);
        std::cout<<"Student's ooplevel:\n";
        std::cin>>pa[i].ooplevel;
        std::cin.get();
        num_of_st++;
    }
    return num_of_st;
}
void display1(student st){
    std::cout<<"Student's fullname: "<<st.fullname<<std::endl;
    std::cout<<"Student's hobby: "<<st.hobby<<std::endl;
    std::cout<<"Student's ooplevel: "<<st.ooplevel<<std::endl;

}   
void display2(const student *ps){   
    std::cout<<"Student's fullname: "<<ps->fullname<<std::endl;
    std::cout<<"Student's hobby: "<<ps->hobby<<std::endl;
    std::cout<<"Student's ooplevel: "<<ps->ooplevel<<std::endl;    
}
void display3(const student pa[], int n){
    for(int i = 0; i < n; i++){
        std::cout<<"Student's fullname: "<<pa[i].fullname<<std::endl;
        std::cout<<"Student's hobby: "<<pa[i].hobby<<std::endl;
        std::cout<<"Student's ooplevel: "<<pa[i].ooplevel<<std::endl;
    }
}
