// The different ways of passing values.  Timing examples where appropriate.

#include <iostream>

// Stopwatch code from: http://codereview.stackexchange.com/questions/48872/measuring-execution-time-in-c
template<typename TimeT = std::chrono::microseconds, 
    typename ClockT=std::chrono::high_resolution_clock,
    typename DurationT=double>
class Stopwatch
{
private:
    std::chrono::time_point<ClockT> _start, _end;
public:
    Stopwatch() { start(); }
    void start() { _start = _end = ClockT::now(); }
    DurationT stop() { _end = ClockT::now(); return elapsed();}
    DurationT elapsed() { 
        auto delta = std::chrono::duration_cast<TimeT>(_end-_start);
        return delta.count(); 
    }
};

// Pass by Value
int mul_by_10(int k) {
    k *= 10;
    return k;
}

// Pass by Reference
int r_mul_by_10(int& k) {
    k *= 10;
    return k;
}

int main() {
    int million = 1000000;
    int i = 100;

    // Pass by Value
    Stopwatch<> sw;
    // Run 1,000,000 times.
    for(int j = 0; j < million; ++j) {
        int k = mul_by_10(i);
    }
    sw.stop();
    std::cout << "Pass by value took " << sw.elapsed() << " microseconds\n";

    // Pass by Reference
    sw.start();
    // Run 1,000,000 times.
    for(int j = 0; j < million; ++j) {
        int k = mul_by_10(i);
    }
    sw.stop();
    std::cout << "Pass by reference took " << sw.elapsed() << " microseconds\n";

}