#include <string>

std::string kangaroo_1(int x1, int v1, int x2, int v2)
{
    // If they have the same velocity, they can only meet if they start at the same position
    if (v1 == v2)
    {
        return x1 == x2 ? "YES" : "NO";
    }

    // Check if (x2 - x1) is divisible by (v1 - v2) and (v1 - v2) is of the correct sign
    if ((x2 - x1) % (v1 - v2) == 0 && (x2 - x1) / (v1 - v2) >= 0)
    {
        return "YES";
    }
    return "NO";
}

std::string kangaroo_2(int x1, int v1, int x2, int v2)
{
    if (x1 == x2)
    {
        return v1 == v2 ? "YES" : "NO";
    }
    else if (x1 < x2)
    {
        while (x1 < x2)
        {
            x1 += v1;
            x2 += v2;
        }
        return x1 == x2 ? "YES" : "NO";
    }
    else
    {
        while (x2 < x1)
        {
            x1 += v1;
            x2 += v2;
        }
        return x1 == x2 ? "YES" : "NO";
    }
}
