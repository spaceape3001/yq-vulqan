////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/UIEvent.hpp>

namespace yq::tachyon {
    class MaximizeEvent : public UIEvent {
        YQ_OBJECT_DECLARE(MaximizeEvent, UIEvent)
    public:
        MaximizeEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        MaximizeEvent(const MaximizeEvent&, const Header&);
        virtual ~MaximizeEvent();
        
    private:

        MaximizeEvent(const MaximizeEvent&) = delete;
        MaximizeEvent(MaximizeEvent&&) = delete;
        MaximizeEvent& operator=(const MaximizeEvent&) = delete;
        MaximizeEvent& operator=(MaximizeEvent&&) = delete;
    };
}
