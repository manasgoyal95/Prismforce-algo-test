#include <bits/stdc++.h>
using namespace std;
    
bool canCrossChakravyuha(int p, int A, int B, vector<int> enemyPowers) {
    int n = enemyPowers.size();
    vector<bool> skipped(n, false);
    vector<bool> regenerated(n, false);

    for (int i = 0; i < n; ++i) {
        // Check if we can skip this enemy
        if (A > 0) {
            A--;
            skipped[i] = true;
            continue;
        }

        // Recharge if possible before battling
        if (B > 0) {
            p += enemyPowers[i];
            B--;
        }

       
        if (p >= enemyPowers[i]) {
            p -= enemyPowers[i];
        } else {
            return false; 
        }

        // Check for regeneration of k3 and k7 enemies
        if (i == 2 || i == 6) {
            if (!regenerated[i]) {
                regenerated[i] = true;
                if (i + 1 < n && !skipped[i + 1]) {
                    int regeneratedPower = enemyPowers[i] / 2;
                    if (p >= regeneratedPower) {
                        p -= regeneratedPower;
                    } else {
                        return false; 
                    }
                }
            }
        }
    }

    return true; 
}
    
int main(){
    
    vector<int> ep1 = {5, 7, 3, 9, 2, 6, 4, 8, 1, 10, 11};
    int p = 20, A = 2, B = 2;
    cout << (canCrossChakravyuha(p, A, B, ep1) ? "Abhimanyu crosses the Chakravyuha" : "Abhimanyu fails") << endl;

    // Test case 2
    vector<int> ep2 = {10, 8, 5, 6, 7, 9, 5, 3, 4, 12, 6};
    int p2 = 25, A2 = 3, B2 = 1;
    cout << (canCrossChakravyuha(p2, A2, B2, ep2) ? "Abhimanyu crosses the Chakravyuha" : "Abhimanyu fails") << endl;

    return 0;
}