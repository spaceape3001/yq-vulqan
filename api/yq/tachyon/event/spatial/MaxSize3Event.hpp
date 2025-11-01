////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/SpatialEvent.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Source resized in 3-Dimensions
    class MaxSize³Event : public SpatialEvent {
        YQ_OBJECT_DECLARE(MaxSize³Event, SpatialEvent)
    public:
        MaxSize³Event(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MaxSize³Event(const Header&);
        MaxSize³Event(const MaxSize³Event&, const Header&);
        ~MaxSize³Event();

    private:
        Size3D  m_size = ZERO;
        
        MaxSize³Event(const MaxSize³Event&) = delete;
        MaxSize³Event(MaxSize³Event&&) = delete;
        MaxSize³Event& operator=(const MaxSize³Event&) = delete;
        MaxSize³Event& operator=(MaxSize³Event&&) = delete;
    };
}
