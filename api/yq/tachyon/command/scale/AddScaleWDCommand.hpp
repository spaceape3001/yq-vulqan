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
    class AddScaleʷDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleʷDCommand, ScaleCommand)
    public:
        AddScaleʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleʷDCommand(const AddScaleʷDCommand&, const Header&);
        AddScaleʷDCommand(const Header&);
        ~AddScaleʷDCommand();

    private:
        double  m_Δw = 0.0;
        
        AddScaleʷDCommand(const AddScaleʷDCommand&) = delete;
        AddScaleʷDCommand(AddScaleʷDCommand&&) = delete;
        AddScaleʷDCommand& operator=(const AddScaleʷDCommand&) = delete;
        AddScaleʷDCommand& operator=(AddScaleʷDCommand&&) = delete;
    };
}
