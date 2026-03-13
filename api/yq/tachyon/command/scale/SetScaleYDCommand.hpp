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
    class SetScaleʸDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleʸDCommand, ScaleCommand)
    public:
        SetScaleʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleʸDCommand(const SetScaleʸDCommand&, const Header&);
        ~SetScaleʸDCommand();

    private:
        double m_y;
        
        SetScaleʸDCommand(const SetScaleʸDCommand&) = delete;
        SetScaleʸDCommand(SetScaleʸDCommand&&) = delete;
        SetScaleʸDCommand& operator=(const SetScaleʸDCommand&) = delete;
        SetScaleʸDCommand& operator=(SetScaleʸDCommand&&) = delete;
    };
}
