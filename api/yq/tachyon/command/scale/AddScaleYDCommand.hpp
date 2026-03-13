////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddScaleʸDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleʸDCommand, ScaleCommand)
    public:
        AddScaleʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleʸDCommand(const AddScaleʸDCommand&, const Header&);
        AddScaleʸDCommand(const Header&);
        ~AddScaleʸDCommand();

    private:
        double  m_Δy = 0.0;
        
        AddScaleʸDCommand(const AddScaleʸDCommand&) = delete;
        AddScaleʸDCommand(AddScaleʸDCommand&&) = delete;
        AddScaleʸDCommand& operator=(const AddScaleʸDCommand&) = delete;
        AddScaleʸDCommand& operator=(AddScaleʸDCommand&&) = delete;
    };
}
