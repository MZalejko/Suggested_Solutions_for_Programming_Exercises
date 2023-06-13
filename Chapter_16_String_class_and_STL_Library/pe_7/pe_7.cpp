#include "pe_7.hxx"

std::vector<int> all_numbers;

void mode_choose(int& num_of_args,char** values, int& num_of_balls, int& num_of_choosen_balls)
{
    if(num_of_args == 3)
    {
        std::cout << "Correct number of arguments. Saving values to variables." << std::endl;
        std::cout << "Number of balls " << values[1] << std::endl;
        num_of_balls = atoi(values[1]);
        std::cout << "Number of balls to choose: " << values[2] << std::endl;
        num_of_choosen_balls = atoi(values[2]);
    }
    else if(num_of_args <= 2)
    {
        std::cout << "Too few arguments. You must choose them by yourself.\n";
        std::cout << "Enter a number of balls: ";
        std::cin >> num_of_balls;
        std::cin.get();
        std::cout << "Now enter a number of balls to choose: ";
        std::cin >> num_of_choosen_balls;
        std::cin.get();

    }
    else if(num_of_args > 3)
    {
        std::cerr << "Too much arguments. Aborting program." << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::vector<int> Lotto(const int& num_of_balls, const int& num_of_choosen_balls)
{
    std::vector<int> temp_winning_balls;
    std::vector<int> temporary_all_balls;
    all_numbers = Filling_the_drawing_chamber(num_of_balls);
    temporary_all_balls.resize(all_numbers.size());
    std::copy(all_numbers.begin(), all_numbers.end(), temporary_all_balls.begin());
    shuffle(temporary_all_balls);
    std::cout << std::endl;
    for(int it = 1; it <= num_of_choosen_balls; it++)
    {
        temp_winning_balls.push_back(temporary_all_balls[it]);
    }

    return temp_winning_balls;   
}

std::vector<int> Filling_the_drawing_chamber(const int& num_of_balls)
{
    std::vector<int> vector_to_fill;
    for(int it = 1; it <=num_of_balls; it++)
    {
        vector_to_fill.push_back(it);
    }

    return vector_to_fill;
}

void choose_your_numbers(std::vector<int>& your_numbs, const int& num_of_choosen_balls, const std::vector<int>&  all_balls)
{
    std::cout << "Choose your numbers! You have " << num_of_choosen_balls << " to choose: " << std::endl;
    for(int it = 1; it <= num_of_choosen_balls; it++)
    {
        int temp{0};
        std::cin >> temp;
        std::cin.get();
        if(temp < *(all_balls.begin()) || temp > *(all_balls.rbegin()))
        {
            std::cout << "Your number can't be greater than " << *(all_balls.rbegin())
                      << " or lower than " << *(all_balls.begin()) << std::endl;
        }
        else
            your_numbs.push_back(temp);
    }

}

void show(const std::vector<int>& your_nums, const std::vector<int>& winning_nums)
{
    std::cout << "Your numbers: " << std::endl;
    for(auto it: your_nums)
    {
        std::cout << it << " ";
    }
    std::cout << '\n';
    std::cout << "Winning numbers: " << std::endl;
    for(auto it: winning_nums)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

void shuffle(std::vector<int>& shuffle_vect)
{
    int how_much_shuffle{0};
    std::srand(time(NULL));
    how_much_shuffle = std::rand() % shuffle_times_max;
    how_much_shuffle += 1;
    for(int it = 0; it <= how_much_shuffle; it++)
    {
        std::random_shuffle(shuffle_vect.begin(), shuffle_vect.end());
    }

}