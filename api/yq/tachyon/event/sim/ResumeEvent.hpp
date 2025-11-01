////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SimEvent.hpp>

namespace yq::tachyon {
    class ResumeEvent : public SimEvent {
        YQ_OBJECT_DECLARE(ResumeEvent, SimEvent)
    public:
        ResumeEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        ResumeEvent(const ResumeEvent&, const Header&);
        virtual ~ResumeEvent();
        
    private:

        ResumeEvent(const ResumeEvent&) = delete;
        ResumeEvent(ResumeEvent&&) = delete;
        ResumeEvent& operator=(const ResumeEvent&) = delete;
        ResumeEvent& operator=(ResumeEvent&&) = delete;
    };
}
