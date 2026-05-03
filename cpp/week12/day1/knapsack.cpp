// The knapsack problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int price;
    int weight;
    float ratio = 0;
};

int main()
{
    // Input the number of items
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    // Insert weight and price for each item
    for (int i = 0; i < n; i++)
    {
        int p, w;
        cout << "Item: " << i << endl;
        cout << "p: " << " ";
        cin >> p;
        cout << "w: " << " ";
        cin >> w;

        items[i].price = p;
        items[i].weight = w;
    }

    // Input the knapsack size
    int size;
    cout << "Enter the size of the knapsack: ";
    cin >> size;

    // Find out the price per unit weight (ratio)
    for (int i = 0; i < n; i++)
        items[i].ratio = (float) items[i].price / (float) items[i].weight;
    

    // Sort the items array based on ratio
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // DEBUG
    for (int i = 0; i < n; i++)
    {
        cout << "Item: " << i << " ";
        cout << "R: " << items[i].ratio << " ";
        cout << "W: " << items[i].weight << " ";
        cout << "P: " << items[i].price << " ";
        cout << endl;
    }
    // DEBUG
    
    // Greedily fill the knapsack and add to the total profit.
    int totalProfit = 0;
    int iter = 0;
    while (size > 0)
    {
        int w = items[iter].weight;
        int p = items[iter].price;
        
        int newSize = size - w;
        // Item fills completely
        if (newSize >= 0)
        {
            totalProfit += p;
            size = newSize;
        }
        // Item fills partially
        else if (newSize < 0)
        {
            totalProfit += (float) p * ((float) size / (float) w);
            size = 0;
        }
    }

    cout << totalProfit << endl;

    return 0;
}