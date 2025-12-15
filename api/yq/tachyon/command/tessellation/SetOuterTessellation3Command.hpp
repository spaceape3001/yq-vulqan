////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/TessellationCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetOuterTessellation³Command : public TessellationCommand {
        YQ_OBJECT_DECLARE(SetOuterTessellation³Command, TessellationCommand)
    public:
        SetOuterTessellation³Command(const Header&, const Vector3D&);
    
        const Vector3D&   outer_tessellation() const  { return m_outerTessellation; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetOuterTessellation³Command();
        SetOuterTessellation³Command(const SetOuterTessellation³Command&, const Header&);
    
    private:
        Vector3D  m_outerTessellation;
        
        SetOuterTessellation³Command(const SetOuterTessellation³Command&) = delete;
        SetOuterTessellation³Command(SetOuterTessellation³Command&&) = delete;
        SetOuterTessellation³Command& operator=(const SetOuterTessellation³Command&) = delete;
        SetOuterTessellation³Command& operator=(SetOuterTessellation³Command&&) = delete;
    };
}
