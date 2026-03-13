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
    class MultiplyScaleʷDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleʷDCommand, ScaleCommand)
    public:
        MultiplyScaleʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δw() const { return m_δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleʷDCommand(const MultiplyScaleʷDCommand&, const Header&);
        MultiplyScaleʷDCommand(const Header&);
        ~MultiplyScaleʷDCommand();

    private:
        double  m_δw = 0.0;
        
        MultiplyScaleʷDCommand(const MultiplyScaleʷDCommand&) = delete;
        MultiplyScaleʷDCommand(MultiplyScaleʷDCommand&&) = delete;
        MultiplyScaleʷDCommand& operator=(const MultiplyScaleʷDCommand&) = delete;
        MultiplyScaleʷDCommand& operator=(MultiplyScaleʷDCommand&&) = delete;
    };
}
