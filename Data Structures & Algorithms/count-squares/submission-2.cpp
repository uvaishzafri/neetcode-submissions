class CountSquares {
public:
    int freq[1001][1001] = {};

    CountSquares() {}

    void add(vector<int> point) {
        freq[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int result = 0;

        for (int d = 1; d <= 1000; d++) {

            // Top-right diagonal
            if (x + d <= 1000 && y + d <= 1000) {
                result += freq[x + d][y + d]
                        * freq[x + d][y]
                        * freq[x][y + d];
            }

            // Bottom-right diagonal
            if (x + d <= 1000 && y - d >= 0) {
                result += freq[x + d][y - d]
                        * freq[x + d][y]
                        * freq[x][y - d];
            }

            // Top-left diagonal
            if (x - d >= 0 && y + d <= 1000) {
                result += freq[x - d][y + d]
                        * freq[x - d][y]
                        * freq[x][y + d];
            }

            // Bottom-left diagonal
            if (x - d >= 0 && y - d >= 0) {
                result += freq[x - d][y - d]
                        * freq[x - d][y]
                        * freq[x][y - d];
            }
        }

        return result;
    }
};