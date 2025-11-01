////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddScaleʸCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleʸCommand, ScaleCommand)
    public:
        AddScaleʸCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleʸCommand(const AddScaleʸCommand&, const Header&);
        AddScaleʸCommand(const Header&);
        ~AddScaleʸCommand();

    private:
        double  m_Δy = 0.0;
        
        AddScaleʸCommand(const AddScaleʸCommand&) = delete;
        AddScaleʸCommand(AddScaleʸCommand&&) = delete;
        AddScaleʸCommand& operator=(const AddScaleʸCommand&) = delete;
        AddScaleʸCommand& operator=(AddScaleʸCommand&&) = delete;
    };
}
