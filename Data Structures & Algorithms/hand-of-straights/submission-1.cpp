class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        int maxCard = *max_element(hand.begin(), hand.end());

        vector<int> cards(maxCard + 1, 0);

        for (auto card : hand) {
            cards[card]++;
        }

        int cardsLeft = hand.size();

        while (cardsLeft) {
            for (int i = 0; i < cards.size(); i++) {
                if (cards[i] > 0) {

                    // Check whether we have enough consecutive cards
                    for (int j = 0; j < groupSize; j++) {
                        if (i + j >= cards.size() || cards[i + j] == 0) {
                            return false;
                        }
                    }

                    // Use those cards
                    for (int j = 0; j < groupSize; j++) {
                        cards[i + j]--;
                    }

                    cardsLeft -= groupSize;
                    break;
                }
            }
        }

        return true;
    }
};