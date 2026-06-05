////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class Size¹CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size¹CMEvent, SpatialEvent)
    public:
        Size¹CMEvent(const Header&, const Size1CM&);
    
        const Size1CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size¹CMEvent(const Header&);
        Size¹CMEvent(const Size¹CMEvent&, const Header&);
        ~Size¹CMEvent();

    private:
        Size1CM  m_size = ZERO;
        
        Size¹CMEvent(const Size¹CMEvent&) = delete;
        Size¹CMEvent(Size¹CMEvent&&) = delete;
        Size¹CMEvent& operator=(const Size¹CMEvent&) = delete;
        Size¹CMEvent& operator=(Size¹CMEvent&&) = delete;
    };
}
