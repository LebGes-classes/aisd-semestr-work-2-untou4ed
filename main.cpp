#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getDigit(int num, int digit) 
{
    int divisor = 1;
    for (int i = 0; i < digit; i++) 
    {
        divisor *= 10;
    }
    return (num / divisor) % 10;
}

void radixSort(vector<int> &arr) 
{
    if (arr.empty()) return;

    int maxNum = *max_element(arr.begin(), arr.end());
    int maxDigits = 0;
    while (maxNum > 0)
    {
        maxNum /= 10;
        maxDigits++;
    }

    for (int digit = 0; digit < maxDigits; digit++) 
    {
        vector<vector<int>> buckets(10);

        for (int num : arr) 
        {
            int currentDigit = getDigit(num, digit);
            buckets[currentDigit].push_back(num);
        }
        arr.clear();
        for (vector<int> &bucket : buckets) 
        {
            for (int num : bucket) 
            {
                arr.push_back(num);
            }
        }
    }
}

void bubbleSort(vector<float> &a)
{
    bool isSwapped = false;
    int n = a.size();
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1]) swap(a[j], a[i]); isSwapped = true;
        }
        if (!isSwapped) break;
    }
}

void bucketSort(vector<float> &arr) 
{
    float minValue = *min_element(arr.begin(), arr.end());
    float maxValue = *max_element(arr.begin(), arr.end());
    float range = maxValue - minValue;

    int n = arr.size();
    vector<vector<float>> buckets(n);

    for (float num : arr) 
    {
        float normalized = (num - minValue) / range;
        int bucketIndex = min(static_cast<int>(normalized * n), n - 1);
        buckets[bucketIndex].push_back(num);
    }

    for (vector<float> &bucket : buckets) 
    {
        if (!bucket.empty()) {
            bubbleSort(bucket);
        }
    }

    int index = 0;
    for (vector<float> &bucket : buckets) 
    {
        for (float num : bucket) {
            arr[index++] = num;
        }
    }
}




int main()
{
    vector<int> arr = { 12, 312, 4232432, 1212, 11, 2, 4, 4222 };
    radixSort(arr);
    for (int num : arr)
    {
        cout << num << endl;
    }

    vector<float> arr2 = { 0.3232, 0.32131, 0.43432, 0.1 };
    bucketSort(arr2);
    for (float num : arr2)
    {
        cout << num << endl;
    }

}
