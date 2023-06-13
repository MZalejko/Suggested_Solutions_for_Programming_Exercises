#include <string>
#include <list>
#include <set>
#include <iostream>
#include <vector>
#include <iterator>

class Person
{
    private:
        std::string name;
        int num_friends;
        std::list<std::string> my_friends_list;
        void enter_num_frnds();
        void enter_name();
        void create_friends_list();
    public:
        Person(std::string my_name = "None", int num = 0) : name(my_name), num_friends(num) {};
        ~Person() {};
        const int& ret_num_frnds() const {return num_friends;};
        const std::string& ret_name() const {return name;};
        void data_creating() {enter_name(); enter_num_frnds(); create_friends_list();};
        std::list<std::string> return_my_frnds_list() const {return my_friends_list;};
        void show_frnds_list() const;
        const int return_list_size () const {return my_friends_list.size();};
};


int how_much_lists();
std::list<std::string> merge_lists(const std::vector<Person>& party_l);
void fill_lists(std::vector<Person>& party_l, const int& num_of_lists);
void show_complete_list(const std::list<std::string>& compl_list);