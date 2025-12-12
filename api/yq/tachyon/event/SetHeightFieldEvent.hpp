////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/typedef/height_field.hpp>

namespace yq::tachyon {
    class SetHeightFieldEvent : public Event {
        YQ_OBJECT_DECLARE(SetHeightFieldEvent, Event)
    public:
        SetHeightFieldEvent(const Header&, const HeightFieldCPtr&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const HeightFieldCPtr&     height_field() const { return m_heightField; }
        const Url&              url() const { return m_url; }

    protected:
        SetHeightFieldEvent(const SetHeightFieldEvent&, const Header&);
        virtual ~SetHeightFieldEvent();
        
    private:
    
        HeightFieldCPtr            m_heightField;
        Url                         m_url;

        SetHeightFieldEvent(const SetHeightFieldEvent&) = delete;
        SetHeightFieldEvent(SetHeightFieldEvent&&) = delete;
        SetHeightFieldEvent& operator=(const SetHeightFieldEvent&) = delete;
        SetHeightFieldEvent& operator=(SetHeightFieldEvent&&) = delete;
    };
}
