////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Source resized in 3-Dimensions
    class Size³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size³Event, SpatialEvent)
    public:
        Size³Event(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size³Event(const Header&);
        Size³Event(const Size³Event&, const Header&);
        ~Size³Event();

    private:
        Size3D  m_size = ZERO;
        
        Size³Event(const Size³Event&) = delete;
        Size³Event(Size³Event&&) = delete;
        Size³Event& operator=(const Size³Event&) = delete;
        Size³Event& operator=(Size³Event&&) = delete;
    };
}
