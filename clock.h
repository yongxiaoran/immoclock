#pragma once
#include <chrono>
using namespace std;
using namespace std::chrono;

typedef time_point<high_resolution_clock> TimePoint;
typedef time_point<high_resolution_clock> CheckPoint;

class Timer
{
public:

    Timer() :_begin(high_resolution_clock::now()) {}
    void reset() { _begin = high_resolution_clock::now();}

    double seconds() const
    {
        return duration_cast<duration<double>>(high_resolution_clock::now() - _begin).count();
    }

    int64_t elapsed() const //milli seconds
    {
        return duration_cast<chrono::milliseconds>(high_resolution_clock::now() - _begin).count();
    }

    int64_t elapsed_micro() const
    {
        return duration_cast<chrono::microseconds>(high_resolution_clock::now() - _begin).count();
    }

    int64_t elapsed_nano() const
    {
        return duration_cast<chrono::nanoseconds>(high_resolution_clock::now() - _begin).count();
    }

    int64_t elapsed_seconds() const
    {
        return duration_cast<chrono::seconds>(high_resolution_clock::now() - _begin).count();
    }

    int64_t elapsed_minutes() const
    {
        return duration_cast<chrono::minutes>(high_resolution_clock::now() - _begin).count();
    }

    int64_t elapsed_hours() const
    {
        return duration_cast<chrono::hours>(high_resolution_clock::now() - _begin).count();
    }

    TimePoint begin()
    {
        return _begin;
    }

    void restart()
    {
        _begin = high_resolution_clock::now();
    }

private:
    TimePoint _begin;
};




class StopWatch : public Timer
{
public:
    StopWatch()
    :Timer()
    ,_begin(_checkpoints.begin())
    {

    }
    void split(CheckPoint && cp)
    {
        cp = high_resolution_clock::now();
        _checkpoints.push_back(cp);
        _begin = _checkpoints.begin();
        _end = _checkpoints.end();
    }

    size_t size() {return _checkpoints.size();} //count num of ticks, not including the initial TimePoint;
    size_t empty() {return _checkpoints.size();}

    class iterator
    {
    public:
        iterator(){}
        iterator(std::vector<CheckPoint>::iterator itor):_itor(itor){}

        iterator * operator->()     { return this;}
        iterator operator++()     { _itor++; return (*this);}
        const iterator & operator--()     { _itor--; return (*this);}
        bool             operator!=(const iterator & rhs )     { return _itor!=rhs._itor;}
        CheckPoint timestamp() {return *_itor;}
        void echo()
        {
            std::cout << "haha" << std::endl;
        }
    private:
        std::vector<CheckPoint>::iterator _itor;
    };

    iterator begin() { return _begin; }
    iterator end() { return _end; }

    double gap(StopWatch::iterator first, StopWatch::iterator second)
    {
        return duration_cast<chrono::duration<double>>(second.timestamp() - first.timestamp()).count();
    }

    double gap(size_t index1, size_t index2)
    {
        return duration_cast<chrono::duration<double>>(_checkpoints[index2] - _checkpoints[index1]).count();
    }
    int64_t gap_milli(StopWatch::iterator first, StopWatch::iterator second);
    int64_t gap_micro(StopWatch::iterator first, StopWatch::iterator second);
    int64_t gap_second(StopWatch::iterator first, StopWatch::iterator second);
    int64_t gap_nano(StopWatch::iterator first, StopWatch::iterator second);

private:
    iterator                _begin;
    iterator                _end;
    std::vector<CheckPoint> _checkpoints;
};

