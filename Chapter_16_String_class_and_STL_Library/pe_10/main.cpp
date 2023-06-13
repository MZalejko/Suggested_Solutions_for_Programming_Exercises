#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdlib>

constexpr int display_width{30};

struct Review
{
    std::string title;
    int rating;
    double price;
};
bool operator<(std::shared_ptr<Review> shr_ptr, std::shared_ptr<Review> shr_ptr2);
bool compare_rating(std::shared_ptr<Review> shr_ptr, std::shared_ptr<Review> shr_ptr2);
bool compare_price(std::shared_ptr<Review> shr_ptr, std::shared_ptr<Review> shr_ptr2);
bool FillReview(std::shared_ptr<Review> shr_ptr);
void ShowReview(const std::shared_ptr<Review> shr_ptr);
char ShowMenu();

int main()
{
    std::vector<std::shared_ptr<Review>> books;
    int size_of_bookshelf{0};
    std::cout << "How much books do you have on your bookshelf: ";
    std::cin >> size_of_bookshelf;
    std::cin.get();
    int fill_it{0};

    for(int it = 0; it < size_of_bookshelf; it++)
    {
        books.push_back(std::shared_ptr<Review>(new Review));
    }

    for(auto& it: books)
    {
        FillReview(it);
    }
    char opt = ShowMenu();
    while (opt != 'q')
    {
        std::vector<std::shared_ptr<Review>> temp(books);
        switch (opt)
        {
        case 'a':
            std::cout << "Alphabetical sort" << std::endl;
            std::sort(temp.begin(), temp.end(), operator<);
            std::for_each(temp.begin(), temp.end(), ShowReview);
            break;
        case 'b':
            std::cout << "Rating ascending" << std::endl;
            std::sort(temp.begin(), temp.end(), compare_rating);
            std::for_each(temp.begin(), temp.end(), ShowReview);
            break;
        case 'c':
            std::sort(temp.rbegin(), temp.rend(), compare_rating);
            std::for_each(temp.begin(), temp.end(), ShowReview);
            break;
        case 'd':
            std::sort(temp.begin(), temp.end(), compare_price);
            std::for_each(temp.begin(), temp.end(), ShowReview);
            break;
        case 'e':
            std::sort(temp.rbegin(), temp.rend(), compare_price);
            std::for_each(temp.begin(), temp.end(), ShowReview);
            break;
        default :
            std::for_each(temp.begin(), temp.end(), ShowReview);
            break;
        }
        opt = ShowMenu();
    }

    std::cout << "goodbye!!" << std::endl;

    return 0;
}

bool operator<(std::shared_ptr<Review> shr_ptr, std::shared_ptr<Review> shr_ptr2)
{
    if(shr_ptr -> title < shr_ptr2 -> title) {return true;}
    else {return false;}   
}
bool compare_rating(std::shared_ptr<Review> shr_ptr, std::shared_ptr<Review> shr_ptr2)
{
    if(shr_ptr -> rating < shr_ptr2 -> rating) {return true;}
    else {return false;}  
}
bool compare_price(std::shared_ptr<Review> shr_ptr, std::shared_ptr<Review> shr_ptr2)
{
    if(shr_ptr -> price < shr_ptr2 -> price) {return true;}
    else {return false;}  
}

bool FillReview(std::shared_ptr<Review> shr_ptr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, shr_ptr->title);
    if(shr_ptr->title == "quit")
        return false;
    
    std::cout << "Enter book rating: ";
    std::cin >> shr_ptr->rating;
    std::cin.get();
    std::cout << "Enter book price: ";
    std::cin >> shr_ptr->price;
    if(!std::cin)
        return false;
    while(std::cin.get() != '\n')
        continue;
    return true;
}
void ShowReview(const std::shared_ptr<Review> shr_ptr)
{
    std::cout << shr_ptr->title << '\t' << shr_ptr->rating << '\t' << shr_ptr->price << std::endl;
}

char ShowMenu()
{
    char exit;
    
    std::cout << "Display menu, choose an option: " << std::endl;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout.width(display_width);
    std::cout << "a: alphabetical display";
    std::cout << "b: rating ascending display";
    std::cout << std::endl;
    std::cout.width(display_width);
    std::cout << "c: rating descending display";
    std::cout << "d: price ascending display";
    std::cout << std::endl;
    std::cout.width(display_width);
    std::cout << "e: price descending display";
    std::cout << "q: quit" << std::endl;
    std::cout.width(0);
    std::cin.get(exit);
    std::cin.get();

    exit = tolower(exit);

    return exit;
}