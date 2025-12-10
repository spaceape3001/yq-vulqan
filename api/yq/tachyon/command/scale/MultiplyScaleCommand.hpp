////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ScaleCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyScaleCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleCommand, ScaleCommand)
    public:
        MultiplyScaleCommand(const Header&, double);
        
        static void init_meta();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleCommand(const MultiplyScaleCommand&, const Header&);
        ~MultiplyScaleCommand();
        MultiplyScaleCommand(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyScaleCommand(const MultiplyScaleCommand&) = delete;
        MultiplyScaleCommand(MultiplyScaleCommand&&) = delete;
        MultiplyScaleCommand& operator=(const MultiplyScaleCommand&) = delete;
        MultiplyScaleCommand& operator=(MultiplyScaleCommand&&) = delete;
    };
}
