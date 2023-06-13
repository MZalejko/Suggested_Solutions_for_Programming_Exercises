#ifndef REVIEW_HXX
#define REVIEW_HXX

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Review
{
    private:
        std::string title;
        int rating;
        double price;
    public:

        bool operator<(const std::shared_ptr<Review> shr_ptr, const std::shared_ptr<Review> shr_ptr2);
        bool worseThan(const std::shared_ptr<Review> shr_ptr, const std::shared_ptr<Review> shr_ptr2);
        bool FillReview(std::shared_ptr<Review> shr_ptr);
        void ShowReview(const std::shared_ptr<Review> shr_ptr);


};

#endif // REVIEW_HXX

