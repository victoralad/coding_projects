The full submission document contains
    - aladele-victor.hpp
    - main.cpp
    - readMe.txt

This program can be compiled and run using the following statement
    - g++ main.cpp -std=c++11 -fopenmp
    - ./a.out

There are several other ways the matrix interface could have been done, including:
    - overloading the operator '<<' to allow the user to directly initialize the matrix similarly to the 'C++ Eigen' library.
    - having the user specify what type they want the matrix to be (i.e double, long, int, etc.)
    - have my program be able read-in the matrix from a '.txt' file provided by the user.

I chose to overload the operator '*', so as to allow my client to multiply as many
matrices as they wanted, without restricting them to a fixed number 
of matrices that can be multiplied at a time.

I have tested my code with the examples in main.cpp

This is not the best implementation there is and I believe there are many ways that this implementation could be improved
    - Arrays with smart pointers could be used instead of vectors
    - Templates could also be used
    
Lastly, I must say, I had fun!
