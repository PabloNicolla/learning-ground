#include <string>
#include <sstream>
#include <iomanip>

std::string timeConversion(const std::string &s)
{
    int hour, min, sec;
    char period;

    std::istringstream iss(s);
    iss >> std::setw(2) >> hour;
    iss.ignore(); // Skip the colon
    iss >> std::setw(2) >> min;
    iss.ignore(); // Skip the colon
    iss >> std::setw(2) >> sec;
    iss >> period; // 'A' or 'P'

    if (period == 'P' && hour != 12)
    {
        hour += 12;
    }
    else if (period == 'A' && hour == 12)
    {
        hour = 0;
    }

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setfill('0') << std::setw(2) << min << ":"
        << std::setfill('0') << std::setw(2) << sec;

    return oss.str();
}