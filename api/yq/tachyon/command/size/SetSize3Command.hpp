////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize³Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize³Command, SizeCommand)
    public:
        SetSize³Command(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_meta();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize³Command(const Header&);
        SetSize³Command(const SetSize³Command&, const Header&);
        ~SetSize³Command();

    private:
        Size3D   m_size = ZERO;
        
        SetSize³Command(const SetSize³Command&) = delete;
        SetSize³Command(SetSize³Command&&) = delete;
        SetSize³Command& operator=(const SetSize³Command&) = delete;
        SetSize³Command& operator=(SetSize³Command&&) = delete;
    };
}
