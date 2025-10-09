class Solution {
private:
    vector<vector<int>> calculateBrewingTimes(const vector<int>& skill, const vector<int>& mana) {
        int wizardCount = skill.size();
        int potionCount = mana.size();
        
        vector<vector<int>> v(wizardCount, vector<int>(potionCount));
        
        for (int wizardIdx = 0; wizardIdx < wizardCount; wizardIdx++) {
            for (int potionIdx = 0; potionIdx < potionCount; potionIdx++) {
                v[wizardIdx][potionIdx] = skill[wizardIdx] * mana[potionIdx];
            }
        }
        
        return v;
    }
    
    long long processBrewingSequence(const vector<vector<int>>& brewingTimes) {
        int wizardCount = brewingTimes.size();
        int potionCount = brewingTimes[0].size();
        
        vector<vector<long long>> completionTime(wizardCount, vector<long long>(potionCount, 0));
        
        for (int wizardIdx = 0; wizardIdx < wizardCount; wizardIdx++) {
            if (wizardIdx == 0) {
                // First wizard starts at time 0
                completionTime[wizardIdx][0] = brewingTimes[wizardIdx][0];
            } else {
                // Each next wizard must start after previous wizard finishes
                completionTime[wizardIdx][0] = completionTime[wizardIdx-1][0] + brewingTimes[wizardIdx][0];
            }
        }
        
        // Process remaining potions
        for (int potionIdx = 1; potionIdx < potionCount; potionIdx++) {
            // Calculate tentative completion times
            for (int wizardIdx = 0; wizardIdx < wizardCount; wizardIdx++) {
                if (wizardIdx == 0) {
                    // First wizard must wait until they finish previous potion
                    completionTime[wizardIdx][potionIdx] = completionTime[wizardIdx][potionIdx-1] +
                                                          brewingTimes[wizardIdx][potionIdx];
                } else {
                    // Other wizards must wait for previous wizard to finish current potion
                    completionTime[wizardIdx][potionIdx] = completionTime[wizardIdx-1][potionIdx] +
                                                          brewingTimes[wizardIdx][potionIdx];
                }
            }
            
            // Calculate required timeAdjustment to ensure proper synchronization
            long long timeAdjustment = 0;
            for (int wizardIdx = wizardCount-1; wizardIdx > 0; wizardIdx--) {
                // Check if previous potion finish time exceeds current potion start time for previous wizard
                timeAdjustment = max(timeAdjustment,
                                  completionTime[wizardIdx][potionIdx-1] -
                                  completionTime[wizardIdx-1][potionIdx]);
            }
            
            // Apply timeAdjustment to all wizards for current potion if needed
            if (timeAdjustment > 0) {
                for (int wizardIdx = 0; wizardIdx < wizardCount; wizardIdx++) {
                    completionTime[wizardIdx][potionIdx] += timeAdjustment;
                }
            }
        }
        
        // Return the time when the last wizard finishes the last potion
        return completionTime[wizardCount-1][potionCount-1];
    }

public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        // Step 1: Calculate the brewing times for each wizard and potion
        vector<vector<int>> brewingTimes = calculateBrewingTimes(skill, mana);
        
        // Step 2: Process the brewing sequence and return minimum time
        return processBrewingSequence(brewingTimes);
    }
};