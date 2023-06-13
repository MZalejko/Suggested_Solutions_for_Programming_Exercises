#include "pe_6.hxx"



int main(int argc, char** argv)
{
    int employees_num{0};
    int current_empl_num{0};

    abstr_emp* list_of_employees[max_array];

    std::cout << "You can add only " << max_array << " employees." << std::endl;
    std::ifstream fin;
    fin.open(file_name);
    if_file_not_empty(fin, list_of_employees, employees_num);
    current_empl_num = employees_num;
    adding_new_employees(list_of_employees, employees_num);
    show_array(list_of_employees, employees_num);
    
    std::ofstream fout;
    fout.open(file_name, std::ios_base::out | std::ios_base::app);
    
    
    send_to_file(fout, list_of_employees, current_empl_num, employees_num);
    delete_memory(list_of_employees, employees_num);

    std::cout << "End of the program, bye." << std::endl;



    return EXIT_SUCCESS;
}