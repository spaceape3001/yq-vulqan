////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/LightEvent.hpp>

namespace yq::tachyon {
    class LightIntensityEvent : public LightEvent {
        YQ_OBJECT_DECLARE(LightIntensityEvent, LightEvent)
    public:
        LightIntensityEvent(const Header&, float);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        float   intensity() const { return m_intensity; }

    protected:
        LightIntensityEvent(const LightIntensityEvent&, const Header&);
        virtual ~LightIntensityEvent();
        
    private:
    
        float   m_intensity;

        LightIntensityEvent(const LightIntensityEvent&) = delete;
        LightIntensityEvent(LightIntensityEvent&&) = delete;
        LightIntensityEvent& operator=(const LightIntensityEvent&) = delete;
        LightIntensityEvent& operator=(LightIntensityEvent&&) = delete;
    };
}
