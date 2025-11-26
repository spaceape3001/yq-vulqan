////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/ShapeEvent.hpp>
#include <yq/tachyon/typedef/texture.hpp>

namespace yq::tachyon {
    class SetTextureEvent : public ShapeEvent {
        YQ_OBJECT_DECLARE(SetTextureEvent, ShapeEvent)
    public:
        SetTextureEvent(const Header&, const TextureCPtr&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const TextureCPtr&     texture() const { return m_texture; }

    protected:
        SetTextureEvent(const SetTextureEvent&, const Header&);
        virtual ~SetTextureEvent();
        
    private:
    
        TextureCPtr            m_texture;

        SetTextureEvent(const SetTextureEvent&) = delete;
        SetTextureEvent(SetTextureEvent&&) = delete;
        SetTextureEvent& operator=(const SetTextureEvent&) = delete;
        SetTextureEvent& operator=(SetTextureEvent&&) = delete;
    };
}
