////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddScaleˣDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleˣDCommand, ScaleCommand)
    public:
        AddScaleˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleˣDCommand(const AddScaleˣDCommand&, const Header&);
        AddScaleˣDCommand(const Header&);
        ~AddScaleˣDCommand();

    private:
        double  m_Δx = 0.0;
        
        AddScaleˣDCommand(const AddScaleˣDCommand&) = delete;
        AddScaleˣDCommand(AddScaleˣDCommand&&) = delete;
        AddScaleˣDCommand& operator=(const AddScaleˣDCommand&) = delete;
        AddScaleˣDCommand& operator=(AddScaleˣDCommand&&) = delete;
    };
}
