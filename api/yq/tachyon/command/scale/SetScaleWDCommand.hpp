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
    class SetScaleʷDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleʷDCommand, ScaleCommand)
    public:
        SetScaleʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleʷDCommand(const SetScaleʷDCommand&, const Header&);
        ~SetScaleʷDCommand();

    private:
        double  m_w;
        
        SetScaleʷDCommand(const SetScaleʷDCommand&) = delete;
        SetScaleʷDCommand(SetScaleʷDCommand&&) = delete;
        SetScaleʷDCommand& operator=(const SetScaleʷDCommand&) = delete;
        SetScaleʷDCommand& operator=(SetScaleʷDCommand&&) = delete;
    };
}
