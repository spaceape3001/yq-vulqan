////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class SetScaleˣDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleˣDCommand, ScaleCommand)
    public:
        SetScaleˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleˣDCommand(const SetScaleˣDCommand&, const Header&);
        ~SetScaleˣDCommand();

    private:
        double  m_x;
        
        SetScaleˣDCommand(const SetScaleˣDCommand&) = delete;
        SetScaleˣDCommand(SetScaleˣDCommand&&) = delete;
        SetScaleˣDCommand& operator=(const SetScaleˣDCommand&) = delete;
        SetScaleˣDCommand& operator=(SetScaleˣDCommand&&) = delete;
    };
}
