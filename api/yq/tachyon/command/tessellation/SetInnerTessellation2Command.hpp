////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/TessellationCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetInnerTessellation²Command : public TessellationCommand {
        YQ_OBJECT_DECLARE(SetInnerTessellation²Command, TessellationCommand)
    public:
        SetInnerTessellation²Command(const Header&, const Vector2D&);
    
        const Vector2D&   inner_tessellation() const  { return m_innerTessellation; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetInnerTessellation²Command();
        SetInnerTessellation²Command(const SetInnerTessellation²Command&, const Header&);
        
    private:
        Vector2D   m_innerTessellation;
        SetInnerTessellation²Command(const SetInnerTessellation²Command&) = delete;
        SetInnerTessellation²Command(SetInnerTessellation²Command&&) = delete;
        SetInnerTessellation²Command& operator=(const SetInnerTessellation²Command&) = delete;
        SetInnerTessellation²Command& operator=(SetInnerTessellation²Command&&) = delete;
    };
}
