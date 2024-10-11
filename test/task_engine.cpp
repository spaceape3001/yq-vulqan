////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <boost/ut.hpp>
#include <yq/core/Logging.hpp>
#include <yq/meta/Init.hpp>
#include <tachyon/task/TaskEngine.hpp>

namespace ut = boost::ut;
using namespace ut;
using namespace yq;
using namespace yq::tachyon;

struct CounterTask : public Task {
    int&        count;
    CounterTask(int& c) : count(c) {}

    EC  tick(TaskAPI&)  override
    {
        ++count;
        return true;
    }
};


suite tests = []{
    "Simple Step"_test = []{
        int         c   = 0;
        TaskEngine        te;
        te.add(new CounterTask(c));
        te.step();
        expect(1 == c);
    };
};



int main()
{
    log_to_std_output();
    return ut::cfg<>.run();
}

