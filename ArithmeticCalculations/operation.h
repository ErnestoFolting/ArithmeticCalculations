#pragma once

struct operation {
    int priority;
    char name;
    operation(const char x) {
        name = x;
        if ((x == '-') || (x == '+'))
        {
            priority = 1;
        }
    	else if ((x == '*') || (x == '/'))
        {
            priority = 2;
        }
		else if (x == '^')
		{
			priority = 3;
		}
        else if((x=='p')||(x=='m'))
        {
	        priority=4;
        }
    }
};