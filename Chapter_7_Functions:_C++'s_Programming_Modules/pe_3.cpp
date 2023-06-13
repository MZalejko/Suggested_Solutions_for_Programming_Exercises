#include <iostream>

struct box{
    char producer[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_struct(const box a);
void edit_struct(box *a);


int main(){

    box new_box{
        "Box_Masters",
        2.3,
        2.4,
        3.5,
    };
    box *ptr;
    ptr = &new_box;

    show_struct(new_box);
    edit_struct(ptr);
    std::cout<<"Our box after editing.\n";
    show_struct(new_box);
    
    return 0;
}

void show_struct(const box a){
    std::cout<<"Our box!"<<std::endl;
    std::cout<<"Producer: "<<a.producer<<'\n';
    std::cout<<"The height of the box: "<<a.height<<'\n';
    std::cout<<"The width of the box:  "<<a.width<<'\n';
    std::cout<<"The length of the box: "<<a.length<<'\n';
    std::cout<<"The volume of the box: "<<a.volume<<'\n';
}
void edit_struct(box *a){
    a->volume = a->height*a->length*a->width;
}