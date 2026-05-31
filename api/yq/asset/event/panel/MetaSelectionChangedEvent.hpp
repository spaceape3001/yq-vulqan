////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/PanelEvent.hpp>

namespace yq::tachyon {
    class TachyonMeta;
    
    class MetaSelectionChangedEvent : public PanelEvent {
        YQ_OBJECT_DECLARE(MetaSelectionChangedEvent, PanelEvent)
    public:
        MetaSelectionChangedEvent(const Header&, const Meta*);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const Meta*  meta() const { return m_meta; }

    protected:
        MetaSelectionChangedEvent(const MetaSelectionChangedEvent&, const Header&);
        virtual ~MetaSelectionChangedEvent();
        
    private:
    
        const Meta*  m_meta  = nullptr;

        MetaSelectionChangedEvent(const MetaSelectionChangedEvent&) = delete;
        MetaSelectionChangedEvent(MetaSelectionChangedEvent&&) = delete;
        MetaSelectionChangedEvent& operator=(const MetaSelectionChangedEvent&) = delete;
        MetaSelectionChangedEvent& operator=(MetaSelectionChangedEvent&&) = delete;
    };
}
