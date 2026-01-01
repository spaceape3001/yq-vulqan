////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/VulqanEvent.hpp>
#include <yq/tachyon/typedef/vi_debug_trace.hpp>

namespace yq::tachyon {
    class VulqanDebugEvent : public VulqanEvent {
        YQ_OBJECT_DECLARE(VulqanDebugEvent, VulqanEvent)
    public:
        VulqanDebugEvent(const Header&, const ViDebugTraceCPtr&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const auto& trace() const { return m_trace; }

    protected:
        VulqanDebugEvent(const VulqanDebugEvent&, const Header&);
        virtual ~VulqanDebugEvent();
        
    private:

        ViDebugTraceCPtr  m_trace;

        VulqanDebugEvent(const VulqanDebugEvent&) = delete;
        VulqanDebugEvent(VulqanDebugEvent&&) = delete;
        VulqanDebugEvent& operator=(const VulqanDebugEvent&) = delete;
        VulqanDebugEvent& operator=(VulqanDebugEvent&&) = delete;
    };
}
