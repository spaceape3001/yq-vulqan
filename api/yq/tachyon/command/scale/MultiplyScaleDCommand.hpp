////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyScaleDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleDCommand, ScaleCommand)
    public:
        MultiplyScaleDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleDCommand(const MultiplyScaleDCommand&, const Header&);
        ~MultiplyScaleDCommand();
        MultiplyScaleDCommand(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyScaleDCommand(const MultiplyScaleDCommand&) = delete;
        MultiplyScaleDCommand(MultiplyScaleDCommand&&) = delete;
        MultiplyScaleDCommand& operator=(const MultiplyScaleDCommand&) = delete;
        MultiplyScaleDCommand& operator=(MultiplyScaleDCommand&&) = delete;
    };
}
