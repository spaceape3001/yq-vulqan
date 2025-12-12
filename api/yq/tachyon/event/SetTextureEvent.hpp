////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/typedef/texture.hpp>

namespace yq::tachyon {
    class SetTextureEvent : public Event {
        YQ_OBJECT_DECLARE(SetTextureEvent, Event)
    public:
        SetTextureEvent(const Header&, const TextureCPtr&, const Url&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const Url&              url() const { return m_url; }
        const TextureCPtr&     texture() const { return m_texture; }

    protected:
        SetTextureEvent(const SetTextureEvent&, const Header&);
        virtual ~SetTextureEvent();
        
    private:
    
        TextureCPtr     m_texture;
        Url             m_url;

        SetTextureEvent(const SetTextureEvent&) = delete;
        SetTextureEvent(SetTextureEvent&&) = delete;
        SetTextureEvent& operator=(const SetTextureEvent&) = delete;
        SetTextureEvent& operator=(SetTextureEvent&&) = delete;
    };
}
