////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Source resized in 1-Dimension
    class Size¹Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(Size¹Event, SpatialEvent)
    public:
        Size¹Event(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        Size¹Event(const Header&);
        Size¹Event(const Size¹Event&, const Header&);
        ~Size¹Event();

    private:
        Size1D  m_size = ZERO;
        
        Size¹Event(const Size¹Event&) = delete;
        Size¹Event(Size¹Event&&) = delete;
        Size¹Event& operator=(const Size¹Event&) = delete;
        Size¹Event& operator=(Size¹Event&&) = delete;
    };
}
