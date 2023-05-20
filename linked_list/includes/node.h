#pragma once
struct Node
{
    int value;
    Node* next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};