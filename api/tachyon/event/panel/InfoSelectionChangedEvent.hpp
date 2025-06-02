////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/PanelEvent.hpp>

namespace yq::tachyon {
    class TachyonInfo;
    
    class InfoSelectionChangedEvent : public PanelEvent {
        YQ_OBJECT_DECLARE(InfoSelectionChangedEvent, PanelEvent)
    public:
        InfoSelectionChangedEvent(const Header&, const TachyonInfo*);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
        
        const TachyonInfo*  info() const { return m_info; }

    protected:
        InfoSelectionChangedEvent(const InfoSelectionChangedEvent&, const Header&);
        virtual ~InfoSelectionChangedEvent();
        
    private:
    
        const TachyonInfo*  m_info  = nullptr;

        InfoSelectionChangedEvent(const InfoSelectionChangedEvent&) = delete;
        InfoSelectionChangedEvent(InfoSelectionChangedEvent&&) = delete;
        InfoSelectionChangedEvent& operator=(const InfoSelectionChangedEvent&) = delete;
        InfoSelectionChangedEvent& operator=(InfoSelectionChangedEvent&&) = delete;
    };
}
