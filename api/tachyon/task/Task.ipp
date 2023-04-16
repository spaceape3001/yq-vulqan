////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/task/Task.hpp>
#include <basic/DelayInit.hpp>

namespace yq::tachyon {

    TaskInfo::TaskInfo(std::string_view name, ObjectInfo&base, const std::source_location& sl) :
        ObjectInfo(name, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Task::initInfo()
    {
        auto w = writer<Task>();
        w.abstract();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Task::Task()
    {
    }
    
    Task::~Task()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    YQ_INVOKE( Task::initInfo(); )
}


YQ_OBJECT_IMPLEMENT(yq::tachyon::Task)
