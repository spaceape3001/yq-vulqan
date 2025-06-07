////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize³Command : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize³Command, SizeCommand)
    public:
        SetMinSize³Command(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize³Command(const Header&);
        SetMinSize³Command(const SetMinSize³Command&, const Header&);
        ~SetMinSize³Command();

    private:
        Size3D   m_size = ZERO;
        
        SetMinSize³Command(const SetMinSize³Command&) = delete;
        SetMinSize³Command(SetMinSize³Command&&) = delete;
        SetMinSize³Command& operator=(const SetMinSize³Command&) = delete;
        SetMinSize³Command& operator=(SetMinSize³Command&&) = delete;
    };
}
