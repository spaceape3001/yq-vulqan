////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Trigger.hpp"
#include "TriggerInfoWriter.hpp"
#include "Post.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Trigger)

namespace yq::tachyon {
    TriggerInfo::TriggerInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::TRIGGER);
    }
    
    Trigger::Trigger(const Param& p) : m_mismatch(p.mismatch), m_errors(p.errors)
    {
    }
    
    Trigger::~Trigger()
    {
    }

    Trigger::Result Trigger::analyze(const Post& pp) const
    {
        try {
            return match(pp);
        }
        catch(...) {
            return FAILURE;
        }
    }

    const PostInfo&     Trigger::post_info() const
    {
        return meta<Post>();
    }

    bool            Trigger::triggered(const Post&pp) const
    {
        Result  r = analyze(pp);
        if(auto p = std::get_if<bool>(&r))
            return *p;
        if(std::get_if<accept_t>(&r))
            return true;
        if(std::get_if<reject_t>(&r))
            return false;
        if(std::get_if<mismatch_t>(&r))
            return m_mismatch;
        if(std::get_if<failure_t>(&r))
            return m_errors;
        return false;
    }

    void Trigger::init_info()
    {
        auto w = writer<Trigger>();
        w.description("Abstract Post Trigger");
    }
}
