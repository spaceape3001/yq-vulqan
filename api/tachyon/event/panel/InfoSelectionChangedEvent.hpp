////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/PanelEvent.hpp>

namespace yq::tachyon {
    class TachyonMeta;
    
    class InfoSelectionChangedEvent : public PanelEvent {
        YQ_OBJECT_DECLARE(InfoSelectionChangedEvent, PanelEvent)
    public:
        InfoSelectionChangedEvent(const Header&, const TachyonMeta*);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
        
        const TachyonMeta*  info() const { return m_info; }

    protected:
        InfoSelectionChangedEvent(const InfoSelectionChangedEvent&, const Header&);
        virtual ~InfoSelectionChangedEvent();
        
    private:
    
        const TachyonMeta*  m_info  = nullptr;

        InfoSelectionChangedEvent(const InfoSelectionChangedEvent&) = delete;
        InfoSelectionChangedEvent(InfoSelectionChangedEvent&&) = delete;
        InfoSelectionChangedEvent& operator=(const InfoSelectionChangedEvent&) = delete;
        InfoSelectionChangedEvent& operator=(InfoSelectionChangedEvent&&) = delete;
    };
}
