////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/thread/ScheduleCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>
#include <tachyon/api/Tachyon.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ScheduleCommand)

namespace yq::tachyon {
    ScheduleCommand::ScheduleCommand(const Header&h, const TachyonPtrVector&tacs) : 
        ThreadCommand(h), m_tachyons(tacs)
    {
    }
    
    ScheduleCommand::ScheduleCommand(const Header&h, TachyonPtrVector&&tacs) : 
        ThreadCommand(h), m_tachyons(std::move(tacs))
    {
    }

    ScheduleCommand::ScheduleCommand(const ScheduleCommand& cp, const Header&h) : 
        ThreadCommand(cp,h), m_tachyons(cp.m_tachyons)
    {
    }

    ScheduleCommand::~ScheduleCommand()
    {
    }

    PostCPtr    ScheduleCommand::clone(rebind_k, const Header& h) const 
    {
        return new ScheduleCommand(*this, h);
    }
    
    void ScheduleCommand::init_info()
    {
        auto w = writer<ScheduleCommand>();
        w.description("Schedule Command");
    }
}
