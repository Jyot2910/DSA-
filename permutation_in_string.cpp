#include <iostream>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i])
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};

    // freq of s1
    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }

    int windSize = s1.length();

    // outer loop
    for (int i = 0; i < s2.length(); i++) {
        int windFreq[26] = {0};

        int windIdx = 0;
        int idx = i;

        // build window
        while (windIdx < windSize && idx < s2.length()) {
            windFreq[s2[idx] - 'a']++;
            windIdx++;
            idx++;
        }

        // check only if full window formed
        if (windIdx == windSize) {
            if (isFreqSame(freq, windFreq)) {
                return true;
            }
        }
    }

    return false;
}