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
    class MultiplyScaleᶻDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleᶻDCommand, ScaleCommand)
    public:
        MultiplyScaleᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleᶻDCommand(const MultiplyScaleᶻDCommand&, const Header&);
        MultiplyScaleᶻDCommand(const Header&);
        ~MultiplyScaleᶻDCommand();

    private:
        double  m_δz = 0.0;
        
        MultiplyScaleᶻDCommand(const MultiplyScaleᶻDCommand&) = delete;
        MultiplyScaleᶻDCommand(MultiplyScaleᶻDCommand&&) = delete;
        MultiplyScaleᶻDCommand& operator=(const MultiplyScaleᶻDCommand&) = delete;
        MultiplyScaleᶻDCommand& operator=(MultiplyScaleᶻDCommand&&) = delete;
    };
}
