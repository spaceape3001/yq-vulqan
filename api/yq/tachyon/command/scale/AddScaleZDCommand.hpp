////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddScaleᶻDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleᶻDCommand, ScaleCommand)
    public:
        AddScaleᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleᶻDCommand(const AddScaleᶻDCommand&, const Header&);
        AddScaleᶻDCommand(const Header&);
        ~AddScaleᶻDCommand();

    private:
        double  m_Δz = 0.0;
        
        AddScaleᶻDCommand(const AddScaleᶻDCommand&) = delete;
        AddScaleᶻDCommand(AddScaleᶻDCommand&&) = delete;
        AddScaleᶻDCommand& operator=(const AddScaleᶻDCommand&) = delete;
        AddScaleᶻDCommand& operator=(AddScaleᶻDCommand&&) = delete;
    };
}
