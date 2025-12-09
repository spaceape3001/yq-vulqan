////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3PeriodEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³PeriodEvent)

namespace yq::tachyon {
    Circular³PeriodEvent::Circular³PeriodEvent(const Header& h, unit::Second _period) : Circular³Event(h), m_period(_period)
    {
    }
    
    Circular³PeriodEvent::Circular³PeriodEvent(const Circular³PeriodEvent&cp, const Header&h) : 
        Circular³Event(cp, h), m_period(cp.m_period)
    {
    }

    Circular³PeriodEvent::~Circular³PeriodEvent()
    {
    }
    
    PostCPtr    Circular³PeriodEvent::clone(rebind_k, const Header&h) const
    {
        return new Circular³PeriodEvent(*this, h);
    }

    void Circular³PeriodEvent::init_meta()
    {
        auto w = writer<Circular³PeriodEvent>();
        w.description("Circular³ Period Event");
        w.property("period", &Circular³PeriodEvent::m_period);
    }
}
