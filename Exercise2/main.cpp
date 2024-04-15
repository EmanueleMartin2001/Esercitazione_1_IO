#include <iostream> //libreria per I/O su compiler
#include <fstream> //libreria di I/O su file
#include <iomanip>  //libreria per formattare l'output
double linearmap(double n) //linear map such that linearmap(1) = -1 and linearmap(5) = 2
{
    return 0.75 * n - 7./4.;
}
int main()
{
    std::string dati = "data.csv";
    std::ifstream ifstr(dati);
    std::string results = "result.csv";
    std::ofstream ofstr;
    ofstr.open(results);
    if (!ofstr.is_open()) //check if the file has been opened  successfully
    {
        std::cerr << "file could not be opened" << std::endl;
        return 1;
    }
    double values = 0;
    double mean = 0;
    double sums = mean;
    int index = 1;
    while (ifstr >> values)
    {
        sums += linearmap(values);
        mean = sums/index;
        ofstr << std::scientific << std::setprecision(16) << index << "  " << mean << "\n"; //upload on result.csv the means
        index++;
    }
    return 0;
}
