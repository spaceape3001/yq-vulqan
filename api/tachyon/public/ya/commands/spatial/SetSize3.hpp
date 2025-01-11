////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetSize³, SpatialCommand)
    public:
        SetSize³(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize³(const Header&);
        SetSize³(const SetSize³&, const Header&);
        ~SetSize³();

    private:
        Size3D   m_size = ZERO;
        
        SetSize³(const SetSize³&) = delete;
        SetSize³(SetSize³&&) = delete;
        SetSize³& operator=(const SetSize³&) = delete;
        SetSize³& operator=(SetSize³&&) = delete;
    };
}
