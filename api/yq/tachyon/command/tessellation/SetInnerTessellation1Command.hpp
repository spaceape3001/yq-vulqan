////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/TessellationCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetInnerTessellation¹Command : public TessellationCommand {
        YQ_OBJECT_DECLARE(SetInnerTessellation¹Command, TessellationCommand)
    public:
        SetInnerTessellation¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   inner_tessellation() const  { return m_innerTessellation; }
        
        static void init_meta();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetInnerTessellation¹Command(const SetInnerTessellation¹Command&, const Header&);
        ~SetInnerTessellation¹Command();

    private:
        Vector1D   m_innerTessellation;
        
        SetInnerTessellation¹Command(const SetInnerTessellation¹Command&) = delete;
        SetInnerTessellation¹Command(SetInnerTessellation¹Command&&) = delete;
        SetInnerTessellation¹Command& operator=(const SetInnerTessellation¹Command&) = delete;
        SetInnerTessellation¹Command& operator=(SetInnerTessellation¹Command&&) = delete;
    };
}
