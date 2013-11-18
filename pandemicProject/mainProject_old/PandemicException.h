#include <stdexcept>//exception testing
#include <string>
using namespace std;

//
//
class PandemicException : public std::runtime_error
{
    public:
        PandemicException(string e): std::runtime_error(e) {}
};