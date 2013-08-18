
//  Valid Number
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        if (s == NULL)
            return false;

        while(isspace(*s))
            s++;

        if (*s == '+' || *s == '-')
            s++;

        bool eAppear = false;
        bool dotAppear = false;
        bool firstPart = false;
        bool secondPart = false;
        bool spaceAppear = false;
        while(*s != '\0')
        {
            if (*s == '.')
            {
                if (dotAppear || eAppear || spaceAppear)
                    return false;
                else
                    dotAppear = true;
            }
            else if (*s == 'e' || *s == 'E')
            {
                if (eAppear || !firstPart || spaceAppear)
                    return false;
                else
                    eAppear = true;
            }
            else if (isdigit(*s))
            {
                if (spaceAppear)
                    return false;

                if (!eAppear)
                    firstPart = true;
                else
                    secondPart = true;
            }
            else if (*s == '+' || *s == '-')
            {
                if (spaceAppear)
                    return false;

                if (!eAppear || !(*(s-1) == 'e' || *(s-1) == 'E'))
                    return false;
            }
            else if (isspace(*s))
                spaceAppear = true;
            else
                return false;

            s++;            
        }

        if (!firstPart)
            return false;
        else if (eAppear && !secondPart)
            return false;
        else
            return true;
    }
};


int main() {
    return 0;
}
