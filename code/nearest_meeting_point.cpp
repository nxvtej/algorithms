#include <vector>
#include <limits>
#include <queue>
#include <iostream>

using namespace std;

// Function to perform Dijkstra's shortest path algorithm
vector<int> dijkstra(int n, const vector<int>& edges, int start) {
    vector<int> dist(n, numeric_limits<int>::max()); // Initialize distances to infinity
    dist[start] = 0; // Distance from start to itself is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // Push starting node with distance 0

    while (!pq.empty()) {
        int curr = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (currDist > dist[curr]) {
            continue; // Already processed with a shorter distance
        }

        for (int next = 0; next < n; next++) {
    if (edges[next] != -1 && next != curr && edges[curr] == next) { // Check if valid neighbor and reachable
        int newDist = currDist + 1; // Update distance with neighbor
        if (newDist < dist[next]) {
            dist[next] = newDist;
            pq.push({newDist, next}); // Add neighbor to queue for further exploration
        }
    }
}
    }

    return dist;
}

int findNearestMeetingCell(int n, const vector<int>& edges, int cell1, int cell2) {
    vector<int> dist1 = dijkstra(n, edges, cell1); // Distances from cell1
    vector<int> dist2 = dijkstra(n, edges, cell2); // Distances from cell2

    int minMeetingDist = numeric_limits<int>::max();
    int meetingCell = -1; // Initialize to -1 for each test case

    for (int i = 0; i < n; i++) {
        if (dist1[i] != numeric_limits<int>::max() && dist2[i] != numeric_limits<int>::max()) { // Check if reachable from both cells
            int totalDist = dist1[i] + dist2[i];
            if (totalDist < minMeetingDist) {
                minMeetingDist = totalDist;
                meetingCell = i;
            }
        }
    }

    return meetingCell;
}


int main() {
    // Example usage:
    int n; // Number of cells
    cin >> n;

    vector<int> edges(n); // Edge connections (example)
    for (int i = 0; i < n; i++) {
        cin >> edges[i];
    }

    int cell1 = 0; // Starting cell 1
    int cell2 = 0; // Starting cell 2

    cin >> cell1 >> cell2;

    // cout<<n<<cell1<<cell2<<endl;
    int meetingCell = findNearestMeetingCell(n, edges, cell1, cell2);

    if (meetingCell == -1) {
        cout << "No meeting cell found." << endl;
    } else {
        cout << "The nearest meeting cell is: " << meetingCell << endl;
    }

    return 0;
}
