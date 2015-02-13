#include <vector>
#include <iostream>

template<typename Container>
Container merge(Container leftSite, Container rightSite)
{
    Container sorted;

    while(!leftSite.empty() && !rightSite.empty())
    {
        if(leftSite[0] <= rightSite[0])
        {
            sorted.push_back(leftSite[0]);
            leftSite.erase(leftSite.begin());
        }
        else
        {
            sorted.push_back(rightSite[0]);
            rightSite.erase(rightSite.begin());
        }
    }
    while(!leftSite.empty())
    {
        sorted.push_back(leftSite[0]);
        leftSite.erase(leftSite.begin());
    }
    while(!rightSite.empty())
    {
        sorted.push_back(rightSite[0]);
        rightSite.erase(rightSite.begin());
    }

    return sorted;
}

template<typename Container>
Container mergesort(Container vec)
{
    if(vec.size() <= 1)
        return vec;

    const auto halfSize = vec.size() / 2;
    Container leftSite(vec.begin(), vec.begin() + halfSize);
    Container rightSite(vec.begin() + halfSize, vec.end());

    leftSite = mergesort(leftSite);
    rightSite = mergesort(rightSite);

    return merge(leftSite, rightSite);
}
