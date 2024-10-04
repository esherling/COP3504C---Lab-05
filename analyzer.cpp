#include "StringData.h"
#include <iostream>

#define MIDPOINT(a, b) ((a + b) / 2)

using namespace std;

int linearSearch(const vector<string> &container, const string &element);

int binarySearch(const vector<string> &container, const string &element);

vector<string>
timeOfAlgorithm(int (&search)(const vector<string> &, const string &),
                const vector<string> &data, const string &element);

int main() {
  const vector<string> data =
      getStringData(); // Access the data set from the stringdata module

  vector<string> result = timeOfAlgorithm(linearSearch, data, "not_here");
  cout << "Result of Linear Search for \"not_here\": " << result[0] << endl;
  cout << "Time: " << result[1] << endl << endl;

  result = timeOfAlgorithm(binarySearch, data, "not_here");
  cout << "Result of Binary Search for \"not_here\": " << result[0] << endl;
  cout << "Time: " << result[1] << endl << endl;

  result = timeOfAlgorithm(linearSearch, data, "mzzzz");
  cout << "Result of Linear Search for \"mzzzz\": " << result[0] << endl;
  cout << "Time: " << result[1] << endl << endl;

  result = timeOfAlgorithm(binarySearch, data, "mzzzz");
  cout << "Result of Binary Search for \"mzzzz\": " << result[0] << endl;
  cout << "Time: " << result[1] << endl << endl;

  result = timeOfAlgorithm(linearSearch, data, "aaaaa");
  cout << "Result of Linear Search for \"aaaaa\": " << result[0] << endl;
  cout << "Time: " << result[1] << endl << endl;

  result = timeOfAlgorithm(binarySearch, data, "aaaaa");
  cout << "Result of Binary Search for \"aaaaa\": " << result[0] << endl;
  cout << "Time: " << result[1] << endl << endl;
}

// Finds runtime of called algorithm and returns result of algorithm
vector<string>
timeOfAlgorithm(int (&search)(const vector<string> &, const string &),
                const vector<string> &data, const string &element) {
  const long long startTime = systemTimeNanoseconds();
  const int result = search(data, element);
  const long long endTime = systemTimeNanoseconds();

  const long long runtime = endTime - startTime;
  return {to_string(result), to_string(runtime).append("ns")};
}

// O(log n)
int binarySearch(const vector<string> &container, const string &element) {
  int low = 0; // First index of container
  int high = static_cast<int>(container.size()) - 1; // Last index of container
  int mid = MIDPOINT(low, high);
  int oldMid = -1;

  while (oldMid != mid) {
    // Break when we check the same spot
    if (container[mid] == element) {
      return mid;
    } else if (element < container[mid]) {
      // Need to look earlier in container
      oldMid = mid;
      high = mid - 1; // New high is everything before mid
      mid = MIDPOINT(low, high);
    } else {
      // Need to look later in container
      oldMid = mid;
      low = mid + 1; // New low is everything after mid
      mid = MIDPOINT(low, high);
    }
  }
  return -1;
}

// O(n)
int linearSearch(const vector<string> &container, const string &element) {
  for (int i = 0; i < container.size(); i++) {
    if (container[i] == element) {
      return i;
    }
  }

  return -1;
}
