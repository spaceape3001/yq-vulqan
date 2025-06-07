////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddScaleᶻCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleᶻCommand, ScaleCommand)
    public:
        AddScaleᶻCommand(const Header&, double);
        
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleᶻCommand(const AddScaleᶻCommand&, const Header&);
        AddScaleᶻCommand(const Header&);
        ~AddScaleᶻCommand();

    private:
        double  m_Δz = 0.0;
        
        AddScaleᶻCommand(const AddScaleᶻCommand&) = delete;
        AddScaleᶻCommand(AddScaleᶻCommand&&) = delete;
        AddScaleᶻCommand& operator=(const AddScaleᶻCommand&) = delete;
        AddScaleᶻCommand& operator=(AddScaleᶻCommand&&) = delete;
    };
}
