////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize³ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize³, SizeCommand)
    public:
        SetMinSize³(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize³(const Header&);
        SetMinSize³(const SetMinSize³&, const Header&);
        ~SetMinSize³();

    private:
        Size3D   m_size = ZERO;
        
        SetMinSize³(const SetMinSize³&) = delete;
        SetMinSize³(SetMinSize³&&) = delete;
        SetMinSize³& operator=(const SetMinSize³&) = delete;
        SetMinSize³& operator=(SetMinSize³&&) = delete;
    };
}
