////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class SetScaleˣCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleˣCommand, ScaleCommand)
    public:
        SetScaleˣCommand(const Header&, double);
        
        static void init_meta();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleˣCommand(const SetScaleˣCommand&, const Header&);
        ~SetScaleˣCommand();

    private:
        double  m_x;
        
        SetScaleˣCommand(const SetScaleˣCommand&) = delete;
        SetScaleˣCommand(SetScaleˣCommand&&) = delete;
        SetScaleˣCommand& operator=(const SetScaleˣCommand&) = delete;
        SetScaleˣCommand& operator=(SetScaleˣCommand&&) = delete;
    };
}
