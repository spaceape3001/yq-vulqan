////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3PeriodCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³PeriodCommand)

namespace yq::tachyon {
    Circular³PeriodCommand::Circular³PeriodCommand(const Header& h, unit::Second _period) : Circular³Command(h), m_period(_period)
    {
    }
    
    Circular³PeriodCommand::Circular³PeriodCommand(const Circular³PeriodCommand&cp, const Header&h) : 
        Circular³Command(cp, h), m_period(cp.m_period)
    {
    }

    Circular³PeriodCommand::~Circular³PeriodCommand()
    {
    }
    
    PostCPtr    Circular³PeriodCommand::clone(rebind_k, const Header&h) const
    {
        return new Circular³PeriodCommand(*this, h);
    }

    void Circular³PeriodCommand::init_meta()
    {
        auto w = writer<Circular³PeriodCommand>();
        w.description("Circular³ Period Command");
        w.property("period", &Circular³PeriodCommand::m_period);
    }
}
