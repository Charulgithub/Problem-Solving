class Solution {
public: 
    
 long createPalindrome(long firstHalf, bool isEven) {
    long palindrome = firstHalf;
    if (!isEven) firstHalf /= 10;
    
    while (firstHalf > 0) {
        palindrome = palindrome * 10 + firstHalf % 10;
        firstHalf /= 10;
    }
    return palindrome;
}

string nearestPalindromic(string n) {
    int len = n.size();
    if (n == "1") return "0"; // Handle special case
    
    int mid = len / 2;
    int firstHalfLen = len % 2 == 0 ? mid : mid + 1;
    long firstHalfNum = stol(n.substr(0, firstHalfLen));

    // Generate possible palindrome candidates
    vector<long> candidates = {
        createPalindrome(firstHalfNum, len % 2 == 0),
        createPalindrome(firstHalfNum + 1, len % 2 == 0),
        createPalindrome(firstHalfNum - 1, len % 2 == 0),
        (long)pow(10, len - 1) - 1, // All 9's case, e.g., 999
        (long)pow(10, len) + 1      // 100...001 case, e.g., 1001
    };

    long originalNum = stol(n);
    long closestPalindrome = -1;
    long minDifference = LONG_MAX;

    for (long candidate : candidates) {
        if (candidate == originalNum) continue;
        long difference = abs(candidate - originalNum);

        if (difference < minDifference || (difference == minDifference && candidate < closestPalindrome)) {
            minDifference = difference;
            closestPalindrome = candidate;
        }
    }

    return to_string(closestPalindrome);
}

};