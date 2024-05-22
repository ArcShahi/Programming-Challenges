#include <iostream>
#include <string_view>
#include <iterator>

void get_pi(unsigned int n)
{
     // We can extend it but the code will take more space.
     const std::string_view PI{
        "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"
         "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"
         "4428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273"
         "7245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094"
         "3305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912"
     };

     // Directly copy the required substring to the output stream
     std::cout.write(PI.data() + 2, n);
     std::cout << '\n'; // Add a newline for better readability
}

int main()
{
     unsigned int n;
     bool take_input = true;

     while (take_input)
     {
          std::cout << "Enter the N (1-500): ";
          std::cin >> n;

          if (n < 1 || n > 500)
          {
               std::cout << "INVALID 'N', TRY AGAIN\n";
          }
          else
          {
               take_input = false;
          }
     }
     get_pi(n);
     std::cout << "\n\n\n";
     std::cin.get();

     return 0;
}
