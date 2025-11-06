// The edit distance between two strings is the minimum number of operations required to transform one string into the other.

// The allowed operations are:
//	-Add one character to the string.
//	-Remove one character from the string.
//	-Replace one character in the string.

// For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.

// Your task is to calculate the edit distance between two strings


// --- SOLUTION DESCRIPTION ---
// The main idea is to create a table where the columns are the characters of the word1 and empty
// and the rows are the characters of the word2 and empty
// obs: to add or to remove are the same opperation.For example if you have LO vs O. It is the same to add L to O than to remove L from LO.
// The core of the solution is to notice that the three allowed operations correspond to three movements on the table
// If you remove a character from the word1, you are moving one block to the left (moving along the column)
// If you remove a character from the word2, you are moving one block up (moving along the row)
// If you replace a character either from word1 or word2 you achive the goal of aligning both characters in a single step
// As you aligned both characters, you don't need to worry about them, so it is as if you had removed both but in a single move
// So in a single operation by replacing you are moving one up and one to the left in a single operation (ie moving on the diagonal)


#include <bits/stdc++.h>

using namespace std;


int main() {
	// read input
	string word1, word2; // You accomodate the word1 horizontally and word2 vertically and that creates a table of n+1 x m+1;
	cin >> word1 >> word2;


	// Initialize the dp tables (prev and dp)
	int n = word1.size();
	vector<int> prev(n + 1); // The tables have +1 to account for the empty word
	vector<int> dp(n + 1);

	// The first row is just removing n letters from word1 to get the empty word
	for (int i = 0; i < n + 1; i++){
		prev[i] = i;
	}

	// build the dp table
	for (auto chr : word2){
		dp[0] = prev[0] + 1;
		for (int i = 1; i < n + 1; i++){
			if (chr == word1[i - 1]){ // If they are the same, they don't really matter, you ignore them
				// i.e. if you have the string LO vs MO. You can ignore the O and just focus on changing L to M.
				dp[i] = prev[i - 1]; // You copy the element in the diagonal above you.
				continue;
			}
			// If the characters are different you have three options (you add +1 to account for the operation):
			int removeChar1 = dp[i-1] + 1; // remove the character from word1 (You move one position to the left)
			int removeChar2 = prev[i] + 1; // remove the character from word2 (You move one position above)}
			int replace = prev[i - 1] + 1; // replace a character from word 1 (You copy what was in the diagonal)
			int remove = min(removeChar1, removeChar2); // is it best to remove from word1 or from word2?
			dp[i] = min(remove, replace); // is it best to remove or replace?
		}
		// swap(dp, prev); // prev becomes dp
		prev = dp;
		fill(dp.begin(), dp.end(), 0); // restart dp
	}

	cout << prev[n] << endl;

	return 0;
}

