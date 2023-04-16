////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <boost/ut.hpp>
#include <basic/Logging.hpp>
#include <meta/Init.hpp>
#include <tachyon/task/TaskEngine.hpp>

namespace ut = boost::ut;
using namespace ut;
using namespace yq;
using namespace yq::tachyon;

struct CounterTask : public Task {
    YQ_OBJECT_DECLARE(CounterTask, Task);
    int&        count;
    CounterTask(int& c) : count(c) {}

    TaskExecutionControl  tick(API&)  override
    {
        ++count;
        return true;
    }
};

YQ_OBJECT_IMPLEMENT(CounterTask);

suite tests = []{
    "Simple Step"_test = []{
        int         c   = 0;
        Task::Engine        te;
        te.add(new CounterTask(c));
        te.step();
        expect(1 == c);
    };
};



int main()
{
    log_to_std_output();
    Meta::init();
    return ut::cfg<>.run();
}

