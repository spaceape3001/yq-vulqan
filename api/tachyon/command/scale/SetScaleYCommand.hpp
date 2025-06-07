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
    class SetScaleʸCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleʸCommand, ScaleCommand)
    public:
        SetScaleʸCommand(const Header&, double);
        
        static void init_info();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleʸCommand(const SetScaleʸCommand&, const Header&);
        ~SetScaleʸCommand();

    private:
        double m_y;
        
        SetScaleʸCommand(const SetScaleʸCommand&) = delete;
        SetScaleʸCommand(SetScaleʸCommand&&) = delete;
        SetScaleʸCommand& operator=(const SetScaleʸCommand&) = delete;
        SetScaleʸCommand& operator=(SetScaleʸCommand&&) = delete;
    };
}
