#include <iostream>

using namespace std;

int main() {
   char choice;
   cout << "Welcome to Percentage Calulator" << endl;
   do {
       int percentage;
       cout << "Enter your percentage: ";
       cin >> percentage;

       if (percentage > 100 || percentage < 0) {
           cout << "Invalid percentage entered. Please enter a value between 0 and 100." << endl;
       } else {
           switch (percentage / 10) {
               case 10:  // 100
                   cout << "Grade: A+" << endl;
                   break;
               case 9:
                   if (percentage >= 95) {  // 95-100
                       cout << "Grade: A+" << endl;
                   } else {  // 90-94
                       cout << "Grade: A" << endl;
                   }
                   break;
               case 8:
                   if (percentage >= 85) {  // 85-89
                       cout << "Grade: B+" << endl;
                   } else {  // 80-84
                       cout << "Grade: B" << endl;
                   }
                   break;
               case 7: // 70-79
                   cout << "Grade: C+" << endl;
                   break;
               case 6:  // 60-69
                   cout << "Grade: C" << endl;
                   break;
               case 5:
               case 4:  // 40-59
                   cout << "Grade: D" << endl;
                   break;
               case 3:
               case 2:
               case 1:
               case 0:  // 0-39
                   cout << "Grade: F" << endl;
                   break;
           }
       }

       cout << "Do you want to run the program again? (y/n): ";
       cin >> choice;
   } while (choice == 'y' || choice == 'Y');

   return 0;
}
