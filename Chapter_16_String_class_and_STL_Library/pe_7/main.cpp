#include "pe_7.hxx"

extern std::vector<int> all_numbers;

int main(int argc, char** argv)
{
    int num_balls{0};
    int num_choosen_balls{0};

    std::vector<int> your_numbers;
    std::vector<int> winnig_numbers;


    mode_choose(argc, argv, num_balls, num_choosen_balls);
    winnig_numbers = Lotto(num_balls, num_choosen_balls);
    choose_your_numbers(your_numbers, num_choosen_balls, all_numbers);
    show(your_numbers, winnig_numbers);


    return 0;
}
