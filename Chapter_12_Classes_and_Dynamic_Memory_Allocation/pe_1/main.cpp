#include "pe_1.h"

int main(){

    Cow first;
    Cow second("Little Mi", "Grass and Water", 1300);
    Cow third("The princessin of all Cows", "Being a Queen of cows and grass", 1500);
    Cow fourth;
    fourth = second;
    Cow fifth(third);

    first.Show();
    second.Show();
    third.Show();
    fourth.Show();
    fifth.Show();

    return 0;
}