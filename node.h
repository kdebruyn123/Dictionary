#pragma once

class node
{
public:
    node()
    {
        next = bottom = nullptr;
    }
    node* next;
    node* bottom;
    char value;
};