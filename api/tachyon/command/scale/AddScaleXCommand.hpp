////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddScaleˣCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleˣCommand, ScaleCommand)
    public:
        AddScaleˣCommand(const Header&, double);
        
        static void init_info();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleˣCommand(const AddScaleˣCommand&, const Header&);
        AddScaleˣCommand(const Header&);
        ~AddScaleˣCommand();

    private:
        double  m_Δx = 0.0;
        
        AddScaleˣCommand(const AddScaleˣCommand&) = delete;
        AddScaleˣCommand(AddScaleˣCommand&&) = delete;
        AddScaleˣCommand& operator=(const AddScaleˣCommand&) = delete;
        AddScaleˣCommand& operator=(AddScaleˣCommand&&) = delete;
    };
}
