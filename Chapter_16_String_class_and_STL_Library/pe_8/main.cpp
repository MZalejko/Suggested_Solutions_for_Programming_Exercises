#include "person.hxx"

std::vector<Person> party_lists;


int main(int argc, char** argv)
{
    int num_lists;
    num_lists = how_much_lists();
    fill_lists(party_lists, num_lists);
    merge_lists(party_lists);

    std::list<std::string> complete_list;
    complete_list.merge(merge_lists(party_lists));
    show_complete_list(complete_list);



    return EXIT_SUCCESS;
}