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
    class MultiplyScaleʸDCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleʸDCommand, ScaleCommand)
    public:
        MultiplyScaleʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleʸDCommand(const MultiplyScaleʸDCommand&, const Header&);
        MultiplyScaleʸDCommand(const Header&);
        ~MultiplyScaleʸDCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplyScaleʸDCommand(const MultiplyScaleʸDCommand&) = delete;
        MultiplyScaleʸDCommand(MultiplyScaleʸDCommand&&) = delete;
        MultiplyScaleʸDCommand& operator=(const MultiplyScaleʸDCommand&) = delete;
        MultiplyScaleʸDCommand& operator=(MultiplyScaleʸDCommand&&) = delete;
    };
}
