////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/TessellationCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetOuterTessellation⁴Command : public TessellationCommand {
        YQ_OBJECT_DECLARE(SetOuterTessellation⁴Command, TessellationCommand)
    public:
        SetOuterTessellation⁴Command(const Header&, const Vector4D&);
    
        const Vector4D&   outer_tessellation() const  { return m_outerTessellation; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetOuterTessellation⁴Command();
        SetOuterTessellation⁴Command(const SetOuterTessellation⁴Command&, const Header&);
    
    private:
        Vector4D  m_outerTessellation;
        
        SetOuterTessellation⁴Command(const SetOuterTessellation⁴Command&) = delete;
        SetOuterTessellation⁴Command(SetOuterTessellation⁴Command&&) = delete;
        SetOuterTessellation⁴Command& operator=(const SetOuterTessellation⁴Command&) = delete;
        SetOuterTessellation⁴Command& operator=(SetOuterTessellation⁴Command&&) = delete;
    };
}
