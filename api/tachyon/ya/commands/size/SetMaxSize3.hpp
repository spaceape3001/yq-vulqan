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
    class SetMaxSize³ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize³, SizeCommand)
    public:
        SetMaxSize³(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize³(const Header&);
        SetMaxSize³(const SetMaxSize³&, const Header&);
        ~SetMaxSize³();

    private:
        Size3D   m_size = ZERO;
        
        SetMaxSize³(const SetMaxSize³&) = delete;
        SetMaxSize³(SetMaxSize³&&) = delete;
        SetMaxSize³& operator=(const SetMaxSize³&) = delete;
        SetMaxSize³& operator=(SetMaxSize³&&) = delete;
    };
}
