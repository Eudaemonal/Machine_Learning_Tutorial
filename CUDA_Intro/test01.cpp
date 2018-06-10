#include <iostream>
#include <cmath>
#include <ctime>
#include <ratio>
#include <chrono>

/*
Compile:
g++ -o test01 test01.cpp -Wall -Wextra --std=c++11 -lbenchmark -lpthread
*/



// function to add the elements of two arrays
static void add(int n, float *x, float *y){
	for (int i = 0; i < n; i++)
		y[i] = x[i] + y[i];
}

int main(void){
  using namespace std::chrono;
  int N = 1<<24; // 1M elements

  float *x = new float[N];
  float *y = new float[N];

  // initialize x and y arrays on the host
  for (int i = 0; i < N; i++) {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  

  // Run kernel on 1M elements on the CPU
  add(N, x, y);

  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  // Check for errors (all values should be 3.0f)
  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = fmax(maxError, fabs(y[i]-3.0f));
  std::cout << "Max error: " << maxError << "\n";
  std::cout << "Duration: " 
              << time_span.count() * 1000
              << " ms\n";
  // Free memory
  delete [] x;
  delete [] y;

  return 0;
}
