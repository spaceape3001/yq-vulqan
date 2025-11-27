////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/event/ShapeEvent.hpp>
#include <yq/tachyon/typedef/material.hpp>

namespace yq::tachyon {
    class SetMaterialEvent : public ShapeEvent {
        YQ_OBJECT_DECLARE(SetMaterialEvent, ShapeEvent)
    public:
        SetMaterialEvent(const Header&, const MaterialCPtr&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const MaterialCPtr&     material() const { return m_material; }
        const Url& url() const { return m_url; }

    protected:
        SetMaterialEvent(const SetMaterialEvent&, const Header&);
        virtual ~SetMaterialEvent();
        
    private:
    
        MaterialCPtr    m_material;
        Url             m_url;

        SetMaterialEvent(const SetMaterialEvent&) = delete;
        SetMaterialEvent(SetMaterialEvent&&) = delete;
        SetMaterialEvent& operator=(const SetMaterialEvent&) = delete;
        SetMaterialEvent& operator=(SetMaterialEvent&&) = delete;
    };
}
