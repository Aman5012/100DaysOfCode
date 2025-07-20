Q2. Count Number of Trapezoids I
//QUESTION LNK: https://leetcode.com/contest/weekly-contest-459/problems/count-number-of-trapezoids-i/

TOPIC: map, Array

CODE:

// Time Complexity: O(NlogN) 
// Space Complexity: O(N)

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7; // Modulo constant

        // Step 1: Group points by their y-coordinate and count occurrences
        // map<y_coordinate, count_of_points_at_this_y>
        map<int, int> y_coordinate_counts;
        for (const auto& point : points) {
            y_coordinate_counts[point[1]]++; // point[1] is the y-coordinate
        }

        // Step 2: Calculate the number of horizontal segments (combinations of 2 points)
        // for each y-level that has at least 2 points.
        // vector<number_of_segments_at_this_y_level>
        vector<long long> segment_combinations;
        for (const auto& pair : y_coordinate_counts) {
            long long num_points_at_y = pair.second;
            if (num_points_at_y >= 2) {
                // Calculate C(n, 2) = n * (n - 1) / 2
                long long combinations = (num_points_at_y * (num_points_at_y - 1) / 2) % MOD;
                segment_combinations.push_back(combinations);
            }
        }

        // Optimized Step 3: Count trapezoids by pairing horizontal segments from different y-levels.
        // This replaces the nested for loop with an O(K) calculation.

        // If there are less than two y-levels with segments, no trapezoids can be formed.
        if (segment_combinations.size() < 2) {
            return 0;
        }

        long long sum_of_elements = 0;
        long long sum_of_squares = 0;

        // Calculate the sum of elements and sum of squares of elements in segment_combinations
        for (long long s : segment_combinations) {
            sum_of_elements = (sum_of_elements + s) % MOD;
            // (s * s) can exceed long long if s is close to LLONG_MAX,
            // but since s is already % MOD, s < MOD (10^9+7).
            // (10^9+7)^2 is around 10^18, which fits in long long.
            // So (s * s) % MOD is safe.
            sum_of_squares = (sum_of_squares + (s * s) % MOD) % MOD;
        }

        // Apply the identity: totalTrapezoids = ( (sum_of_elements)^2 - sum_of_squares ) / 2
        // Make sure the result of subtraction is positive before modulo
        long long totalTrapezoids = ((sum_of_elements * sum_of_elements) % MOD - sum_of_squares + MOD) % MOD;
        
        // Modular multiplicative inverse of 2 (since MOD is prime)
        // (MOD + 1) / 2 for MOD = 10^9 + 7
        long long inv_2 = 500000004; 

        totalTrapezoids = (totalTrapezoids * inv_2) % MOD;

        return static_cast<int>(totalTrapezoids);
    }
};
