////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class MultiplyScaleᶻCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleᶻCommand, ScaleCommand)
    public:
        MultiplyScaleᶻCommand(const Header&, double);
        
        static void init_meta();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleᶻCommand(const MultiplyScaleᶻCommand&, const Header&);
        MultiplyScaleᶻCommand(const Header&);
        ~MultiplyScaleᶻCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplyScaleᶻCommand(const MultiplyScaleᶻCommand&) = delete;
        MultiplyScaleᶻCommand(MultiplyScaleᶻCommand&&) = delete;
        MultiplyScaleᶻCommand& operator=(const MultiplyScaleᶻCommand&) = delete;
        MultiplyScaleᶻCommand& operator=(MultiplyScaleᶻCommand&&) = delete;
    };
}
