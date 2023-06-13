#include "person.hxx"

//class Person

void Person::enter_num_frnds()
{
    std::cout << "Ok " << name
              << " enter now how much friends want you invite: ";
    std::cin >> num_friends;
    std::cin.get();
}

void Person::enter_name()
{
    std::cout << "Ok, now enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Hi " << name << std::endl;

}

void Person::create_friends_list()
{   
    std::string temp_name;
    std::cout << "Enter your friends names: " << '\n';
    for(int it = 0; it < num_friends; it++)
    {
        std::getline(std::cin, temp_name);
        my_friends_list.push_back(temp_name);
    }
    my_friends_list.sort();
    my_friends_list.unique();
    show_frnds_list();
}

void Person::show_frnds_list() const
{   
    for(auto it: my_friends_list)
        std::cout << it << std::endl;
}

//Functions

int how_much_lists()
{
    int temp_num_of_lists;

    std::cout << "Hi, how much lists would you like to create? " << std::endl;

    std::cin >> temp_num_of_lists;
    std::cin.get();

    return temp_num_of_lists;

}

std::list<std::string> merge_lists(const std::vector<Person>& party_l)
{
    std::list<std::string> temp_list;

    for(int it = 0; it < party_l.size(); it++)
    {
        
        temp_list.merge(party_l[it].return_my_frnds_list());
    }
    temp_list.sort();
    temp_list.unique();

    return temp_list;
}

void fill_lists(std::vector<Person>& party_l, const int& num_of_lists)
{   
    Person temp_person;
    std::cout << "Time to create " << num_of_lists << " lists: " << std::endl;
    for(int it = 0; it < num_of_lists; it++)
    {   
        temp_person.data_creating();
        party_l.push_back(temp_person);
    }
}

void show_complete_list(const std::list<std::string>& compl_list)
{   
    std::cout << "Hi yours list: " << std::endl;
    for(auto it: compl_list)
        std::cout << it << std::endl;
}