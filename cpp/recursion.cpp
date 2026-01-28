#include <iostream>
#include <string>
using namespace std;
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    return n * power(n, p - 1);
}
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
string reverse(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char firstChar = s[0];
    return reverse(s.substr(1)) + firstChar;
}
string findPI(string s)
{
    if (s.length() < 2)
    {
        return s;
    }
    if (s[0] == 'p' && s[1] == 'i')
    {
        return "3.14" + findPI(s.substr(2));
    }
    else
    {
        return s[0] + findPI(s.substr(1));
    }
}
bool arrayCheck(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    bool restArr = arrayCheck(arr + 1, n - 1);
    return (restArr && arr[0] < arr[1]);
}
void decreasingOrder(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    decreasingOrder(n - 1);
}
void incOrder(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    incOrder(n - 1);
    cout << n << endl;
}
int firstOcc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return firstOcc(arr, n, i + 1, key);
}
int lastOcc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restArr = lastOcc(arr, n, i + 1, key);
    if (restArr != -1)
    {
        return restArr;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}
void towerofHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return;
    }
    towerofHanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerofHanoi(n - 1, helper, dest, src);
}
string removeDuplicate(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string rest = removeDuplicate(s.substr(1));
    if (ch == rest[0])
    {
        return rest;
    }
    return (ch + rest);
}
string moveXEnd(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string rest = moveXEnd(s.substr(1));
    if (ch == 'x')
    {
        return rest + ch;
    }
    return ch + rest;
}

void subString(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string rest = s.substr(1);
    subString(rest, ans);
    subString(rest, ans + ch);
}

void subSeq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string rest = s.substr(1);
    int code = ch;
    subSeq(rest, ans);
    subSeq(rest, ans + ch);
    subSeq(rest, ans + to_string(code));
}
void subsets(int arr[], int size, int index, int subArr[], int subSize)
{
    if (index == size)
    {
        cout << "[ ";
        for (int i = 0; i < subSize; i++)
        {
            cout << subArr[i] << " ";
        }
        cout << " ]" << endl;
        return;
    }

    subsets(arr, size, index + 1, subArr, subSize);
    subArr[subSize] = arr[index];
    subsets(arr, size, index + 1, subArr, subSize + 1);
}

bool palindromeCheck(string s, int size)
{
    if (s.length() <= 1)
    {
        return true;
    }
    char fisrstCh = s[0];
    char lastCh = s[size - 1];
    if (fisrstCh != lastCh)
    {
        return false;
    }
    else
    {
        string middlePart = s.substr(1, size - 2);
        return palindromeCheck(middlePart, size - 2);
    }
}
int findLCM(int a, int b, int temp)
{
    if ((temp % a == 0) && (temp % b == 0))
    {
        return temp;
    }
    return findLCM(a, b, temp + temp);
}
int main()
{
    // Rescursion
    cout << factorial(5) << endl;
    cout << power(5, 2) << endl;
    cout << sum(5) << endl;
    cout << fib(6) << endl;
    cout << reverse("CAT") << endl;
    cout << findPI("pi = pi = pi") << endl;
    decreasingOrder(5);
    cout << endl;
    incOrder(5);
    cout << endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 2, 8};
    cout << firstOcc(arr, 8, 0, 2) << endl;
    cout << lastOcc(arr, 8, 0, 2) << endl;
    towerofHanoi(3, 'A', 'B', 'C');
    cout << removeDuplicate("aaaabbbbcccdddd") << endl;
    cout << moveXEnd("axbxbxxasddf") << endl;
    subString("ABC", "");
    subSeq("AB", "");

    int set[] = {1, 2, 3, 4};
    int sub[16];
    subsets(set, 4, 0, sub, 0);
    cout << endl;
    string str = "RADAR";
    cout << palindromeCheck("radar", str.length()) << endl;
    cout << findLCM(15, 10, 2);
    return 0;
}