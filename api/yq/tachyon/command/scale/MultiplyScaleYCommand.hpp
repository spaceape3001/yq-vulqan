////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplyScaleʸCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScaleʸCommand, ScaleCommand)
    public:
        MultiplyScaleʸCommand(const Header&, double);
        
        static void init_meta();
        
        double  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScaleʸCommand(const MultiplyScaleʸCommand&, const Header&);
        MultiplyScaleʸCommand(const Header&);
        ~MultiplyScaleʸCommand();

    private:
        double  m_δy = 0.0;
        
        MultiplyScaleʸCommand(const MultiplyScaleʸCommand&) = delete;
        MultiplyScaleʸCommand(MultiplyScaleʸCommand&&) = delete;
        MultiplyScaleʸCommand& operator=(const MultiplyScaleʸCommand&) = delete;
        MultiplyScaleʸCommand& operator=(MultiplyScaleʸCommand&&) = delete;
    };
}
