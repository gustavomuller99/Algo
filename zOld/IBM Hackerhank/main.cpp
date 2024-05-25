#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);


/*
 * Complete the 'getNumPairs' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER l
 *  3. INTEGER r
 */

//long getNumPairs(vector<int> arr, int l, int r) {
//    long ans = 0;
//    std::sort(arr.begin(), arr.end());
//    for (int i = 1; i < arr.size(); ++i) {
//        int l1 = 0, r1 = i - 1;
//        while (r1 > l1 + 1) {
//            int mid = (l1 + r1) / 2;
//            if (arr[mid] + arr[i] >= l) r1 = mid;
//            else l1 = mid;
//        }
//        int l2 = 0, r2 = i - 1;
//        while (r2 > l2 + 1) {
//            int mid = (l2 + r2) / 2;
//            if (arr[mid] + arr[i] <= r) l2 = mid;
//            else r2 = mid;
//        }
//        if (arr[l1] + arr[i] >= l && arr[r2] + arr[i] <= r) ans += r2 - l1 + 1;
//        else if (arr[r1] + arr[i] >= l && arr[l2] + arr[i] <= r) ans += l2 - r1 + 1;
//    }
//    return ans;
//}

long getNumPairs(vector<int> arr, int l, int r) {
    long ans = 0;
    int l1 = 0, r1 = 0;
    std::sort(arr.begin(), arr.end());
    for (int i = arr.size() - 1; i > 0; --i) {
        l1 = min(l1, i);
        r1 = min(r1, i);
        while (l1 < i && arr[l1] + arr[i] < l) l1++;
        while (r1 < i && arr[r1] + arr[i] <= r) r1++;
        if (arr[l1] + arr[i] >= l && r && arr[r1 - 1] + arr[i] <= r) ans += (r1 - l1);
    }
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string r_temp;
    getline(cin, r_temp);

    int r = stoi(ltrim(rtrim(r_temp)));

    long result = getNumPairs(arr, l, r);

    fout << result << "\n";
    cout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
