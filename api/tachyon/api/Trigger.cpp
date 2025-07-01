////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Trigger.hpp>
#include <tachyon/api/TriggerInfoWriter.hpp>
#include <tachyon/api/Post.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Trigger)

namespace yq::tachyon {
    TriggerInfo::TriggerInfo(std::string_view zName, DelegateInfo& base, const std::source_location& sl) :
        DelegateInfo(zName, base, sl)
    {
        set(Flag::TRIGGER);
    }
    
    TriggerInfo::~TriggerInfo(){}

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

    const PostMeta&     Trigger::post_info() const
    {
        return meta<Post>();
    }

    bool            Trigger::triggered(const Post&pp) const
    {
        Result  r = analyze(pp);
        if(auto p = std::get_if<bool>(&r))
            return *p;
        if(std::get_if<accept_k>(&r))
            return true;
        if(std::get_if<reject_k>(&r))
            return false;
        if(std::get_if<mismatch_k>(&r))
            return m_mismatch;
        if(std::get_if<failure_k>(&r))
            return m_errors;
        return false;
    }

    void Trigger::init_info()
    {
        auto w = writer<Trigger>();
        w.description("Abstract Post Trigger");
    }
}
