////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/event/Circular3Event.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³OriginEvent : public Circular³Event {
        YQ_OBJECT_DECLARE(Circular³OriginEvent, Circular³Event)
    public:
    
        static void init_meta();
        Circular³OriginEvent(const Header&, const Vector3D&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        const Vector3D&    origin() const { return m_origin; }
        
    protected:
        Circular³OriginEvent(const Circular³OriginEvent&, const Header&);
        ~Circular³OriginEvent();
        
    private:
        Vector3D    m_origin;
    
        Circular³OriginEvent(const Circular³OriginEvent&) = delete;
        Circular³OriginEvent(Circular³OriginEvent&&) = delete;
        Circular³OriginEvent& operator=(const Circular³OriginEvent&) = delete;
        Circular³OriginEvent& operator=(Circular³OriginEvent&&) = delete;
    };
}
