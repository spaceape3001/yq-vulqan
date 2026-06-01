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
    class MaxSize¹CMEvent : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize¹CMEvent, SpatialEvent)
    public:
        MaxSize¹CMEvent(const Header&, const Size1CM&);
    
        const Size1CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize¹CMEvent(const Header&);
        MaxSize¹CMEvent(const MaxSize¹CMEvent&, const Header&);
        ~MaxSize¹CMEvent();

    private:
        Size1CM  m_size = ZERO;
        
        MaxSize¹CMEvent(const MaxSize¹CMEvent&) = delete;
        MaxSize¹CMEvent(MaxSize¹CMEvent&&) = delete;
        MaxSize¹CMEvent& operator=(const MaxSize¹CMEvent&) = delete;
        MaxSize¹CMEvent& operator=(MaxSize¹CMEvent&&) = delete;
    };
}
