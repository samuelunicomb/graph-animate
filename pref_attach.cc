#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

float distance (float x1, float y1, float x2, float y2) {
  float d = (x1 - x2) * (x1 - x2);
  d += (y1 - y2) * (y1 - y2);
  d = sqrt (d);
  return d;
}

int main () {
  
  int N = 10000;

  vector<vector<float>> pos (N); 
  vector<int> degrees (N, 0);
  vector<int> distribution (N, 0);

  // add fist node, degree zero
  pos[0].push_back (rand () / double (RAND_MAX)); // x position
  pos[0].push_back (rand () / double (RAND_MAX)); // y position

  for (int i = 1; i < N; ++i) {

    // place new node in random position
    pos[i].push_back (rand () / double (RAND_MAX)); // x position
    pos[i].push_back (rand () / double (RAND_MAX)); // y position

    // find existing node j nearest to node i
    float dmin = 1.415;
    int jmin = 0;
    for (int j = 0; j < i; ++j) {
      float d = distance (pos[i][0], pos[i][1], pos[j][0], pos[j][1]);
      if (d < dmin) {
        dmin = d;
        jmin = j;
      }
    }

    // increment degrees of new node and closest node by 1
    ++degrees[i];
    ++degrees[jmin];
  }

  // check degree dist
  for (int i = 0; i < degrees.size (); ++i)
    ++distribution[degrees[i]];

  // print distribution
  for (int i = 0; i < degrees.size (); ++i)
    cout << i << " " << distribution[i] << endl;
}
